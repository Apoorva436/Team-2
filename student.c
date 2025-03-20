#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to add a new student record
void addStudent() {
    FILE *fp = fopen("students.txt", "a");  // Open file in append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    printf("\nEnter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);  // Reads a full string with spaces
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Write to file
    fprintf(fp, "%d %s %.2f\n", s.rollNo, s.name, s.marks);
    fclose(fp);

    printf("\nStudent record added successfully!\n");
}

// Function to display all students
void displayStudents() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Student s;
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("-----------------------------------------\n");

    while (fscanf(fp, "%d %s %f", &s.rollNo, s.name, &s.marks) != EOF) {
        printf("%-10d %-20s %-10.2f\n", s.rollNo, s.name, s.marks);
    }
    fclose(fp);
}

// Function to search for a student by Roll Number
void searchStudent() {
    int roll;
    printf("\nEnter Roll No to Search: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Student s;
    int found = 0;

    while (fscanf(fp, "%d %s %f", &s.rollNo, s.name, &s.marks) != EOF) {
        if (s.rollNo == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n======== Student Management System ========");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by Roll No");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("\nExiting...\n"); exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
    
    return 0;
}
