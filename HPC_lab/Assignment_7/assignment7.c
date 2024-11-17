#include <stdio.h>
#include <omp.h>

int main() {
    int num_iterations = 16; // Total number of iterations
    int chunk = 4;           // Number of iterations in each chunk

    // Set the number of threads to 4
    omp_set_num_threads(4);

    printf("Static scheduling with chunk size: %d\n", chunk);

    // Parallel for loop with static scheduling
    #pragma omp parallel for schedule(static, chunk)
    for (int i = 0; i < num_iterations; i++) {
        int thread_id = omp_get_thread_num(); // Get thread ID
        printf("Thread %d is processing iteration %d\n", thread_id, i);
    }

    return 0;
}
