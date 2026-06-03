#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent(struct Student students[], int *numStudents);
void displayStudents(struct Student students[], int numStudents);
void updateGPA(struct Student students[], int numStudents, int studentID, float newGPA);
void removeStudent(struct Student students[], int *numStudents, int studentID);

int main() {
    const int maxStudents = 100;

    struct Student students[maxStudents];

    int numStudents = 0;

    int choice;
    do {
        printf("\nStudent Information Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update GPA\n");
        printf("4. Remove Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3: {
                int studentID;
                float newGPA;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                printf("Enter new GPA: ");
                scanf("%f", &newGPA);
                updateGPA(students, numStudents, studentID, newGPA);
                break;
            }
            case 4: {
                int studentID;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                removeStudent(students, &numStudents, studentID);
                break;
            }
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents < 100) {
        struct Student newStudent;
        printf("Enter student ID: ");
        scanf("%d", &newStudent.id);
        printf("Enter student name: ");
        scanf("%s", newStudent.name);
        printf("Enter student GPA: ");
        scanf("%f", &newStudent.gpa);

        students[*numStudents] = newStudent;
        (*numStudents)++;

        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached. Cannot add more.\n");
    }
}

void displayStudents(struct Student students[], int numStudents) {
    if (numStudents > 0) {
        printf("\nList of Students:\n");
        printf("ID\tName\t\tGPA\n");
        for (int i = 0; i < numStudents; i++) {
            printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
        }
    } else {
        printf("No students in the system.\n");
    }
}

void updateGPA(struct Student students[], int numStudents, int studentID, float newGPA) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentID) {
            students[i].gpa = newGPA;
            printf("GPA updated successfully!\n");
            return;
        }
    }
    printf("Student not found with ID %d. GPA update failed.\n", studentID);
}

void removeStudent(struct Student students[], int *numStudents, int studentID) {
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].id == studentID) {
            students[i] = students[*numStudents - 1];
            (*numStudents)--;
            printf("Student removed successfully!\n");
            return;
        }
    }
    printf("Student not found with ID %d. Removal failed.\n", studentID);
}
