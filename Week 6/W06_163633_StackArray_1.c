#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

void initStack(Stack *s, int size) {
    s->data = (int*) malloc(size * sizeof(int));
    s->top = -1;
    s->maxSize = size;
}

int isFull(Stack *s) {
    return s->top == s->maxSize - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push element.\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("Successfully pushed: %d\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to pop.\n");
        return;
    }
    int removed = s->data[s->top];
    s->top--;
    printf("Successfully popped: %d\n", removed);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("No one. Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", s->data[s->top]);
}

void clearStack(Stack *s) {
    s->top = -1;
    printf("Stack has been cleared.\n");
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack: [ empty ]\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d", s->data[i]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

void printMenu() {
    printf("\n----- STACK MENU -----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. IsFull\n");
    printf("4. IsEmpty\n");
    printf("5. Peek\n");
    printf("6. Clear Stack\n");
    printf("7. Exit\n");
    printf("----------------------\n");
}

int main() {
    Stack s;
    int size;

    printf("=== STACK PROGRAM (Array Implementation) ===\n");
    printf("Enter stack capacity: ");
    scanf("%d", &size);

    while (size <= 0) {
        printf("Capacity must be greater than 0. Try again: ");
        scanf("%d", &size);
    }

    initStack(&s, size);
    printf("Stack initialized with capacity %d.\n", s.maxSize);

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
                if (isFull(&s))
                    printf("IsFull: Yes, stack is full (%d/%d).\n", s.top + 1, s.maxSize);
                else
                    printf("IsFull: No, stack is not full (%d/%d).\n", s.top + 1, s.maxSize);
                break;

            case 4:
                if (isEmpty(&s))
                    printf("Yes, stack is empty.\n");
                else
                    printf("No, stack is not empty (%d element(s)).\n", s.top + 1);
                break;

            case 5:
                peek(&s);
                break;

            case 6:
                clearStack(&s);
                break;

            case 7:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter 1-7.\n");
        }

    } while (choice != 7);

    free(s.data);
    return 0;
}