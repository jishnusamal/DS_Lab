#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int coefficient;
    int exponent;
    struct polynomial *next;
} poly;

poly* createList(int data[][2], int n, poly* head) {
    poly *temp = head;

    head -> data = data[0];
    head -> next = NULL;

    for (int i = 1; i < n; i++) {
        temp -> next = (poly*) malloc(sizeof(poly));
        temp = temp -> next;
        temp -> data = data[i];
        temp -> next = NULL;
    }

    temp -> next = head;

    return temp;
}

int main() {
    int data[][2] = {
        {10, 5},
        {2, 3},
        {3, 0}
    };
    int n = sizeof(data) / sizeof(data[0]);
    poly* head = (poly*) malloc(sizeof(poly));

    printf("%d\n", n);

    createList(data, n, head);
}
