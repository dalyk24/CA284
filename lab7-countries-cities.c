/*
    Author: Killian Daly
    Date: 26/10/23
    Description: Find the largest city of all countries and display the result
*/

// include functions we need
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define strcuts so we don't need full declaration whenever a struct is created
typedef struct Country Country;
typedef struct City City;

// Struct to hold city values
struct City {
    char name[40];
    int size;
};

// Struct to hold country values like its name and some cities
struct Country {
    char name[40];
    City cities[4];
};

// Function to populate a Country structure from command-line arguments
void buildStructs(Country *c, char *argv[], int p);

// Function to find the largest city within a Country
City findMax(Country *c);

// Function to print information about the largest city of each country
void printC(Country *countries, int numC);

int main(int argc, char *argv[]){
    int numC = (argc - 1) / 7;
    Country countries[numC];
    int count = 0;

    for (int i = 1; i < argc; i = i + 7){
        buildStructs(&countries[count], argv, i);
        count = count + 1;
    }

    printC(countries, numC);

    return 0;
}

// Function to populate a Country structure from command-line arguments
void buildStructs(Country *c, char *argv[], int p){
    strcpy(c->name, argv[p]);
    strcpy(c->cities[0].name, argv[p + 1]);
    strcpy(c->cities[1].name, argv[p + 3]);
    strcpy(c->cities[2].name, argv[p + 5]);

    c->cities[0].size = atoi(argv[p + 2]);
    c->cities[1].size = atoi(argv[p + 4]);
    c->cities[2].size = atoi(argv[p + 6]);
}

// Function to find the largest city within a Country
City findMax(Country *c){
    City maxCity = c->cities[0];

    for (int i = 1; i < 3; i++){
        if (c->cities[i].size > maxCity.size){
            maxCity = c->cities[i];
        }
    }

    return maxCity;
}

// Function to print information about the largest city of each country
void printC(Country *countries, int numC){
    for (int i = 0; i < numC; i++){
        printf("%s: ", countries[i].name);
        printf("%s\n", findMax(&(countries[i])).name);
    }
}
