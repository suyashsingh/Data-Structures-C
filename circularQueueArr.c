#include <stdio.h>

#define SIZE 5

int isEmpty(int front, int rear);
int isFull(int front, int rear, int size);
void enqueue(int *arr, int *front, int *rear, int size, int value);
void dequeue(int *arr, int *front, int *rear, int size);
void peek(int *arr, int front, int rear);

int main() {
    int arr[SIZE];
    int front = -1;
    int rear = -1;

    dequeue(arr, &front, &rear, SIZE);
    peek(arr, front, rear);
    enqueue(arr, &front, &rear, SIZE, 10);
    enqueue(arr, &front, &rear, SIZE, 11);
    enqueue(arr, &front, &rear, SIZE, 12);
    enqueue(arr, &front, &rear, SIZE, 13);
    enqueue(arr, &front, &rear, SIZE, 14);
    enqueue(arr, &front, &rear, SIZE, 15);
    printf("isEmpty: %d\n", isEmpty(front, rear));
    printf("isFull: %d\n", isFull(front, rear, SIZE));
    dequeue(arr, &front, &rear, SIZE);
    enqueue(arr, &front, &rear, SIZE, 18);
    printf("f= %d, r = %d\n", front, rear);
    peek(arr, front, rear);

    return 0;
}

int isEmpty(int front, int rear) {
    return (-1 == front && -1 == rear) ? 1: 0;
}

int isFull(int front, int rear, int size) {
    return (((rear + 1) % size) == front) ? 1: 0;
}

void enqueue(int *arr, int *front, int *rear, int size, int value) {
    if(isFull(*front, *rear, size)) {
        printf("Overflow!\n");
        return;
    } else if(isEmpty(*front, *rear)) {
        *front = *rear = 0;
    } else {
        *rear = (*rear + 1) % size;
    }

    *(arr + *rear) = value;
}

void dequeue(int *arr, int *front, int *rear, int size) {
    if(isEmpty(*front, *rear)) {
        printf("Underflow!\n");
        return;
    } else if(*front == *rear) { // Only one element in the Queue
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % size;
    }
}

void peek(int *arr, int front, int rear) {
    if(isEmpty(front, rear)) {
        printf("The queue is empty!\n");
        return;
    } else {
        printf("Front: %d, Rear: %d\n", *(arr + front), *(arr + rear));
    }
}