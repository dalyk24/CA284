/* 
	Name: Killian Daly
	Date: 2/11/23
	Description: Accepts shopping cart items, 4 args per item then 
	builds structs for these items and prints their total price
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
void calcPrice(Cart *pCart, float *pFinal, int numC);
float calcDiscount(Cart *pCart, float *pFinal);

int main(int argc, char *argv[]){
	// each item has 4 args, so we can find total num of items
	// by dividing by 4 and subtracting 1 for the file name
	int numC = (argc - 1) / 4;
	Cart carts[100];
	// we set a pointer to first array index to navigate it
	Cart *pCart = &carts[0];
	float finalPrice;
	// this lets us update our final price in functions without returning value
	float *pFinal = &finalPrice;

	buildStructs(pCart, argv, numC);
	calcPrice(pCart, pFinal, numC);

	printf("%.2f\n", finalPrice);

	return 0;
}

// uses pointer to first array index to access array of structs and build them
void buildStructs(Cart *pCart, char *argv[], int numC){
   for(int i = 0; i < numC; i++){
   	// we can add i to our pointer to access the second item and so on
		// we add 3 * i so we can advance the length of an items args per iteration
      strcpy((pCart + i)->name, argv[(i + 1) + (3 * i)]);
      (pCart + i)->amount = atoi(argv[(i + 2) + (3 * i)]);
      (pCart + i)->price = atof(argv[(i + 3) + (3 * i)]);
      (pCart + i)->sale = atoi(argv[(i + 4) + (3 * i)]);
   }
}

// calculates the total price of the shopping cart items
void calcPrice(Cart *pCart, float *pFinal, int numC){
	int tempDiscount;

	for(int i = 0; i < numC; i++){
		if((pCart + i)->sale == 0){
			// we access final price and add calculated item total price
			*pFinal += (pCart + i)->price * (pCart + i)->amount;
		}
		else{
			// since there is sale, we use a function to find total
			tempDiscount = calcDiscount((pCart + i), pFinal);
			// we subract discount from total
			*pFinal += ((pCart + i)->price * (pCart + i)->amount) - tempDiscount;
		}
	}
}

// find amount discount to be appiled
float calcDiscount(Cart *pCart, float *pFinal){
	// since every third item is discounted, we can divide by 3 to find how many
	// items should be discounted
	int discountItems = pCart->amount / 3;

	// we return amount of discounted items by price which is discount
	return discountItems * pCart->price;
}
