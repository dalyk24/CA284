/*
 Program: lab2-print-day.c
 Author: Killian Daly
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function properties */
int checkInp(int inp);

/* 
 Function: main
 Parameters: int argc, char *argv[]
 Returns: int
 Description: print corresponding day of the week to input number
*/
int main(int argc, char *argv[])
{
    char days[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int inp = atoi(argv[1]);

    if (checkInp(inp) == 1) {
        exit(1);
    }
    else {
        char day[10];
        strcpy(day, days[inp-1]);
        printf("%s\n", day);
    }

    return 0;
}

/* 
 Function: checkInp
 Parameters: int inp
 Returns: int check
 Description: checks if the input integer is a valid day of the week
*/
int checkInp(int inp)
{
    if (inp > 7 || inp < 1) {
        return 1;
    }

    return 0;

}
