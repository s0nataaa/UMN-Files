#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    char major[50];
    int nim;

    struct Student *next;
} Student;

int main() {
    Student *head, *node;

    head = NULL;

    node = (Student*) malloc(sizeof(Student));

    node->nim = 13531;
    strcpy(node->name, "Fabe Febrita");
    strcpy(node->major, "Informatics");

    node->next = NULL;

    head = node;

    return 0;
}