#include <stdio.h>
#include <stdlib.h>

char *file_to_string(char *filename) {
    FILE *file = fopen(filename, "r");
    char *buffer = 0;
    long length;
    
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        buffer = (char *)malloc(length);
        if (buffer != NULL) {
            fread(buffer, 1, length, file);
        }
    }

    return buffer;
}
