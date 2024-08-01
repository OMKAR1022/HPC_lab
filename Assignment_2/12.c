#include <stdio.h>

int main(int argc, char *argv[]) {
    // Iterate through each command-line argument
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
