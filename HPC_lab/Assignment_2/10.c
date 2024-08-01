#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strlen

int main() {
    char *str;      // Pointer to char for dynamic string
    int length;     // Length of the string

    // Ask the user for the maximum length of the string (excluding the null terminator)
    printf("Enter the maximum length of the string: ");
    scanf("%d", &length);

    // Allocate memory for the string (+1 for the null terminator)
    str = (char *)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    // Clear the input buffer
    getchar(); // To consume the newline character left in the buffer by scanf

    // Ask the user to input the string
    printf("Enter the string (up to %d characters): ", length);
    fgets(str, length + 1, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Print the string
    printf("The entered string is: %s\n", str);

    // Free the allocated memory
    free(str);

    return 0;
}
