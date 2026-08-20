#include <stdio.h>

int *bubbleSort(int nums[], int len);
int binarySearch(int nums[], int len, int k);

int main(void) {
    int nums[] = {15, 46, 25, 11, 91, 97};
    int len = sizeof(nums) / sizeof(nums[0]);
    int k;

    int *sortnums = bubbleSort(nums, len);

    for (int i = 0; i < len; i++) {
        printf("%d\n", sortnums[i]);
    }

    printf("Enter a key: ");
    scanf("%d", &k);

    int pos = binarySearch(sortnums, len, k);

    printf("%d found at %d", k, pos+1);

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

int binarySearch(int nums[], int len, int k) {
    int low = 0;
    int high = len-1;
    int pos = -1;
    while (low <= high) {
        int mid = (low+high)/2;

        if(nums[mid] == k) {
            pos = mid;
            break;
        } else if (k < nums[mid]) {
            high = mid - 1;
        } else if (k > nums[mid]) {
            low = mid + 1;
        }
    }

    return pos;
}
