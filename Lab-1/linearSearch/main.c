#include <stdio.h>

int main() {
    int key = 0, n = 0, pos = 0;
    int arr[100];

    printf("Enter the size of arr: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the key: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }

    printf("Key %d found at index %d", key, pos);
}
