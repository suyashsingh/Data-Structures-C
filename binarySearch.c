#include <stdio.h>

int binarySearch(int *arr, int target, int length);

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	
	//printf("Index of 2: %d\n", binarySearch(arr, 2, 5));
	//printf("%d\n", binarySearch(arr, 3, 5));
	//printf("%d\n", binarySearch(arr, 1, 5));
	//printf("%d\n", binarySearch(arr, 5, 5));
	//printf("%d\n", binarySearch(arr, 7, 5));
	//printf("%d\n", binarySearch(arr, -1, 5));

	for(int i = 0; i < 10; i++) {
		printf("index of %d is %d\n", i, binarySearch(arr,i, 5));
	}

	return 0;
}

int binarySearch(int *arr, int target, int length) {
	int minIndex = 0;
	int maxIndex = length - 1;
	int guessIndex;

	//while(maxIndex > minIndex) { // You forgot the condition when maxIndex ==minIndex
	// this is the condition for the worst case in(1,2,3,4,5) and it then went out of the loop
	while(maxIndex >= minIndex) {
		guessIndex = (minIndex + maxIndex) / 2;
		if( *(arr + guessIndex) == target) {
			return guessIndex;
		} else if(*(arr + guessIndex) < target) {
			minIndex = guessIndex + 1;
		} else {
			maxIndex = guessIndex - 1;
		}

		//printf("Debug min = %d, max = %d\n", minIndex, maxIndex);
		//return -1; // You placed return within the loop so it always returned -1

	}
	
	return -1; // Element not found
}
