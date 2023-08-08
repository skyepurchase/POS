#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

token *tokenize(char *program_string) {
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
                tokens[id] = DO;
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
}

void free_tokens(token *tokens) {
    free(tokens);
}

void print_tokens(token *tokens) {
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
            case DO:
                printf("DO,");
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
}
