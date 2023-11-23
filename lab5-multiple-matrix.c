/*
 Author: Killian Daly
 Date: 13/10/23
 Print the resulting matrix of the product of the two given matrix
*/

// libraries
#include <stdio.h>
#include <stdlib.h>

// main function
int main(int argc, char *argv[]) {
    int row1 = atoi(argv[1]);
    int col1 = atoi(argv[2]);
    int matrix1[row1][col1];
    int argvPos = 3;
    int total_m = 0;

    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            matrix1[i][j] = atoi(argv[argvPos]);
            argvPos++;
        }
    }

    int row2 = atoi(argv[argvPos]);
    int col2 = atoi(argv[argvPos+1]);
    int matrix2[row2][col2];

    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            matrix2[i][j] = atoi(argv[argvPos+2]);
            argvPos++;
        }
    }

    int resultMatrix[row1][col2];

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the resulting matrix
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d", resultMatrix[i][j]);
            if (j < col2 - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
