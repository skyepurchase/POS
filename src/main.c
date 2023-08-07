#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "file_handler.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *program = file_to_string(argv[1]);

    if (program == NULL) {
       printf("Could not load program from %s.\n", argv[1]);
       return -1;
    }

    FILE *file_to_write = fopen(argv[2], "w");

    if (file_to_write == NULL) {
        printf("Output file could not be opened!\n");
        return -1;
    }

    while (*program != '\0') {
        char c = *program;
        if (c == '+') {
            c = '-';
        }
        fputc(c, file_to_write);
        program++;
    }

    fclose(file_to_write);

    return 0;
}
