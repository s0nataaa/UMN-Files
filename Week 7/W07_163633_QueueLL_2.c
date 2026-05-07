#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int isEmpty(Node *head) {
    return head == NULL;
}

void enqueue(Node **head, Node **tail, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(*head)) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    printf("Enqueued: %d\n", data);
}

void dequeue(Node **head, Node **tail) {
    if (isEmpty(*head)) {
        printf("Queue is empty! Nothing to dequeue.\n");
        return;
    }
    Node *trash = *head;
    printf("Dequeued: %d\n", trash->data);
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(trash);
}

void peek(Node *head) {
    if (isEmpty(head)) {
        printf("No front element.\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

void printQueue(Node *head) {
    if (isEmpty(head)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents (front to back): ");
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" <- ");
        current = current->next;
    }
    printf("\n");
}

void clearQueue(Node **head, Node **tail) {
    if (isEmpty(*head)) {
        printf("Queue is already empty.\n");
        return;
    }
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    *tail = NULL;
    printf("Queue has been cleared.\n");
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int choice, data;

    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Peek\n");
        printf("5. PrintQueue\n");
        printf("6. Clear Queue\n");
        printf("7. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &data);
                enqueue(&head, &tail, data);
                break;
            case 2:
                dequeue(&head, &tail);
                break;
            case 3:
                if (isEmpty(head))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 4:
                peek(head);
                break;
            case 5:
                printQueue(head);
                break;
            case 6:
                clearQueue(&head, &tail);
                break;
            case 7:
                clearQueue(&head, &tail);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1-7.\n");
        }
    } while (choice != 7);

    return 0;
}