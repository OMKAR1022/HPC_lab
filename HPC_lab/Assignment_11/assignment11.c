#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, size;
    long N = 10000; // Define N
    long local_sum = 0, total_sum = 0; // Variables for local and total sum
    long start, end, chunk_size;

    MPI_Init(&argc, &argv);                 // Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get the rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get the total number of processes

    // Divide the range among processes
    chunk_size = N / size;
    start = rank * chunk_size + 1;
    end = (rank == size - 1) ? N : start + chunk_size - 1;

    // Each process calculates its local sum
    for (long i = start; i <= end; i++) {
        local_sum += i;
    }

    // Reduce all local sums to the total sum in the root process
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result in the root process
    if (rank == 0) {
        printf("The sum of the first %ld integers is: %ld\n", N, total_sum);
    }

    MPI_Finalize(); // Finalize the MPI environment
    return 0;
}
