/*
 Author: Killian Daly
 Date: 29/9/23
 Search for duplicate values in an integer array and output findings
*/

#include <stdio.h>
#include <stdlib.h>

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
    int key;
    int nums[argc-1];

    /* put nums into array */
    for(int i = 1; i < argc; i++)
    {
        nums[i-1] = atoi(argv[i]);
    }

    for(int i = 0; i < argc-1; i++)
    {
        /* get number to search for duplicates */
        key = nums[i];
        for(int j = 0; j < argc-1; j++)
        {
            if(nums[j] == key && i != j)
            {
            /* if value is found, print it and end function */
            printf("%d\n", key);
            return 0;
            }
        }
    }
    
    printf("no duplicated number\n");

    return 0;
}
