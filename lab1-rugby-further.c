/*
 Program: lab1-rugby-further.c
 Author: Killian Daly
 Input: Four inputs (try, conversion, penalty, drop-goal) from command line
 Output: The total points calculated
*/

/* Includes */
#include <stdio.h>

/* function properties */
int checkNum(int curr);
void sumScore(int try, int conv, int pen, int drop);

/* 
 Function: Main
 Parameters: int argc, char *argv[]
 Description: Takes four command line representing rugby goals and calculates the score
*/
int main(int argc, char *argv[])
{
    /* intialise variables */
    int total = 0;
    int curr = 0;
    int scorings[4];
    
    printf("Please input amount of tries, conversions, penalties and drop goals, one per line:\n");

    /* prompt user for input until they have given 4 positive numbers */
    for(int i = 0; i < 4; i++){
        scanf("%d", &curr);

        if(checkNum(curr) == 0){
            printf("Please input valid number:\n");
            i--;
        }
        else{
            scorings[i] = curr;
        }
    }

    /* pass to method to find total score */
    sumScore(scorings[0], scorings[1], scorings[2], scorings[3]);

    return 0;
}

/* 
 Function: checkNum
 Parameters: int curr
 Description: Checks if number is negative
 Returns: 0 if number is negative and 1 if positive
*/
int checkNum(int curr)
{
    if(curr < 0){
        return 0;
    }

    return 1;
}

/* 
 Function: sumScore
 Parameters: int try, int conv, int pen, int drop
 Description: Convert type of goals to their point value then find total and print
 Returns: Total score
*/
void sumScore(int try, int conv, int pen, int drop)
{
    int total = 0;

    total = try * 5 + conv * 2 + pen * 3 + drop * 3;

    printf("%d\n", total);
}
