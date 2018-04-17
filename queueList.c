/*
* Queue - Linked List Implementation
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/* Node Structure */
struct node {
	int data;
	struct node *next;
};

void peekFront(struct node *front); /* Displays the Front Element */
void peekRear(struct node *rear); /* Displays the Rear Element */
void enqueue(struct node **front, struct node **rear, int *size, int maxSize, int value);
void dequeue(struct node **front, struct node **rear, int *size, int maxSize);

int main() {
	struct node *front = NULL, *rear = NULL;
	int size = 0;
	
	peekFront(front);
	enqueue(&front, &rear, &size, MAX_SIZE, 10);
	enqueue(&front, &rear, &size, MAX_SIZE, 11);
	peekFront(front);
	peekRear(rear);
	printf("Size: %d\n", size);

	
	dequeue(&front, &rear, &size, MAX_SIZE);
	peekFront(front);
	peekRear(rear);
	printf("Size: %d\n", size);

	dequeue(&front, &rear, &size, MAX_SIZE);
	peekFront(front);
	peekRear(rear);
	printf("Size: %d\n", size);
	return 0;
}

/* Function to Display the Front node of a Queue */
void peekFront(struct node *front) {
	if(front == NULL) {
		printf("Empty Queue!\n");
	} else {
		printf("Front is %d\n", front -> data);
	}
}

/* Function to Display the Rear node of a Queue */
void peekRear(struct node *rear) {
	if(rear == NULL) {
		printf("Empty Queue!\n");
	} else {
		printf("Rear is %d\n", rear -> data);
	}
}

/* Function to Add data to the Rear of the Queue */
void enqueue(struct node **front, struct node **rear, int *size, int maxSize, int value) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

	newNode -> data = value;

	if(*size == maxSize) {
		printf("Overflow Condition!\n");
		return;
	}

	if(*size == 0) { /* Enqueue in an Empty Queue */
		newNode -> next = NULL;
		*front = newNode;
		*rear = newNode;
	} else {
		newNode -> next = NULL;
		(*rear) -> next = newNode;
		*rear = newNode;
	}
	(*size)++;
}

/* Function to remove value from the Queue */
void dequeue(struct node **front, struct node **rear, int *size, int maxSize) {
	if(*size == 0) {
		printf("Underflow Condition!\n");
		return;
	} else {
		struct node *frontNode = *front;
		printf("%d would be removed!\n", frontNode -> data);
		
		if(*size == 1) {
			*front = NULL;
			*rear = NULL;
		} else {
			*front = frontNode -> next;
		}

		(*size)--;
		free(frontNode);
	}
}