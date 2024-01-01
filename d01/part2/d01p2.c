#include <stdio.h>

int main(int argc, char** argv) {
    char* filename;
    FILE* input_fp;
    FILE* output_fp;

    /* make sure we have a file passed as input and a path to write output */
    if (argc != 3) {
        printf("need input and output files as arguments\n");
        return 1;
    }

    /* open the input file in read mode */
    filename = argv[1];
    input_fp = fopen(filename, "r");
    if (input_fp == NULL) {
        perror(filename);
        return 1;
    }

    /* open the output file in write mode */
    filename = argv[2];
    output_fp = fopen(filename, "w");
    if (input_fp == NULL) {
        perror(filename);
        return 1;
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
