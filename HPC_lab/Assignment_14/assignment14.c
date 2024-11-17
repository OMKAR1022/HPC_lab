#include <iostream>
#include <cuda_runtime.h>

#define N 1024  // Define the size of the matrices (N x N)

// CUDA kernel to perform matrix multiplication
__global__ void matrixMultiply(int *A, int *B, int *C, int width) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int idy = threadIdx.y + blockIdx.y * blockDim.y;

    int sum = 0;
    if (idx < width && idy < width) {
        // Perform the matrix multiplication C = A * B
        for (int k = 0; k < width; k++) {
            sum += A[idy * width + k] * B[k * width + idx];
        }
        C[idy * width + idx] = sum;
    }
}

int main() {
    int *A, *B, *C, *D, *E;
    int *d_A, *d_B, *d_C, *d_D, *d_E;

    // Allocate memory for matrices on the host
    A = new int[N * N];
    B = new int[N * N];
    C = new int[N * N];
    D = new int[N * N];
    E = new int[N * N];

    // Initialize matrices A, B, and D with random values
    for (int i = 0; i < N * N; ++i) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
        D[i] = rand() % 100;
    }

    // Allocate memory for matrices on the device
    cudaMalloc((void**)&d_A, N * N * sizeof(int));
    cudaMalloc((void**)&d_B, N * N * sizeof(int));
    cudaMalloc((void**)&d_C, N * N * sizeof(int));
    cudaMalloc((void**)&d_D, N * N * sizeof(int));
    cudaMalloc((void**)&d_E, N * N * sizeof(int));

    // Copy matrices A, B, and D from host to device
    cudaMemcpy(d_A, A, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_D, D, N * N * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block sizes
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (N + 15) / 16);

    // Perform the first matrix multiplication C = A * B
    matrixMultiply<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Perform the second matrix multiplication E = C * D
    matrixMultiply<<<numBlocks, threadsPerBlock>>>(d_C, d_D, d_E, N);

    // Copy result matrix E back to host
    cudaMemcpy(E, d_E, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    // Print a small portion of the result matrix E (optional)
    std::cout << "Result of the second matrix multiplication (C * D):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << E[i * N + j] << " ";
        }
        std::cout << std::endl;
    }

    // Free allocated memory
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    cudaFree(d_D);
    cudaFree(d_E);

    return 0;
}
