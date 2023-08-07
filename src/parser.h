#ifndef PARSER
#define PARSER

#include <stdio.h>

typedef enum {
    INC,
    DEC,
    NEXT,
    PREV,
    DO,
    WHILE,
    FAIL
} token;

token *lex(FILE *input_file);

void parse(token *tokens);

#endif
