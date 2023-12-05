#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

const char *morse_codes[] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        "-----",
        ".----",
        "..---",
        "...--",
        "....-",
        ".....",
        "-....",
        "--...",
        "---..",
        "----.",
        ".-.-.-",
        "--..--",
        "..--..",
        "---...",
        "-....-",
        "-.-.--",
};

const char ascii_chars[] = {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'J',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z',
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        '.',
        ',',
        '?',
        ':',
        '-',
        '!',
};

void translate_to_morse(char *str);

int main() {
    char *str = NULL, input[MAX_LINE];
    printf("Enter text you want to translate to morse code:\n");
    fgets(input, MAX_LINE, stdin);
    str = (char *)malloc((strlen(input)) * sizeof(char));
    if (!str) {
        printf("Memory error");
        exit(1);
    }
    strcpy(str, input);
    translate_to_morse(str);

    free(str);
    str = NULL;
}

void translate_to_morse(char *str) {
    while (*str != 0) {
        if (*str == 32) {
            printf("\t");
        } else {
            for (int i = 0; i <= 67; i++) {
                if (*str == ascii_chars[i]) {
                    printf("%s ", morse_codes[i]);
                }
            }
        }
        str++;
    }
}
