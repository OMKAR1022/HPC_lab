#include <stdio.h>

extern char **environ;  // Declare the environ variable

int main() {
    char **env = environ;  // Pointer to environment variables

    // Iterate through the environment variables and print them
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
