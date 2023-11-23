/*
 Author: Killian Daly
 Date: 28/9/23
 The program takes 2 numbers and a mathematical operation then calculates the result
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function properties */
int checkInput(char operator[]);
float calculate(int operation, float num1, float num2);

/* main function */
int main(int argc, char *argv[])
{
    /* variable initialisation */
   char *operator = argv[1];
   float num1 = atof(argv[2]);
   float num2 = atof(argv[3]);

   int operation = checkInput(operator);

   /* check for attempts to divide by 0 */
   if(num2 == 0 && operation == 1)
   {
      printf("invalid\n");
      return 0;
   }

   float result = calculate(operation, num1, num2);

   printf("%f\n", result);

   return 0;
}


int checkInput(char operator[])
{
   /* return 0 if user wants to multiply and 1 for divide */
   if(strcmp(operator, "multiply") == 0)
   {
   return 0;
   }

   return 1;
}

float calculate(int operation, float num1, float num2)
{
    if(operation == 0)
    {
      return num1 * num2;
    }

    return num1 / num2;
}
