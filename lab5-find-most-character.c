/*
 Author: Killian Daly
 Date: 12/10/23
 Find most frequent char in given string
*/

/* functions */
#include <stdio.h>
#include <string.h>

void countChar(char *word);

/* main function */
int main(int argc, char *argv[]) {
    char *word = argv[1];

    countChar(word);

    return 0;
}

void countChar(char *word){
    char key;
    char *maxChar = NULL;
    int count = 0;
    int maxCount = count;

    while (*word != '\0') {
        key = *word;
        count = 0;
        char *ptr = word;

        while (ptr = strchr(ptr, key)) {
            count++;
            ptr++;
        }
        if (count > maxCount && *word != ' ') {
            maxCount = count;
            maxChar = word;
        }
        word++;
    }

    printf("%c\n", *maxChar);
}
