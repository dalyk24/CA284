/*
 Author: Killian Daly
 Date: 28/9/23
 This program takes a string and outputs its reverse
*/

#include <stdio.h>
#include <string.h>

/* function properties */
void reverse(char inpString[]);

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
   char *inpString = argv[1];

   reverse(inpString);

   return 0;
}


void reverse(char inpString[])
{
   /* variable initialisation */
   int length = strlen(inpString) - 1;
   
   /* print out string starting backwards from last char */
   for(int i = length; i >= 0; i--)
   {
      printf("%c", inpString[i]);
   }

   printf("\n");

}

