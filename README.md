# Parallel-Programing-assignments


In this assignment we show results and explanations for openMP stencil cpmputation.
I tested 3 codes/algorithams
- stencil_opt2 (baseline version)
- stencil_opt4 (optimized version)
- stencil_opt6 (high-level optimized version)

Here is code from my terminal:
mirza@Mirza:~$ cd ~/Parallel-Programing-assignments/Example_06
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$ make clean
Cleaning up...
rm -f stencil_opt2 stencil_opt4 stencil_opt6 timer.o malloc2D.o
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$ make
Compiling timer...
gcc -fopenmp -Wall -std=c11 -march=native -O3 -c timer.c -o timer.o
Compiling malloc2D...
gcc -fopenmp -Wall -std=c11 -march=native -O3 -c malloc2D.c -o malloc2D.o
Building stencil_opt2...
gcc -fopenmp -Wall -std=c11 -march=native -O3 stencil_opt2.c timer.o malloc2D.o -o stencil_opt2 -lm
stencil_opt2.c: In function ‘main’:
stencil_opt2.c:44:15: warning: ‘init_time’ is used uninitialized [-Wuninitialized]
   44 |     init_time += cpu_timer_stop(tstart_init);
      |               ^~
stencil_opt2.c:20:12: note: ‘init_time’ was declared here
   20 |     double init_time, flush_time, stencil_time, total_time;
      |            ^~~~~~~~~
stencil_opt2.c:65:16: warning: ‘total_time’ is used uninitialized [-Wuninitialized]
   65 |     total_time += cpu_timer_stop(tstart_total);
      |                ^~
stencil_opt2.c:20:49: note: ‘total_time’ was declared here
   20 |     double init_time, flush_time, stencil_time, total_time;
      |                                                 ^~~~~~~~~~
stencil_opt2.c:52:20: warning: ‘flush_time’ is used uninitialized [-Wuninitialized]
   52 |         flush_time += cpu_timer_stop(tstart_flush);
      |                    ^~
stencil_opt2.c:20:23: note: ‘flush_time’ was declared here
   20 |     double init_time, flush_time, stencil_time, total_time;
      |                       ^~~~~~~~~~
stencil_opt2.c:60:22: warning: ‘stencil_time’ is used uninitialized [-Wuninitialized]
   60 |         stencil_time += cpu_timer_stop(tstart_stencil);
      |                      ^~
stencil_opt2.c:20:35: note: ‘stencil_time’ was declared here
   20 |     double init_time, flush_time, stencil_time, total_time;
      |                                   ^~~~~~~~~~~~
Building stencil_opt4...
gcc -fopenmp -Wall -std=c11 -march=native -O3 stencil_opt4.c timer.o malloc2D.o -o stencil_opt4 -lm
stencil_opt4.c: In function ‘main’:
stencil_opt4.c:40:14: warning: ‘init_time’ is used uninitialized [-Wuninitialized]
   40 |    init_time += cpu_timer_stop(tstart_init);
      |              ^~
stencil_opt4.c:16:11: note: ‘init_time’ was declared here
   16 |    double init_time, flush_time, stencil_time, total_time;
      |           ^~~~~~~~~
stencil_opt4.c:70:15: warning: ‘total_time’ is used uninitialized [-Wuninitialized]
   70 |    total_time += cpu_timer_stop(tstart_total);
      |               ^~
stencil_opt4.c:16:48: note: ‘total_time’ was declared here
   16 |    double init_time, flush_time, stencil_time, total_time;
      |                                                ^~~~~~~~~~
Building stencil_opt6...
gcc -fopenmp -Wall -std=c11 -march=native -O3 stencil_opt6.c timer.o malloc2D.o -o stencil_opt6 -lm
stencil_opt6.c: In function ‘main’:
stencil_opt6.c:87:15: warning: ‘total_time’ is used uninitialized [-Wuninitialized]
   87 |    total_time += cpu_timer_stop(tstart_total);
      |               ^~
stencil_opt6.c:19:48: note: ‘total_time’ was declared here
   19 |    double init_time, flush_time, stencil_time, total_time;
      |                                                ^~~~~~~~~~
