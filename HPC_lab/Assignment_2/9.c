#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    int *array;     // Pointer to int, for dynamic array
    int size;       // Number of elements in the array

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    // Initialize the array with values
    printf("Enter %d integer values:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Print the array
    printf("The elements of the array are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
