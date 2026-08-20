#include <stdio.h>
#include <stdlib.h>

int smallest(int* arr, int n);

int main() {
    int n;

    printf("Enter the no of elements: ");
    scanf("%d", &n);

    int* arr = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int min = smallest(arr, n);
    printf("%d is the minimum.", min);

    free(arr);
}

int smallest(int* arr, int n) {
    int min = *arr;
    for (int i = 0; i < n; i++) {
        if (*(arr+i) < min) {
            min = *(arr+i);
        }
    }

    return min;
}
