/*
 Author: Killian Daly
 Date: 29/9/23
 Find the longest word in array and output it
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // variables will hold the current word in the sentence, longest word and current position in current word
    char *words = argv[1];
    char maxWord[50];
    char tempWord[50];
    int p;
    char temp[2];

    for (int i = 0; words[i] != '\0'; i++) 
    {
        // if current character is a space then current word has ended
        if (words[i] == ' ') 
        {
            // check if current word is longer than max word and make it max word if so
            if (strlen(tempWord) > strlen(maxWord)) {
                strcpy(maxWord, tempWord);
            }

            // reset position for new curren word
            p = 0;
            // Reset tempWord to an empty string by null-terminating it
            tempWord[0] = '\0';
        } 
        else 
        {
            // if current char is a letter then add it to current word
            temp[0] = words[i];
            strcat(tempWord, temp);
            p++;
        }
    }

    // check if last word is longest
    if (strlen(tempWord) > strlen(maxWord)) 
    {
        strcpy(maxWord, tempWord);
    }

    printf("%s\n", maxWord);

    return 0;
}
