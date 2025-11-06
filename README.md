WHAT I DID AT HOME

mirza@Mirza:~$ cd ~/Parallel-Programing-assignments
mirza@Mirza:~/Parallel-Programing-assignments$ make clean
rm -f baseline opt1 opt2 opt3 *.o
mirza@Mirza:~/Parallel-Programing-assignments$ make
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c main.c -o main_base.o
main.c:13:25: optimized: loop vectorized using 32 byte vectors
main.c:30:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:86:10: missed: statement clobbers memory: __printf_chk (2, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timer.c
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep.c
timestep.c:9:22: missed: couldn't vectorize loop
timestep.c:9:22: missed: not vectorized: control flow in loop.
timestep.c:11:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o baseline main_base.o timer.o timestep.o -lm
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -DUSE_OPT1 -c main.c -o main_opt1.o
main.c:13:25: optimized: loop vectorized using 32 byte vectors
main.c:24:15: missed: statement clobbers memory: mymindt_6 = timestep_opt1 (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:86:10: missed: statement clobbers memory: __printf_chk (2, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep_opt1.c
timestep_opt1.c:20:25: missed: couldn't vectorize loop
timestep_opt1.c:20:25: missed: not vectorized: control flow in loop.
timestep_opt1.c:22:32: missed: statement clobbers memory: wavespeed_51 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o opt1 main_opt1.o timer.o timestep_opt1.o -lm
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -DUSE_OPT2 -c main.c -o main_opt2.o
main.c:13:25: optimized: loop vectorized using 32 byte vectors
main.c:26:15: missed: statement clobbers memory: mymindt_6 = timestep_opt2 (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:86:10: missed: statement clobbers memory: __printf_chk (2, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep_opt2.c
timestep_opt2.c:20:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:22:9: missed: couldn't vectorize loop
timestep_opt2.c:22:9: missed: not vectorized: control flow in loop.
timestep_opt2.c:20:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:23:32: missed: statement clobbers memory: wavespeed_63 = sqrt (_36);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o opt2 main_opt2.o timer.o timestep_opt2.o -lm
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -DUSE_OPT3 -c main.c -o main_opt3.o
main.c:13:25: optimized: loop vectorized using 32 byte vectors
main.c:28:15: missed: statement clobbers memory: mymindt_6 = timestep_opt3 (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:86:10: missed: statement clobbers memory: __printf_chk (2, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -fno-trapping-math -fno-math-errno -c timestep_opt3.c
timestep_opt3.c:23:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:25:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:23:9: optimized: loop vectorized using 32 byte vectors
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -fno-trapping-math -fno-math-errno -o opt3 main_opt3.o timer.o timestep_opt3.o -lm
mirza@Mirza:~/Parallel-Programing-assignments$ perf stat ./baseline
Minimum dt is 0.016964

 Performance counter stats for './baseline':

            670.87 msec task-clock                       #    1.013 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
            107491      page-faults                      #  160.227 K/sec
        1436547791      cycles                           #    2.141 GHz
        1021151628      instructions                     #    0.71  insn per cycle
         177896171      branches                         #  265.173 M/sec
            347585      branch-misses                    #    0.20% of all branches

       0.662559850 seconds time elapsed

       0.190449000 seconds user
       0.482201000 seconds sys


mirza@Mirza:~/Parallel-Programing-assignments$ perf stat ./opt1
Minimum dt is 0.016964

 Performance counter stats for './opt1':

            682.11 msec task-clock                       #    1.014 CPUs utilized
                 3      context-switches                 #    4.398 /sec
                 0      cpu-migrations                   #    0.000 /sec
            107492      page-faults                      #  157.588 K/sec
        1439233199      cycles                           #    2.110 GHz
        1021165050      instructions                     #    0.71  insn per cycle
         177898610      branches                         #  260.808 M/sec
            363304      branch-misses                    #    0.20% of all branches

       0.672681474 seconds time elapsed

       0.186960000 seconds user
       0.495851000 seconds sys


mirza@Mirza:~/Parallel-Programing-assignments$ perf stat ./opt2
Minimum dt is 0.016964

 Performance counter stats for './opt2':

            691.52 msec task-clock                       #    1.014 CPUs utilized
                 3      context-switches                 #    4.338 /sec
                 0      cpu-migrations                   #    0.000 /sec
            107491      page-faults                      #  155.443 K/sec
        1436678190      cycles                           #    2.078 GHz
        1021093009      instructions                     #    0.71  insn per cycle
         177882856      branches                         #  257.236 M/sec
            349896      branch-misses                    #    0.20% of all branches

       0.682288863 seconds time elapsed

       0.158873000 seconds user
       0.533653000 seconds sys


mirza@Mirza:~/Parallel-Programing-assignments$ perf stat ./opt3
Minimum dt is 0.016964

 Performance counter stats for './opt3':

            629.34 msec task-clock                       #    1.014 CPUs utilized
                 1      context-switches                 #    1.589 /sec
                 0      cpu-migrations                   #    0.000 /sec
            107480      page-faults                      #  170.783 K/sec
        1345898523      cycles                           #    2.139 GHz
         878433644      instructions                     #    0.65  insn per cycle
         149083688      branches                         #  236.890 M/sec
            344926      branch-misses                    #    0.23% of all branches

       0.620447561 seconds time elapsed

       0.126003000 seconds user
       0.504015000 seconds sys


mirza@Mirza:~/Parallel-Programing-assignments$ export LIKWID_ACCESSMODE=perf_event
mirza@Mirza:~/Parallel-Programing-assignments$ likwid-perfctr -C 0 -g FLOPS_DP -m ./baseline
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i5-6500 CPU @ 3.20GHz
CPU type:       Intel Skylake processor
CPU clock:      3.27 GHz
Cannot get access to MSRs. Please check permissions to the MSRs
mirza@Mirza:~/Parallel-Programing-assignments$ likwid-perfctr -C 0 -g FLOPS_DP -m ./opt1
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i5-6500 CPU @ 3.20GHz
CPU type:       Intel Skylake processor
CPU clock:      3.24 GHz
Cannot get access to MSRs. Please check permissions to the MSRs
mirza@Mirza:~/Parallel-Programing-assignments$ likwid-perfctr -C 0 -g FLOPS_DP -m ./opt2
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i5-6500 CPU @ 3.20GHz
CPU type:       Intel Skylake processor
CPU clock:      3.24 GHz
Cannot get access to MSRs. Please check permissions to the MSRs
mirza@Mirza:~/Parallel-Programing-assignments$ likwid-perfctr -C 0 -g FLOPS_DP -m ./opt3
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i5-6500 CPU @ 3.20GHz
CPU type:       Intel Skylake processor
CPU clock:      3.19 GHz
Cannot get access to MSRs. Please check permissions to the MSRs
mirza@Mirza:~/Parallel-Programing-assignments$

WHAT WE DID AT LAB
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ make clean
rm -f baseline opt1 opt2 opt3 *.o
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ make
gcc -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o baseline main.c timer.c timestep.c -lm
main.c:11:25: optimized: loop vectorized using 32 byte vectors
main.c:22:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
timer.c:4:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
timestep.c:9:22: missed: couldn't vectorize loop
timestep.c:9:22: missed: not vectorized: control flow in loop.
timestep.c:11:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_9);
gcc -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o opt1 main.c timer.c timestep_opt1.c -lm
main.c:11:25: optimized: loop vectorized using 32 byte vectors
main.c:22:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
timer.c:4:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
timestep_opt1.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:13:21: missed: couldn't vectorize loop
timestep_opt1.c:13:21: missed: not vectorized: control flow in loop.
timestep_opt1.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:14:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o opt2 main.c timer.c timestep_opt2.c -lm
main.c:11:25: optimized: loop vectorized using 32 byte vectors
main.c:22:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
timer.c:4:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
timestep_opt2.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:13:21: missed: couldn't vectorize loop
timestep_opt2.c:13:21: missed: not vectorized: control flow in loop.
timestep_opt2.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:14:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -fno-trapping-math -fno-math-errno -o opt3 main.c timer.c timestep_opt3.c -lm
main.c:11:25: optimized: loop vectorized using 32 byte vectors
main.c:22:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
timer.c:4:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
timestep_opt3.c:10:13: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:12:21: optimized: loop vectorized using 16 byte vectors
timestep_opt3.c:10:13: optimized: loop vectorized using 32 byte vectors
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ sudo modprobe msr
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ likwid-topology
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU stepping:   7
********************************************************************************
Hardware Thread Topology
********************************************************************************
Sockets:                1
CPU dies:               1
Cores per socket:       2
Threads per core:       2
--------------------------------------------------------------------------------
HWThread        Thread        Core        Die        Socket        Available
0               0             0           0          0             *                
1               0             1           0          0             *                
2               1             0           0          0             *                
3               1             1           0          0             *                
--------------------------------------------------------------------------------
Socket 0:               ( 0 2 1 3 )
--------------------------------------------------------------------------------
********************************************************************************
Cache Topology
********************************************************************************
Level:                  1
Size:                   32 kB
Cache groups:           ( 0 2 ) ( 1 3 )
--------------------------------------------------------------------------------
Level:                  2
Size:                   256 kB
Cache groups:           ( 0 2 ) ( 1 3 )
--------------------------------------------------------------------------------
Level:                  3
Size:                   3 MB
Cache groups:           ( 0 2 1 3 )
--------------------------------------------------------------------------------
********************************************************************************
NUMA Topology
********************************************************************************
NUMA domains:           1
--------------------------------------------------------------------------------
Domain:                 0
Processors:             ( 0 2 1 3 )
Distances:              10
Free memory:            1330.75 MB
Total memory:           7826.61 MB
--------------------------------------------------------------------------------
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./baseline
ž
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  217791914 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  827881240 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  827884662 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |   90420250 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+-------------------------+------------+
|          Metric         | HWThread 0 |
+-------------------------+------------+
|   Runtime (RDTSC) [s]   |     0.4963 |
|   Runtime unhalted [s]  |     0.2515 |
|       Clock [MHz]       |  3292.4031 |
|           CPI           |     3.8012 |
|       DP [MFLOP/s]      |   182.2001 |
|     AVX DP [MFLOP/s]    |          0 |
|     Packed [MUOPS/s]    |          0 |
|     Scalar [MUOPS/s]    |   182.2001 |
| Vectorization ratio [%] |          0 |
+-------------------------+------------+

ž: command not found
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt1
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  217792057 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  832382503 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  832376688 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |   90222053 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+-------------------------+------------+
|          Metric         | HWThread 0 |
+-------------------------+------------+
|   Runtime (RDTSC) [s]   |     0.5014 |
|   Runtime unhalted [s]  |     0.2528 |
|       Clock [MHz]       |  3292.4402 |
|           CPI           |     3.8219 |
|       DP [MFLOP/s]      |   179.9377 |
|     AVX DP [MFLOP/s]    |          0 |
|     Packed [MUOPS/s]    |          0 |
|     Scalar [MUOPS/s]    |   179.9377 |
| Vectorization ratio [%] |          0 |
+-------------------------+------------+

student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt2
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  217791954 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  827408150 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  827402565 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |   90408875 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+-------------------------+------------+
|          Metric         | HWThread 0 |
+-------------------------+------------+
|   Runtime (RDTSC) [s]   |     0.4956 |
|   Runtime unhalted [s]  |     0.2513 |
|       Clock [MHz]       |  3292.4054 |
|           CPI           |     3.7991 |
|       DP [MFLOP/s]      |   182.4171 |
|     AVX DP [MFLOP/s]    |          0 |
|     Packed [MUOPS/s]    |          0 |
|     Scalar [MUOPS/s]    |   182.4171 |
| Vectorization ratio [%] |          0 |
+-------------------------+------------+

student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt3
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  137798768 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  524492886 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  524487744 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |   45185876 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |         30 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          2 |
+--------------------------------------+---------+------------+

+-------------------------+--------------+
|          Metric         |  HWThread 0  |
+-------------------------+--------------+
|   Runtime (RDTSC) [s]   |       0.4191 |
|   Runtime unhalted [s]  |       0.1593 |
|       Clock [MHz]       |    3292.4496 |
|           CPI           |       3.8062 |
|       DP [MFLOP/s]      |     215.6413 |
|     AVX DP [MFLOP/s]    | 1.908926e-05 |
|     Packed [MUOPS/s]    |     107.8206 |
|     Scalar [MUOPS/s]    |       0.0001 |
| Vectorization ratio [%] |      99.9999 |
+-------------------------+--------------+

student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g MEM_DP ./baseline
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
ERROR - [/home/student/likwid/src/perfgroup.c:perfgroup_readGroup:830] No such file or directory.
Cannot read group file MEM_DP.txt. Searched in /usr/local/share/likwid/perfgroups/sandybridge/MEM_DP.txt and /home/student/.likwid/groups/sandybridge/MEM_DP.txt
ERROR - [/home/student/likwid/src/perfmon.c:perfmon_addEventSet:2533] Permission denied.
Access to performance group MEM_DP not allowed
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g MEM_DP ./opt1
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
ERROR - [/home/student/likwid/src/perfgroup.c:perfgroup_readGroup:830] No such file or directory.
Cannot read group file MEM_DP.txt. Searched in /usr/local/share/likwid/perfgroups/sandybridge/MEM_DP.txt and /home/student/.likwid/groups/sandybridge/MEM_DP.txt
ERROR - [/home/student/likwid/src/perfmon.c:perfmon_addEventSet:2533] Permission denied.
Access to performance group MEM_DP not allowed
student@itcenter-lab128:~/Desktop/Parallel-Programing-assignments$ LIKWID_PIN=0 likwid-perfctr -C 0 -g SIMD ./opt3
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
ERROR - [/home/student/likwid/src/perfgroup.c:perfgroup_readGroup:830] No such file or directory.
Cannot read group file SIMD.txt. Searched in /usr/local/share/likwid/perfgroups/sandybridge/SIMD.txt and /home/student/.likwid/groups/sandybridge/SIMD.txt
ERROR - [/home/student/likwid/src/perfmon.c:perfmon_addEventSet:2533] Permission denied.
Access to performance group SIMD not allowed



