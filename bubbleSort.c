#include <stdio.h>

/* Bubble Sort Function */
void bubbleSort(int *arr, int size);

int main() {
	int arr[] = {5, 2, 4, 1, 3};

	bubbleSort(arr, 5);

	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}

/* Bubble Sort Function */
void bubbleSort(int *arr, int size) {
	int temp;
	for(int i = size - 1; i >= 0; i--) {
		for(int j = 0; j < i;j++) {

			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
