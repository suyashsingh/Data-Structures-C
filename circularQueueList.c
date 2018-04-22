/*
*   Circular Queue
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int isEmpty(struct node *front, struct node *rear);
void enqueue(struct node **front, struct node **rear, int value);
void dequeue(struct node **front, struct node **rear);

void peek(struct node *front, struct node* rear);

int main() {
    struct node *front = NULL;
    struct node *rear = NULL;
    
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 11);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    enqueue(&front, &rear, 21);
    enqueue(&front, &rear, 22);
    enqueue(&front, &rear, 23);
    //printf("isEmpty: %d\n", isEmpty(front, rear));
    //peek(front, rear);
    //printf("Current rear: %d\n", rear -> next -> next -> next -> data); // Checking the links
    return 0;
}

int isEmpty(struct node *front, struct node *rear) {
    return ((front == NULL) && (rear == NULL));
}

void enqueue(struct node **front, struct node **rear, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;

    if(isEmpty(*front, *rear)) {
        newNode -> next = newNode;
        *front = newNode;
    } else {
        newNode -> next = *front;
        (*rear) -> next = newNode;
    }
    *rear = newNode;
}

void dequeue(struct node **front, struct node **rear) {
    if(isEmpty(*front, *rear)) {
        printf("Underflow!\n");
        return;
    } else if(*front == *rear) { // Only one element in the queue
        *front = *rear = NULL;
    } else {
        struct node *temp = *front;
        *front = (*front) -> next;
        (*rear) -> next = *front;
        free(temp);
    }
}

void peek(struct node *front, struct node *rear) {
    if(isEmpty(front, rear)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front: %d, Rear: %d\n", front -> data, rear -> data);
}