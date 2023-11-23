/* 
	Name: Killian Daly
	Date: 2/11/23
	Description: Accepts an even list of unsorted integers, sorts them
	then prints the middle 2 values
*/

// libraries
#include <stdlib.h>
#include <stdio.h>

// functions
void buildArray(int *pNums, char *argv[], int len);
void sortArray(int *pNums, int len);
void printMids(int *pNums, int len);

int main(int argc, char *argv[]){
	int len = argc - 1;
	int nums[100];
	// we set a pointer to first array index to navigate the array
	int *pNums = &nums[0];

	buildArray(pNums, argv, len);
	sortArray(pNums, len);
	printMids(pNums, len);

	return 0;
}

// uses pointer to first array index to access array and populate it
void buildArray(int *pNums, char *argv[], int len){
	for(int i = 0; i < len; i++){
		// we can add i to our pointer to access the second item etc.
		*(pNums+i) = atoi(argv[i+1]);
	}
}

// similarly uses pointer to sort array so we can discern middle values
void sortArray(int *pNums, int len){
	int temp;

	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++)
			// we can add i to our pointer to access the second item etc.
			if(*(pNums+i) < *(pNums+j)){
				temp = *(pNums+i);
				*(pNums+i) = *(pNums+j);
				*(pNums+j) = temp;
			}
	}
}

// finds mid values of even array by dividing length by 2 and print them
void printMids(int *pNums, int len){
	int mid = len / 2;

	printf("%d\n", *(pNums+mid-1));
	printf("%d\n", *(pNums+mid));
}
