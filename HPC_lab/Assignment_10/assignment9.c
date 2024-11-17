#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, size;
    int numbers[2]; // Array to hold two numbers
    int received_numbers[2]; // Array to receive numbers from other processes

    MPI_Init(&argc, &argv);                 // Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get the rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get the total number of processes

    // Assign two numbers to each process
    numbers[0] = rank * 10 + 1; // First number
    numbers[1] = rank * 10 + 2; // Second number

    if (rank == 0) {
        // Root process: Receive numbers from all other processes
        printf("Root Process (Rank %d): Receiving numbers...\n", rank);

        // Print its own numbers
        printf("Root Process (Rank %d): Numbers [%d, %d]\n", rank, numbers[0], numbers[1]);

        for (int i = 1; i < size; i++) {
            MPI_Recv(received_numbers, 2, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Root Process (Rank %d): Received numbers [%d, %d] from Process %d\n", 
                   rank, received_numbers[0], received_numbers[1], i);
        }
    } else {
        // Non-root processes: Send their numbers to the root process
        MPI_Send(numbers, 2, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process %d: Sent numbers [%d, %d] to Root Process.\n", rank, numbers[0], numbers[1]);
    }

    MPI_Finalize(); // Finalize the MPI environment
    return 0;
}
