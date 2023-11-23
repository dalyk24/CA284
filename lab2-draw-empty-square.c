/*
 Program: lab2-draw-empty-square.c
 Author: Killian Daly
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>

/* function properties */
void drawSquare(int sides);

/* 
 Function: main
 Parameters: int argc, char *argv[]
 Returns: int
 Description: take int representing height and width then output empty square
*/
int main(int argc, char *argv[])
{
    if (argc <= 1){
        exit(0);
    }

    drawSquare(atoi(argv[1]));

    return 0;
}

/* 
 Function: drawSquare
 Parameters: int sides
 Returns: N/A
 Description: take lengths of sides then draw empty square with dimensions
*/
void drawSquare(int sides)
{
    for (int i = 0; i < sides; i++){
        for (int j = 0; j < sides; j++){
            if (i == 0 || i == (sides-1) || j == 0 || j == (sides-1)){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

}
