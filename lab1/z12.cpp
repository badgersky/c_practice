#include <stdio.h>
#include <time.h>
#include <math.h>

#pragma warning (disable: 4996)


int main()
{
    // defining current year
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);  // tm_info pointing to tm struct
    int curr_year = tm_info->tm_year + 1900;  // getting tm_year field using pointer

    // getting users input
    int birth_year;
    printf("Enter your birth year\n");
    int ret = scanf("%d", &birth_year);
    if (birth_year < 0) {
        printf("%d", birth_year);
        printf("Incorect birthdate");
        return 0;
        exit(1);
    }

    printf("Your age is: %d", curr_year - birth_year);
}
