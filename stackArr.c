#include <stdio.h>
#define SIZE 5

int isEmpty(int top);
int isFull(int top, int size);
void push(int *arr, int *top, int size, int value);
void pop(int *arr, int *top);
void peek(int *arr, int top);

int main() {
    int arr[SIZE];
    int top = -1;
    push(arr, &top, SIZE, 10);
    push(arr, &top, SIZE, 11);
    pop(arr, &top);
    //pop(arr, &top);
    //pop(arr, &top);
    printf("isEmpty: %d\n", isEmpty(top));
    peek(arr, top);
    
    return 0;
}

int isEmpty(int top) {
    return top == -1;
}

int isFull(int top, int size) {
    return top == SIZE;
}

void push(int *arr, int *top, int size, int value) {
    if(isFull(*top, size)) {
        printf("Stack Overflow!\n");
    } else {
        (*top)++;
        arr[*top] = value;
    }
}

void pop(int *arr, int *top) {
    if(isEmpty(*top)) {
        printf("Stack Underflow!\n");
    } else {
        (*top)--;
    }
}

void peek(int *arr, int top) {
    printf("Top: ");
    if(isEmpty(top)){
        printf("Empty !\n");
    } else {
        printf("%d\n", arr[top]);
    }
}