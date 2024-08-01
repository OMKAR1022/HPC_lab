#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid integer
int isInteger(const char *str) {
    // Check if the string is empty
    if (*str == '\0') {
        return 0;
    }

    // Check if the string is negative
    if (*str == '-') {
        str++;
    }

    // Check if all characters are digits
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    
    return 1;
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct (including program name)
    if (argc < 2) {
        printf("Error: No arguments provided.\n");
        printf("Usage: %s <integer1> <integer2> ...\n", argv[0]);
        return 1;
    }

    // Validate each argument
    for (int i = 1; i < argc; i++) {
        if (!isInteger(argv[i])) {
            printf("Error: Argument '%s' is not a valid integer.\n", argv[i]);
            return 1;
        }
    }

    // If all arguments are valid integers
    printf("All arguments are valid integers.\n");

    return 0;
}
