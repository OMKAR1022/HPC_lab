#include <stdio.h>

int main() {
    // Declare and initialize an integer array
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Determine the number of elements in the array

    // Declare a pointer to int and initialize it to point to the first element of the array
    int *ptr = numbers;

    // Print each element of the array using the pointer
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(ptr + i)); // Access array elements using pointer arithmetic
    }

    return 0;
}
