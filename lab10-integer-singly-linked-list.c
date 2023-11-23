#include <stdio.h>
#include <stdlib.h>


typedef struct Nums Nums;

struct Nums{
    int data;
    Nums *next;

};

Nums* make_Node(int argc, char *argv[]);
void printNums(Nums *start);

int main(int argc, char *argv[]){
    Nums *start = NULL;
    start = make_Node(argc, argv);
    printNums(start);

    return 0;
}

Nums* make_Node(int argc, char *argv[]){
    Nums *first, *current;

    first = (Nums*)calloc(1, sizeof(Nums));
    current = first;

    current->data = atoi(argv[2]);

    for(int i = 3; i < argc; i++){
        current->next = (Nums*)calloc(1, sizeof(Nums));

        current = current->next;
        current->data = atoi(argv[i]);
    }

    current->next = NULL;

    return first;
}

void printNums(Nums *start){
    Nums *p = NULL;

    for(p = start; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
}
