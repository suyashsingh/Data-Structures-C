#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void reverseDisplay(struct node *head);
int length(struct node *head);
void insertAtBeg(struct node **head, int value);
void insertAtEnd(struct node **head, int value);
void insertAtPos(struct node **head, int pos, int value);

void deleteAtBeg(struct node **head);
void deleteAtEnd(struct node **head);
void deleteAtPos(struct node **head, int pos);

int main(){
    struct node *head = NULL;
    insertAtBeg(&head, 10);
    //insertAtBeg(&head, 20);
    //insertAtBeg(&head, 30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,30);
    //printf("length %d\n", length(head));
    //insertAtPos(&head, 2, 99);
    //display(head);
    //deleteAtBeg(&head);
    //deleteAtBeg(&head);
    //deleteAtEnd(&head);
    //deleteAtEnd(&head);
    //display(head);
    deleteAtPos(&head, 2);
    display(head);
    reverseDisplay(head);
    return 0;
}

void display(struct node *head) {
    printf("List: ");
    struct node *temp = head;
    if(head == NULL) {
        printf("Empty");
    } else {
        while(temp != NULL) {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
    printf("\n");
}

void reverseDisplay(struct node *head) {
    printf("Rev. List: ");
    struct node *temp = head;
    if(head == NULL) {
        printf("Empty");
    } else {
        // Move pointer to the last node
        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        while(temp != NULL) {
            printf("%d ", temp -> data);
            temp = temp -> prev;
        }
    }
    printf("\n");
}

int length(struct node *head) {
    int length = 0;
    struct node *temp = head;
    
    while(temp != NULL) {
        length++;
        temp = temp -> next;
    }

    return length;
}

void insertAtBeg(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> prev = NULL;

    if(*head == NULL) {
        newNode -> next = NULL;
        *head = newNode;
    } else {
        newNode -> next = *head;
        (*head) -> prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = NULL;

    if(*head == NULL) {
        insertAtBeg(head, value);
    } else {
         // Traverse till the last node
         struct node *temp = *head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }
}

void insertAtPos(struct node **head, int pos, int value) {
    int maxIndex = length(*head) - 1; 
    if(pos < 0) {
        printf("Invalid - Negative Index!\n");
    } else if(pos >= maxIndex) {
        printf("Index >= Current max possible index. Insert at End!\n");
        insertAtEnd(head, value);
    } else if(pos == 0) {
        insertAtBeg(head, value);
    } else {
        struct node *temp = *head;
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> data = value;
        for(int i = 0; i < pos - 1; i++) {
            temp = temp -> next;
        }

        newNode -> next = temp ->next;
        newNode-> prev = temp;
        temp -> next = newNode;
    }
}


void deleteAtBeg(struct node **head) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = *head;

    if(*head == NULL) {
        printf("List Already Empty!\n");
        return;
    } else {
        *head = (*head) ->next;
        (*head) -> prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(struct node **head) {
    struct node *lastNode = *head;

    if(*head == NULL) {
        printf("List Already Empty!\n");
        return;
    } else if((*head) ->next == NULL) { // List with single element
        lastNode = *head;
        *head = NULL;
        free(lastNode);
    } else { // More than one elements in the list
        while(lastNode -> next != NULL) {
            lastNode = lastNode -> next;
        }
        lastNode -> prev -> next = NULL;
        free(lastNode);
    }
}

void deleteAtPos(struct node **head, int pos) {
    struct node *targetNode = *head;

    int maxIndex = length(*head) - 1; 
    if(pos < 0 || pos > maxIndex) {
        printf("Invalid Index!\n");
    } else if(pos == 0) {
        deleteAtBeg(head);
    } else if(pos == maxIndex) {
        deleteAtEnd(head);
    } else {
        for(int i = 0; i < pos; i++) {
            targetNode = targetNode -> next;
        }

        targetNode -> prev -> next = targetNode -> next;
        targetNode -> next -> prev = targetNode -> prev;
        free(targetNode);
    }
}
