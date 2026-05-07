#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
    char url[MAX];
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(const char* url);
void visit();
void move();
void delete();

int main() {
    int option; 

    do {
        printf("==========================\n");
        printf("    Browser History ARYA  \n");
        printf("==========================\n");

        printf("Pilih Aksi:\n");
        printf("1. Visit\n");
        printf("2. Move\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Masukkan pilihan: "); scanf("%d", &option); getchar();

        switch(option) {
            case 1:
                visit();
                break;
            case 2:
                move();
                break;
            case 3:
                delete();
                break;
            case 4:
                printf("Thank you");
                break;
            default:
                printf("Invalid");
        }
    } while (option != 4);

    return 0;
}

Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("Gagal alokasi memori!\n");
        exit(1);
    }
    strncpy(newNode->url, url, MAX - 1);
    newNode->url[MAX_URL - 1] = '\0';
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void visit() {
    printf("Input URL: "); fgets
}