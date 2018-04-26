/*
	Linear Search on Array of integers.

	int linearSearch() - Returns index of the target if found, -1 otherwise.
*/

#include <stdio.h>
#define SIZE 5

int linearSearch(int *arr, int target, int size);

int main() {
	int arr[SIZE] = {1, 2, 3, 4, 5};
	printf("Index of 5: %d\n", linearSearch(arr, 5,SIZE));
	printf("Index of 6: %d\n", linearSearch(arr, 6, SIZE));
	return 0;
}

int linearSearch(int *arr, int target, int size) {
	for(int i = 0; i < size; i++) {
		// Element Found
		if(*(arr + i) == target) {
			return i;
		}
	}

	//Element not found
	return -1;
}