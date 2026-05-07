#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int head;
    int tail;
} Queue;

void initQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
}

int isFull(Queue *q) {
    return q->tail == MAX_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->head == -1;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
        return;
    }
    if (isEmpty(q)) {
        q->head = 0;
    }
    q->tail++;
    q->data[q->tail] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to dequeue.\n");
        return;
    }
    int removed = q->data[q->head];
    printf("Dequeued: %d\n", removed);

    if (q->head == q->tail) {
        q->head = -1;
        q->tail = -1;
    } else {
        q->head++;
    }
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return;
    }
    printf("Front element: %d\n", q->data[q->head]);
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents (front to back): ");
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d", q->data[i]);
        if (i < q->tail) printf(" <- ");
    }
    printf("\n");
}

void clearQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
    printf("Queue has been cleared.\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, data;

    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsFull\n");
        printf("4. IsEmpty\n");
        printf("5. Peek\n");
        printf("6. PrintQueue\n");
        printf("7. Clear Queue\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                if (isFull(&q))
                    printf("Queue is FULL.\n");
                else
                    printf("Queue is NOT full. (%d/%d slots used)\n",
                        (isEmpty(&q) ? 0 : q.tail - q.head + 1), MAX_SIZE);
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                peek(&q);
                break;
            case 6:
                printQueue(&q);
                break;
            case 7:
                clearQueue(&q);
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1-8.\n");
        }
    } while (choice != 8);

    return 0;
}