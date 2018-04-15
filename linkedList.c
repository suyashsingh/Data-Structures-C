/*
*Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

/* List node Structure */
struct node {
	int data;
	struct node *next;
};

/* Helper functions */
int length(struct node *head);
struct node* nthNode(struct node *head, int n); /* Returns a pointer to the nthNode */

/* Main Linked List Functions */
void display(struct node *head);
void reverseDisplay(struct node *head);
void insertAtBeg(struct node **head, int value);
void deleteAtBeg(struct node **head);
void insertAtEnd(struct node **head, int value);
void deleteAtEnd(struct node **head);
void insertAtPos(struct node **head, int index, int value);
void deleteAtPos(struct node **head, int index);

/* Main function */
int main()
{
	struct node *head = NULL;
	int  choice, value, index;
	
	// Static nodes for testing!
	/*
	struct node n1, n2, n3;

	head = &n1;

	n1.data = 10;
	n2.data = 20;
	n3.data = 30;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	*/
	// End of static nodes
	
	//printf("The 2nd node in the list is: %d\n", nthNode(head, 2) -> data);
	
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

	return 0;
}

/* Function to calculate the length of the list */
int length(struct node *head) {
	int length = 0;
	if(head != NULL) {
		struct node *temp = head;

		// Travese through the list and increment length
		while(temp != NULL) {
			length++;
			temp = temp -> next;
		}
	}

	return length;
}

/* Function to return a pointer to the nthNode 
*	Assumes that the index passed is VALID.
*	Index is to be verified before passing to this function
*/
struct node* nthNode(struct node *head, int n) {
	struct node *temp = head;

	for(int i = 0; i < n; i++) {
		temp = temp -> next;
	}
	return temp;
}

/* Function to display the entire list */
void display(struct node *head) {
	printf("List: ");

	/* Traverse the list and print the data items in each node */
	for(int i = 0; i < length(head); i++) {
		printf("%d ", nthNode(head, i) -> data);
	}

	printf("\n");
}

/* Function to display the entire list in reverse order*/
void reverseDisplay(struct node *head) {
	int size = length(head);
	printf("List(reverse order): ");

	/* Traverse the list in reverse order and print the data items in each node */
	for(int i = size - 1; i >= 0; i--) {
		printf("%d ", nthNode(head, i) -> data);
	}

	printf("\n");
}

/* Function to insert node at the begining of the linked list */
void insertAtBeg(struct node **head, int value) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> data = value;

	if(length(*head) == 0) { /* Empty linked list */
		newNode -> next = NULL;
		*head = newNode;
	} else { /* Non Empty linked list */
		newNode -> next = *head;
		*head = newNode;
	}
}

/* Function to delete node at the begining of the list */
void deleteAtBeg(struct node **head) {
	if(length(*head) == 0) {
		printf("List already Empty!\n");
	} else {
		struct node *temp = *head;
		printf("%d will be deleted\n", temp -> data);
		*head = (*head) -> next;
		free(temp);
	}
}

/* Function to insert node at the end of the list */
void insertAtEnd(struct node **head, int value) {
	if(length(*head) == 0) {
		insertAtBeg(head, value);
	} else {
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> data = value;
		newNode -> next = NULL;
		nthNode(*head, length(*head) - 1) -> next = newNode;
	}
}

/* Function to delete a node at the end of the list */
void deleteAtEnd(struct node **head) {
	int size = length(*head);

	if(size == 0) {
		printf("List already Empty!\n");
	} else if(size == 1) {
		deleteAtBeg(head);
	} else {
		struct node *temp = nthNode(*head, length(*head) - 1);

		/* Make the second last node point to NULL */
		nthNode(*head, length(*head) - 2) -> next = NULL;

		printf("%d will be deleted!\n", temp -> data);
		free(temp);
	}
}

/* Function to insert at a given index */
void insertAtPos(struct node **head, int index, int value) {
	if(index < 0) {
		printf("Invalid. Negative Index!\n");
	} else if(index > length(*head) - 1) { 
		printf("Invalid. Index > maximum index, value will be inseted at end!\n");
		insertAtEnd(head, value);
	} else {
		/* All valid indexes*/
		if(index == 0) {
			insertAtBeg(head, value);
		} else {
			printf("Insertion at a valid Index\n");
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode -> data = value;
			newNode -> next = nthNode(*head, index);
			nthNode(*head, index - 1) -> next = newNode;
		}
	}
}

/* Function to delete node at a position */
void deleteAtPos(struct node **head, int index) {
	if(index < 0) {
		printf("Invalid negative index!\n");
	} else if(index > length(*head) - 1) {
		printf("Invalid positive index!\n");
	} else {
		if(index == 0){
			deleteAtBeg(head);
		} else if(index == length(*head) - 1) {
			deleteAtEnd(head);
		} else {
			struct node *temp = nthNode(*head, index);

			printf("%d will be deleted!\n", temp -> data);

			nthNode(*head, index - 1) -> next = (temp -> next);
			free(temp);
		}
	}
}
