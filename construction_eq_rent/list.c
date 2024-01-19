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
        return NULL;
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
        return;
    } else {
        el = HEAD;
    }

    printf("id\tbrand\t\t\t\t\tname\t\t\t\t\tprice\n");
    while (el) {
        printf("%d\t%-20s\t%-20s\t%-20.2lf\n", el->id, el->brand, el->name, el->price);
        el = el->next;
    }
}

void del_el(int i, EQ **HEAD) {
    EQ *el;
    if (!*HEAD) {
        print_errors(2);
        return;
    } else {
        el = *HEAD;
    }

    // delete HEAD element
    if (el->id == i) {
        *HEAD = el->next;
        free(el->name);
        free(el->brand);
        free(el);
        return;
    }

    EQ *p_el = NULL;
    while (el->next) {
        p_el = el;
        el = el->next;

        if (el->id == i) {
            p_el->next = el->next;
            if (el->next) {
                el->next->prev = p_el;
            }

            free(el->name);
            free(el->brand);
            free(el);
            return;
        }
    }

    print_errors(3);
}

unsigned get_max_id(EQ *HEAD) {
    EQ *el;
    if (!HEAD) {
        print_errors(2);
        return 0;
    } else {
        el = HEAD;
    }

    unsigned id = 0;
    while (el) {
        if (el->id > id) {
            id = el->id;
        }
        el = el->next;
    }

    return id;
}

unsigned append_element(unsigned max_id, EQ *HEAD, char *name, char *brand, double price) {
    EQ *new, *last = HEAD;

    new = (EQ *) malloc(sizeof(EQ));
    if (!new) {
        print_errors(1);
        return max_id;
    }

    new->name = (char *) malloc(sizeof(strlen(name)) + 1);
    strcpy(new->name, name);
    new->brand = (char *) malloc(sizeof(strlen(brand)) + 1);
    strcpy(new->brand, brand);
    new->price = price;
    new->id = max_id + 1;
    new->next = NULL;

    while (last->next) {
        last = last->next;
    }

    new->prev = last;
    last->next = new;

    return max_id + 1;
}

void save_list(EQ*HEAD) {
    EQ *el;
    if (!HEAD) {
        print_errors(2);
        return;
    } else {
        el = HEAD;
    }

    FILE *f_out;
    f_out = fopen("out.b", "wb");
    if (!f_out) {
        print_errors(0);
        return;
    }

    while (el) {

        fwrite((void *) el, sizeof(EQ), 1, f_out);
        el = el->next;
    }
}

int main() {
    EQ *HEAD = make_list();
    unsigned id = get_max_id(HEAD);
    del_el(10, &HEAD);
    del_el(9, &HEAD);
    del_el(2, &HEAD);
    id = append_element(id, HEAD, "lol", "lol", 2137);
    show_list(HEAD);
    save_list(HEAD);
    free_list(HEAD);
    printf("done");
}
