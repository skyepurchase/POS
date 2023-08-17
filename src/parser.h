#ifndef PARSER
#define PARSER

#include <stdio.h>

typedef enum {INC,DEC,NEXT,PREV,LOOP,DAL,OUT,EOP,HALT} token;
typedef struct prog * prog_t;

struct prog {
    token inst;
    prog_t next;
    prog_t loop;
};

token *tokenize(char *input_file);

void free_tokens(token *tokens);

void print_tokens(token *tokens);

prog_t mk_inst(token curr_inst, prog_t next_inst);

prog_t mk_loop(token curr_inst, prog_t next_inst, prog_t loop);

void free_prog(prog_t program);

int parse(token *tokens, prog_t *program);

#endif
