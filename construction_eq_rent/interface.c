#include <stdio.h>
#include "list.h"
#include "error.h"

void show_help() {
    printf("Here are available commands:\n");
    printf("help/h - show available commands\n");
    printf("add/a - adds element at the end of a list\n");
    printf("del/d - deletes element with given id\n");
    printf("free/f - deletes list\n");
    printf("save/s - saves list to binary file\n");
    printf("load/l - loads list from binary file\n");
    printf("get/g - gets element with given id\n");
    printf("print/p - prints whole list to monitor\n");
    printf("quit/q - quits program\n");
}

void add_element(int max_id, EQ **HEAD) {
    char brand[MAX_LINE], name[MAX_LINE];
    double price;
    int ret;

    printf("Enter equipment brand:\n");
    fgets(brand, MAX_LINE, stdin);
    printf("Enter equipment name:\n");
    fgets(name, MAX_LINE, stdin);
    printf("Enter equipment price:\n");
    ret = scanf("%lf", &price);
    if (ret != 1) {
        print_errors(5);
        return;
    }

    append_element(max_id, *HEAD, name, brand, price);
    printf("item added\n");
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
