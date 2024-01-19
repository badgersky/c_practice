#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "list.h"

FILE *open_file() {
    FILE *fd = NULL;

    fd = fopen("data.txt", "r");

    if (!fd) {
        print_errors(0);
        exit(1);
    }

    return fd;
}

struct EQ *make_list() {
    FILE *file = open_file();
    struct EQ *HEAD = NULL, *new = NULL, *curr = NULL;
    char input[MAX_LINE];
    unsigned len;
    int i = 1;

    while (fgets(input, MAX_LINE, file)) {
        new = (EQ *) malloc(sizeof(EQ));
        if (!new) {
            print_errors(1);
            exit(1);
        }

        if (!HEAD) {
            HEAD = new;
            HEAD->prev = NULL;
        } else {
            curr->next = new;
        }
        new->next = NULL;
        new->prev = curr;

        // brand name
        len = (unsigned) strlen(input);
        input[len - 1] = 0;
        new->brand = (char *) malloc(len);
        strcpy(new->brand, input);

        // model name
        fgets(input, MAX_LINE, file);
        len = (unsigned) strlen(input);
        input[len - 1] = 0;
        new->name = (char *) malloc(len);
        strcpy(new->name, input);

        // price
        fgets(input, MAX_LINE, file);
        new->price = atof(input);

        // id
        new->id = i;
        i++;

        curr = new;
    }

    return HEAD;
}

void free_list(EQ *HEAD) {
    EQ *el = HEAD, *el_prev;

    while (el->next) {
        free(el->name);
        free(el->brand);
        el_prev = el;
        el = el->next;
        free(el_prev);
    }

    HEAD = NULL;
}
