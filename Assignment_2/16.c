#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if at least one argument is passed
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    // Calculate the total length needed for the concatenated string
    int total_length = 0;
    for (int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]);
    }
    
    // Allocate memory for the concatenated string (+1 for null terminator)
    char *concat_str = (char *)malloc((total_length + 1) * sizeof(char));
    if (concat_str == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Initialize the concatenated string
    concat_str[0] = '\0';

    // Concatenate all strings
    for (int i = 1; i < argc; i++) {
        strcat(concat_str, argv[i]);
    }

    // Print the concatenated string
    printf("Concatenated string: %s\n", concat_str);

    // Free the allocated memory
    free(concat_str);

    return 0;
}
