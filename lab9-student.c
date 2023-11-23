/*
    Name: Killian Daly
    Date: 11/11/23
    Description: Check if the number of input students is more than two, allocate more memory if so. Output student info
    Approach: Create an array for students, resize as necessary. Iterate to build array and iterate to print it
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

// Function to print the student information
void printStudents(int *numStudents, Student *students);

int main(int argc, char *argv[]) {
    // Calculate the length of the command line arguments
    int length = argc - 1;

    // Allocate memory to store the number of students
    int *numStudents = (int *)malloc(sizeof(int));

    // Allocate memory for an initial array of 2 students
    Student *students = (Student *)calloc(2, sizeof(Student));

    // Check for memory allocation failure
    if (!numStudents || !students) {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        free(numStudents);
        free(students);
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

    // Build the array of students
    buildArray(numStudents, students, argv);

    // Print the student information
    printStudents(numStudents, students);

    // Free allocated memory
    free(numStudents);
    free(students);

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

// Function to print the student information
void printStudents(int *numStudents, Student *students) {
    for (int i = 0; i < *numStudents; i++) {
        // Print each student's information on a new line
        printf("%s, %s, %.2f\n", (students + i)->name, (students + i)->programme, (students + i)->grade);
    }
}
