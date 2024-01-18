#include <stdio.h>

struct data {
    char one;
    char two;
};

int main() {
    struct data new;
    new.one = 100;
    new.two = 100;

    union european_union {
        struct data int8;
        short int16;
    };

    union european_union onion;
    onion.int8 = new;
    onion.int16 = 420;

    printf("%x\n", onion.int8.one);
    printf("%x\n", onion.int8.two);
    printf("%x\n", onion.int16);
}