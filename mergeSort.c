#include <stdio.h>

void merge(int *left, int *right, int *arr, int leftSize, int rightSize);
void mergeSort(int *arr, int n);

int main() {
    //int arr[8] = {2, 4, 1, 6, 8, 5, 3, 7};
    int arr[] = {88, 1, -1, 100, 4, 2};
    mergeSort(arr, 6);
    //mergeSort(arr, 8);


    for(int i = 0; i < 6; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

void merge(int *left, int *right, int *arr, int leftSize, int rightSize) {
    int nl = leftSize;
    int rl = rightSize;

    int i, j, k;
    // Initialize the array indices
    i = j = k = 0;

    // insert in main array in sorted order
    while(i < nl && j < rl) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            k++;
            i++;
        } else {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    // insert left overs of right and left sub array
    while(i < nl) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < rl) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int n) {
    // Check for base condition
    if(n < 2) {
        return;
    }
    
    // calculate mid
    int mid = n / 2;

    // calculate size of sub arrays
    int leftSize = mid;
    int rightSize = n - mid;

    int left[leftSize];
    int right[rightSize];

    // Populate the sub array
    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for(int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, leftSize);
    mergeSort(right, rightSize);
    merge(left, right, arr, leftSize, rightSize);
}
