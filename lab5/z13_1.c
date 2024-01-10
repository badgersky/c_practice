#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80

void make_list(FILE* file);

typedef struct student {
    char *name;
    char *surname;
    int birth_year;
    char *address;
    double scholarship;
    struct stud *next;
} stud;

stud *HEAD = NULL;
FILE *fd = NULL;

int main() {
    fd = fopen("data", "r");
    make_list(fd);
}

void make_list(FILE *file) {
    unsigned len;
    char input[MAX_LINE];
    stud *curr = NULL, *new = NULL;
    while (fgets(input, MAX_LINE, file)) {
        new = (stud*) malloc(sizeof(stud));
        if (HEAD == (stud*)NULL) {
            HEAD = new;
        } else if (curr != (stud*)NULL) {
            curr->next = (struct stud *) new;
        }
        new->next = (struct stud *) (stud *) NULL;

        len = (unsigned)strlen(input);
        input[len - 1] = 0;
        new->name = (char*) malloc(len);
        strcpy(new->name, input);

        fgets(input, MAX_LINE, file);
        len = (unsigned)strlen(input);
        input[len - 1] = 0;
        new->surname = (char*) malloc(len);
        strcpy(new->surname, input);

        fgets(input, MAX_LINE, file);
        new->birth_year = atoi(input);

        fgets(input, MAX_LINE, file);
        len = (unsigned)strlen(input);
        input[len - 1] = 0;
        new->address = (char*) malloc(len);
        strcpy(new->address, input);

        fgets(input, MAX_LINE, file);
        new->scholarship = atof(input);

        curr = new;
    }
}