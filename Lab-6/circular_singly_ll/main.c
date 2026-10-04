#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

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

    temp -> next = head;

    return temp;
}

void traverseList(node* head, node* last) {
    node* temp = head;

    while (1) {
        printf("%d - %x\n", temp -> data, temp);
        temp = temp -> next;
        if (temp == head) break;
    }
    printf("\n");
}

node* insertElementAtEnd(node* head, node* last, int data) {
    node* newNode = (node *) malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = head;
    node* temp = head;
    last -> next = newNode;
    return newNode;
}

node* deleteElementAtEnd(node* head, node* last) {
    node* temp = head;
    while (temp -> next != last) {
        temp = temp -> next;
    }

    temp -> next = head;
    free(last);

    return temp;
}

int main() {
    node* head = (node*) malloc(sizeof(node));
    int data[] = {1, 25, 1, 58, 32, 91, 76};
    int n = sizeof(data) / sizeof(data[0]);

    node* tail = createList(data, n, head);

    traverseList(head, tail);

    tail = insertElementAtEnd(head, tail, 89);

    traverseList(head, tail);

    tail = deleteElementAtEnd(head, tail);

    traverseList(head, tail);

    printf("%d - %x\n", head -> data, head);
    printf("%d - %x\n", tail -> data, tail);

}
