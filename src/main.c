#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "file_handler.h"
#include "parser.h"

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

    token *tokens = tokenize(program);
    print_tokens(tokens);

    free_tokens(tokens);
    return 0;
}
