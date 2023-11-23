/* 
	Name: Killian Daly
	Date: 2/11/23
	Description: Accepts shopping cart items, 4 args per item
	then builds structs for these items and prints them
*/

// libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// this simplifies struct declaration
typedef struct Cart Cart;

// struct to hold our cart items
struct Cart {
    char name[20];
    int amount;
    float price;
    int sale;
};

// functions
void buildStructs(Cart *pCart, char *argv[], int numC);
void printStructs(Cart *pCart, int numC);

int main(int argc, char *argv[]){
	// each item has 4 args, so nums of args / 4 - filename is num items
	int numC = (argc - 1) / 4;
	Cart carts[100];
	// we set a pointer to first array index to navigate it
	Cart *pCart = &carts[0];

	buildStructs(pCart, argv, numC);

	printStructs(pCart, numC);

	return 0;
}

// uses pointer to first array index to access array of structs and build them
void buildStructs(Cart *pCart, char *argv[], int numC){
	for(int i = 0; i < numC; i++){
		// add i to our pointer to access the second item and so on
		// add 3 * i to advance length of an items args per iteration
		strcpy((pCart + i)->name, argv[(i + 1) + (3 * i)]);
		(pCart + i)->amount = atoi(argv[(i + 2) + (3 * i)]);
		(pCart + i)->price = atof(argv[(i + 3) + (3 * i)]);
		(pCart + i)->sale = atoi(argv[(i + 4) + (3 * i)]);
	}
}

// we similarly use pointer to access values of struct array and print them
void printStructs(Cart *pCart, int numC){
	for(int i = 0; i < numC; i++){
		printf("%s,%d,%.2f,", (pCart + i)->name, (pCart + i)->amount, (pCart + i)->price);

		// check for 0 or 1 indicating sale and print newline for next item
		if((pCart + i)->sale == 0){
			printf("No Sale\n");
		}
		else{
			printf("On Sale\n");
		}
	}
}
