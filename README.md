# ParallelComputing

OpenACC
what we did:
cd openacc
make
./StreamTriad_kern1

and we get this

Average runtime for stream triad loop is 0.058473 secs

Explanation
The code compiled successfully, but GCC on the local workstation only supports OpenACC on the CPU.


OpenCL 
what we did

cd ocl
make
./StreamTriad

what we get

Warning: Device of requested type not found in clGetDeviceID call
clCreateProgramWithSource returned an error -34
Not supporting anything other than AMD or NVIDIA at the moment


The system does not have an OpenCL-compatible GPU device (NVIDIA/AMD) the OpenCL runtime cannot create a device, context, or kernel.


OpenMP 

Initial build:

make

I get this errors
Error
cc: error: unrecognized command-line option ‘-qthreaded’
Then:
make CC=nvcc
Error
nvcc: command not found

Then I instal toolkit
After installing CUDA toolkit:

sudo apt install nvidia-cuda-toolkit
make CC=nvcc
Successful build and run

./StreamTriad
Average runtime for stream triad loop is 0.061263 msecs

Explanation
The OpenMP Makefile contained compiler flags meant for commercial compilers (PGI/IBM).
GCC does not support these options.
After CUDA installation, nvcc could compile the code, but OpenMP offloading still runs only on CPU, because GPU-offload-enabled GCC or Clang was not available on the workstation.



OpenACC on GPU Server

Execution Results

Program	Runtime
StreamTriad	0.022310 sec
StreamTriad_kern1	2.236922 sec
StreamTriad_kern2	0.051985 sec
StreamTriad_kern3	0.001192 sec
StreamTriad_par1	0.052199 sec
StreamTriad_par2	0.001192 sec
StreamTriad_par3	0.001192 sec
StreamTriad_par4	0.001191 sec

Explanation
The lab server contains an NVIDIA GPU and the NVHPC / PGI OpenACC compiler.
This machine supports full OpenACC GPU acceleration.

StreamTriad_kern1
2.236922 sec
Reason:
kern1 performs the STREAM Triad operation with no optimized data regions, meaning:
Data is copied to the GPU every iteration
Data is copied back from the GPU every iteration
The kernel is extremely small compared to the cost of memory transfer. tis results in the GPU spending almost all its time on data movement, not computation.

StreamTriad_par4
0.00119 sec
Reason:
These versions use fully optimized OpenACC GPU regions, typically combining:
Persistent data regions (acc data copyin/copyout)
Efficient memory access patterns, parallel loop or kernels constructs allowing full GPU parallelization
Minimal data transfers: data is moved to the GPU once, computed in parallel, and returned once


Portability Summary 
CUDA -	Low	NVIDIA-only; fails without proper runtime and drivers
OpenCL -	Medium	Works on many devices, but only when drivers expose a GPU platform
OpenMP  - Medium-Low	Depends heavily on compiler implementation and GPU backend availability
OpenACC	- High (source level)	Code portable, but performance depends on compiler GPU support (GCC CPU-only vs NVHPC GPU)

Conclusion
Only the GPU server provided full hardware acceleration.
OpenACC offered the best performance portability when a GPU-enabled compiler was available. 



TERMINAL CODE:

student@itcenter-lab128:~$ cd ~/Parallel-Programing-assignments
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd cuda
student@itcenter-lab128:~/Parallel-Programing-assignments/cuda$ make
make: Nothing to be done for 'all'.
student@itcenter-lab128:~/Parallel-Programing-assignments/cuda$ ./StreamTriad
./StreamTriad: error while loading shared libraries: libcudart.so.11.0: cannot open shared object file: No such file or directory
student@itcenter-lab128:~/Parallel-Programing-assignments/cuda$ cd ..
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd ocl
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ make
make: Nothing to be done for 'all'.
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ ./StreamTriad_simple
bash: ./StreamTriad_simple: No such file or directory
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ cd ..
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd omp
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ make
cc -qthreaded -g -O3 -std=gnu99 -fstrict-aliasing -fopenmp -foffload=nvptx-none -foffload=-lm -fopt-info-omp -c StreamTriad.c
cc: error: unrecognized command-line option ‘-qthreaded’; did you mean ‘-pthread’?
make: *** [Makefile:8: StreamTriad.o] Error 1
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ ./StreamTriad_par1 
bash: ./StreamTriad_par1: No such file or directory
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ cd..
cd..: command not found 
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ cd ..
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd opemacc
bash: cd: opemacc: No such file or directory
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd openacc
student@itcenter-lab128:~/Parallel-Programing-assignments/openacc$ make
make: Nothing to be done for 'default'.
student@itcenter-lab128:~/Parallel-Programing-assignments/openacc$ ./StreamTriad_kern1 
Average runtime for stream triad loop is 0.058473 secs
student@itcenter-lab128:~/Parallel-Programing-assignments/openacc$ cd ..
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd ocl
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ make
make: Nothing to be done for 'all'.
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ ls
embed_source.pl  Makefile               StreamTriad_kernel.inc  timer.h
ezcl_lite.c      StreamTriad            StreamTriad.o           timer.o
ezcl_lite.h      StreamTriad.c          StreamTriad_simple.c
ezcl_lite.o      StreamTriad_kernel.cl  timer.c
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ ./StreamTriad 
Warning: Device of requested type not found in clGetDeviceID call
EZCL_CREATE_PROGRAM_WSOURCE: clCreateProgramWithSource returned an error -34 in file StreamTriad.c at line 36
Invalid context in clCreatProgramWithSource
EZCL_CREATE_KERNEL: Not supporting anything other than AMD or NVIDIA at the moment
student@itcenter-lab128:~/Parallel-Programing-assignments/ocl$ cd ..
student@itcenter-lab128:~/Parallel-Programing-assignments$ cd omp
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ make
cc -qthreaded -g -O3 -std=gnu99 -fstrict-aliasing -fopenmp -foffload=nvptx-none -foffload=-lm -fopt-info-omp -c StreamTriad.c
cc: error: unrecognized command-line option ‘-qthreaded’; did you mean ‘-pthread’?
make: *** [Makefile:8: StreamTriad.o] Error 1
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ make CC=nvcc
nvcc -g -O3  -c StreamTriad.c
make: nvcc: No such file or directory
make: *** [Makefile:7: StreamTriad.o] Error 127
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ nvcc --version
Command 'nvcc' not found, but can be installed with:
sudo apt install nvidia-cuda-toolkit
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ sudo apt install nvidia-cuda-toolkit
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done

