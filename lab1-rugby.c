/*
 Program: lab1-rugby.c
 Author: Killian Daly
 Input: Four inputs (try, conversion, penalty, drop-goal) from command line
 Output: The total points calculated
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
/* 
 Function: Main
 Parameters: int argc, char *argv[]
 Description: Takes four command line representing rugby goals and calculates the score
*/
int main(int argc, char *argv[])
{
    /* convert arguments into respective type of goal */
    int try = atoi(argv[1]) * 5;
    int conv = atoi(argv[2]) * 2;
    int pen = atoi(argv[3]) * 3;
    int drop = atoi(argv[4]) * 3;

    /* sum goals into total score */
    int total = try + conv + pen + drop;
    
    printf("%d\n", total);

    return 0;
}