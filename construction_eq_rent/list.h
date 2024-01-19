#include <stdio.h>

#define MAX_LINE 100

typedef struct EQ {
    unsigned id;
    char *brand;
    char *name;
    double price;
    struct EQ *next;
    struct EQ *prev;
} EQ;

FILE *open_file();

struct EQ *make_list();

void free_list(EQ *HEAD);

void show_list(EQ *HEAD);

EQ *get_el(int i, EQ *HEAD);

void del_el(int i, EQ **HEAD);

void append_element(EQ *HEAD, char *name, char *brand, double price);

unsigned get_max_id(EQ *HEAD);