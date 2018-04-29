/*
*   Singly linked list with student data
*   30
*/
#include <stdio.h>
#include <stdlib.h>

struct student {
    int rollNo;
    char name[10];
    char course[10];
};

struct node {
    struct student data;
    struct node *next;
};

/* Utility Functions */
int isEmpty(struct node *head);
void display(struct node *head);
int length(struct node *head);
void insertAtBeg(struct node **head, struct student stud);
void insertAtEnd(struct node **head, struct student stud);
void insertAtPos(struct node **head, int pos, struct student stud);

void deleteAtBeg(struct node **head);
void deleteAtEnd(struct node **head);
void deleteAtPos(struct node **head, int pos);

void reverseLinks(struct node **head);
int main() {
    struct node *head = NULL;
    struct student stud1 = {1, "Minion", "Banana"};
    struct student stud2 = {2, "Ninion", "Canana"};
    struct student stud3 = {3, "Dinion", "Danana"};
    // Getting Data from User
    // int i;
    // for(i = 0; i < 3; i++) {
    //     printf("Enter Roll No, Name, Course ");
    //     scanf("%d%s%s", &stud.rollNo, &stud.name, &stud.course);
    //     insertAtBeg(&head, stud);
    // }
    insertAtBeg(&head, stud1);
    insertAtEnd(&head, stud2);
    insertAtEnd(&head, stud3);
    //insertAtPos(&head, 3, s2);
    //display(head);
    //deleteAtBeg(&head);
    //deleteAtBeg(&head);
    //deleteAtBeg(&head);
    // deleteAtEnd(&head);
    // deleteAtEnd(&head);
    // deleteAtEnd(&head);
    // deleteAtEnd(&head);
    //deleteAtPos(&head, 1);
    //deleteAtPos(&head, 0);
    //deleteAtPos(&head, 0);
    //deleteAtPos(&head, 0);
    display(head);
    reverseLinks(&head);
    display(head);
    return 0;
}

int isEmpty(struct node *head) {
    return head == NULL;
}

void display(struct node *head) {
    printf("Details:\n");

    if(isEmpty(head)) {
        printf("Empty List\n");
    } else {
        struct node *temp = head;
        
        while(temp != NULL) {
            printf("%d ", temp -> data.rollNo);
            printf("%s ", temp -> data.name);
            printf("%s\n", temp -> data.course);
            temp = temp -> next;
        }
    }
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


void insertAtBeg(struct node **head, struct student stud) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = stud;

    if(isEmpty(*head)) {
        newNode -> next = NULL;
        *head = newNode;
    } else {
        newNode -> next = *head;
        *head = newNode;
    }
}

void insertAtEnd(struct node **head, struct student stud) {    
    if(isEmpty(*head)) {
        insertAtBeg(head, stud);
    } else {
        struct node *temp = *head;
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = stud;
        newNode -> next = NULL;

        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        temp -> next = newNode;
    }
}

void insertAtPos(struct node **head, int pos, struct student stud) {
    int size = length(*head);
    int i;
    if(pos < 0) {
        printf("Negative index!\n");
    } else if(pos > size - 1) {
        printf("Excess Index!\n");
    } else if(pos == 0) {
        insertAtBeg(head, stud);
    } else if(pos == size - 1) {
        insertAtEnd(head, stud);
    } else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = stud;

        struct node *temp = *head;
        for(i = 0; i < pos -1; i++) {
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void deleteAtBeg(struct node **head) {
    if(isEmpty(*head)) {
        printf("Already Empty!\n");
    } else {
        struct node *temp = *head;

        *head = (*head) -> next;
        free(temp);
    }
}

void deleteAtEnd(struct node **head) {
    if(isEmpty(*head)) {
        printf("Already Empty!\n");
    } else if((*head) -> next == NULL) {
        deleteAtBeg(head);
    } else {

        struct node *lastNode = *head;
        struct node *prevNode = *head;

        while(lastNode -> next != NULL) {
            prevNode = lastNode;
            lastNode = lastNode -> next;
        }

        prevNode -> next = NULL;
        free(lastNode);
    }
}

void deleteAtPos(struct node **head, int pos) {
    int size = length(*head);
    int i;
    if(pos < 0) {
        printf("Negative index!\n");
    } else if(pos > size - 1) {
        printf("Excess Index!\n");
    } else if(pos == 0) {
        deleteAtBeg(head);
    } else if(pos == size - 1) {
        deleteAtEnd(head);
    } else {
        struct node *prevNode = *head;
        struct node *lastNode = *head;

        for(i = 0; i < pos -1; i++) {
            prevNode = prevNode -> next;
        }

        lastNode = prevNode -> next;
        prevNode -> next = lastNode -> next;
        free(lastNode);
    }
}

void reverseLinks(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = *head;

    while(current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next; 
    }

    *head = prev;
}