/*
 Author: Killian Daly
 Date: 20/10/23
 Accepts the detail of a list of countries from the command line and prints them
*/

/* Includes standard C libraries for input/output, dynamic memory allocation, and string manipulation. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct declaration for Country to simplify future declarations. */
typedef struct Country Country;

/* Define a struct for storing information about countries. */
struct Country {
    char name[40];
    char capital[40];
    float population;
    int size;
};

/* Function declaration for inputC. */
void inputC(int length, int numC, char *argv[], Country *countries);

/* Function declaration for printC. */
void printC(int length, int numC, Country *countries);

/* The main function, the entry point of the program. */
int main(int argc, char *argv[]) {
    /* Create an array to store country data. */
    Country countries[50];

    /* Calculate the number of countries based on command-line arguments. */
    int numC = (argc - 1) / 4;

    /* Call inputC to populate the 'countries' array. */
    inputC(argc - 1, numC, argv, countries);

    /* Initialize an unused count variable. */

    /* Call printC to display country information. */
    printC(argc - 1, numC, countries);

    /* Exit the program. */
    return 0;
}

/* Function to populate the 'countries' array with data from command-line arguments. */
void inputC(int length, int numC, char *argv[], Country *countries) {
    /* Initialize a count variable. */
    int count = 0;

    /* Iterate through command-line arguments to fill the 'countries' array. */
    for (int i = 0; count < numC; i += 4) {
        /* Copy the country name from the command-line argument. */
        strcpy(countries[count].name, argv[i + 1]);

        /* Copy the capital from the command-line argument. */
        strcpy(countries[count].capital, argv[i + 2]);

        /* Convert and store the population from the command-line argument. */
        countries[count].population = atof(argv[i + 3]);

        /* Convert and store the size from the command-line argument. */
        countries[count].size = atoi(argv[i + 4]);

        /* Increment the count for the next country. */
        count++;
    }
}

/* Function to display country information. */
void printC(int length, int numC, Country *countries) {
    /* Display a header for the information table. */
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    /* Iterate through the 'countries' array to display each country's information. */
    for (int i = 0; i < numC; i++) {
        /* Print the name, capital, size, and population of the current country. */
        printf("%s\t\t\t", countries[i].name);
        printf("%s\t\t\t", countries[i].capital);
        printf("%d\t\t\t", countries[i].size);
        printf("%.2f\n", countries[i].population);
    }
}
