#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    printf("Successfully pushed: %d\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to pop.\n");
        return;
    }
    Node *temp = s->top;
    int removed = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    printf("Successfully popped: %d\n", removed);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("No one. Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", s->top->data);
}

void clearStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is already empty.\n");
        return;
    }
    Node *current = s->top;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    s->top = NULL;
    s->size = 0;
    printf("Stack has been cleared.\n");
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack: [ empty ]\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    Node *current = s->top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

void printMenu() {
    printf("\n----- STACK MENU -----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. IsEmpty\n");
    printf("4. Peek\n");
    printf("5. Clear Stack\n");
    printf("6. Exit\n");
    printf("----------------------\n");
}

int main() {
    Stack s;
    initStack(&s);

    printf("=== STACK PROGRAM (Linked List Implementation) ===\n");
    printf("Stack initialized.\n");

    int choice, value;

    do {
        printMenu();
        displayStack(&s);
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                if (isEmpty(&s))
                    printf("Yes, stack is empty.\n");
                else
                    printf("No, stack is not empty (%d element(s)).\n", s.size);
                break;

            case 4:
                peek(&s);
                break;

            case 5:
                clearStack(&s);
                break;

            case 6:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter 1-6.\n");
        }

    } while (choice != 6);

    clearStack(&s);
    return 0;
}