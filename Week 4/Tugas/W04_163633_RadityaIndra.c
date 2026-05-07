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

Student* createNode(int nim, char name[], char major[]) {
    Student *newNode = (Student*) malloc(sizeof(Student));
    newNode->nim = nim;
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = NULL;
    return newNode;
}

void insertnew();
void printlist();
void deleteall();
void deletefirst();
void deletenim();


int main() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Insert new node\n");
        printf("2. Print linked list\n");
        printf("3. Delete all data\n");
        printf("4. Delete first data\n");
        printf("5. Delete data by NIM\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertnew(); break;
            case 2: printlist(); break;
            case 3: deleteall(); break;
            case 4: deletefirst(); break;
            case 5: deletenim(); break;
            case 6: printf("Exitting program\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

void insertnew() {
    int nim;
    char name[100], major[50];

    printf("Input NIM   : ");
    scanf("%d", &nim);
    getchar();

    printf("Input Name  : ");
    scanf("%[^\n]", name);
    getchar();

    printf("Input Major : ");
    scanf("%[^\n]", major);

    Student *newNode = createNode(nim, name, major);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("Data inserted\n");
}

void printlist() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Student *current = head;
    while (current != NULL) {
        printf("\nNIM   : %d\n", current->nim);
        printf("Name  : %s\n", current->name);
        printf("Major : %s\n", current->major);
        current = current->next;
    }
}

void deleteall() {
    Student *current = head;

    while (current != NULL) {
        Student *temp = current;
        current = current->next;
        free(temp);
    }

    head = tail = NULL;
    printf("All data deleted\n");
}

void deletefirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Student *temp = head;
    head = head->next;
    
    if (head == NULL)
        tail = NULL;
        
    free(temp);
    printf("First data deleted\n");
}

void deletenim() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int nim;
    printf("Input NIM to delete: ");
    scanf("%d", &nim);
    
    Student *current = head;
    Student *prev = NULL;
    
    while (current != NULL && current->nim != nim) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Data not found\n");
        return;
    }
    
    if (prev == NULL) { 
        head = current->next;
        if (head == NULL)
        tail = NULL;
    } else {
        prev->next = current->next;
        if (current == tail)
        tail = prev;
    }

    free(current);
    printf("Data deleted.\n");
}