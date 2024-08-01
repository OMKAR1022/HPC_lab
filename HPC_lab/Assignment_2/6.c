#include <stdio.h>

void findMinMax(int *arr, int size, int *min, int *max) {
    // Initialize min and max with the first element of the array
    *min = *max = *arr;
    
    // Traverse the array to find the min and max values
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
    }
}

int main() {
    // Declare and initialize an integer array
    int numbers[] = {34, 7, 23, 32, 5, 62, 32};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Determine the number of elements in the array
    int min, max;

    // Find the minimum and maximum values
    findMinMax(numbers, size, &min, &max);

    // Print the results
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Smallest element: %d\n", min);
    printf("Largest element: %d\n", max);

    return 0;
}
