/*
    Name: Killian Daly
    Date: 11/11/23
    Description:  Find studentswith higher grade than average and display their info
    Approach: Create an array for students, resize as necessary. Iterate to build array and iterate any over avg
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Student Student;

struct Student {
    char name[20];
    char programme[20];
    float grade;
};

// Function to build the array of students
void buildArray(int *numStudents, Student *students, char *argv[]);

void findAvg(int *numStudents, Student *students, float *pAvg);

// Function to print the student information
void printStudents(int *numStudents, Student *students, float *pAvg);

int main(int argc, char *argv[]) {
    int length = argc - 1;

    int *numStudents = (int *)malloc(sizeof(int));
    float *pAvg = (float *)malloc(sizeof(float));

    // Allocate memory for an initial array of 2 students
    Student *students = (Student *)calloc(2, sizeof(Student));

    // Check for memory allocation failure
    if (!numStudents || !students || !pAvg) {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        free(numStudents);
        free(students);
        free(pAvg);
        return 0;
    }

    // Calculate the number of students based on the input
    *numStudents = length / 3;

    // If the number of students is more than 2, resize the array
    if (*numStudents > 2) {
        // Attempt to reallocate memory for the array
        Student *pTemp = realloc(students, *numStudents * sizeof(Student));

        // Check for reallocation failure
        if (!pTemp) {
            printf("Failed to allocate memory!");
            free(pTemp);
            return 0;
        }

        // Update the pointer to the resized array
        students = pTemp;
    }

    buildArray(numStudents, students, argv);

    findAvg(numStudents, students, pAvg);

    printStudents(numStudents, students, pAvg);

    // Free allocated memory
    free(numStudents);
    free(students);
    free(pAvg);

    return 0;
}

// Function to build the array of students
void buildArray(int *numStudents, Student *students, char *argv[]) {
    for (int i = 0; i < *numStudents; i++) {
        // Extract and store student information from command line arguments
        strcpy((students + i)->name, argv[i * 3 + 1]);
        strcpy((students + i)->programme, argv[i * 3 + 2]);
        (students + i)->grade = atof(argv[i * 3 + 3]);
    }
}

void findAvg(int *numStudents, Student *students, float *pAvg){
    for(int i = 0; i < *numStudents; i++){
        *pAvg += (students+i)->grade;
    }

    *pAvg = *pAvg / *numStudents;
}

// Function to print the student information
void printStudents(int *numStudents, Student *students, float *pAvg) {
    for (int i = 0; i < *numStudents; i++) {
        // Print each student's information on a new line if they are above average
        if((students + i)->grade > *pAvg && strcmp((students + i)->programme, "CSCE") == 0){
            printf("%s, %.2f\n", (students + i)->name, (students + i)->grade);
        }
    }

    printf("Average grade: %.2f\n", *pAvg);
}
