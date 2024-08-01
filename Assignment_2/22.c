#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if at least one command is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command1> [<command2> ... <commandN>]\n", argv[0]);
        return 1;
    }

    // Iterate over each command provided on the command line
    for (int i = 1; i < argc; i++) {
        printf("Executing command: %s\n", argv[i]);
        
        // Execute the command using system()
        int status = system(argv[i]);
        
        // Check if the command was executed successfully
        if (status == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", argv[i]);
            return 1;
        } else {
            // Check the exit status of the command
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Command exited with status: %d\n", exit_status);
            } else if (WIFSIGNALED(status)) {
                int signal_number = WTERMSIG(status);
                printf("Command terminated by signal: %d\n", signal_number);
            }
        }
    }

    return 0;
}
