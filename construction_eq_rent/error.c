#include <stdio.h>
#include "error.h"

void print_errors(int i) {
    char *errors[] = {
            "File error",
            "Memory error",
            "Other error",
    };

    printf("%s\n", errors[i]);
}
