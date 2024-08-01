#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if at least one integer is passed
    if (argc < 2) {
        printf("Usage: %s <integer1> <integer2> ... <integerN>\n", argv[0]);
        return 1;
    }

    // Initialize sum and count variables
    int sum = 0;
    int count = 0;

    // Iterate through each command-line argument
    for (int i = 1; i < argc; i++) {
        char *endptr;
        // Convert the argument to an integer
        int num = strtol(argv[i], &endptr, 10);
        
        // Check if the conversion was successful
        if (*endptr != '\0') {
            printf("Invalid integer: %s\n", argv[i]);
            return 1;
        }
        
        // Add the number to the sum
        sum += num;
        count++;
    }

    // Calculate the average
    double average = (double)sum / count;

    // Print the average
    printf("Average: %.2f\n", average);

    return 0;
}
