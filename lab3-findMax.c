/*
 Author: Killian Daly
 Date: 28/9/23
 Ouput the max in an array of integers
*/

#include <stdio.h>
#include <stdlib.h>

/* function properties */
int findMax(int nums[], int length);

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
   int nums[40];

   for(int i = 1; i != argc; i++)
   {
      nums[i - 1] = atoi(argv[i]);
   }

   printf("%d\n", findMax(nums, argc - 1));

   return 0;
}

int findMax(int nums[], int length)
{
   int max = 0;

   for(int i = 0; i < length; i++)
   {
      if(nums[i] > max)
      {
         max = nums[i];
      }
   }

   return max;
}