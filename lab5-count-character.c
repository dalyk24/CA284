/*
 Author: Killian Daly
 Date: 12/10/23
 Count occurences of given char in given string
*/

#include <stdio.h>
#include <string.h>

/* main function */
int main(int argc, char *argv[]){
    /* store key and word in pointers, and create counter for chars */
    char *key = &argv[1][0];
    char *word = argv[2];
    char *curr;
    int count = 0;

    /* iterate over word counting occurences of key char */
    for(int i = 0; word[i] != '\0'; i++){
        /* store pointer to current char */
        curr = &word[i];
        /* access current char value, key value and check if they match */
        if(*key == *curr){
            count += 1;
        }
    }
    
    printf("%d\n", count);

    return 0;
}
