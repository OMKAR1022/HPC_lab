#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int rank, size;
    char message[50];
    MPI_Init(&argc, &argv);                 // Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get the rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get the total number of processes

    if (rank == 0) {
        // Root process: Receive messages from all other processes
        printf("Root Process (Rank %d): Receiving messages...\n", rank);
        for (int i = 1; i < size; i++) {
            MPI_Recv(message, 50, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Root Process (Rank %d): Received '%s' from Process %d\n", rank, message, i);
        }
    } else {
        // Non-root processes: Send message to the root process
        snprintf(message, 50, "Hello World from Process %d!", rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        printf("Process %d: Sent message to Root Process.\n", rank);
    }

    MPI_Finalize(); // Finalize the MPI environment
    return 0;
}
