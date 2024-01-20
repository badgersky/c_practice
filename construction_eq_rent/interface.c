#include <stdio.h>
#include "list.h"
#include "error.h"

void show_help() {
    printf("Here are available commands:\n");
    printf("h - show available commands\n");
    printf("a - adds element at the end of a list\n");
    printf("d - deletes element with given id\n");
    printf("f - deletes list\n");
    printf("s - saves list to binary file\n");
    printf("l - loads list from binary file\n");
    printf("g - gets element with given id\n");
    printf("p - prints whole list to monitor\n");
    printf("q - quits program\n");
}

unsigned add_element(unsigned max_id, EQ **HEAD) {
    char brand[MAX_LINE], name[MAX_LINE];
    double price;
    int ret;

    printf("Enter equipment brand\n");
    ret = scanf("%[^\n]%*c", brand);
    if (ret != 1) {
        print_errors(5);
        return max_id;
    }

    printf("Enter equipment name:\n");
    ret = scanf("%[^\n]%*c", name);
    if (ret != 1) {
        print_errors(5);
        return max_id;
    }

    printf("Enter equipment price:\n");
    ret = scanf("%lf", &price);
    if (ret != 1) {
        print_errors(5);
        return max_id;
    }

    printf("item added\n");
    return append_element(max_id, *HEAD, name, brand, price);
}

void delete_element(EQ **HEAD) {
    int id, ret;
    printf("Enter id of element you want to delete:\n");
    ret = scanf("%d", &id);
    if (ret != 1) {
        print_errors(5);
        return;
    }

    del_el(id, &*HEAD);
}

void delete_list(EQ **HEAD) {
    free_list(&*HEAD);
}

void save_to_bin(EQ **HEAD) {
    save_list(*HEAD);
}

void load_from_bin(EQ **HEAD) {
    read_list(&*HEAD);
}

void get_element(EQ *HEAD) {
    int id, ret;
    printf("Enter id of element you want to delete:\n");
    ret = scanf("%d", &id);
    if (ret != 1) {
        print_errors(5);
        return;
    }

    get_el(id, HEAD);
}

void print_list(EQ *HEAD) {
    show_list(HEAD);
}