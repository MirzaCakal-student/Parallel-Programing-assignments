# ParallelComputing

First, the file `file_generator.c` was compiled and executed.
I generated a large CSV file called `temperature_data.csv`.

File size: ~880 MB
Number of records: 15,000,000

Example_01 uses serial file I/O.
Only rank 0 reads and writes the file. Other processes wait during I/O.

Example_02 uses MPI-IO with independent access.
Every process opens the file, reads its own part, and writes directly to its position.

Example_03 uses collective MPI-IO.
Processes write together using collective calls and file views.


Example_01 is much slower than the oters.
Example_02 and Example_03 are much faster because file reading and writing are done in parallel.

Measured times

| Example    | Processes | Time (s) |
| ---------- | --------- | -------- |
| Example_01 | 1         | ~24      |
| Example_01 | 2         | ~25      |
| Example_01 | 4         | ~58      |
| Example_02 | 2         | ~13      |
| Example_02 | 4         | ~16      |
| Example_03 | 2         | ~13      |
| Example_03 | 4         | ~15      |



Why Example_01 is much slower
In Example_01, rank 0 does all file reading and writing.
It also has to send and receive data from other processes using scatter and gather.
This creates a big bottleneck and makes the program slow, especially when the number of proceses increases.

What Example_03 improves compared to Example_02
Example_03 uses:
File views
Collective write operations
MPI-IO hints (aggregators and buffering)

Because of this, MPI can organize the write operations better and reduce the number of small writes.


Example_02 vs Example_03
On a local laptop, Example_02 can be faster than Example_03.
This happens because collective I/O adds extra synchronization overhead.
Example_03 works better on HPC systems with parallel filesystems, where collective I/O gives better scalability.

 
