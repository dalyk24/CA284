/*
Program: lab1-hello_again-further.c
Author: Killian Daly
Input: A full name
Output: Print out the given name
*/

/* includes */
#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main(int argc, char * argv[])
{
    char name[40];

    printf("Please input name:\n");
    scanf("%s", name);
    printf("\tHello\n\t%s\n", name);

    return(0);
}