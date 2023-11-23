/*
    Name: Killian Daly
    Date: 10/11/23
    Description: Accepts a number of strings. The program finds and prints the longest string(s) line by line
    Approach: Iterate over strings to find longest, then iterate to find strings matching this length and print those
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to find the length of the longest string
void findMax(int *longest, int length, char *argv[]);

// Function to find and store the longest string(s)
int findLongs(int *longest, int length, char (*words)[*longest + 1], char *argv[]);

// Function to print the longest string(s)
void printLongs(int *longest, char (*words)[*longest + 1], int counter);

int main(int argc, char *argv[]){
    int length = argc - 1;
    int *longest = NULL;
    int counter;

    // Allocate memory to store the length of the longest string
    longest = (int*)malloc(sizeof(int));

    if (!longest){
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        return 0;
    }

    // Find the length of the longest string
    findMax(longest, length, argv);

    // Allocate memory for an array of strings to store the longest string(s)
    char (*words)[*longest + 1] = (char(*)[*longest + 1])calloc(length, sizeof(char[*longest + 1]));

    if (!words){
        printf("Failed to allocate memory!");
        return 0;
    }

    // Find and store the longest string(s), get the count of such strings
    counter = findLongs(longest, length, words, argv);

    // Print the longest string(s)
    printLongs(longest, words, counter);

    // Free allocated memory
    free(longest);
    free(words);

    return 0;
}

// Function to find the length of the longest string
void findMax(int *longest, int length, char *argv[]){
    *longest = strlen(argv[1]);

    for(int i = 0; i < length; i++){
        if(strlen(argv[i+1]) > *longest){
            *longest = strlen(argv[i+1]);
        }
    }
}

// Function to find and store the longest string(s)
int findLongs(int *longest, int length, char (*words)[*longest + 1], char *argv[]){
    int counter = 0;

    for(int i = 0; i < length; i++){
        if(strlen(argv[i+1]) == *longest){
            // Copy the longest string to the 'words' array
            strcpy(words[counter], argv[i+1]);
            counter += 1;
        }
    }

    return counter;
}

// Function to print the longest string(s)
void printLongs(int *longest, char (*words)[*longest + 1], int counter){
    for(int i = 0; i < counter; i++){
        // Print each longest string
        printf("%s\n", words[i]);
    }
}
