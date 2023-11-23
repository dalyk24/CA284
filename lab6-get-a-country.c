/*
 Author: Killian Daly
 Date: 20/10/23
 Gets the detail of a country from the command line and prints it
*/

#include <stdio.h>
#include <stdlib.h>

/* Function declaration for printC. */
void printC(char *name, char *capital, float *pop, int *size);

/* Define a struct declaration for Country to simplify future declarations. */
typedef struct Country Country;

/* Define a struct for storing information about countries. */
struct Country {
    char name[40];
    char capital[40];
    float population;
    int size;
};

/* The main function, the entry point of the program. */
int main(int argc, char *argv[]) {
    /* Extract command-line arguments for country name, capital, population, and size. */
    char *country = argv[1];
    char *city = argv[2];
    float pop = atof(argv[3]);
    int size = atoi(argv[4]);

    /* Create a 'Country' struct named 'ire' and initialize its fields with extracted data. */
    Country ire = { *country, *city, pop, size };

    /* Call the 'printC' function to display the country information. */
    printC(country, city, &pop, &size);

    /* Exit the program. */
    return 0;
}

/* Function to print country information using provided data. */
void printC(char *name, char *capital, float *pop, int *size) {
    /* Display the country name and capital. */
    printf("%s\n", name);
    printf("%s\n", capital);

    /* Display the population and size with appropriate units. */
    printf("%.2f million people\n", *pop);
    printf("%d km2\n", *size);
}
