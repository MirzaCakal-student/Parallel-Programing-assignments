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