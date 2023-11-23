#include <stdio.h>
#include <stdlib.h>

typedef struct Nums Nums;

struct Nums{
    float data;
    Nums *next;
    Nums *prev;

};

Nums* make_Node(int argc, char *argv[]);
void printNums(Nums *end);

int main(int argc, char *argv[]){
    int length = atoi(argv[1]);
    Nums *end = NULL;
    end = make_Node(argc, argv);
    printNums(end);

    return 0;
}

Nums* make_Node(int argc, char *argv[]){
    Nums *first, *current, *prev;

    first = (Nums*)calloc(1, sizeof(Nums));
    current = first;

    current->data = atoi(argv[2]);
    current->prev = NULL;

    for(int i = 3; i < argc; i++){
        current->next = (Nums*)calloc(1, sizeof(Nums));
        prev = current;

        current = current->next;
        current->data = atof(argv[i]);
        current->prev = prev;
    }

    current->next = NULL;

    return current;
}

void printNums(Nums *end){
    Nums *p = NULL;

    for(p = end; p != NULL; p = p->prev){
        printf("%.2f\n", p->data);
    }
}
