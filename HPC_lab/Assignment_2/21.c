#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ENV_VAR_NAME>\n", argv[0]);
        return 1;
    }

    // Get the environment variable name from command line argument
    const char *env_var_name = argv[1];
    
    // Get the value of the environment variable
    const char *env_var_value = getenv(env_var_name);
    
    // Print the value or an error message if the variable is not set
    if (env_var_value) {
        printf("%s=%s\n", env_var_name, env_var_value);
    } else {
        printf("Environment variable %s is not set.\n", env_var_name);
    }
    
    return 0;
}
