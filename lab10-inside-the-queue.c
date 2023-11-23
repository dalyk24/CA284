#include <stdio.h>
#include <stdlib.h>


typedef struct Nums Nums;

struct Nums{
    int data;
    Nums *next;

};

Nums* makeNode(int length, int *pNums);
void insertElement(Nums **start, char *argv[]);
void printNums(Nums *start);

int main(int argc, char *argv[]){
    int nums[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int *pNums = &nums[0];
    int length = 10;

    Nums *start = NULL;

    start = makeNode(length, nums);
    insertElement(&start, argv);
    printNums(start);

    return 0;
}

Nums* makeNode(int length, int *pNums){
    Nums *first, *current;

    first = (Nums*)calloc(1, sizeof(Nums));
    current = first;

    current->data = *pNums;

    for (int i = 1; i < length; i++){
        current->next = (Nums*)calloc(1, sizeof(Nums));
        current = current->next;
        current->data = *(pNums + i);
    }

    current->next = NULL;

    return first;
}

void insertElement(Nums **start, char *argv[]){
    Nums *current = *start;
    Nums *prev;

    while (current->data != atoi(argv[1])){
        current = current->next;
    }

    prev = current->next;
    current->next = (Nums*)calloc(1, sizeof(Nums));
    current = current->next;
    current->data = atoi(argv[2]);
    current->next = prev;
}

void printNums(Nums *start){
    Nums *p = NULL;

    for(p = start; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
}
