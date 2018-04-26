/* Delete at End and Delete at Pos is incomplete as of now */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head);
int length(struct node *head);
void insertAtBeg(struct node **head, int value);
void insertAtEnd(struct node **head, int value);
void insertAtPos(struct node **head, int pos, int value);

void deleteAtBeg(struct node **head);
void deleteAtEnd(struct node **head);
void deleteAtPos(struct node **head, int pos);

int main(){
    struct node *head = NULL;
    insertAtBeg(&head, 20);
    insertAtBeg(&head, 10);
    insertAtBeg(&head, 5);
    //insertAtEnd(&head,20);
    //insertAtEnd(&head,30);
    printf("length %d\n", length(head));
    //insertAtPos(&head, 2, 99);
    //display(head);
    deleteAtBeg(&head);
    //deleteAtBeg(&head);
    //deleteAtEnd(&head);
    //deleteAtEnd(&head);
    //display(head);
    //deleteAtPos(&head, 0);
    display(head);
    //printf("data %d\n", head->next->next-> data);
    return 0;
}

void display(struct node *head) {
    printf("List: ");
    struct node *temp = head;
    if(head == NULL) {
        printf("Empty");
    } else {
        do {
            printf("%d ", temp -> data);
            temp = temp -> next;
        } while(temp != head);
    }
    printf("\n");
}

int length(struct node *head) {
    int length = 0;
    struct node *temp = head;
    
    if(head == NULL) {
        length = 0;
    } else {
        do {
            length++;
            temp = temp -> next;
        } while(temp != head);
    }
    return length;
}

void insertAtBeg(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    newNode -> data = value;
    
    if(*head == NULL) {
        newNode -> next = newNode;
        *head = newNode;
    } else {
        newNode -> next = *head;
        // go till the end of the list and make it point to the firts node
        while(temp -> next != *head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = *head;

    if(*head == NULL) {
        insertAtBeg(head, value);
    } else {
         // Traverse till the last node
        struct node *temp = *head;
        while(temp -> next != *head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
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
        temp -> next = newNode;
    }
}

void deleteAtBeg(struct node **head) {
    struct node *temp = *head;
    struct node *lastNode = *head;

    if(*head == NULL) {
        printf("List Already Empty!\n");
        return;
    } else if((*head) -> next == *head) { // only one element in the list
        *head = NULL;
    } else { // More than one element
        while(lastNode -> next != *head) {
            lastNode = lastNode -> next;
        }
        //printf("data: %d\n", lastNode -> data);
        lastNode -> next = (*head) -> next;
        *head = (*head) -> next;
    }
    free(temp);
}

/*
    Incomplete

void deleteAtEnd(struct node **head) {
    struct node *lastNode = *head;
    struct node *prevNode = *head;

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
            if(lastNode -> next != NULL){
                prevNode = prevNode -> next;
            }
        }
        prevNode -> next = NULL;
        free(lastNode);
    }
}

void deleteAtPos(struct node **head, int pos) {
    struct node *targetNode = *head;
    struct node *prevNode = *head;
    
    int maxIndex = length(*head) - 1; 
    if(pos < 0 || pos > maxIndex) {
        printf("Invalid Index!\n");
    } else if(pos == 0) {
        deleteAtBeg(head);
    } else if(pos == maxIndex) {
        deleteAtEnd(head);
    } else {
        for(int i = 0; i < pos - 1; i++) {
            prevNode = prevNode -> next;
        }

        targetNode = prevNode -> next;
        prevNode -> next = targetNode -> next;
        free(targetNode);
    }
}
*/
