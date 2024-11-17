#include <stdio.h>
#include <omp.h>

int main() {
    int val = 100; // Initialize the variable
    printf("Initial value of val outside the parallel region: %d\n", val);

    // Initialize OpenMP with 4 threads
    omp_set_num_threads(4);

    // Parallel region with private clause
    #pragma omp parallel private(val)
    {
        int thread_id = omp_get_thread_num(); // Get thread ID
        val = thread_id * 10; // Each thread initializes its own val
        printf("Thread %d - Value of val after initialization: %d\n", thread_id, val);

        val += 5; // Modify the private copy of val
        printf("Thread %d - Value of val after modification: %d\n", thread_id, val);
    }

    // Print final value of val outside the parallel region
    printf("Final value of val outside the parallel region: %d\n", val);

    return 0;
}
