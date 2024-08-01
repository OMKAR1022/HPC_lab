#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if exactly one argument is passed
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Get the string from command line argument
    char *str = argv[1];
    int length = strlen(str);

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
