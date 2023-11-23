/*
 Author: Killian Daly
 Date: 29/9/23
 Find all leap years between two command line integers, and output them
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function properties to calculate leap year */
int leapYears(int year1, int year2);

int main(int argc, char *argv[]) {
    // pass command line years to function to calculate and output leap years
    leapYears(atoi(argv[1]), atoi(argv[2]));

    return 0;
}

int leapYears(int year1, int year2)
{
    // iterate through all years between inputs
    for (int i = year1; i <= year2; i++) 
    {
        // check by division if ends in zeroes and is end of century, then it must be divisble by 400
        if(i / 10 == i / 10.0 && i / 100 == i / 100.0)
        {
            if(i % 400 == 0)
            {
                printf("%d\n", i);
            }
        }
        // check if year is divisble by 4 and therefore leap year
        else if(i % 4 == 0)
        {
            printf("%d\n", i);
        }
    }

}
