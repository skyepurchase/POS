#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

token *tokenize(char *program_string) { // {{{
    // Dynamic arrays later
    token *tokens = malloc(1024 * sizeof(token));

    int id = 0;
    while (*program_string && id < 1023) {
        switch(*program_string) { // {{{
            case '+':
                tokens[id] = INC;
                id++;
                break;
            case '-':
                tokens[id] = DEC;
                id++;
                break;
            case '>':
                tokens[id] = NEXT;
                id++;
                break;
            case '<':
                tokens[id] = PREV;
                id++;
                break;
            case '[':
                tokens[id] = LOOP;
                id++;
                break;
            case ']':
                tokens[id] = DAL;
                id++;
                break;
            case '.':
                tokens[id] = OUT;
                id++;
                break;
            default:
                break;
        } // }}}
        program_string++;
    }

    tokens[id] = EOP;
    return tokens;
} // }}}

void free_tokens(token *tokens) { // {{{
    free(tokens);
} // }}}

void print_tokens(token *tokens) { // {{{
    while (*tokens != EOP) {
        switch(*tokens) { // {{{
            case INC:
                printf("INC,");
                break;
            case DEC:
                printf("DEC,");
                break;
            case NEXT:
                printf("NEXT,");
                break;
            case PREV:
                printf("PREV,");
                break;
            case LOOP:
                printf("LOOP,");
                break;
            case DAL:
                printf("DAL,");
                break;
            case OUT:
                printf("OUT,");
                break;
            case EOP:
                printf("EOP");
        } // }}}
        tokens++;
    }

    printf("EOP\n");
} // }}}

prog_t mk_inst(token curr_inst, prog_t next_inst) { // {{{
    prog_t p = malloc(sizeof(struct prog));
    p->inst = curr_inst;
    p->next = next_inst;
    p->loop = NULL;
    return p;
} // }}}

prog_t mk_loop(token curr_inst, prog_t next_inst, prog_t loop) { // {{{
    prog_t p = malloc(sizeof(struct prog));
    p->inst = curr_inst;
    p->next = next_inst;
    p->loop = loop;
    return p;
} // }}}

void free_prog(prog_t p) { // {{{
    if (p != NULL) {
        switch (p->inst) {
            case LOOP:
                free_prog(p->loop);
            case INC:
            case DEC:
            case NEXT:
            case PREV:
            case OUT:
            case HALT:
            case EOP:
                free_prog(p->next);
                free(p);
                break;
            case DAL:
            default:
                printf("Encountered unexpected AST symbol!");
                break;
        }
    }
} // }}}

int parse_loop(token *tokens, int i, prog_t *loop) {
    return -1;
}

int parse(token *tokens, prog_t *program) { // {{{
    int id = 0;
    while (tokens[id] != EOP) {
        token curr_inst = *tokens;
        prog_t loop, next_inst = malloc(sizeof(struct prog));

        id++;
        switch (curr_inst) {
            case LOOP:
                id = parse_loop(tokens, id, &loop);
                if (id == -1) {
                    return -1;
                }
                id = parse(tokens, &next_inst);
                if (id == -1) {
                    return -1;
                }
                *program = mk_loop(curr_inst, next_inst, loop);
                break;
            case EOP:
                *program = mk_inst(HALT, NULL);
                break;
            case DAL:
                *program = mk_inst(EOP, NULL);
                break;
            case INC:
            case DEC:
            case NEXT:
            case PREV:
            case OUT:
                id = parse(tokens, &next_inst);
                if (id == -1) {
                    return -1;
                }
                *program = mk_inst(curr_inst, next_inst);
                break;
            case HALT:
                printf("Unexpected token 'HALT'!");
                break;
        }
    }
} // }}}

