#include <stdio.h>

// Function prototypes for arithmetic operations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    // Function pointers for arithmetic operations
    int (*operation)(int, int);
    float (*div_operation)(int, int);

    int choice;
    int num1, num2;
    int int_result;
    float float_result;

    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check if user wants to exit
        if (choice == 5) {
            break;
        }

        // Input two integers
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        // Select the function based on the user's choice
        switch (choice) {
            case 1:
                operation = add;
                int_result = operation(num1, num2);
                printf("Result: %d\n", int_result);
                break;

            case 2:
                operation = subtract;
                int_result = operation(num1, num2);
                printf("Result: %d\n", int_result);
                break;

            case 3:
                operation = multiply;
                int_result = operation(num1, num2);
                printf("Result: %d\n", int_result);
                break;

            case 4:
                div_operation = divide;
                // Check for division by zero
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    float_result = div_operation(num1, num2);
                    printf("Result: %.2f\n", float_result);
                }
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}
