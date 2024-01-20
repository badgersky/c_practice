#include <stdio.h>

#define MAX_LINE 100

typedef struct EQ {
    unsigned id;
    char brand[MAX_LINE];
    char name[MAX_LINE];
    double price;
    struct EQ *next;
    struct EQ *prev;
} EQ;

FILE *open_file();

struct EQ *make_list();

void free_list(EQ **HEAD);

void show_list(EQ *HEAD);

EQ *get_el(int i, EQ *HEAD);

void del_el(int i, EQ **HEAD);

unsigned append_element(unsigned max_id, EQ *HEAD, char *name, char *brand, double price);

unsigned get_max_id(EQ *HEAD);

void save_list(EQ*HEAD);

EQ* read_list(EQ**HEAD);
