#include <stdio.h>

int *bubbleSort(int nums[], int len);
int *selectionSort(int nums[], int len);
int *insertionSort(int nums[], int len);

int main(void) {
    int nums[] = {15, 46, 25, 11, 91, 97};
    int len = sizeof(nums) / sizeof(nums[0]);
    int sort;
    int *sortnums;

    printf("Select a sorting technique: ");
    scanf("%d", &sort);

    switch(sort) {
    case 1:
        sortnums = bubbleSort(nums, len);
        break;
    case 2:
        sortnums = selectionSort(nums, len);
        break;
    case 3:
        sortnums = insertionSort(nums, len);
        break;
    default:
        printf("Invalid option");
        break;
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", sortnums[i]);
    }

    return 0;
}

int *bubbleSort(int nums[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return nums;
}

int *selectionSort(int nums[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = min+1; j < len; j++) {
            if (nums[min] > nums[j]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }

    return nums;
}

int *insertionSort(int nums[], int len) {

}
