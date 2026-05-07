#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    char major[50];
    int nim;

    struct Student *next;
} Student;

Student *head = NULL;
Student *tail = NULL;

Student* createNode(int nim, char major[], char name[]) {
    Student *newNode = (Student*) malloc(sizeof(Student));
    newNode->nim = nim;
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = NULL;
    return newNode;
}

void insertnew();
void printll();
void deleteall();
void deletefirst();
void deletebynim();

int main() {
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Insert new node\n");
        printf("2. Print Linked List\n");
        printf("3. Delete All Data\n");
        printf("4. Delete First Data\n");
        printf("5. Delete Data by NIM\n");
        printf("6. Exit\n");
        printf("Choose : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertnew();break;
            case 2: printll();break;
            case 3: deleteall();break;
            case 4: deletefirst();break;
            case 5: deletebynim();break;
            case 6: printf("Exiting program\n");break;
            default: printf("Invalid input\n");
        }
    }while (choice != 6);

    return 0;
}

void insertnew() {
    
}