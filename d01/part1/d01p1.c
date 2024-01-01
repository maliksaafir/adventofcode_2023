#include <stdio.h>

int main(int argc, char** argv) {
    char c;
    char* filename;
    FILE* input_fp;
    FILE* output_fp;
    int first_num;
    int last_num;
    int line_value;
    int total_value;

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

    /* begin reading input file and calculating each line's calibration value */
    first_num = -1;
    last_num = -1;
    total_value = 0;
    while ((c = getc(input_fp)) != EOF) {
        if (c == '\n') {
            /* calculate the line's calibration value */
            total_value += 10 * first_num + last_num;

            /* reset for the next line */
            first_num = -1;
            last_num = -1;
        } else if (c >= '0' && c <= '9') {
            /* update records of first and last numbers in this line */
            if (first_num == -1) {
                /* first number only changes for the first time we see a 
                 * number on this line */
                first_num = c - '0';
            }
            /* last number updates each time we see a number */
            last_num = c - '0';
        }
    }

    fprintf(output_fp, "%d\n", total_value);
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
