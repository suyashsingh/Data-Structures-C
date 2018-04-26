#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int isEmpty(struct node *top);
void push(struct node **top, int value);
void pop(struct node **top);
void peek(struct node *top);

int main() {
    struct node *top = NULL;
    printf("isEmpty: %d\n", isEmpty(top));
    peek(top);
    push(&top, 20);
    push(&top, 10);
    push(&top, 30);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    peek(top);
    return 0;
}

int isEmpty(struct node *top) {
    return top == NULL;
}

void push(struct node **top, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;

    if(isEmpty(*top)) {
        newNode -> next = NULL;
    } else {
        newNode -> next = *top;
    }
    *top = newNode;
}

void pop(struct node **top) {
    struct node *temp = *top;

    if(isEmpty(*top)) {
        printf("Underflow!\n");
    } else {
        *top = (*top) -> next;
    }
    free(temp);
}

void peek(struct node *top) {
    printf("Stack: ");
    if(isEmpty(top)) {
        printf("Empty!\n");
    } else {
        printf("%d \n", top -> data);
    }
}