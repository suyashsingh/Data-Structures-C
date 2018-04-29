#include <stdio.h>

void selectionSort(int *arr, int size);
int main() {
    int arr[] = {2, 7, 4, 1, 5, 3};
    selectionSort(arr, 6);

    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void selectionSort(int *arr, int size) {
    int minIndex, temp;

    // traverse till the second last element
    // as the last element will get in place
    for(int i = 0; i < size - 1; i++) {
       int minIndex = i;
       for(int j = i + 1; j < size; j++) {
           if(arr[j] < arr[minIndex]) { // arr[j] > arr[minIndex] for decending order
               minIndex = j;
           }
       }

       temp = arr[i];
       arr[i] = arr[minIndex];
       arr[minIndex] = temp;
    }
}
