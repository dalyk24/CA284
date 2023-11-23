/*
 Program: lab2-find-even-number.c
 Author: Killian Daly
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>

/* function properties */
void findEven(int *nums, int len);

/* 
 Function: main
 Parameters: int argc, char *argv[]
 Returns: int
 Description: find all even numbers and print them along with their index
*/
int main(int argc, char *argv[])
{
    int len = argc-1;
    int nums[10];

    for (int i = 0; i < len; i++) {
        nums[i] = atoi(argv[i+1]);
    }

    findEven(nums, len);

    return 0;
}

/* 
 Function: findEven
 Parameters: int *nums[]
 Returns: N/A
 Description: find even numbers and print their index
*/
void findEven(int *nums, int len)
{
    int check = 0;

    for (int i = 0; i < len; i++){
        if (nums[i] % 2 == 0){
            check = 1;
            printf("%d - %d\n", i, nums[i]);
        }
    }

    if (check == 0) {
        printf("Not found!\n");
    }

}
