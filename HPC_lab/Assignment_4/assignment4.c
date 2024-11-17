#include <stdio.h>
#include <omp.h>

int main() {
    // Set the number of threads to 4
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); // Get thread ID
        printf("My name is Omkar from thread %d\n", thread_id);
    }
    return 0;
}
