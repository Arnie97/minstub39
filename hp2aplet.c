/*
*
*HP String to Aplet Convertor
*
*This tool accepts a HP String, containing an HPGCC executable
*and converts it into a form suitable for the HP39g+
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//verbose printf
#define verprintf if (verbose) printf

//the library file
#define HP_LIB_FILE "LIB275L.L39"
#define HP_LIB_FILE_OUT "LIB275L.000"
#define FILE_1 "apletcode.bin"
#define FILE_2 "apletepilog.bin"

int verbose = 0; //not verbose by default

FILE *inputFile;
FILE *outputFile;

const char
raw_filename[] = "HPGCC000.S",
aplet_filename[] = "HPGCC000.000",
default_grob[] = "blank.gro";

// configuration stuff (read in from command line arguments)
const char *aplet_name, *author_name;
const char *source_filename, *destination_filename, *grob_filename;

int X = 0, Y = 0; //position of the graphic

char nibToHex(int nib)  //converts a nibble to its hex form
{
    char *hex = "0123456789ABCDEF";
    return hex[nib & 0xf];
}

void dumpRawOutput(void)
{
    int i;
    for (i = 0; i <= 12; i++) { fgetc(inputFile); } //discard the string header

    outputFile = fopen(destination_filename, "w");

    int c = 0; //the character
    unsigned int count = 0; //character count
    while (1) {

        if (count % 30 == 0) { fprintf(outputFile, "\n  NIBHEX "); } //new line every 30 characters
        c = fgetc(inputFile); //read a char
        if (c == EOF) { return; } //bail out if EOF
        fprintf(outputFile, "%c%c", nibToHex(c), nibToHex(c >> 4)); //print it (swap nibbles)
        count++;
    }

}

int loadFile(const char *fileName, int fileOffset, unsigned char *buffer, int offset)
{
    //this loads a file skips the first 'fileOffset' characters
    // and copies it into the buffer at offset 'offset'
    //it returns the number of bytes copied if sucessful
    // If failure occurred, exits
    verprintf("\n\nAttempting to Read %s into buffer position %d", fileName, offset);

    FILE *sourceFile = fopen(fileName, "rb"); //open for binary reading
    if (sourceFile == NULL) {
        printf("\n\n\n***Error*** Could not open %s\n\n\n", fileName);
        exit(0); //failure, could not open
    }

    int c = 0; //the character
    int count = 0; //number of bytes copied

    int i;
    for (i = 0; i != fileOffset; i++) { //discard any header
        fgetc(sourceFile);
    }
    verprintf("\nDiscarded the first %d bytes", fileOffset);

    while (1) {
        c = fgetc(sourceFile); //read a char
        if (c == EOF) {
            fclose(sourceFile);
            verprintf(" - Copied %d bytes", count);
            return count; //bail out if EOF
        }
        buffer[offset] = c; //write it
        offset++;
        count++;
    }
}

void writeFiveBytes(long long bytes, unsigned char *buffer, unsigned int offset)
{
    //writes 5 bytes to the buffer (little endian)
    verprintf("\nAppending 5 bytes, ending with, %X to position 0x%X", (int)bytes, offset);
    buffer[offset + 4] = (bytes >> 32) & 0xff;
    buffer[offset + 3] = (bytes >> 24) & 0xff;
    buffer[offset + 2] = (bytes >> 16) & 0xff;
    buffer[offset + 1] = (bytes >> 8) & 0xff;
    buffer[offset] = bytes & 0xff;
}

void writeThreeBytes(int bytes, unsigned char *buffer, unsigned int offset)
{
    //writes 3 bytes to the buffer. (little endian)
    verprintf("\nAppending 0x%X to position 0x%X", bytes, offset);
    buffer[offset + 2] = (bytes >> 16) & 0xff;
    buffer[offset + 1] = (bytes >> 8) & 0xff;
    buffer[offset] = bytes & 0xff;
}

void writeSixBytes(long long bytes, unsigned char *buffer, unsigned int offset)
{
    //6 bytes (little endian)
    // eg
    // 0x 01 23 45 67 89 AB -> [67 89 AB] [01 23 45]
    // -> AB 89 67 45 23 01
    writeThreeBytes(bytes & 0xffffff, buffer, offset);
    writeThreeBytes((bytes >> 24) & 0xffffff, buffer, offset + 3);
}

void createAplet(void)
{
    //creates a HP39g+ Aplet

    unsigned char aplet[300000]; //the aplet structure - 300kb should be heaps
    int i; //iterator

    strcpy(aplet, "HP39BinB"); //aplet header
    aplet[8] = strlen(aplet_name);   //8th byte contains the name size, in bytes
    strcpy(aplet + 9, aplet_name); //name is copied into the 9th byte onwards
    int position = 9 + strlen(aplet_name);

    // next a constant, 0x60102a96 - library ID is embedded.
    // CHANGED BY CLAUDIO - NEW LIBRARY NUMBER IS 0x113 = 275
    verprintf("Writing 0x11302a96 to position 0x%X", position);
    aplet[position + 3] = 0x11; //little endian
    aplet[position + 2] = 0x30;
    aplet[position + 1] = 0x2a;
    aplet[position] = 0x96;
    position += 4; //skip over magic number

    int offsetPosition = position;
    position += 6; //skip over the patched offset
    int apletcodesize = loadFile(FILE_1, 0, aplet, position); //TODO: Error checking
    position += apletcodesize; //move position to the end of theapletcode.bin data

    writeThreeBytes(0x02a740, aplet, position); //write =DOLIST
    position += 3;

    //write the HP string, skipping the HPHP49-C header
    int hpstringsize = loadFile(source_filename, 8, aplet, position);
    position += hpstringsize;

    // write the parameters, eg author, aplet title etc
    writeFiveBytes(0x2a2c + (long long)((strlen(aplet_name) * 2 + 5) << 20), aplet, position);
    position += 5;

    strcpy(aplet + position, aplet_name);
    position += strlen(aplet_name); //length of the title

    writeFiveBytes(0x2a2c + (long long)((strlen(author_name) * 2 + 5) << 20), aplet, position);
    position += 5;

    strcpy(aplet + position, author_name);
    position += strlen(author_name); //length of the author name

    // now do the grob stuff
    int grobsize = loadFile(grob_filename, 8, aplet, position);
    position += grobsize; //append the grob file

    writeFiveBytes(0x2911 + (long long)(X << 20), aplet, position); //write grob position
    position += 5;
    writeFiveBytes(0x2911 + (long long)(Y << 20), aplet, position);
    position += 5;

    // null list as custom application data
    writeFiveBytes((long long)0x2a74 + (((long long)0x312b) << 20), aplet, position);
    position += 5;

    // now write the various patched offsets
    unsigned int numbytes = 3 + hpstringsize + 5 + strlen(aplet_name) + 5 + strlen(author_name);
    // ADDED 5 BYTES FOR THE NULL LIST - CLAUDIO
    numbytes += grobsize + 5 + 5 + 5;
    unsigned int vf_offset = numbytes * 2 + 6;
    verprintf("\n\n'numbytes' = 0x%X, 'vf_offset' = 0x%X", numbytes, vf_offset);

    long long constant = (long long)0x312b + (((long long)vf_offset) << 20);

    verprintf("\n\nthe constant is 0x%x %x", (int)(constant >> 32), (int)constant);

    //write vf_offset
    writeSixBytes(constant, aplet, position);
    position += 6;

    int epilogsize = loadFile(FILE_2, 0, aplet, position); //append the epilog
    position += epilogsize;

    unsigned int totalsize = 6 + apletcodesize + numbytes + 6 + epilogsize;
    unsigned int offset = (totalsize - 6) * 2;

    verprintf("\n\n\nWriting the patched offset, %X, to position 0x%X", offset, offsetPosition);
    writeSixBytes(offset, aplet, offsetPosition);

    // finally, write the aplet to disk
    outputFile = fopen(destination_filename, "wb"); //open for binary writing

    for (i = 0; i < position; i++) {
        fputc(aplet[i], outputFile); //write the char to the file
    }
    fclose(outputFile);
}

void createSupportFiles(void)
{
    //this generates the support files, for an Aplet
    //eg hp39dir.cur and hp39dir.000
    verprintf("\n\nCreating support files...");

    FILE *hp39dir_cur = fopen("hp39dir.cur", "w");
    FILE *hp39dir_000 = fopen("hp39dir.000", "w");
    FILE *hplib_out = fopen(HP_LIB_FILE_OUT, "wb");
    FILE *hplib_in = fopen(HP_LIB_FILE, "rb");

    if (hplib_in == NULL) {
        printf("\n\nError! Could not find library file %s\n\n", HP_LIB_FILE);
        exit(0);
    }
    if ((hp39dir_000 == NULL) || (hp39dir_cur == NULL) || (hplib_out == NULL)) {
        //couldn't create support files
        printf("\n\n\nError! Could not create Aplet support files (hp39dir.cur/hp39dir.000\n\n\n");
        exit(0);
    }

    fputs("HP39AscA A 11 HP39DIR.0004 Root", hp39dir_cur);
    fprintf(hp39dir_000, "HP39AscA B 12 HPGCC000.000%d %s H 11 LIB275L.0007 LIB275L ", strlen(aplet_name), aplet_name);
    //  verprintf("\n\nHP39AscA B 12 HPGCC000.000%d %s H 12 LIB1537L.0008 LIB1537L ",strlen(aplet_name),aplet_name);

    //now copy library file into the current directory
    int c = 0;
    while (1) {
        c = fgetc(hplib_in);
        if (c == EOF) { break; } //we're done
        fputc(c, hplib_out);
    }

    fclose(hp39dir_000);
    fclose(hp39dir_cur);
    fclose(hplib_in);
    fclose(hplib_out);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        // raw mode, creates NIBHEX
        verprintf("\nInput: %s Output: %s\n\n", source_filename, destination_filename);
        inputFile = fopen(source_filename, "rb"); //open for reading
        destination_filename = raw_filename;

        verprintf("Generating NIBHEX output\n\n"); //setup output file
        dumpRawOutput();
    } else if (argc == 4 || argc == 7) {
        // aplet mode
        verprintf("\nInput: %s Output: %s\n\n", source_filename, destination_filename);
        inputFile = fopen(source_filename, "rb"); //open for reading
        destination_filename = aplet_filename;

        aplet_name = argv[3];
        author_name = argv[4];
        if (argc == 5) { //there's graphics
            grob_filename = argv[5];
            X = atoi(argv[6]);
            Y = atoi(argv[7]);
        } else { //no user graphics, use a blank grob
            verprintf("\n\nNo user graphic");
            grob_filename = default_grob;
        }
        verprintf("\n\ngrob file is %s X:%d Y:%d", grob_filename, X, Y);

        createAplet();
        createSupportFiles();
    } else {
        printf("\n\nHP39 Aplet Builder\n\nusage:");
        printf("\n\nhp2aplet <inputfile> [-r]");
        printf("\n\n'inputfile' is a HP string, produced by HP-GCC. \nYour aplet is created in the current folder. ");
        printf("\n\n-r is an optional parameter. ");
        printf("\n\nIf you add the -r flag, the convertor instead outputs a text file containing ");
        printf("\nthe ARM program suitably formatted for use with the HPTools. ");
        printf("\n\nNOTE: Before running this program, you should use the HP39 Aplet Wizard ");
        printf("\nto create an aplet project file. Type 'hp39wiz' to run it.");
        exit(0);
    }
    fclose(inputFile); //clean up
    fclose(outputFile);
    return 0;
}
