/*
    Name: Killian Daly
    Date: 10/11/23
    Description: Find the second largest value in the array and print up to 1 decimal point.
    Approach: Find largest number in first loop through array, then search for second largest
    by repeating the opration with addition requirement that num must not be same as largest.
*/

#include <stdlib.h>
#include <stdio.h>

// Function to build the array from command line arguments
void buildArray(float *nums, int length, char *argv[]);

// Function to find the second largest value in the array
void secondLargest(float *nums, int length, float *result);

int main(int argc, char *argv[]){
    int length = argc - 1;

    float *nums = NULL;
    float *result = NULL;

    // Allocate memory for the array and result
    nums = (float*)calloc(length, sizeof(float));
    result = (float*)malloc(sizeof(float));

    if(!nums || !result){
        // Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        return 0;
    }

    buildArray(nums, length, argv);

    secondLargest(nums, length, result);

    // Print the result up to 1 decimal point
    printf("%.1f\n", *result);

    // Free allocated memory
    free(nums);
    free(result);
    nums = NULL;
    result = NULL;

    return 0;
}

// Function to build the array from command line arguments
void buildArray(float *nums, int length, char *argv[]){
    for(int i = 0; i < length; i++){
        *(nums + i) = atof(argv[i + 1]);  // Convert command line arguments to floating-point numbers.
    }
}

// Function to find the second largest value in the array
void secondLargest(float *nums, int length, float *result){
    float largest = 0;

    // Find the largest value in the array
    for(int i = 0; i < length; i++){
        if(*(nums + i) > largest){
            largest = *(nums + i);
        }
    }

    // Find the second largest value in the array
    for(int i = 0; i < length; i++){
        if(*(nums + i) > *result && *(nums + i) != largest){
            *result = *(nums + i);
        }
    }
}
