# ParallelComputing

code had a missing memory allocation for the AoSoA data structure.
Inside the function run_aos_aoa_kernel(long len), the array AoSoA 
was never actually created — only commented-out lines existed for filling it.
Because of that, the program had no allocated memory, and any attempt to access 
AoSoA[j].R[i], G[i], or B[i] would have caused fault or undefined behavior.

how I fix it, I added:
SoA_type* AoSoA = new SoA_type[num_blocks];

after that I just uncomment these 3 lines of code:
AoSoA[j].R[i] = rand();
AoSoA[j].G[i] = rand();
AoSoA[j].B[i] = rand();

and at the end I freed memory:
delete[] AoSoA;

after that fix, the code successfully allocated memory, initialized random data, 
and measured execution time correctly.

In make me file I just added TARGET_SRC = aosoa_measurement.cpp.

Then I run scripts, I run all tests and all of them passed and showe me a results.
I also merge all results in one .csv file, in run_all.sh wich I created, I write
this code ->  
#!/bin/bash
echo "Running all AoSoA tests..."
for test in test_1K test_10K test_100K test_1M test_10M; do
    make $test
done
echo "Merging results..."
echo "N,V,Time(ms)" > combined_results.csv
grep -h -v "N," results_N*.csv >> combined_results.csv
echo "All done! Combined file ready: combined_results.csv"

and I make it executable
chmod +x run_all.sh
./ruu_all.sh


mirza@Mirza:~$ cd ~/ParallelComputing
mirza@Mirza:~/ParallelComputing$ ls
README.md  aosoa_measurement.cpp  makefile
mirza@Mirza:~/ParallelComputing$ make test_1K
=============================================
 Running AoSoA benchmark for N=1000
=============================================
→ Building for V=2 ...
→ Running test with N=1000, V=2
→ Building for V=4 ...
→ Running test with N=1000, V=4
→ Building for V=8 ...
→ Running test with N=1000, V=8
→ Building for V=16 ...
→ Running test with N=1000, V=16
→ Building for V=32 ...
→ Running test with N=1000, V=32
→ Building for V=64 ...
→ Running test with N=1000, V=64
→ Building for V=128 ...
→ Running test with N=1000, V=128
→ Building for V=256 ...
→ Running test with N=1000, V=256
Results saved to results_N1000.csv
mirza@Mirza:~/ParallelComputing$ make test_10K
=============================================
 Running AoSoA benchmark for N=10000
=============================================
→ Building for V=2 ...
→ Running test with N=10000, V=2
→ Building for V=4 ...
→ Running test with N=10000, V=4
→ Building for V=8 ...
→ Running test with N=10000, V=8
→ Building for V=16 ...
→ Running test with N=10000, V=16
→ Building for V=32 ...
→ Running test with N=10000, V=32
→ Building for V=64 ...
→ Running test with N=10000, V=64
→ Building for V=128 ...
→ Running test with N=10000, V=128
→ Building for V=256 ...
→ Running test with N=10000, V=256
Results saved to results_N10000.csv
mirza@Mirza:~/ParallelComputing$ make test_100K
=============================================
 Running AoSoA benchmark for N=100000
=============================================
→ Building for V=2 ...
→ Running test with N=100000, V=2
→ Building for V=4 ...
→ Running test with N=100000, V=4
→ Building for V=8 ...
→ Running test with N=100000, V=8
→ Building for V=16 ...
→ Running test with N=100000, V=16
→ Building for V=32 ...
→ Running test with N=100000, V=32
→ Building for V=64 ...
→ Running test with N=100000, V=64
→ Building for V=128 ...
→ Running test with N=100000, V=128
→ Building for V=256 ...
→ Running test with N=100000, V=256
Results saved to results_N100000.csv
mirza@Mirza:~/ParallelComputing$ make test_1M
=============================================
 Running AoSoA benchmark for N=1000000
