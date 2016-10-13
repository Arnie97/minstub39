#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char help_text[] = "\

HP39 Aplet Builder MARK II

usage: %s <src> <dest> [aplet_name]

Convert a HP string file produced by HP-GCC into various formats.

If the aplet name is present, patch the skeleton aplet according to
the name and ARM program from the HP string file.
Otherwise, convert the HP string to a text format compatible with the HPTools.

"

const char skeleton_filename[] = "HPGCC000.000"

// configuration stuff (read in from command line arguments)
const char *src_filename, *dest_filename, *aplet_name



FILE* open(const char *filename, const char *mode):
    "Wrap fopen() to catch exceptions."
    FILE *fp = fopen(filename, mode)
    if !fp:
        fprintf(stderr, "Error: Cannot open file '%s'.\n", filename)
        exit(EXIT_FAILURE)
    return fp


size_t dump_raw_output():
    "Convert a HP string file to a text file containing
        the raw ARM program suitably formatted for use with the HPTools."

    FILE *input = open(src_filename, "rb")
    FILE *output = open(dest_filename, "wb")

    // discard the string header
    fseek(input, 12, SEEK_SET)

    size_t count = 0;  // character count
    for int count = 0, c; (c = fgetc(input)) != EOF; count++:

        // new line every 30 characters
        if count % 30 == 0:
            fprintf(output, "\n  NIBHEX ")

        // print it (swap nibbles)
        fprintf(output, "%x%x", c & 0xf, (c >> 4) & 0xf)

    fclose(input)
    fclose(output)
    return count


size_t cat(
    FILE *output, int skip_bytes, const char *filename,
    int (*callback)(char **beg, char **end)
):
    "Open a file and skip the first few bytes.
        If the callback function is present, invoke it to do some hacks.
        Then copy the remaining bytes into the given stream.
        Return the number of copied bytes."

    FILE *input = open(filename, "rb")

    // get the size of file
    fseek(input, 0, SEEK_END)
    size_t size = ftell(input) - skip_bytes

    // rewind and skip the header
    fseek(input, skip_bytes, SEEK_SET)

    // read the remaining bytes
    char buffer[size]
    fread(buffer, 1, size, input)

    // invoke the callback function
    char *beg = buffer, *end = buffer + size
    if callback:
        if callback(&beg, &end):
            fprintf(stderr, "Error: Invalid aplet skeleton.\n")
            exit(EXIT_FAILURE)

    fwrite(beg, 1, end - beg, output)
    return size


int truncate_aplet_code(char **beg, char **end):
    const char magic[] = "ARMCODE HERE!!!"
    size_t len = strlen(magic)

    for char *p = *beg; p + len < *end; p++:
        if strncmp(p, magic, len) == 0:
            *end = p - 8
            return memcmp(*end, "\x40\xA7\x02\x2C", 4)
    return 1


int truncate_aplet_epilog(char **beg, char **end):
    const char magic[] = "t*\xb0\x12\x03+1"
    size_t len = strlen(magic)

    for char *p = *end - 1; p >= *beg; p--:
        if strncmp(p, magic, len) == 0:
            *beg = p + 11
            return memcmp(*beg, "t*", 2)
    return 1


size_t write_bytes(FILE *output, size_t size, long long bytes):
    "Write part of the integer, according to size, to the stream
        in little endian, and return the number of copied bytes."

    for size_t i = 0; i < size; i++:
        fputc((bytes >> (8 * i)) & 0xff, output)
    return size


size_t create_aplet():
    "Create file structure of a HP39g+ aplet."

    FILE *aplet = open(dest_filename, "wb")
    fputs("HP39BinB", aplet)
    fputc(strlen(aplet_name), aplet)  // length of aplet name, in bytes
    fputs(aplet_name, aplet)  // name itself

    // next a constant, 0x60102a96 - library ID is embedded.
    // CHANGED BY CLAUDIO - NEW LIBRARY NUMBER IS 0x113 = L275
    write_bytes(aplet, 4, 0x11302a96LL)

    // skip over 6 bytes, leave space for the patched offset
    size_t patched_offset_position = ftell(aplet)
    fseek(aplet, 6, SEEK_CUR)

    // write the aplet code binary
    cat(aplet, 30, skeleton_filename, truncate_aplet_code)
    size_t offset_marker = ftell(aplet)

    // write =DOLIST
    write_bytes(aplet, 3, 0x02a740)

    // write the HP string, skipping the HPHP49-C header
    cat(aplet, 8, src_filename, NULL)

    // null list as custom application data
    write_bytes(aplet, 5, 0x2a74 + (0x312bLL << 20))

    // stop counting the offset
    size_t bytes_wrote = ftell(aplet) - offset_marker
    size_t vf_offset = bytes_wrote * 2 + 6
    long long constant = 0x312b + ((long long)vf_offset << 20)
    write_bytes(aplet, 6, constant)

    // append the epilog
    cat(aplet, 0, skeleton_filename, truncate_aplet_epilog)

    // go back and write the patched offset
    size_t total_size = ftell(aplet) - patched_offset_position
    size_t patched_offset = (total_size - 6) * 2
    printf(
        "Offset: %zu bytes, vf_offset: %#zx, constant: %#llx\n"
        "Writing the patched offset %#zx to position %#zx\n",
        bytes_wrote, vf_offset, constant,
        patched_offset, patched_offset_position
    )

    fseek(aplet, patched_offset_position, SEEK_SET)
    write_bytes(aplet, 6, patched_offset)

    // get the size of file
    fseek(aplet, 0, SEEK_END)
    bytes_wrote = ftell(aplet)

    fclose(aplet)
    return bytes_wrote


size_t create_wrapper():
    "Patch a HP string object to wrap it in UserRPL."

    // add RPL header and skip the original header
    FILE *output = open(dest_filename, "wb")
    fputs("HPHP49-B\x9D-\x90\x9B""8", output)
    size_t bytes_wrote = cat(output, 8, src_filename, NULL)

    // append the epilog
    fwrite("\x92.0\x11\0@\x9D""8+1\0", 1, 11, output)
    fclose(output)
    return bytes_wrote + 16 + 11


int main(int argc, char *argv[]):
    "Parse the command line arguments."

    if argc < 2 || argc > 4:
        fprintf(stderr, help_text, argv[0])
        return EXIT_FAILURE

    char buffer[strlen(argv[1]) + 5]
    if argc == 2:
        // buffer for file name with .bak suffix
        strcpy(buffer, argv[1])
        strcat(buffer, ".bak")

        // move the file for backup
        src_filename = buffer
        dest_filename = argv[1]
        remove(src_filename)
        rename(dest_filename, src_filename)
    else:
        src_filename = argv[1]
        dest_filename = argv[2]
        if argc == 4:
            aplet_name = argv[3]

    const char *msg[] = {
        "UserRPL wrapper",
        "NIBHEX output",
        "aplet skeleton"
    }
    size_t (*func[])() = {
        &create_wrapper,
        &dump_raw_output,
        &create_aplet
    }

    argc -= 2
    printf(
        "Input: %s Output: %s\n"
        "Generating %s...\n",
        src_filename, dest_filename, msg[argc]
    )
    printf("Well done, %zu bytes written.", (*func[argc])())
    return EXIT_SUCCESS
