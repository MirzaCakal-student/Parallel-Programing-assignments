# ParallelComputing

mirza@Mirza:~$ cd ~/ParallelComputing
mirza@Mirza:~/ParallelComputing$ make
Linking sum_test...
gcc main.o sum_algorithms.o -o sum_test
/usr/bin/ld: main.o: in function `main':
main.c:(.text+0x13d): undefined reference to `pow'
collect2: error: ld returned 1 exit status
make: *** [Makefile:20: sum_test] Error 1
mirza@Mirza:~/ParallelComputing$ make run
Linking sum_test...
gcc main.o sum_algorithms.o -o sum_test
/usr/bin/ld: main.o: in function `main':
main.c:(.text+0x13d): undefined reference to `pow'
collect2: error: ld returned 1 exit status
make: *** [Makefile:20: sum_test] Error 1
mirza@Mirza:~/ParallelComputing$ make clean
Cleaning up...
rm -f main.o sum_algorithms.o sum_test
Clean complete!
mirza@Mirza:~/ParallelComputing$ make
Compiling main.c...
gcc -Wall -std=c99 -c main.c -o main.o
Compiling sum_algorithms.c...
gcc -Wall -std=c99 -c sum_algorithms.c -o sum_algorithms.o
Linking sum_test...
gcc main.o sum_algorithms.o -lm -o sum_test
mirza@Mirza:~/ParallelComputing$ ./sum_test
========================================
 Global Sum Precision and Performance Test
========================================

----------------------------------------
TESTING WITH 2^10 = 1024 elements
----------------------------------------
Expected accurate sum: 51.2000000512

Standard double  -> sum: 51.20000005120137 diff: 1.37135e-12  rel_diff: 2.67841e-14 time: 0.000005 s
Long double      -> sum: 51.2000000512     diff: 3.55271e-15  rel_diff: 6.93889e-17 time: 0.000006 s
Pairwise sum     -> sum: 51.2000000512     diff: 0            rel_diff: 0          time: 0.000013 s
Kahan sum        -> sum: 51.2000000512     diff: 0            rel_diff: 0          time: 0.000016 s
Knuth sum        -> sum: 51.2000000512     diff: 0            rel_diff: 0          time: 0.000008 s

----------------------------------------
TESTING WITH 2^11 = 2048 elements
----------------------------------------
Expected accurate sum: 102.4000001024

Standard double  -> sum: 102.4000001024003 diff: 2.84217e-13  rel_diff: 2.77556e-15 time: 0.000009 s
Long double      -> sum: 102.4000001024    diff: 7.10543e-15  rel_diff: 6.93889e-17 time: 0.000011 s
Pairwise sum     -> sum: 102.4000001024    diff: 0            rel_diff: 0          time: 0.000024 s
Kahan sum        -> sum: 102.4000001024    diff: 0            rel_diff: 0          time: 0.000032 s
Knuth sum        -> sum: 102.4000001024    diff: 0            rel_diff: 0          time: 0.000015 s

----------------------------------------
TESTING WITH 2^12 = 4096 elements
----------------------------------------
Expected accurate sum: 204.8000002048

Standard double  -> sum: 204.8000002047672 diff: -3.27987e-11 rel_diff: -1.6015e-13 time: 0.000019 s
Long double      -> sum: 204.8000002048    diff: 0            rel_diff: 0          time: 0.000079 s
Pairwise sum     -> sum: 204.8000002048    diff: 0            rel_diff: 0          time: 0.000047 s
Kahan sum        -> sum: 204.8000002048    diff: 0            rel_diff: 0          time: 0.000063 s
Knuth sum        -> sum: 204.8000002048    diff: 0            rel_diff: 0          time: 0.000031 s

----------------------------------------
TESTING WITH 2^13 = 8192 elements
----------------------------------------
Expected accurate sum: 409.6000004096

Standard double  -> sum: 409.6000004095737 diff: -2.62617e-11 rel_diff: -6.41154e-14 time: 0.000037 s
Long double      -> sum: 409.6000004096001 diff: 5.68434e-14  rel_diff: 1.38778e-16 time: 0.000063 s
Pairwise sum     -> sum: 409.6000004096    diff: 0            rel_diff: 0          time: 0.000093 s
Kahan sum        -> sum: 409.6000004096    diff: 0            rel_diff: 0          time: 0.000127 s
Knuth sum        -> sum: 409.6000004096    diff: 0            rel_diff: 0          time: 0.000061 s

----------------------------------------
TESTING WITH 2^14 = 16384 elements
----------------------------------------
Expected accurate sum: 819.2000008192

Standard double  -> sum: 819.2000008196816 diff: 4.81577e-10  rel_diff: 5.87863e-13 time: 0.000074 s
Long double      -> sum: 819.2000008192    diff: 2.84217e-14  rel_diff: 3.46945e-17 time: 0.000090 s
Pairwise sum     -> sum: 819.2000008192    diff: 0            rel_diff: 0          time: 0.000204 s
Kahan sum        -> sum: 819.2000008192    diff: 0            rel_diff: 0          time: 0.000254 s
Knuth sum        -> sum: 819.2000008192    diff: 0            rel_diff: 0          time: 0.000122 s

