#include <iostream>
#include <cuda_runtime.h>

#define N 1024 // Define the size of the matrices (N x N)

// CUDA kernel to perform matrix addition
__global__ void matrixAdd(int *A, int *B, int *C, int width) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int idy = threadIdx.y + blockIdx.y * blockDim.y;
    if (idx < width && idy < width) {
        int index = idy * width + idx;
        C[index] = A[index] + B[index];
    }
}

int main() {
    int *A, *B, *C, *D;
    int *d_A, *d_B, *d_C, *d_D;

    // Allocate memory for matrices on the host
    A = new int[N * N];
    B = new int[N * N];
    C = new int[N * N];
    D = new int[N * N];

    // Initialize matrices A and B with random values
    for (int i = 0; i < N * N; ++i) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Allocate memory for matrices on the device
    cudaMalloc((void**)&d_A, N * N * sizeof(int));
    cudaMalloc((void**)&d_B, N * N * sizeof(int));
    cudaMalloc((void**)&d_C, N * N * sizeof(int));
    cudaMalloc((void**)&d_D, N * N * sizeof(int));

    // Copy matrices A and B from host to device
    cudaMemcpy(d_A, A, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * N * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block sizes
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (N + 15) / 16);

    // Perform the first matrix addition C = A + B
    matrixAdd<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Perform the second matrix addition D = C + B
    matrixAdd<<<numBlocks, threadsPerBlock>>>(d_C, d_B, d_D, N);

    // Copy result matrix D back to host
    cudaMemcpy(D, d_D, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    // Print a small portion of the result matrix D (optional)
    std::cout << "Result of the second matrix addition (C + B):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << D[i * N + j] << " ";
        }
        std::cout << std::endl;
    }

    // Free allocated memory
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    cudaFree(d_D);

    return 0;
}
