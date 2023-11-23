/*
 Program: lab1-convert-units-further.c
 Author: Killian Daly
 Input: N/A
 Output: The value in inches of every number starting at 30 and finishing at 49 inclusive
*/

/* Includes */
#include <stdio.h>

/* 
 Function: Main
 Parameters: int argc (argument count), char *argv[] (an array of command-line arguments)
 Description: Numbers 30 to 49 inclusive converted from centimetres to inches
*/
int main(int argc, char *argv[])
{
    /* variable initialisation */
    float cent = 2.54;

    /* output numbers 30 to 49 converted in table with rows of 5 */
    for(int i = 30; i < 50; i++){
        /* if current number is fifth in iteration then start new row */
        if((i+1) % 5 == 0){
            printf("%.2f\n", i/cent);
        }
        else{
            printf("%.2f\t", i/cent);
        }
    }

    return 0; /* exit correctly */
}