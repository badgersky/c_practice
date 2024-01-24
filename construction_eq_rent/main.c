#include "interface.h"
#include "error.h"

int main() {
    EQ *HEAD = make_list();
    unsigned max_id = get_max_id(HEAD);
    char choice;
    show_help();

    do {
        printf("\nEnter command character:\n");

        scanf(" %c", &choice);
        getchar();

        switch (choice) {
            case 'h':
                show_help();
                break;
            case 'a':
                add_element(&max_id, &HEAD);
                break;
            case 'd':
                delete_element(&HEAD);
                break;
            case 'f':
                delete_list(&HEAD);
                break;
            case 's':
                save_to_bin(&HEAD);
                break;
            case 'l':
                load_from_bin(&HEAD);
                max_id = get_max_id(HEAD);
                break;
            case 'g':
                get_element(HEAD);
                break;
            case 'p':
                print_list(HEAD);
                break;
            case 'q':
                printf("Exiting program. Goodbye!\n");
                free_list(&HEAD); // Make sure to free memory before quitting
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 'q');

    return 0;
}