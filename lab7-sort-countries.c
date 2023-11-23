/*
    Author: Killian Daly
    Date: 26/10/23
    Description: Sort the list of countries based on their population in descending order and print the result
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a country
typedef struct Country {
    char name[40];
    char capital[40];
    int size;
    float population;
} Country; // Typedef declaration for struct Country

// Function to populate a Country structure from command-line arguments
void buildStructs(Country *c, char *argv[], int p);

// Function to sort the array of countries by population in descending order
void sortC(Country *countries, int numC);

// Function to print information about the sorted countries
void printC(Country *countries, int numC);

int main(int argc, char *argv[]){
    // Calculate the number of countries based on the number of command-line arguments
    int numC = (argc - 1) / 4;
    
    // Create an array of Country structures to store the country data
    Country countries[numC];
    
    int count = 0;

    // Populate the Country structures from command-line arguments
    for(int i = 1; i < argc; i = i + 4){
        buildStructs(&countries[count], argv, i);
        count = count + 1;
    }

    // Sort the array of countries by population in descending order
    sortC(countries, numC);

    // Print information about the sorted countries
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

// Function to sort the array of countries by population in descending order
void sortC(Country *countries, int numC){
    for(int i = 0; i < numC; i++){
        for(int j = 0; j < numC; j++){
            if(countries[i].population > countries[j].population){
                Country temp = countries[i];
                countries[i] = countries[j];
                countries[j] = temp;
            }
        }
    }
}

// Function to print information about the sorted countries
void printC(Country *countries, int numC){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for(int i = 0; i < numC; i++){
        printf("%s\t\t\t", countries[i].name);
        printf("%s\t\t\t", countries[i].capital);
        printf("%d\t\t\t", countries[i].size);
        printf("%.2f\n", countries[i].population);
    }
}
