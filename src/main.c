#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *file_to_read = fopen(argv[1], "r");
    FILE *file_to_write = fopen(argv[2], "w");

    if (file_to_read == NULL) {
        printf("%s file could not be opened!\n", argv[1]);
        return -1;
    }
    if (file_to_write == NULL) {
        printf("Output file could not be opened!\n");
        return -1;
    }

    char c;
    while ((c = fgetc(file_to_read)) != EOF) {
        if (c == '+') {
            c = '-';
        }
        fputc(c, file_to_write);
    }

    fclose(file_to_read);
    fclose(file_to_write);

    return 0;
}
