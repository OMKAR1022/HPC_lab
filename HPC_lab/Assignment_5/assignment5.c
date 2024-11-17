#include <stdio.h>
#include <omp.h>

int main() {
    int val = 1234; // Initialize the variable
    printf("Initial value of val outside the parallel region: %d\n", val);

    // Initialize OpenMP with 4 threads
    omp_set_num_threads(4);

    // Parallel region with firstprivate clause
    #pragma omp parallel firstprivate(val)
    {
        int thread_id = omp_get_thread_num(); // Get thread ID
        printf("Thread %d - Initial value of val: %d\n", thread_id, val);
        val += 1; // Increment val by 1
        printf("Thread %d - Updated value of val: %d\n", thread_id, val);
    }

    // Print final value of val outside the parallel region
    printf("Final value of val outside the parallel region: %d\n", val);

    return 0;
}
