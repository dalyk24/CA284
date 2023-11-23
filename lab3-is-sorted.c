/*
 Author: Killian Daly
 Date: 29/9/23
 Sort an array in ascending order then print it
*/

#include <stdio.h>
#include <stdlib.h>

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
    int length = argc-1;
    int nums[length];
    int temp;

    /* put nums into array */
    for(int i = 1; i < argc; i++)
    {
        nums[i-1] = atoi(argv[i]);
    }

    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            if(nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    /* print sorted array */
    for(int i = 0; i < length; i++)
    {
        printf("%d\n", nums[i]);
    }

    return 0;
}
