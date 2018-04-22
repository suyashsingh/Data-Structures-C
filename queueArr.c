/*
* Queue using array
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* Queue Operations */
int isEmpty(int rear, int front);
int isFull(int rear, int size);
void enqueue(int *arr, int *front, int *rear, int size, int value);
void dequeue(int *arr, int *front, int *rear);
void peek(int *arr, int front, int rear);

int main() {
    int arr[SIZE];
    int front = -1;
    int rear = -1;

    //enqueue(arr, &front, &rear, SIZE, 10);
    //printf("isEmpty -> %d\n", isEmpty(front, rear));
    //printf("isFull -> %d\n", isFull(rear, SIZE));
    peek(arr, front, rear);
    enqueue(arr, &front, &rear, SIZE, 10);
    peek(arr, front, rear);
    enqueue(arr, &front, &rear, SIZE, 11);
    enqueue(arr, &front, &rear, SIZE, 12);
    enqueue(arr, &front, &rear, SIZE, 13);
    enqueue(arr, &front, &rear, SIZE, 14);
    enqueue(arr, &front, &rear, SIZE, 15);
    enqueue(arr, &front, &rear, SIZE, 16);
    enqueue(arr, &front, &rear, SIZE, 17);
    enqueue(arr, &front, &rear, SIZE, 18);
    dequeue(arr, &front, &rear);
    dequeue(arr, &front, &rear);
    dequeue(arr, &front, &rear);
    dequeue(arr, &front, &rear);
    enqueue(arr, &front, &rear, SIZE, 18);
    dequeue(arr, &front, &rear);
    peek(arr, front, rear);
    return 0;
}

int isEmpty(int rear, int front) {
    return (-1 == rear && -1 == front) ? 1: 0;
}

int isFull(int rear, int size) {
    return (rear == size - 1) ? 1: 0;
}

void enqueue(int *arr, int *front, int *rear, int size, int value) {
    if(isFull(*rear, size)) {
        printf("Overflow!\n");
        return;
    } else if(isEmpty(*front, *rear)) {
        *front = *rear = 0;
    } else {
        (*rear)++;
    }
    *(arr + *rear) = value;
}

void dequeue(int *arr, int *front, int *rear) {
    if(isEmpty(*front, *rear)) {
        printf("Underflow!\n");
        return;
    } else if(*front == *rear) { // Only One Element in the Queue
        *front = *rear = -1;
    } else {
        (*front)++;
    }
}

void peek(int *arr, int front, int rear) {
    if(isEmpty(front, rear)) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front: %d, Rear: %d\n", arr[front], arr[rear]);
    }
}