=============================================
→ Building for V=2 ...
→ Running test with N=1000000, V=2
→ Building for V=4 ...
→ Running test with N=1000000, V=4
→ Building for V=8 ...
→ Running test with N=1000000, V=8
→ Building for V=16 ...
→ Running test with N=1000000, V=16
→ Building for V=32 ...
→ Running test with N=1000000, V=32
→ Building for V=64 ...
→ Running test with N=1000000, V=64
→ Building for V=128 ...
→ Running test with N=1000000, V=128
→ Building for V=256 ...
→ Running test with N=1000000, V=256
Results saved to results_N1000000.csv
mirza@Mirza:~/ParallelComputing$ make test_10M
=============================================
 Running AoSoA benchmark for N=10000000
=============================================
→ Building for V=2 ...
→ Running test with N=10000000, V=2
→ Building for V=4 ...
→ Running test with N=10000000, V=4
→ Building for V=8 ...
→ Running test with N=10000000, V=8
→ Building for V=16 ...
→ Running test with N=10000000, V=16
→ Building for V=32 ...
→ Running test with N=10000000, V=32
→ Building for V=64 ...
→ Running test with N=10000000, V=64
→ Building for V=128 ...
→ Running test with N=10000000, V=128
→ Building for V=256 ...
→ Running test with N=10000000, V=256
Results saved to results_N10000000.csv
mirza@Mirza:~/ParallelComputing$ ls -l results_*.csv
-rw-r--r-- 1 mirza mirza 167 Oct 23 10:27 results_N1000.csv
-rw-r--r-- 1 mirza mirza 175 Oct 23 10:28 results_N10000.csv
-rw-r--r-- 1 mirza mirza 174 Oct 23 10:28 results_N100000.csv
-rw-r--r-- 1 mirza mirza 182 Oct 23 10:28 results_N1000000.csv
-rw-r--r-- 1 mirza mirza 190 Oct 23 10:29 results_N10000000.csv
mirza@Mirza:~/ParallelComputing$ head results_N100000.csv
N, V, Time (ms)
100000, 2, 5.85642
100000, 4, 5.59373
100000, 8, 5.58505
100000, 16, 5.45568
100000, 32, 5.94317
100000, 64, 6.37006
100000, 128, 5.73895
100000, 256, 5.9293
mirza@Mirza:~/ParallelComputing$ echo "N,V,Time(ms)" > combined_results.csv
mirza@Mirza:~/ParallelComputing$ grep -h -v "N," results_N*.csv >> combined_results.csv
mirza@Mirza:~/ParallelComputing$ head combined_results.csv
N,V,Time(ms)
1000, 2, 0.048971
1000, 4, 0.051781
1000, 8, 0.091285
1000, 16, 0.048929
1000, 32, 0.050537
1000, 64, 0.050657
1000, 128, 0.051077
1000, 256, 0.079733
10000, 2, 0.566317
mirza@Mirza:~/ParallelComputing$
mirza@Mirza:~/ParallelComputing$ nano run_all.sh
mirza@Mirza:~/ParallelComputing$ chmod +x run_all.sh
mirza@Mirza:~/ParallelComputing$ ./run_all.sh
Running all AoSoA tests...
=============================================
 Running AoSoA benchmark for N=1000
=============================================
→ Building for V=2 ...
→ Running test with N=1000, V=2
→ Building for V=4 ...
→ Running test with N=1000, V=4
→ Building for V=8 ...
→ Running test with N=1000, V=8
→ Building for V=16 ...
→ Running test with N=1000, V=16
→ Building for V=32 ...
→ Running test with N=1000, V=32
→ Building for V=64 ...
→ Running test with N=1000, V=64
→ Building for V=128 ...
→ Running test with N=1000, V=128
→ Building for V=256 ...
→ Running test with N=1000, V=256
Results saved to results_N1000.csv
=============================================
 Running AoSoA benchmark for N=10000
=============================================
→ Building for V=2 ...
→ Running test with N=10000, V=2
→ Building for V=4 ...
→ Running test with N=10000, V=4
→ Building for V=8 ...
→ Running test with N=10000, V=8
→ Building for V=16 ...
→ Running test with N=10000, V=16
→ Building for V=32 ...
→ Running test with N=10000, V=32
→ Building for V=64 ...
→ Running test with N=10000, V=64
→ Building for V=128 ...
→ Running test with N=10000, V=128
→ Building for V=256 ...
→ Running test with N=10000, V=256
Results saved to results_N10000.csv
=============================================
 Running AoSoA benchmark for N=100000
