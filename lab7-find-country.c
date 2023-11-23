/*
    Author: Killian Daly
    Date: 26/10/23
    Description: Find all countries whose size is smaller than 100000 km2 and print the result
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country;

// Define a structure for a country
struct Country {
    char name[40];
    char capital[40];
    int size;
    float population;
};

// Function to populate a Country structure from command-line arguments
void buildStructs(Country *c, char *argv[], int p);

// Function to print information about countries with a size smaller than 100,000 km2
void printC(Country *countries, int numC);

int main(int argc, char *argv[]){
    // Calculate the number of countries based on the number of command-line arguments
    int numC = (argc-1) / 4;

    // Create an array of Country structures to store the country data
    Country countries[numC];
    int count = 0;

    // Populate the Country structures from command-line arguments
    for(int i = 1; i < argc; i = i + 4){
        buildStructs(&countries[count], argv, i);
        count = count + 1;
    }

    // Print information about countries with a size smaller than 100,000 km2
    printC(countries, numC);

    return 0;
}

// Function to populate a Country structure from command-line arguments
void buildStructs(Country *c, char *argv[], int p){
        // Copy country name and capital from command-line arguments
        strcpy(c->name, argv[p]);
        strcpy(c->capital, argv[p+1]);

        // Convert and store size and population from command-line arguments
        c->size = atoi(argv[p+3]);
        c->population = atof(argv[p+2]);

}

// Function to print information about countries with a size smaller than 100,000 km2
void printC(Country *countries, int numC){
    int maxSize = 100000;

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for(int i = 0; i < numC; i++){
        // Check if the size of the country is smaller than maxSize
        if(countries[i].size < maxSize){
            printf("%s\t\t\t", countries[i].name);
            printf("%s\t\t\t", countries[i].capital);
            printf("%d\t\t\t", countries[i].size);
            printf("%.2f\n", countries[i].population);
        }
    }
}