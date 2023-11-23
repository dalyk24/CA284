/*
 Author: Killian Daly
 Date: 13/10/23
 Checks if the first string contains the second string
*/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main function
int main(int argc, char *argv[]) {
    char *word = argv[1];
    char *key = argv[2];
    int count = 0;

    for(int i = 0; word[i] != '\0'; i++){
        // Check if the current character in 'word' matches the first character in 'key'
        if(word[i] == key[count]){
            // If a match is found, enter a nested loop to check subsequent characters
            for(int j = i; word[j] != '\0' && word[j] == key[count]; j++){
                count++;
            }
            // Check if the count matches the length of 'key', meaning a complete match is found
            if(count == strlen(key)){
                printf("%d %d\n", i, i+count-1);
                return 0;
            }
        }
    }

    return 0;
}
