#ifndef PARSER
#define PARSER

#include <stdio.h>

typedef enum {INC,DEC,NEXT,PREV,DO,DAL,OUT,EOP} token;

token *tokenize(char *input_file);

void free_tokens(token *tokens);

void print_tokens(token *tokens);

void parse(token *tokens);

#endif
