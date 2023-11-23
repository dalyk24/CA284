/*
 Author: Killian Daly
 Date: 5/10/23
 Description: Accepts a string as an input. The program checks if the input 
 string is symmetric and print yes, otherwise print no
*/

/* these include needed functions such as to print and find string length */
#include <stdio.h>
#include <string.h>

/* 
 function declarations: 
 symmetry checks if word is symmetric and outputs yes or no respectively 
*/
void symmetry(char *word);

/* main function */
int main(int argc, char *argv[]){
    /* store word so it's easier to index through */
    char *word = argv[1];

    /* function takes word, checks symmetry and outputs yes/no respectively */
    symmetry(word);
}

void symmetry(char *word){
    /* store word length and check for if any non-symmetric char is found */
    int length = strlen(word);
    int check = 0;

    /* loop through first half of word, checking if first char matches last 
        char etc. We ignore second half and middle char, since they're already 
        checked or have no match */
    for(int i = 0; i < length / 2; i++){
        /* non-symmetric char found so check set to 1, indicating non-symmetry */
        if(word[i] != word[length-1-i]){
            check = 1;
        }
    }

    /* print no to indicate non-symmetry if check is not 0 and yes otherwise */
    if(check != 0){
        printf("no\n");
    }
    else{
        printf("yes\n");
    }
}