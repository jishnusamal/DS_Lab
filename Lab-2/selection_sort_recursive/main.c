#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of minimum element from start to end
int findMin(int* arr, int start, int end) {
    if (start == end)
        return start;

    int minIdx = findMin(arr, start + 1, end);

    // Compare and return minimum index
    if (*(arr + start) < *(arr + minIdx))
        return start;
    else
        return minIdx;
}

// Recursive Selection Sort function
void selectionSortRecursive(int* arr, int n, int index) {
    // Base case: if index reaches n-1, array is sorted
    if (index == n - 1)
        return;

    // Find minimum element from index to n-1
    int minIdx = findMin(arr, index, n - 1);

    // Swap minimum element with current index
    if (minIdx != index)
        swap((arr + index), (arr + minIdx));

    // Recursively sort remaining array
    selectionSortRecursive(arr, n, index + 1);
}

// Function to read array from user
void readArray(int* arr, int n) {
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", (arr + i));
    }
}

// Function to display array using pointers
void displayArray(int* arr, int n) {
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}


int main() {
    int n;

    printf("=== Recursive Selection Sort Using Pointers ===\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input! Number of elements must be positive.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    readArray(arr, n);

    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    selectionSortRecursive(arr, n, 0);
    displayArray(arr, n);
    free(arr);

    return 0;
}
