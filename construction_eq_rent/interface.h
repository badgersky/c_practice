#include "list.h"

void show_help();

EQ * init_list();

unsigned int add_element(unsigned max_id, EQ *HEAD);

void delete_element(EQ**HEAD);

void delete_list(EQ **HEAD);

void save_to_bin(EQ **HEAD);

void load_from_bin(EQ **HEAD);

void get_element(EQ *HEAD);

void print_list(EQ *HEAD);
