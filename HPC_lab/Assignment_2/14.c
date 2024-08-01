#include <stdio.h>

int main(int argc, char *argv[]) {
    // Loop through each command-line argument and print it
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
