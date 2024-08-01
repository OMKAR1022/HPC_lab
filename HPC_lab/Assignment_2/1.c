#include <stdio.h>

int main() {
    // Declare an integer variable and assign it a value
    int number = 42;
    
    // Declare a pointer variable and assign it the address of the integer variable
    int *ptr = &number;
    
    // Print the value of the integer variable
    printf("Value of number: %d\n", number);
    
    // Print the address of the integer variable using the pointer
    printf("Address of number: %p\n", (void *)ptr);
    
    return 0;
}