All stencil executables built successfully!
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$ make run-opt2
./stencil_opt2
Running with 4 thread(s)
Iter 0
Iter 1000
Iter 2000
Iter 3000
Iter 4000
Iter 5000
Iter 6000
Iter 7000
Iter 8000
Iter 9000
Timing is init 0.017124 flush 49.114242 stencil 38.226055 total 87.360458
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$ make run-opt4
./stencil_opt4
Running with 4 thread(s)
Iter 0
Iter 1000
Iter 2000
Iter 3000
Iter 4000
Iter 5000
Iter 6000
Iter 7000
Iter 8000
Iter 9000
Timing is init 0.013963 flush 45.759116 stencil 35.840739 total 81.617311
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$ make run-opt6
./stencil_opt6
Running with 4 thread(s)
Iter 0
Iter 1000
Iter 2000
Iter 3000
Iter 4000
Iter 5000
Iter 6000
Iter 7000
Iter 8000
Iter 9000
Timing is init 0.014069 flush 46.164147 stencil 36.067257 total 82.830693
mirza@Mirza:~/Parallel-Programing-assignments/Example_06$


Here is final results
Stencil Performance Comparison 
-------------------------------------------
Number of threads used: 4
1) Baseline version – stencil_opt2
-----------------------------------
init time:    0.017124 sec
flush time:  49.114242 sec
stencil time: 38.226055 sec
TOTAL:       87.360458 sec

2) Optimized version – stencil_opt4
------------------------------------
init time:    0.013963 sec
flush time:  45.759116 sec
stencil time: 35.840739 sec
TOTAL:       81.617311 sec
Speedup over baseline: ~6.57% faster

3) Highly optimized version – stencil_opt6
-------------------------------------------
init time:    0.014069 sec
flush time:  46.164147 sec
stencil time: 36.067257 sec
TOTAL:       82.830693 sec
Speedup over baseline: ~5.18% faster
-------------------------------------------
Summary
• stencil_opt2 is the slowest (baseline). This is the least optimized version. Multiple parallel regions, which increases thread creation overhead. Implicit barriers at the end of each parallel loop force threads to wait.

• stencil_opt4 is the fastest overall with the best total time.This implementation is noticeably improved over the baseline. initialization loop is parallelized, improving memory placement and NUMA locality. Reduced number of synchronization points, fewer implicit barriers. Slight loop restructuring improves cache behavior. Utility arrays better distributed across threads.

• stencil_opt6 is very close to opt4 but slightly slower because:
   - different barrier usage
   - different memory or loop behavior

• All versions ran using 4 threads


QUESTIONS

1. How many threads did your CPU use to execute the code?
Running with 4 threads

2. What parts of the code were improved? What strategies were used?
-First-Touch Optimization
Initializing arrays inside a #pragma omp parallel for allocates memory close to the thread that will use it → NUMA friendly.
-Reduced Number of Parallel Regions
Keeping threads alive longer reduces overhead from starting/ending parallel sections.
-Better Synchronization Control
Using nowait removes unnecessary implicit barriers.
-Explicit Barriers Only Where Needed
In stencil_opt6, barriers are manually inserted only where correctness requires it.
-Memory & Cache Optimizations
Pointer swapping and array layout improvements reduce cache misses.
-Loop Restructuring
Better loop ordering leads to improved cache reuse and less memory latency.ž

3. Difference Between Explicit and Implicit Barriers & Their Presence in Code
Implicit Barriers
OpenMP automatically inserts them at the end of:
#pragma omp for
#pragma omp single
#pragma omp sections
They force all threads to wait before continuing.

Explicit Barriers
Programmer manually inserts:
#pragma omp barrier
These are used only where synchronization must happen.

Implicit barrier = automatically inserted sync point
All threads wait, even if they finished early.
Explicit barrier = manually placed sync point
Used when you very specifically need threads to wait to ensure correctness.

Implicit barriers slow down performance if used too much.
Explicit barriers give more control and allow advanced optimizations.