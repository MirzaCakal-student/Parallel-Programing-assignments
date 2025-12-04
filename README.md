# ParallelComputing

GPU Architectures & Parallel Programming
CPU Benchmark (OpenMP)

Run command:
./omp-stream

| Kernel | Bandwidth (MB/s) |
| ------ | ---------------- |
| Copy   | 9196             |
| Mul    | 9209             |
| Add    | 10263            |
| Triad  | 10235            |
| Dot    | 14061            |

iGPU Benchmark (OpenCL)

Run command:
./ocl-stream

Error:
terminate called after throwing an instance of 'std::runtime_error'
what(): Invalid device index
Aborted (core dumped)


the program tried to access a non-existent device index.


GPU Benchmark (CUDA) – Lab Server
./cuda-stream

| Kernel | Bandwidth (MB/s) |
| ------ | ---------------- |
| Copy   | 396054           |
| Mul    | 394258           |
| Add    | 404005           |
| Triad  | 403993           |
| Dot    | 419292           |

Thread config:136 blocks × 1024 threads = 139,264 threads


Comparison

| Kernel | CPU (MB/s) | GPU (MB/s) | GPU vs CPU |
| ------ | ---------- | ---------- | ---------- |
| Copy   | 9196       | 396054     | ~43×       |
| Mul    | 9209       | 394258     | ~43×       |
| Add    | 10263      | 404005     | ~39×       |
| Triad  | 10235      | 403993     | ~39×       |
| Dot    | 14061      | 419292     | ~30×       |

GPU outperforms CPU significantly for memory-bound operations. iGPU (if configured correctly) would perform between CPU and dGPU.


CPU – limited by DDR4 memory, fine for small tasks.
iGPU (OpenCL) – potential improvement over CPU, needs correct device setup.
dGPU (CUDA) – superior for all memory-intensive tasks, thanks to massive parallelism and high-speed memory.

U

