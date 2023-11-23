/*
 Author: Killian Daly
 Date: 29/23
 Search for an integer in an array of integers
*/

#include <stdio.h>
#include <stdlib.h>

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
    int key = atoi(argv[1]);
    int nums[argc-2];

    /* put nums into array */
    for(int i = 2; i < argc; i++)
    {
        nums[i-2] = atoi(argv[i]);
    }

    for(int i = 0; i < argc-2; i++)
    {
        if(nums[i] == key)
        {
            /* if value is found, print its index and end function */
            printf("Found %d at %d\n", key, i);
            return 0;
        }
    }
    
    printf("Value not found\n");

    return 0;
}
