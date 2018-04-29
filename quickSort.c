#include <stdio.h>

void swapArr(int *arr, int index1, int index2);
int partition(int *arr, int start, int end);
void quickSort(int *arr, int start, int end);

int main() {
    int arr[] = {2, 1, 7, 6, 8, 5, 3, 4};
    //int arr[] = {2, 1, 7, 6, 8, 5, 1, 4};

    //swapArr(arr, 0, 4);
    //partition(arr, 0, 7);
    quickSort(arr, 0, 7);
    for(int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

void swapArr(int *arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp; 
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int pIndex = 0;
    
    // Place all the elements lesser than the pivot to the left
    // of pivot index

    for(int i = 0; i < end; i++) {
        if(arr[i] <= pivot) {
            swapArr(arr, i, pIndex);
            pIndex++;
        }
    }

    // Now put the pivot at its place ie at pivot index
    swapArr(arr, pIndex, end);
    return pIndex;
}

void quickSort(int *arr, int start, int end) {
    if(start < end) {
        int pIndex = partition(arr, start, end); // Get the partition index
        quickSort(arr, start, pIndex - 1); // sort the left sub array
        quickSort(arr, pIndex + 1, end); // sort the right sub array
    }
}