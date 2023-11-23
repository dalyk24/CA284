/*
 Author: Killian Daly
 Date: 5/10/23
 Description: Accepts numbers and requirement to output largest or smallest number
*/

/* these include needed functions like to print, convert to float and compare strings */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 function declarations: 
 checkReq checks if largest or smallest is requirement and returns result 
 findNum loops through array of floats to find and return largest or smallest
*/
int checkReq(char *requirement);
float findNum(float nums[], int requirement, int length);

/* main function */
int main(int argc, char *argv[]){
	/* variable initialisation to store requirement and empty float array */
	char *requirement = argv[1];
	float nums[50];

	/* iteration through args starts at 2 because that's where where floats begin */
	for(int i = 2; i < argc; i++){
		/* we convert input float and store it in array starting at position 0 */
		nums[i-2] = atof(argv[i]);
	}

	int req = checkReq(requirement);
	/* pass float array, the requirement for largest or smallest and array length */
	float result = findNum(nums, req, argc-2);

	/* print largest or smallest float to 2 decimal places */
	printf("%.2f\n", result);

}

int checkReq(char *requirement){
	/* return 0 if requirement is largest, and 1 otherwise indicating smallest */
	if(strcmp(requirement, "largest") == 0){
		return 0;
	}

	return 1;
}

float findNum(float nums[], int requirement, int length){
	/* find largest if that's requirement */
	if(requirement == 0){
		/* check each float, if it's greater than max then it becomes new max and so on */
		float max = 0;

		for(int i = 0; i < length; i++){
			if(nums[i] > max){
				max = nums[i];
			}
		}

		return max;
	}

	/* we give min value from array, since smallest value might be smaller than any we make up */
	float min = nums[0];

	/* check each float, if it's lesser than min then it becomes new min and so on */
	for(int i = 1; i < length; i++){
			if(nums[i] < min){
				min = nums[i];
			}
	}

	return min;
}
