#include <stdio.h>
#include <stdlib.h>

typedef struct Nums Nums;

struct Nums {
    int data;
    Nums *next;
    Nums *prev;
};

Nums* make_Node(int argc, char *argv[]);
void popList(Nums **start);
void pushList(Nums **start, int argc, char *argv[]);
void printNums(Nums *start);

int main(int argc, char *argv[]) {
    Nums *start = NULL;
    start = make_Node(argc, argv);
    
    popList(&start);
    pushList(&start, argc, argv);
    printNums(start);

    return 0;
}

Nums* make_Node(int argc, char *argv[]) {
    Nums *first, *current, *prev;
    first = (Nums*)calloc(1, sizeof(Nums));

    if (first == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    current = first;

    current->data = atoi(argv[2]);
    current->prev = NULL;

    for (int i = 3; i < argc-2; i++) {
        current->next = (Nums*)calloc(1, sizeof(Nums));
        if (current->next == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        
        prev = current;

        current = current->next;
        current->data = atoi(argv[i]);
        current->prev = prev;
    }

    current->next = NULL;

    return first;
}

void popList(Nums **start) {
    Nums *current = *start;

    while (current->next->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        // If there's only one node in the list
        *start = NULL;
    }

    free(current);
}

void pushList(Nums **start, int argc, char *argv[]){
    Nums *current = *start;
    Nums *prev;

    while (current->next != NULL) {
        current = current->next;
    }

    for (int i = argc-2; i < argc; i++) {
        current->next = (Nums*)calloc(1, sizeof(Nums));
        if (current->next == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        
        prev = current;

        current = current->next;
        current->data = atoi(argv[i]);
        current->prev = prev;
    }

    current->next = NULL;
}

void printNums(Nums *start) {
    Nums *p = NULL;

    for (p = start; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
}
