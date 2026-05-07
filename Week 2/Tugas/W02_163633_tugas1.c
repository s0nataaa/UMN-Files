#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
    char name[50];
    char major[50];
    float gpa;
} Student;

void showall(Student students[], int n);
void inputstudent(Student students[], int *n);

int main() {
    Student students[MAX];
    int n, option;
    n = 0;
    while (1) {
        printf("Welcome to simple student database (%d/20)\n", n);
        printf("1. Show all students\n2. Input new student\n3. Exit\nChoose : ");
        scanf("%d", &option);
        printf("\n");

        if (option == 1) {
            showall(students, n);
        } else if (option == 2) {
            inputstudent(students, &n);
        } else if (option == 3) {
            break;
        } else { 
            printf("Invalid Choice\n");
        }

    }
    return 0;
}

void showall(Student students[], int n) {
    if (n == 0) {
        printf("No input yet\n\n");
        return;
    }

    printf("                             List of Student Information                         \n");
    printf("---------------------------------------------------------------------------------\n");
    printf("|No.|                  Name                 |          Major          |   GPA   |\n");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("| %-2d| %-38s| %-25s| %-7.2f|\n", i+1, students[i].name, students[i].major, students[i].gpa);
    } 
    printf("---------------------------------------------------------------------------------\n");
}

void inputstudent(Student students[], int *n) {   
    if (*n >= MAX) {
        printf("Database is full\n\n");
        return;
    }

    printf("  Insert Student Information  \n");
    printf("------------------------------\n");

    printf("Name   : "); scanf(" %[^\n]", students[*n].name);
    printf("Major  : "); scanf(" %[^\n]", students[*n].major);
    printf("GPA    : "); scanf("%f", &students[*n].gpa);
    printf("Inserting data\n");   
    printf("New students added\n\n");   
    (*n)++;
}


