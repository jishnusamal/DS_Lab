#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

void traverse(node *head, int reverse) {

    if (traverse == 0) {
        node *temp = head;
        while(temp != NULL) {
            printf("%d - %x\n", temp -> data, temp);
            temp = temp->next;
        }
    } else {

    }
}

void insertNodeByPos(node *head, int data, int pos) {
    node *temp = head;
    node *newNode = (node*) malloc(sizeof(node));
    newNode -> data = data;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertElement(node* head, int num, int position, int index) {
    node* temp = head;
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;

    index--;

    if (position == 1) {
        index++;
    }

    if (index == 0) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp -> next;
        i++;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


node* createList(int data[], int n, node* head) {
    node *temp = head;

    head -> data = data[0];
    head -> next = NULL;

    for (int i = 1; i < n; i++) {
        temp -> next = (node*) malloc(sizeof(node));
        temp = temp -> next;
        temp -> data = data[i];
        temp -> next = NULL;
    }

    return head;
}

int main() {
    node *head = (node *) malloc(sizeof(node));
    int data[] = {1,2,3,5,7};
    head = createList(data, 5, head);
    insertNodeByPos(head, 9, 2);
    traverse(head);
    return 0;
}







/*
Write a menu-driven C program using structures to implement the following operations
on a Doubly Linked List.
➢ Insert an element at the rear end of the list -----------------> 1
(Append a new node to the end of the list)
➢ Delete an element from the rear end of the list  -----------------> 4
(Remove the last node in the list)
➢ Insert an element at a given position in the list -----------------> 1
(e.g., Insert at position 3. Positioning starts from 1.)
➢ Delete an element from a given position in the list  -----------------> 4
➢ Insert an element after a node containing a specific value -----------------> 2
(e.g., Insert 40 after 25)
➢ Insert an element before a node containing a specific value -----------------> 2
(e.g., Insert 10 before 25)
➢ Traverse the list in forward direction  -----------------> 3
(From head to tail)
➢ Traverse the list in reverse direction -----------------> 3
(From tail to head – i.e., reverse traversal)
Requirements:
• Use dynamic memory allocation (malloc and free).
• Maintain both head and tail pointers for efficient operations.
• Use appropriate functions for modular implementation of each operation.
*/
