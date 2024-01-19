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

EQ *get_el(int i, EQ *HEAD) {
    EQ *el;
    if (!HEAD) {
        print_errors(2);
        exit(1);
    } else {
        el = HEAD;
    }

    while (el) {
        if (el->id == i) {
            printf("id\tbrand\t\t\t\t\tname\t\t\t\t\tprice\n");
            printf("%d\t%-20s\t%-20s\t%-20.2lf\n", el->id, el->brand, el->name, el->price);
            return el;
        }
        el = el->next;
    }

    print_errors(3);
    el = NULL;
    return el;
}

void show_list(EQ *HEAD) {
    EQ *el;
    if (!HEAD) {
        print_errors(2);
        exit(1);
    } else {
        el = HEAD;
    }

    printf("id\tbrand\t\t\t\t\tname\t\t\t\t\tprice\n");
    while (el) {
        printf("%d\t%-20s\t%-20s\t%-20.2lf\n", el->id, el->brand, el->name, el->price);
        el = el->next;
    }
}

int main() {
    EQ *HEAD = make_list();
    EQ *el = get_el(1, HEAD);
    free_list(HEAD);
}
