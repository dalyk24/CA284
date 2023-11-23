/*
 Program: lab2-count-odd-number.c
 Author: Killian Daly
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>

/* function properties */
void countOdd(int *nums, int len);

/* 
 Function: main
 Parameters: int argc, char *argv[]
 Returns: int
 Description: find number of odd numbers and print count of them
*/
int main(int argc, char *argv[])
{
    int len = argc-1;
    int nums[len];

    for (int i = 0; i < len; i++) {
        nums[i] = atoi(argv[i+1]);
    }

    countOdd(nums, len);

    return 0;
}

/* 
 Function: countOdd
 Parameters: int *nums[]
 Returns: N/A
 Description: count odd numbers and return that count
*/
void countOdd(int *nums, int len)
{
    int counter = 0;

    for (int i = 0; i < len; i++){
        if (nums[i] % 2 != 0){
            counter += 1;
        }
    }

    printf("%d\n", counter);

}
