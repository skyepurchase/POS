#include <stdio.h>
#include <stdlib.h>

char *file_to_string(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open %s to convert to string.\n", filename);
        return NULL;
    }

    char *buffer = 0;
    long length;
    
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = (char *)malloc(length);
    if (buffer != NULL) {
        fread(buffer, 1, length, file);
    }

    fclose(file);

    return buffer;
}
