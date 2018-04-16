/*
* Doubly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

/* Node to hold the data items */
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

/* Helper Functions */
int length(struct node *head);
struct node* nthNode(struct node *head, int n);

/* Main List functions */
void display(struct node *head);
void reverseDisplay(struct node *head);
void insertAtBeg(struct node **head, int value);
void deleteAtBeg(struct node **head);
void insertAtEnd(struct node **head, int value);
void deleteAtEnd(struct node **head);
void insertAtPos(struct node **head, int index, int value);
void deleteAtPos(struct node **head, int index);

/* Main function */
int main() {
	struct node *head = NULL;
	int choice, index, value;

	/* Static Nodes for Testing */
	/*
	struct node n1, n2, n3;

	head = &n1;

	n1.data = 10;
	n2.data = 20;
	
	n1.next = &n2;
	n2.next = NULL;

	n1.prev = NULL;
	n2.prev = &n1;
	*/
	/* End of Static Nodes for Testing */
	
	/* Start Menu */
	// Menu
	system("clear");
	while(1) {
		printf(" ------------------------\n");
		printf("|          MENU          |\n");
		printf("|------------------------|\n");
		printf("| 1. Display             |\n");
		printf("| 2. Reverse Display     |\n");
		printf("| 3. Add at Begining     |\n");
		printf("| 4. Delete at Begining  |\n");
		printf("| 5. Insert at End       |\n");
		printf("| 6. Delete at End       |\n");
		printf("| 7. Insert at Position  |\n");
		printf("| 8. Delete at Position  |\n");
		printf("| 9. Exit                |\n");
		printf(" ------------------------ \n");

		printf("Enter choice: \n");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("\n");
				display(head);
				printf("\n");
				break;
			case 2:
				printf("\n");
				reverseDisplay(head);
				printf("\n");
				break;
			case 3:
				printf("\n");
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				insertAtBeg(&head, value);
				printf("Inserted at Begining!\n");
				printf("\n");
				break;
			case 4:
				printf("\n");
				deleteAtBeg(&head);
				printf("\n");
				break;
			case 5:
				printf("\n");
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				insertAtEnd(&head, value);
				printf("Inserted at End!\n");
				printf("\n");
				break;
			case 6:
				printf("\n");
				deleteAtEnd(&head);
				printf("\n");
				break;
			case 7:
				printf("\n");
				printf("Enter the position, value to insert: ");
				scanf("%d%d", &index, &value);
				insertAtPos(&head, index, value);
				printf("Inserted at Position!\n");
				printf("\n");
				break;
			case 8:
				printf("\n");
				printf("Enter the position to delete: ");
				scanf("%d", &index);
				deleteAtPos(&head, index);
				printf("\n");
				break;
			case 9:
				printf("Bye!\n");
				exit(0);
				break;
			default: 
				printf("Please Enter a valid Choice!\n");
		}

	}
	/* End Menu */
	return 0;
}

/* Function to return the length of the linked list */
int length(struct node *head) {
	int length = 0;

	if(head != NULL) {
		struct node *temp = head;

		while(temp != NULL) {
			length++;
			temp = temp -> next;
		}

		return length;
	}
}

/* Function to return a pointer to the nTh node.
*	Assumes that the index is valid, and hence should be verified beforehand.
*/
struct node* nthNode(struct node *head, int n) {
	struct node *temp = head; /* Return head if n equals 0 */

	// Traverse the list till nth index
	for(int i = 0; i < n; i++) {
		temp = temp -> next;
	}

	return temp;
}

/* Function to display the linked list */
void display(struct node *head) {

	printf("List: ");
	if(length(head) == 0) {
		printf("Empty!");
	} else {
		struct node *temp = head;

		while(temp != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
	}

	printf("\n");
}


/* Function to display a list in Reverse order */
void reverseDisplay(struct node *head) {

	printf("List(rev. order): ");
	if(length(head) == 0) {
		printf("Empty!");
	} else {
		struct node *temp = nthNode(head, length(head) - 1); /* Pointer to the last node*/

		while(temp != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> prev;
		}	
	}

	printf("\n");
}

/* Function to add node at the begining of the list */
void insertAtBeg(struct node **head, int value) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> data = value;

	if(length(*head) == 0) {
		newNode -> next = NULL;
		newNode -> prev = NULL;
		*head = newNode;
	} else {
		printf("insertion in non empty list: %d\n", length(*head));
		newNode -> prev = NULL;
		newNode -> next = (*head);
		(*head) -> prev = newNode;
		*head = newNode;
	}
}

/* Function to delete the Node at the begining of the list */
void deleteAtBeg(struct node **head) {
	if(length(*head) == 0){
		printf("The list is already empty!\n");
	} else {
		struct node *temp = *head;
		printf("%d will be deleted!\n", temp -> data);

		if(length(*head) == 1) {
			*head = NULL;
			free(temp);
		} else {
			nthNode(*head, 1) -> prev = NULL;
			*head = nthNode(*head, 1);
			free(temp);
		}
	}
}

/* Function to insert value at the end node */
void insertAtEnd(struct node **head, int value) {
	if(length(*head) == 0) {
		insertAtBeg(head, value);
	} else {
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> data = value;
		newNode -> next = NULL;
		newNode -> prev = nthNode(*head, length(*head) - 1);

		nthNode(*head, length(*head) - 1) -> next = newNode;
	}
}

/* Function to delete node from the end of the linked list */
void deleteAtEnd(struct node **head) {
	if(length(*head) == 0) {
		printf("The list is already empty!\n");
	} else {
		if(length(*head) == 1) {
			deleteAtBeg(head);
		} else {
			struct node *lastNode = nthNode(*head, length(*head) - 1); // Last node
			struct node *secndLastNode = lastNode -> prev;

			printf("%d will be deleted!\n", lastNode -> data);
			secndLastNode -> next = NULL;

			free(lastNode);
		}
	}
}

/* Function to Insert node at a given index in a list*/
void insertAtPos(struct node **head, int index, int value) {
	if(index < 0) {
		printf("Invalid Negative Index!\n");
	} else if(index > length(*head) - 1) {
		printf("invalid, index > Max. Index! Node will be inseted at end.\n");
		insertAtEnd(head, value);
	} else { /* Valid Index */
		if(index == 0) {
			insertAtBeg(head, value);
		} else {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode -> data = value;
			newNode -> next = nthNode(*head, index);
			newNode -> prev = nthNode(*head, index - 1);

			nthNode(*head, index) -> prev = newNode;
			nthNode(*head, index - 1) -> next = newNode;
		}
	}
}

/* Function to Delete node at an index */
void deleteAtPos(struct node **head, int index) {
	if((index < 0) || (index > length(*head) - 1)) {
		printf("Invalid Index to Delete!\n");
	} else {
		if(index == 0) {
			deleteAtBeg(head);
		} else if(index == length(*head) - 1) {
			deleteAtEnd(head);
		} else {
			struct node *targetNode, *prevNode, *nextNode;
			targetNode = nthNode(*head, index);
			prevNode = targetNode -> prev;
			nextNode = targetNode -> next;

			printf("%d will be deleted!\n", targetNode -> data);
			prevNode -> next = nextNode;
			nextNode -> prev = prevNode;

			free(targetNode);
		}
	}
}
