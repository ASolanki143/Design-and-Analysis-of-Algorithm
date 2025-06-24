// Write a program to implement queue operations (INSERT, DELETE, DISPLAY) for a normal (linear) queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void insert(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->arr[queue->rear] = value;
}

int delete(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // Return -1 to indicate an error
    }
    int value = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        // Queue is now empty after deletion
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate an error
    }
    return queue->arr[queue->front];
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. PEEK\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&queue, value);
                break;
            case 2:
                value = delete(&queue);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                value = peek(&queue);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}