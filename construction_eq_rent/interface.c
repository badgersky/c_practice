#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = 0;
    }
}

void add_element(unsigned *max_id, EQ **HEAD) {
    char brand[MAX_LINE], name[MAX_LINE];
    double price;
    int ret;

    printf("Enter equipment brand\n");
    if (!fgets(brand, MAX_LINE, stdin)) {
        print_errors(5);
        exit(1);
    }
    remove_newline(brand);

    printf("Enter equipment name:\n");
    if (!fgets(name, MAX_LINE, stdin)) {
        print_errors(5);
        exit(1);
    }
    remove_newline(name);

    printf("Enter equipment price:\n");
    ret = scanf("%lf", &price);
    if (ret != 1) {
        print_errors(5);
        exit(1);
    }

    printf("item added\n");
    *max_id = append_element(*max_id, *HEAD, name, brand, price);
}

void delete_element(EQ **HEAD) {
    int id, ret;
    printf("Enter id of element you want to delete:\n");
    ret = scanf("%d", &id);
    if (ret != 1) {
        print_errors(5);
        exit(1);
    }

    del_el(id, &*HEAD);
}

void delete_list(EQ **HEAD) {
    char answer = 0;
    printf("Are you sure you want to delete list: [y/n]\n");
    scanf("%c", &answer);

    if (answer == 'y') {
        free_list(&*HEAD);
        printf("List deleted\n");
    } else {
        printf("List not deleted\n");
    }

}

void save_to_bin(EQ **HEAD) {
    save_list(*HEAD);
    printf("List saved to file out.dat\n");
}

void load_from_bin(EQ **HEAD) {
    read_list(&*HEAD);
    printf("list loaded from file out.dat\n");
}

void get_element(EQ *HEAD) {
    int id, ret;
    printf("Enter id of element you want to see:\n");
    ret = scanf("%d", &id);
    if (ret != 1) {
        print_errors(5);
        exit(1);
    }

    get_el(id, HEAD);
}

void print_list(EQ *HEAD) {
    show_list(HEAD);
}