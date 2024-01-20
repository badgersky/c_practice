#include "interface.h"
#include "error.h"

int main() {
    EQ *HEAD = make_list();
    unsigned max_id = get_max_id(HEAD);
    char input;
    int ret;

    while (1) {
        printf("To see available commands type h:\n");
        printf("Enter command character:\n");
        ret = scanf("%c", &input);
        if (ret != 1) {
            print_errors(5);
            continue;
        }

        switch (input) {
            case 'h':
                show_help();
            case 'q':
                break;
            case 'a':
                max_id = add_element(max_id, HEAD);
            case 'd':
                delete_element(&HEAD);
            case 'f':
                delete_list(&HEAD);
                free_list(&HEAD);
                max_id = 0;
            case 's':
                save_to_bin(&HEAD);
                free_list(&HEAD);
                max_id = 0;
            case 'l':
                load_from_bin(&HEAD);
                max_id = get_max_id(HEAD);
            case 'g':
                get_element(HEAD);
            case 'p':
                print_list(HEAD);
            default:
                printf("Unknown command\n");
                continue;
        }
    }
}