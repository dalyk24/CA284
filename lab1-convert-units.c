/*
 Program: lab1-convert-units.c
 Author: Killian Daly
 Input: Amount of centimetres from commamd line
 Output: Input centimetres converted to inches
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need */

/* 
 Function: Main
 Parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
 Description: Takes a centimeter argument and outputs conversion to inches
*/
int main(int argc, char *argv[])
{
    /* variable initialisation */
    float cent = atof(argv[1]);
    float inches = 0.0;

    /* convert to inches */
    inches = cent / 2.54;

    /* print to two decimal places */
    printf("%.2f\n", inches);

    return 0; /* exit correctly */
}
