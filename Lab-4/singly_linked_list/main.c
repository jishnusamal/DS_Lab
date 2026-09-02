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

    return head;
}

void traverseList(node* head) {
    node* temp = head;
    int i = 0;

    do {
        printf("Node %d: %d (%x)\n", i+1, temp -> data, temp);
        temp = temp -> next;
        i++;
    } while (temp != NULL);
    printf("\n");
}

void freeList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        node* toFree = temp;
        temp = temp -> next;
        free(toFree);
    }
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

void deleteElement(node* head, int num) {
    node* temp = head;
    node* prev = NULL;

    while (temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n\n", num);
        return;
    }

    if (prev == NULL) {
        head->next = temp->next;
        free(temp);
        printf("Element %d deleted successfully.\n\n", num);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted successfully.\n\n", num);
}

void reverseList(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void sortList(node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    node* current = NULL;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current != NULL && current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

void deleteAlternateNodes(node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    node* current = head;

    while (current != NULL && current->next != NULL) {
        node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        free(nodeToDelete);
        current = current->next;
    }
}

void insertInSortedList(node* head, int num) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;

    if (head->next == NULL || head->next->data >= num) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    node* current = head->next;
    while (current->next != NULL && current->next->data < num) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void displayMenu() {
    printf("\n");
    printf("========== LINKED LIST MENU ==========\n");
    printf("1.  Display List\n");
    printf("2.  Insert Element (by position and index)\n");
    printf("3.  Insert Element (in sorted list)\n");
    printf("4.  Delete Element (by value)\n");
    printf("5.  Reverse List\n");
    printf("6.  Sort List\n");
    printf("7.  Delete Alternate Nodes\n");
    printf("8.  Exit\n");
    printf("======================================\n");
    printf("Enter your choice: ");
}

int main() {
    node *head = (node*) malloc(sizeof(node));
    int data[] = {1, 25, 1, 58, 32, 91, 76};
    int n = sizeof(data) / sizeof(data[0]);

    createList(data, n, head);

    int choice, num, position, index;
    int listSorted = 0;  // Flag to track if list is currently sorted

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Current List ---\n");
                traverseList(head);
                break;

            case 2: {
                printf("\nEnter element to insert: ");
                scanf("%d", &num);
                printf("Enter position (-1 for BEFORE, 1 for AFTER): ");
                scanf("%d", &position);
                printf("Enter index (1-based): ");
                scanf("%d", &index);

                if (position != -1 && position != 1) {
                    printf("Invalid position! Use -1 for BEFORE or 1 for AFTER.\n");
                } else {
                    insertElement(head, num, position, index);
                    printf("Element %d inserted at index %d (%s).\n\n", num, index,
                           position == -1 ? "BEFORE" : "AFTER");
                }
                listSorted = 0;
                break;
            }

            case 3: {
                printf("\nEnter element to insert in sorted list: ");
                scanf("%d", &num);
                insertInSortedList(head, num);
                printf("Element %d inserted in sorted order.\n\n", num);
                listSorted = 1;
                break;
            }

            case 4: {
                printf("\nEnter element to delete: ");
                scanf("%d", &num);
                deleteElement(head, num);
                break;
            }

            case 5: {
                reverseList(&head);
                printf("List reversed successfully.\n\n");
                listSorted = 0;
                break;
            }

            case 6: {
                sortList(head);
                printf("List sorted successfully.\n\n");
                listSorted = 1;
                break;
            }

            case 7: {
                deleteAlternateNodes(head);
                printf("Alternate nodes deleted successfully.\n\n");
                listSorted = 0;
                break;
            }

            case 8: {
                printf("\nFreeing memory and exiting...\n");
                freeList(head);
                printf("Program terminated.\n");
                return 0;
            }

            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