student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ make CC=nvcc
nvcc -g -O3  -c StreamTriad.c
nvcc -g -O3  StreamTriad.o timer.o -o StreamTriad
nvcc -g -O3  -c StreamTriad_par1.c
nvcc -g -O3  StreamTriad_par1.o timer.o -o StreamTriad_par1
nvcc -g -O3  -c StreamTriad_par2.c
nvcc -g -O3  StreamTriad_par2.o timer.o -o StreamTriad_par2
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ make
make: Nothing to be done for 'default'.
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ ls
Makefile             StreamTriad_par1    StreamTriad_par3.c  StreamTriad_par8.c
Makefile.simple.gcc  StreamTriad_par1.c  StreamTriad_par3.o  StreamTriad_par8.o
ShallowWater_par1.c  StreamTriad_par1.o  StreamTriad_par4.c  timer.c
StreamTriad          StreamTriad_par2    StreamTriad_par5.c  timer.h
StreamTriad.c        StreamTriad_par2.c  StreamTriad_par6.c  timer.o
StreamTriad.o        StreamTriad_par2.o  StreamTriad_par7.c
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ ./StreamTriad
Average runtime for stream triad loop is 0.061263 msecs
student@itcenter-lab128:~/Parallel-Programing-assignments/omp$ ssh gpulab@10.1.8.100
gpulab@10.1.8.100's password: 
Welcome to Ubuntu 22.04.5 LTS (GNU/Linux 6.8.0-87-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/pro

Expanded Security Maintenance for Applications is not enabled.

0 updates can be applied immediately.

25 additional security updates can be applied with ESM Apps.
Learn more about enabling ESM Apps service at https://ubuntu.com/esm

New release '24.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

*** System restart required ***
Last login: Thu Dec 11 15:53:34 2025 from 10.1.50.30
gpulab@nanda-B560M-DS3H-V2:~$ cd ~/Parallel-Programing-assignments/cuda
-bash: cd: /home/gpulab/Parallel-Programing-assignments/cuda: No such file or directory
gpulab@nanda-B560M-DS3H-V2:~$ cd ~/Parallel-Programing-assignments
-bash: cd: /home/gpulab/Parallel-Programing-assignments: No such file or directory
gpulab@nanda-B560M-DS3H-V2:~$ cd cuda
-bash: cd: cuda: No such file or directory
gpulab@nanda-B560M-DS3H-V2:~$ cd /opt/openacc/
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ls
Makefile             StreamTriad_kern2.o  StreamTriad_par2.o
MakefilePGI          StreamTriad_kern3    StreamTriad_par3
Makefile.simple.gcc  StreamTriad_kern3.c  StreamTriad_par3.c
StreamTriad          StreamTriad_kern3.o  StreamTriad_par3.o
StreamTriad.c        StreamTriad.o        StreamTriad_par4
StreamTriad_kern1    StreamTriad_par1     StreamTriad_par4.c
StreamTriad_kern1.c  StreamTriad_par1.c   StreamTriad_par4.o
StreamTriad_kern1.o  StreamTriad_par1.o   timer.c
StreamTriad_kern2    StreamTriad_par2     timer.h
StreamTriad_kern2.c  StreamTriad_par2.c   timer.o
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad
Average runtime for stream triad loop is 0.022310 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_kern1

Average runtime for stream triad loop is 2.236922 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ 
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_kern2
Average runtime for stream triad loop is 0.051985 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_kern3
Average runtime for stream triad loop is 0.001192 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_part1
-bash: ./StreamTriad_part1: No such file or directory
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_par1
Average runtime for stream triad loop is 0.052199 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_par2
Average runtime for stream triad loop is 0.001192 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_par3
Average runtime for stream triad loop is 0.001192 secs
gpulab@nanda-B560M-DS3H-V2:/opt/openacc$ ./StreamTriad_par4
Average runtime for stream triad loop is 0.001191 secs
