// Write a program to implement stack operations (PUSH, POP, PEEP, CHANGE & DISPLAY)
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->arr[stack->top];
}

void change(struct Stack* stack, int index, int value) {
    if (index < 0 || index > stack->top) {
        printf("Invalid index\n");
        return;
    }
    stack->arr[index] = value;
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int choice, value, index;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                printf("Enter index to change: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(&stack, index, value);
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}