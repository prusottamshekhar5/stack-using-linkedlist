#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

void push(node **stack, int data);
void pop(node **stack);
void display(node **stack);

node *stack = NULL;
int count = 0;

int main(void) {
    int val;
    int ch;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Count\n");
        
        printf("Choice of operation: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&stack, val);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Count: %d\n", count);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}

void push(node **stack, int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = data;
    newNode->next = *stack;
    *stack = newNode;
    count++;
}

void pop(node **stack) {
    if (*stack == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    node *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    count--;
}

void display(node **stack) {
    node *temp = *stack;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}