----------------------------------------
TESTING WITH 2^15 = 32768 elements
----------------------------------------
Expected accurate sum: 1638.4000016384

Standard double  -> sum: 1638.400001638733 diff: 3.33102e-10  rel_diff: 2.0331e-13 time: 0.000171 s
Long double      -> sum: 1638.4000016384   diff: -8.52651e-14 rel_diff: -5.20417e-17 time: 0.000180 s
Pairwise sum     -> sum: 1638.4000016384   diff: 0            rel_diff: 0          time: 0.000372 s
Kahan sum        -> sum: 1638.4000016384   diff: 0            rel_diff: 0          time: 0.000543 s
Knuth sum        -> sum: 1638.4000016384   diff: 0            rel_diff: 0          time: 0.000243 s

----------------------------------------
TESTING WITH 2^16 = 65536 elements
----------------------------------------
Expected accurate sum: 3276.8000032768

Standard double  -> sum: 3276.800003276371 diff: -4.29281e-10 rel_diff: -1.31006e-13 time: 0.000568 s
Long double      -> sum: 3276.800003276801 diff: 1.0516e-12   rel_diff: 3.20924e-16 time: 0.000863 s
Pairwise sum     -> sum: 3276.8000032768   diff: 0            rel_diff: 0          time: 0.000793 s
Kahan sum        -> sum: 3276.8000032768   diff: 0            rel_diff: 0          time: 0.000902 s
Knuth sum        -> sum: 3276.8000032768   diff: 0            rel_diff: 0          time: 0.000398 s

----------------------------------------
TESTING WITH 2^17 = 131072 elements
----------------------------------------
Expected accurate sum: 6553.6000065536

Standard double  -> sum: 6553.600006562821 diff: 9.22137e-09  rel_diff: 1.40707e-12 time: 0.000435 s
Long double      -> sum: 6553.600006553604 diff: 4.23483e-12  rel_diff: 6.46184e-16 time: 0.000592 s
Pairwise sum     -> sum: 6553.6000065536   diff: 0            rel_diff: 0          time: 0.001108 s
Kahan sum        -> sum: 6553.6000065536   diff: 0            rel_diff: 0          time: 0.001307 s
Knuth sum        -> sum: 6553.6000065536   diff: 0            rel_diff: 0          time: 0.000615 s

----------------------------------------
TESTING WITH 2^18 = 262144 elements
----------------------------------------
Expected accurate sum: 13107.2000131072

Standard double  -> sum: 13107.20001314317 diff: 3.59742e-08  rel_diff: 2.74461e-12 time: 0.000734 s
Long double      -> sum: 13107.20001310719 diff: -1.12266e-11 rel_diff: -8.5652e-16 time: 0.000916 s
Pairwise sum     -> sum: 13107.2000131072  diff: 0            rel_diff: 0          time: 0.001940 s
Kahan sum        -> sum: 13107.2000131072  diff: 0            rel_diff: 0          time: 0.003051 s
Knuth sum        -> sum: 13107.2000131072  diff: 0            rel_diff: 0          time: 0.001274 s

----------------------------------------
TESTING WITH 2^19 = 524288 elements
----------------------------------------
Expected accurate sum: 26214.4000262144

Standard double  -> sum: 26214.40002564823 diff: -5.66171e-07 rel_diff: -2.15977e-11 time: 0.001556 s
Long double      -> sum: 26214.40002621434 diff: -5.67013e-11 rel_diff: -2.16298e-15 time: 0.001872 s
Pairwise sum     -> sum: 26214.4000262144  diff: 0            rel_diff: 0          time: 0.003684 s
Kahan sum        -> sum: 26214.4000262144  diff: 0            rel_diff: 0          time: 0.005466 s
Knuth sum        -> sum: 26214.4000262144  diff: 0            rel_diff: 0          time: 0.002649 s

----------------------------------------
TESTING WITH 2^20 = 1048576 elements
----------------------------------------
Expected accurate sum: 52428.8000524288

Standard double  -> sum: 52428.80005292332 diff: 4.94518e-07  rel_diff: 9.43218e-12 time: 0.003328 s
Long double      -> sum: 52428.80005242807 diff: -7.29727e-10 rel_diff: -1.39184e-14 time: 0.003902 s
Pairwise sum     -> sum: 52428.8000524288  diff: 0            rel_diff: 0          time: 0.007581 s
Kahan sum        -> sum: 52428.8000524288  diff: 0            rel_diff: 0          time: 0.011551 s
Knuth sum        -> sum: 52428.8000524288  diff: 0            rel_diff: 0          time: 0.005136 s

----------------------------------------
TESTING WITH 2^21 = 2097152 elements
----------------------------------------
Expected accurate sum: 104857.6001048576

