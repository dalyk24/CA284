/*
 Program: lab1-circle-area-further.c
 Author: Killian Daly
 Input: Radius of a circle
 Output: Print out the area of the circle
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need */

#define PI 3.14 /* Defining PI as a constant */

/* function properties */
void findRadius(int radius);

/* 
 Function: Main
 Parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
 Description: Takes a single argument and outputs area of circle
*/
int main(int argc, char *argv[])
{
    /* variable initialisation */
    int radius = 0;

    /* all command-line arguments come in as character strings, so atoi turns them into ints */
    radius = atoi(argv[1]);
    printf("4");
    findRadius(radius);

    return 0; /* exit correctly */
}

/* 
 Function: findRadius
 Parameters: int radius
 description: Takes an integer radius and returns area of circle
*/
void findRadius(int radius)
{
    int radiusSquared = radius*radius; /* radius squared */
	float area = radiusSquared*PI; /* calculate area of circle */

    /* print to two decimal places */
    printf("%.2f\n",area);

    /* check if input is valid aread of circle and ask for new input if not */
    if(radius < 0){
        printf("You input a negative radius, which may produce inaccurate results\nPlease enter a new radius: ");
        scanf("%d", &radius);
        findRadius(radius);
    }

}
