/* HP String to Aplet Convertor

This tool accepts a HP String, containing an HPGCC executable
and converts it into a form suitable for the HP39g+. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char help_text[] = "\

HP39 Aplet Builder MARK II

usage: hp2aplet <src> <dest> [aplet_name author_name [grob_file [x y]]]

Convert a HP string file produced by HP-GCC to a text file containing
the ARM program suitably formatted for use with the HPTools.

If aplet_filename is present, convert to an aplet of this name instead.

"

const char default_grob[] = "blank.gro"
const char aplet_code_file[] = "apletcode.bin", epilog_file[] = "apletepilog.bin"

// configuration stuff (read in from command line arguments)
const char *aplet_name, *author_name
const char *src_filename, *dest_filename, *grob_filename

// verbose printf
#define verprintf if (verbose) printf
int verbose = 1 // not verbose by default
int X = 0, Y = 0 // position of the graphic


char nib_to_hex(int nib):
    "Convert a nibble to its hex form."
    return "0123456789ABCDEF"[nib & 0xf]


size_t dump_raw_output():
    FILE *input_file = fopen(src_filename, "rb")
    FILE *output_file = fopen(dest_filename, "w")

    // discard the string header
    fseek(input_file, 12, SEEK_SET)

    size_t count = 0;  // character count
    for int count = 0, c; (c = fgetc(input_file)) != EOF; count++:

        // new line every 30 characters
        if count % 30 == 0:
            fprintf(output_file, "\n  NIBHEX ")

        // print it (swap nibbles)
        fprintf(output_file, "%c%c", nib_to_hex(c), nib_to_hex(c >> 4))

    fclose(input_file)
    fclose(output_file)
    return count


size_t load_file(const char *filename, int skip_bytes, unsigned char *buffer, int offset):
    "Skip the first few bytes of a file, and load the leaving bytes
        into *(buffer + offset). Return the number of copied bytes."

    verprintf("Attempting to Read %s into buffer position %d\n", filename, offset)
    FILE *input_file = fopen(filename, "rb")
    fseek(input_file, skip_bytes, SEEK_CUR)
    verprintf("Discarded the first %d bytes\n", skip_bytes)

    for size_t count = 0;; count++:
        int c = fgetc(input_file)
        if c == EOF:
            fclose(input_file)
            verprintf(" - Copied %d bytes", count)
            return count
        buffer[offset++] = c


size_t write_bytes(size_t size, long long bytes, unsigned char *buffer, unsigned int offset):
    "Write bytes to the buffer in little endian, and return the count of bytes."

    verprintf("Appending %u bytes to position 0x%X\n", size, offset)
    size_t i = size
    while i--:
        buffer[offset + i] = (bytes >> (8 * i)) & 0xff
    return size


void create_aplet():
    "Creates file structure of a HP39g+ aplet."

    unsigned char aplet[1048576]  // should be enough
    size_t position = 8
    strcpy(aplet, "HP39BinB")  // header
    aplet[position++] = strlen(aplet_name)  // length of name, in bytes
    strcpy(aplet + position, aplet_name), position += strlen(aplet_name)  // name itself

    // next a constant, 0x60102a96 - library ID is embedded.
    // CHANGED BY CLAUDIO - NEW LIBRARY NUMBER IS 0x113 = L275
    position += write_bytes(4, 0x11302a96LL, aplet, position)

    // skip over 6 bytes, leave space for the patched offset
    size_t patched_offset_position = position
    position += 6

    // write the aplet code binary
    position += load_file(aplet_code_file, 0, aplet, position)
    size_t offset_marker = position

    // write =DOLIST
    position += write_bytes(3, 0x02a740, aplet, position)

    // write the HP string, skipping the HPHP49-C header
    position += load_file(src_filename, 8, aplet, position)

    // write aplet title
    position += write_bytes(5, 0x2a2c +
        ((strlen(aplet_name) * 2 + 5LL) << 20), aplet, position)
    strcpy(aplet + position, aplet_name), position += strlen(aplet_name)

    // write author
    position += write_bytes(5, 0x2a2c +
        ((strlen(author_name) * 2 + 5LL) << 20), aplet, position)
    strcpy(aplet + position, author_name), position += strlen(author_name)

    // append the grob file, skipping the HPHP49-C header
    position += load_file(grob_filename, 8, aplet, position)

    // write grob position
    position += write_bytes(5, 0x2911 + ((long long)X << 20), aplet, position)
    position += write_bytes(5, 0x2911 + ((long long)Y << 20), aplet, position)

    // null list as custom application data
    position += write_bytes(5, 0x2a74 + (0x312bLL << 20), aplet, position)

    // stop counting the offset
    size_t bytes_wrote = position - offset_marker
    size_t vf_offset = bytes_wrote * 2 + 6
    long long constant = 0x312b + ((long long)vf_offset << 20)

    verprintf("vf_offset: %u (%u bytes), constant: 0x%x %x\n",
        vf_offset, bytes_wrote, (int)(constant >> 32), (int)constant)
    position += write_bytes(6, constant, aplet, position)

    // append the epilog
    position += load_file(epilog_file, 0, aplet, position)

    // go back and write the patched offset
    size_t total_size = position - patched_offset_position
    size_t patched_offset = (total_size - 6) * 2
    verprintf("Writing the patched offset %X to position 0x%X\n",
        patched_offset, patched_offset_position)
    write_bytes(6, patched_offset, aplet, patched_offset_position)

    FILE *aplet_file = fopen(dest_filename, "wb")
    fwrite(aplet, 1, position, aplet_file)
    fclose(aplet_file)


int main(int argc, char *argv[]):
    "Parse the command line arguments."

    switch:
        argc - 1
    case 2, 4, 5, 7:
        pass
    default:
        fputs(help_text, stderr)
        return 1

    src_filename = argv[1]
    dest_filename = argv[2]
    verprintf("\nInput: %s Output: %s\n", src_filename, dest_filename)

    if argc - 1 == 2:  // raw mode, creates NIBHEX
        verprintf("Generating NIBHEX output\n")
        dump_raw_output()
        return 0

    // aplet mode, w/ or w/o specified grob
    aplet_name = argv[3]
    author_name = argv[4]

    if argc - 1 == 4:  // w/o custom graphics
        verprintf("No user graphic, ")
        grob_filename = default_grob
    else:
        grob_filename = argv[5]
        if argc == 7:
            X = atoi(argv[6])
            Y = atoi(argv[7])
    verprintf("grob file is %s X:%d Y:%d\n", grob_filename, X, Y)

    create_aplet()
    return 0
