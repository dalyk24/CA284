
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(int, int);
float sub(int, int);
float product(int, int);
float divide(int, int);
float power(int, int);
float nlog(int, int);

int main(int argc, char *argv[]){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    float result = 0;
    //float resultF = 0;
    //int (*pfunctionInt)(int, int);
    float (*pfunction)(int, int);

    pfunction = sum;
	result = pfunction(x, y);
	printf("%.2f\n", result);

    pfunction = sub;                  // Points to function difference()
	result = pfunction(x, y);                // Call difference() through pointer
	printf("%.2f\n", result);

	pfunction = product;                     // Points to function product()
	result = pfunction(x, y);                // Call product() through pointer
	printf("%.2f\n", result);

    pfunction = divide;
	result = pfunction(x, y);
	printf("%.2f\n", result);
    
    pfunction = power;
	result = pfunction(x, y);
	printf("%.2f\n", result);
    
    pfunction = nlog;
	result = pfunction(x, y);
	printf("%.2f\n", result);

    return 0;
}

float sum(int x, int y){
	return (float)x + y;
}

float sub(int x, int y){
	return (float)x - y;
}

float product(int x, int y){
	return (float)x * y;
}

float divide(int x, int y){
	return (float)x / y;
}

float power(int x, int y){
	return (float)pow(x, y);
}

float nlog(int x, int y){
    return (float)log(x) + log(y);
}
