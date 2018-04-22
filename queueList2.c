#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int isEmpty(struct node *front, struct node *rear);
void enqueue(struct node **front, struct node **rear, int value);
void dequeue(struct node **front, struct node **rear);
void peek(struct node *front, struct node*rear);

int main() {
    struct node *front = NULL;
    struct node *rear = NULL;
    
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 11);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    printf("isEmpty: %d\n", isEmpty(front, rear));
    peek(front, rear);
    return 0;
}

int isEmpty(struct node *front, struct node *rear) {
    return (front == NULL && rear == NULL) ? 1: 0;
}

void enqueue(struct node **front, struct node **rear, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = NULL; 
    
    if(isEmpty(*front, *rear)) {
        *front = newNode;
    } else {
        (*rear) -> next = newNode;
    }
    *rear = newNode;
}

void dequeue(struct node **front, struct node **rear) {
    struct node *temp;
    if(isEmpty(*front, *rear)) {
        printf("The queue is already empty");
        return;
    } else if(*front == *rear) { // Only one element in the queue
        temp = *front;
        *front = NULL;
        *rear = NULL;
    } else {
        temp = *front;
        *front = (*front) -> next;
        free(temp);
    }
}

void peek(struct node *front, struct node*rear) {
    if(isEmpty(front, rear)) {
        printf("The queue is empty!\n");
        return;
    } else {
        printf("Front: %d, Rear: %d\n", front -> data, rear -> data);
    }
}