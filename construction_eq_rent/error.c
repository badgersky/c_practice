#include <stdio.h>
#include "error.h"

void print_errors(int i) {
    char *errors[] = {
            "File error",
            "Memory error",
            "List empty",
            "No such element in the list",
            "Other error",
    };

    printf("%s\n", errors[i]);
}