=============================================
→ Building for V=2 ...
→ Running test with N=100000, V=2
→ Building for V=4 ...
→ Running test with N=100000, V=4
→ Building for V=8 ...
→ Running test with N=100000, V=8
→ Building for V=16 ...
→ Running test with N=100000, V=16
→ Building for V=32 ...
→ Running test with N=100000, V=32
→ Building for V=64 ...
→ Running test with N=100000, V=64
→ Building for V=128 ...
→ Running test with N=100000, V=128
→ Building for V=256 ...
→ Running test with N=100000, V=256
Results saved to results_N100000.csv
=============================================
 Running AoSoA benchmark for N=1000000
=============================================
→ Building for V=2 ...
→ Running test with N=1000000, V=2
→ Building for V=4 ...
→ Running test with N=1000000, V=4
→ Building for V=8 ...
→ Running test with N=1000000, V=8
→ Building for V=16 ...
→ Running test with N=1000000, V=16
→ Building for V=32 ...
→ Running test with N=1000000, V=32
→ Building for V=64 ...
→ Running test with N=1000000, V=64
→ Building for V=128 ...
→ Running test with N=1000000, V=128
→ Building for V=256 ...
→ Running test with N=1000000, V=256
Results saved to results_N1000000.csv
=============================================
 Running AoSoA benchmark for N=10000000
=============================================
→ Building for V=2 ...
→ Running test with N=10000000, V=2
→ Building for V=4 ...
→ Running test with N=10000000, V=4
→ Building for V=8 ...
→ Running test with N=10000000, V=8
→ Building for V=16 ...
→ Running test with N=10000000, V=16
→ Building for V=32 ...
→ Running test with N=10000000, V=32
→ Building for V=64 ...
→ Running test with N=10000000, V=64
→ Building for V=128 ...
→ Running test with N=10000000, V=128
→ Building for V=256 ...
→ Running test with N=10000000, V=256
Results saved to results_N10000000.csv
Merging results...
All done! Combined file ready: combined_results.csv
mirza@Mirza:~/ParallelComputing$ ls
README.md              combined_results.csv  results_N1000.csv   results_N100000.csv   results_N10000000.csv
aosoa_measurement.cpp  makefile              results_N10000.csv  results_N1000000.csv  run_all.sh
mirza@Mirza:~/ParallelComputing$ cat combined_results.csv
N,V,Time(ms)
1000, 2, 0.050331
1000, 4, 0.048929
1000, 8, 0.049432
1000, 16, 0.062829
1000, 32, 0.054075
1000, 64, 0.063239
1000, 128, 0.099096
1000, 256, 0.050757
10000, 2, 0.660041
10000, 4, 0.522208
10000, 8, 0.763623
10000, 16, 0.68585
10000, 32, 0.616367
10000, 64, 0.587421
10000, 128, 0.68129
10000, 256, 0.518999
100000, 2, 5.80408
100000, 4, 5.76116
100000, 8, 5.7127
100000, 16, 6.326
100000, 32, 6.52934
100000, 64, 6.69142
100000, 128, 6.17511
100000, 256, 5.67277
1000000, 2, 56.4305
1000000, 4, 60.2539
1000000, 8, 63.287
1000000, 16, 57.6464
1000000, 32, 57.3931
1000000, 64, 56.5888
1000000, 128, 56.9602
1000000, 256, 57.4939
10000000, 2, 587.189
10000000, 4, 575.695
10000000, 8, 619.175
10000000, 16, 581.876
10000000, 32, 645.352

10000000, 64, 602.527
10000000, 128, 621.238
10000000, 256, 620.746
mirza@Mirza:~/ParallelComputing$


HERE IS LINK FOR GOOGLE SHEETS https://docs.google.com/spreadsheets/d/1bXN1SGRbkPXUenqW2v3J6sdNIua3F9Tt926fRKZ-0qs/edit?usp=sharing
