#include <stdio.h>

// Function that adds two integers
int add(int a, int b) {
    return a + b;
}

int main() {
    // Define a function pointer and assign it to the add function
    int (*func_ptr)(int, int) = add;
    
    int num1, num2, result;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Use the function pointer to call the add function
    result = func_ptr(num1, num2);

    // Output the result
    printf("The sum of %d and %d is %d\n", num1, num2, result);

    return 0;
}

