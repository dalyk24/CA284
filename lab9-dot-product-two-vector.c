/*
    Name: Killian Daly
    Date: 10/11/23
    Description: Program accepts 2 vectors from the command line and finds the dot product.
    Approach: Allocate memory for two vectors and build them, calc dot product and free memory
*/

#include <stdlib.h>
#include <stdio.h>

// Function to build vectors from command line arguments
void buildVectors(int *pVector1, int *pVector2, int vectorSize, char *argv[]);

// Function to calculate the dot product of two vectors
void calcProduct(int *pVector1, int *pVector2, int vectorSize, int *pResult);

int main(int argc, char *argv[]){
    // Get vector size from command line argument
    int vectorSize = atoi(argv[1]);

    // Pointers to vectors and result
    int *pVector1 = NULL;
    int *pVector2 = NULL;
    int *pResult = NULL;

    // Allocate memory for vectors and result
    pVector1 = (int*)calloc(vectorSize, sizeof(int));
    pVector2 = (int*)calloc(vectorSize, sizeof(int));
    pResult = (int*)malloc(sizeof(int));

    if(!pVector1 || !pVector2 || !pResult){
        // Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        return 0;
    }

    // Build vectors from command line arguments
    buildVectors(pVector1, pVector2, vectorSize, argv);

    // Calculate the dot product and store the result
    calcProduct(pVector1, pVector2, vectorSize, pResult);

    // Print the result
    printf("%d\n", *pResult);

    // Free allocated memory
    free(pVector1);
    free(pVector2);
    free(pResult);

    // Set pointers to NULL to avoid dangling pointers
    pVector1 = NULL;
    pVector2 = NULL;
    pResult = NULL;

    return 0;
}

// Function to build vectors from command line arguments
void buildVectors(int *pVector1, int *pVector2, int vectorSize, char *argv[]){
    for(int i = 0; i < vectorSize; i++){
        // Convert command line arguments to integers and assign to vectors
        *(pVector1 + i) = atoi(argv[i+2]);
        *(pVector2 + i) = atoi(argv[i+2+vectorSize]);
    }
}

// Function to calculate the dot product of two vectors
void calcProduct(int *pVector1, int *pVector2, int vectorSize, int *pResult){
    for(int i = 0; i < vectorSize; i++){
        // Calculate dot product
        *pResult += *(pVector1 + i) * *(pVector2 + i);
    }
}
