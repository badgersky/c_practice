#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80

typedef struct stud {
    char *name;
    char *surname;
    int birth_year;
    char *address;
    double scholarship;
    struct stud *next;
} stud;

stud *HEAD = NULL;
FILE *fd = NULL;

void make_list(FILE *file, char *input);

void display_list();

void max_scholarship(stud **max);

void push_head(char *name, char *surname, char *address, int birth_year, double scholarship);

void append_student(char *name, char *surname, char *address, int birth_year, double scholarship);

int len();

void remove_start();

void remove_end();

int main() {
    stud *max_s = NULL;
    char input[MAX_LINE];
    fd = fopen("data", "r");
    if (!fd) {
        printf("file error");
        exit(1);
    }

    make_list(fd, input);
    display_list();

    max_scholarship(&max_s);
    printf("\n\nThe biggest scholarship has: %s %s - %.2lf\n\n", max_s->name, max_s->surname, max_s->scholarship);

    printf("Length %d\n", len());

    push_head(
            "Merry",
            "Brandybuck",
            "2137 Oak Street",
            2002,
            1400.
    );

    append_student(
            "Pippin",
            "Tuk",
            "2138 Oak Street",
            2002,
            1000.
    );

    printf("Length %d\n", len());
    remove_start();
    printf("Length %d\n", len());
    remove_end();
    printf("Length %d\n", len());
}

void remove_end() {
    if (!HEAD) {
        printf("list empty");
        exit(1);
    }

    stud* curr = HEAD;
    stud* prev = NULL;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    if (prev) {
        prev->next = NULL;
    }
}

void remove_start() {
    if (!HEAD) {
        printf("list empty");
        exit(1);
    }

    stud *new_head = HEAD->next;
    HEAD = new_head;
}

int len() {
    stud *s = HEAD;
    int i = 0;
    if (s == NULL) {
        return i;
    }

    while (s->next != NULL) {
        i += 1;
        s = (stud *) s->next;
    }
    return i + 1;
}

void append_student(char *name, char *surname, char *address, int birth_year, double scholarship) {
    stud *s = HEAD;
    while (s->next != NULL) {
        s = (stud *) s->next;
    }

    static stud new;
    new.name = name;
    new.surname = surname;
    new.address = address;
    new.birth_year = birth_year;
    new.scholarship = scholarship;
    new.next = NULL;
    s->next = (struct stud *) &new;
}

void push_head(char *name, char *surname, char *address, int birth_year, double scholarship) {
    static stud new;
    new.name = name;
    new.surname = surname;
    new.address = address;
    new.birth_year = birth_year;
    new.scholarship = scholarship;
    new.next = (struct stud *) HEAD;
    HEAD = &new;
}

void max_scholarship(stud **max) {
    stud *curr;
    if (HEAD == (stud *) NULL) {
        printf("list empty");
        exit(0);
    }
    curr = HEAD;
    *max = curr;

    while (curr) {
        if (curr->scholarship > (*max)->scholarship) {
            *max = curr;
        }
        curr = (stud *) curr->next;
    }
}

void display_list() {
    stud *curr;
    if (HEAD == (stud *) NULL) {
        printf("list empty");
        exit(0);
    }
    curr = HEAD;

    while (curr) {
        printf("\n\n");
        printf("Name: %s\nSurname: %s\nYear of birth: %d\nAddress: %s\nScholarship: %.2lf", curr->name, curr->surname,
               curr->birth_year, curr->address, curr->scholarship);
        curr = (stud *) curr->next;
    }
}

void make_list(FILE *file, char *input) {
    unsigned len;
    stud *curr = NULL, *new = NULL;
    while (fgets(input, MAX_LINE, file)) {
        new = (stud *) malloc(sizeof(stud));
        if (!new) {
            printf("memory error");
            exit(1);
        }

        if (HEAD == (stud *) NULL) {
            HEAD = new;
        } else if (curr != (stud *) NULL) {
            curr->next = new;
        }
        new->next = (stud *) NULL;

        len = (unsigned) strlen(input);
        input[len - 1] = 0;
        new->name = (char *) malloc(len);
        strcpy(new->name, input);

        fgets(input, MAX_LINE, file);
        len = (unsigned) strlen(input);
        input[len - 1] = 0;
        new->surname = (char *) malloc(len);
        strcpy(new->surname, input);

        fgets(input, MAX_LINE, file);
        new->birth_year = atoi(input);

        fgets(input, MAX_LINE, file);
        len = (unsigned) strlen(input);
        input[len - 1] = 0;
        new->address = (char *) malloc(len);
        strcpy(new->address, input);

        fgets(input, MAX_LINE, file);
        new->scholarship = atof(input);

        curr = new;
    }
}