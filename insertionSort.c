#include <stdio.h>

void insertionSort(int *arr, int size) {
	int hole, value;

	for(int i = 1; i < size; i++) {
		value = arr[i];
		hole = i;

		while(hole > 0 && arr[hole - 1] > value) {
			arr[hole] = arr[hole - 1];
			hole--; 
		}
		arr[hole] = value;
	}
}
int main() {
	int arr[] = {7, 2, 4, 1, 5, 3};

	insertionSort(arr, 6);

	printf("Sorted Array: ");
	for(int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}