Standard double  -> sum: 104857.6001084272 diff: 3.56956e-06  rel_diff: 3.40419e-11 time: 0.006331 s
Long double      -> sum: 104857.6001048604 diff: 2.81366e-09  rel_diff: 2.68332e-14 time: 0.007078 s
Pairwise sum     -> sum: 104857.6001048576 diff: 0            rel_diff: 0          time: 0.015579 s
Kahan sum        -> sum: 104857.6001048576 diff: 0            rel_diff: 0          time: 0.019816 s
Knuth sum        -> sum: 104857.6001048576 diff: 0            rel_diff: 0          time: 0.010103 s

----------------------------------------
TESTING WITH 2^22 = 4194304 elements
----------------------------------------
Expected accurate sum: 209715.2002097152

Standard double  -> sum: 209715.2001908246 diff: -1.88906e-05 rel_diff: -9.00774e-11 time: 0.012080 s
Long double      -> sum: 209715.2002097158 diff: 5.87221e-10  rel_diff: 2.80009e-15 time: 0.014560 s
Pairwise sum     -> sum: 209715.2002097152 diff: 0            rel_diff: 0          time: 0.030593 s
Kahan sum        -> sum: 209715.2002097152 diff: 0            rel_diff: 0          time: 0.040820 s
Knuth sum        -> sum: 209715.2002097152 diff: 0            rel_diff: 0          time: 0.019755 s

----------------------------------------
TESTING WITH 2^23 = 8388608 elements
----------------------------------------
Expected accurate sum: 419430.4004194304

Standard double  -> sum: 419430.400462431  diff: 4.30006e-05  rel_diff: 1.02521e-10 time: 0.023828 s
Long double      -> sum: 419430.4004193632 diff: -6.71956e-08 rel_diff: -1.60207e-13 time: 0.028708 s
Pairwise sum     -> sum: 419430.4004194304 diff: 0            rel_diff: 0          time: 0.059763 s
Kahan sum        -> sum: 419430.4004194304 diff: 0            rel_diff: 0          time: 0.080565 s
Knuth sum        -> sum: 419430.4004194304 diff: 0            rel_diff: 0          time: 0.038928 s

----------------------------------------
TESTING WITH 2^24 = 16777216 elements
----------------------------------------
Expected accurate sum: 838860.8008388608

Standard double  -> sum: 838860.800853056  diff: 1.41952e-05  rel_diff: 1.6922e-11 time: 0.048554 s
Long double      -> sum: 838860.800838807  diff: -5.37497e-08 rel_diff: -6.40746e-14 time: 0.056192 s
Pairwise sum     -> sum: 838860.8008388608 diff: 0            rel_diff: 0          time: 0.119600 s
Kahan sum        -> sum: 838860.8008388608 diff: 0            rel_diff: 0          time: 0.159203 s
Knuth sum        -> sum: 838860.8008388608 diff: 0            rel_diff: 0          time: 0.075836 s

----------------------------------------
TESTING WITH 2^25 = 33554432 elements
----------------------------------------
Expected accurate sum: 1677721.601677722

Standard double  -> sum: 1677721.600413603 diff: -0.00126412  rel_diff: -7.53474e-10 time: 0.094435 s
Long double      -> sum: 1677721.601678708 diff: 9.86421e-07  rel_diff: 5.87953e-13 time: 0.113471 s
Pairwise sum     -> sum: 1677721.601677722 diff: 0            rel_diff: 0          time: 0.233341 s
Kahan sum        -> sum: 1677721.601677722 diff: 0            rel_diff: 0          time: 0.316611 s
Knuth sum        -> sum: 1677721.601677722 diff: 0            rel_diff: 0          time: 0.154774 s

----------------------------------------
TESTING WITH 2^26 = 67108864 elements
----------------------------------------
Expected accurate sum: 3355443.203355443

Standard double  -> sum: 3355443.201976103 diff: -0.00137934  rel_diff: -4.11075e-10 time: 0.186967 s
Long double      -> sum: 3355443.203356126 diff: 6.82577e-07  rel_diff: 2.03424e-13 time: 0.227734 s
Pairwise sum     -> sum: 3355443.203355443 diff: 0            rel_diff: 0          time: 0.472980 s
Kahan sum        -> sum: 3355443.203355443 diff: 0            rel_diff: 0          time: 0.656801 s
Knuth sum        -> sum: 3355443.203355443 diff: 0            rel_diff: 0          time: 0.308219 s

----------------------------------------
TESTING WITH 2^27 = 134217728 elements
----------------------------------------
Expected accurate sum: 6710886.406710886

Standard double  -> sum: 6710886.393382353 diff: -0.0133285   rel_diff: -1.98611e-09 time: 0.374895 s
Long double      -> sum: 6710886.406710008 diff: -8.78785e-07 rel_diff: -1.30949e-13 time: 0.451014 s
Pairwise sum     -> sum: 6710886.406710886 diff: 0            rel_diff: 0          time: 0.937989 s
Kahan sum        -> sum: 6710886.406710886 diff: 0            rel_diff: 0          time: 1.270341 s
Knuth sum        -> sum: 6710886.406710886 diff: 0            rel_diff: 0          time: 0.604672 s

========================================
All tests complete!
========================================


https://docs.google.com/spreadsheets/d/1Ln0fV2s7ZpaeZ0A3MtLAvg2Hj7G4u23_IsxO6y6ruiM/edit?usp=sharing