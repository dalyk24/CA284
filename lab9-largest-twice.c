/*
    Name: Killian Daly
    Date: 10/11/23
    Description: Find the largest number at least twice one number in the array and print it; otherwise, print 0
    Approach: Iterate to find any num that's are twice another, store that as max and search for greater num
*/

#include <stdlib.h>
#include <stdio.h>

// Function to build array from command line arguments
void buildArray(int *pNums, int length, char *argv[]);

// Function to find the largest number at least twice one number
void findLargest(int *pNums, int *result, int length);

int main(int argc, char *argv[]){
    int length = argc - 1;
    int *pNums = NULL;
    int *pResult = 0;

    // Allocate memory for nums and result
    pNums = (int*)calloc(length, sizeof(int));
    pResult = (int*)malloc(sizeof(int));

    if (!pNums || !pResult){
        // Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        return 0;
    }

    buildArray(pNums, length, argv);

    findLargest(pNums, pResult, length);

    printf("%d\n", *pResult);

    // Free allocated memory
    free(pNums);
    free(pResult);

    // Set pointers to NULL to avoid dangling pointers
    pNums = NULL;
    pResult = NULL;

    return 0;
}

// Function to build array from command line arguments
void buildArray(int *pNums, int length, char *argv[]){
    for (int i = 0; i < length; i++){
        // Convert command line arguments to integers and assign to array
        *(pNums + i) = atoi(argv[i + 1]);
    }
}

// Function to find the largest number at least twice one number
void findLargest(int *pNums, int *result, int length){
    int *temp = NULL;
    int *max = NULL;
    int maxCheck = 0;

    temp = (int*)malloc(sizeof(int));
    max = (int*)malloc(sizeof(int));

    if (!temp || !max){
        // Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }

    max = pNums;

    for (int i = 0; i < length; i++){
        temp = pNums + i;
        for (int j = 0; j < length; j++){
            if (*temp > *(pNums + j) * 2 && *temp > *max){
                max = temp;
                // we now know that max has been found
                maxCheck = 1;
                break;
            }
        }
    }

    if(maxCheck == 1){
        *result = *max;
    }

    // we don't free max  or temp since they already point to nums in memory
}
