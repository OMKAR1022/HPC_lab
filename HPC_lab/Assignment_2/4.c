#include <stdio.h>

int main() {
    // Declare and initialize an integer array
    int numbers[] = {5, 10, 15, 20, 25};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Determine the number of elements in the array

    // Declare a pointer to int and initialize it to point to the first element of the array
    int *ptr = numbers;

    // Variable to hold the sum of array elements
    int sum = 0;

    // Calculate the sum of array elements using the pointer
    for (int i = 0; i < size; i++) {
        sum += *(ptr + i); // Add each element to the sum
    }

    // Print the result
    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}
