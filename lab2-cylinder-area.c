/*
 Program: lab2-cylinder-area.c
 Author: Killian Daly
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>

/* function properties */
int inpCheck(int argc, char *argv[]);
void findArea(float radius, float height);

/* 
 Function: main
 Parameters: int argc, char *argv[]
 Returns: int
 Description: takes radius and height of circle and outputs area
*/
int main(int argc, char *argv[])
{
    /* variable initialisation */
    float radius = 0;

    if (inpCheck(argc, argv) == 1){
        exit(0);
    }

    findArea(atof(argv[1]), atof(argv[2]));

    return 0;
}

/* 
 Function: inpCheck
 Parameters: int radius, int height
 Returns: int set to 1 if test failed and 0 otherwise
 Description: checks if inputs are valid and returns result of test
*/
int inpCheck(int argc, char *argv[])
{
    int checker = 1;

    if (argc <= 1){
        printf("No input given!");
    }
    else if (argc == 2){
        printf("Two arguments needed!");
    }
    else if (atof(argv[1]) < 0 || atof(argv[2]) < 0){
        printf("The radious or height cannot be negative!");
    }
    else {
        checker = 0;
    }

        return checker;

}

/* 
 Function: findArea
 Parameters: int radius, int height
 Returns: N/A
 Description: take radius and height and uses formula to print area
*/
void findArea(float radius, float height)
{
    float PI = 3.14151;
    float area = 2 * radius * height * PI + 2 * PI * (radius * radius);

    printf("%.2f\n", area);
    
}
