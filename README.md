# ParallelComputing

Example_01 – Sequential Word Count

Compilation
gcc -O3 sequential_wordcount.c -o wordcount
Execution
time ./wordcount /home/dilfa/dataset_for_map_reduce/D1.7GB

Output
Total files processed: 2808
Total words: 197,572,278
Unique words: 9,631,226

The program correctly produced the Top 20 most frequent words and completed without errors.

Real time: 1m 35.927s
Processing rate: ~2.1 million words/second

The sequential version processes all files using a single process. Mapping, shuffling, and reduction are interleaved using a hash table, which allows immediate grouping and counting of words.




Example_02 – Parallel Word Count

Compilation
mpicc -O3 mpi_wordcount.c -o wordcount

Error I get
Running the program with 8 processes initially failed due to insufficient available CPU cores:
mpirun -np 8 ./wordcount ...
OpenMPI reported that there were not enough slots available. This issue was resolved by enabling oversubscription, which allows running more MPI processes than physical cores:

mpirun --oversubscribe -np 8 ./wordcount /home/dilfa/dataset_for_map_reduce/D1.7GB


Execution 8 Results

Output Summary

Total files processed: 2808
Total words: 197,572,278
Unique words: 9,631,226

Performance
Real time: 48.094 seconds
Processing rate: ~4.25 million words/second

This represents approximately 2× speedup compared to the sequential implementation.

Execution with 4 Processes
Wall time: 42.51 seconds
Processing rate: 4,647,924 words/second

Execution with 2 Processes
Wall time: 52.95 seconds
Processing rate: 3,731,333 words/second


Comparison

Implementation	Processes	Wall Time (s)	Words/sec
Sequential	      1	        94.00	        2,101,833
Parallel	      2	        52.95	        3,731,333
Parallel	      4	        42.51	        4,647,924
Parallel	      8	        46.50	        4,248,726

Parallel implementation is faster due to workload distribution across multiple processes.


How Parallel Implementation Differs from Sequential

Sequential (Example_01)
Processes files one by one on a single CPU core.
Word counts are accumulated in a single global hash table.

Parallel (Example_02)
Distributes files across multiple MPI processes.
Each process counts words independently, then results are reduced into a global summary.

Uses MapReduce approach:
Map: Each process counts words in its assigned files.
Shuffle/Reduce: Results are merged and sorted to get final counts.


