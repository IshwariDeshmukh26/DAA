#include <iostream>
using namespace std;

void moveZeroesToEnd(int arr[], int start, int end) {
    if (start >= end) return;


    int mid = (start + end) / 2;

    // Conquer: Recursively move zeroes in the left and right halves
    moveZeroesToEnd(arr, start, mid);
    moveZeroesToEnd(arr, mid + 1, end);

    // Combine: Merge the two halves
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    // Copy non-zero elements from left half
    while (i <= mid) {
        if (arr[i] != 0) {
            temp[k++] = arr[i];
        }
        i++;
    }

    // Copy non-zero elements from right half
    while (j <= end) {
        if (arr[j] != 0) {
            temp[k++] = arr[j];
        }
        j++;
    }

    // Fill the remaining positions with zeroes
    while (k < (end - start + 1)) {
        temp[k++] = 0;
    }

    // Copy the merged elements back to the original array
    for (i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, 0, n - 1);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
