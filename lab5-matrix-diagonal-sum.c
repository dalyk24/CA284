/*
 Author: Killian Daly
 Date: 13/10/23
 Find sum of diagonal of matrix
*/

/* libraries */
#include <stdio.h>
#include <stdlib.h>

/* main function */
int main(int argc, char *argv[]) {
    int len = atoi(argv[1]);
    int nums[len][len];
    int ptrTemp = 0;
    int *total = &ptrTemp;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            nums[i][j] = atoi(argv[2 + i * len + j]);
        }
    }

    for(int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        for(int j = 0; j < sizeof(nums)/sizeof(nums[0]); j++){
            if(i == j){
                *total = *total + *(*(nums + i)+j);
            }
        }
    }

    printf("%d\n", *total);

    return 0;
}
