#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp;
    temp = *a; // Save the value at address a
    *a = *b;   // Put the value at address b into address a
    *b = temp; // Put the saved value into address b
}

int main() {
    int x, y;
    
    // Read two integers from the user
    printf("Enter the first integer: ");
    scanf("%d", &x);
    printf("Enter the second integer: ");
    scanf("%d", &y);
    
    // Print the values before swapping
    printf("Before swapping:\n");
    printf("x = %d, y = %d\n", x, y);
    
    // Call the swap function
    swap(&x, &y);
    
    // Print the values after swapping
    printf("After swapping:\n");
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}
