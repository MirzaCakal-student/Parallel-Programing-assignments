# Parallel-Programing-assignments

Assignment 7

This assignment implements a distributed partial-sum computation using MPI collective communication routines. The goal is to divide an array across multiple processes, compute partial sums locally, and then reduce them into a final global sum.

----------------------------------------------------------------------------------------------
Operations that we used are:
- MPI_Allgather
Each process contributes one integer (`nsize_local`), and every process receives the entire `nsizes[]` array.
Used so all processes know:
how many elements each rank gets  
how offsets should be computed  
how much memory to allocate  
- MPI_Scatterv
Allows root (rank 0) to send different amounts of data to each rank.  
Uses:
- `nsizes[]` — number of elements for each rank  
- `offsets[]` — displacement into global array
This makes distribution flexible and correct even when the array cannot be evenly divided.
- MPI_Reduce
Combines all local sums using MPI_SUm and stores the final result only on rank 0.  
Other ranks do not allocate or store the global sum.
--------------------------------------------------------------------------------------
Now what I implemented in code, also I provide some exmplanations of ocode in directly in file:

- I implemented the logic that calculates how many elements each process receives:
base = ncells / nprocs
remainder = ncells % nprocs

int base = ncells / nprocs;
int rem = ncells % nprocs;

int nsize_local;
int start_index_local;

if (rank < rem) {
    nsize_local = base + 1;
    start_index_local = rank * (base + 1);
} else {
    nsize_local = base;
    start_index_local = rem * (base + 1) + (rank - rem) * base;
}

- Use of MPI_Allgather to build nsizes[]. Each process sends its nsize_local to all other processes.
MPI_Allgather(&nsize_local, 1, MPI_INT, nsizes, 1, MPI_INT, comm);

- Allocation of local array
double *a_local = (double *)malloc(nsize_local * sizeof(double));

- Scatterv call. Scatterv distributes the array from rank 0 to all processes,
using nsizes[] and offsets[] to send exactly the correct portion to each process.
MPI_Scatterv(a_global, nsizes, offsets, MPI_DOUBLE, a_local, nsize_local, MPI_DOUBLE, 0, comm);


- Local sum calculation
double local_sum = 0.0;
for (int i = 0; i < nsize_local; i++) {
    local_sum += a_local[i];
}


- MPI_Reduce to compute final sum
MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, comm);
All partial sums are combined into a total sum on rank 0 using a reduction operation.

- Memory deallocation
if (rank == 0) {
    free(a_global);
}

free(a_local);
free(nsizes);
free(offsets);
Only rank 0 frees a_global since it is the only rank that allocated it.

------------------------------------------------------------------------------

Here are results from terminal:

mirza@Mirza:~$ cd ~/Parallel-Programing-assignments/Example_05
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$ make clean
rm -f PartialSum PartialSum.o timer.o
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$ make
mpicc -c PartialSum.c
mpicc -c timer.c
mpicc PartialSum.o timer.o -o PartialSum
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$ mpirun -n 2 ./PartialSum
Main process initializing array of 10000 elements
Array initialization complete

Rank 1: processed 5000 elements, partial sum = 37502500.00, compute time = 0.000030 sec
Rank 0: processed 5000 elements, partial sum = 12502500.00, compute time = 0.000030 sec

========================================
Timing Results:
  Scatter operation: 0.000313 seconds
  Reduce operation:  0.000022 seconds

Final Results:
  Total sum across all processes: 50005000.00
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$ mpirun -n 4 ./PartialSum
Main process initializing array of 10000 elements
Array initialization complete

Rank 1: processed 2500 elements, partial sum = 9376250.00, compute time = 0.000007 sec
Rank 2: processed 2500 elements, partial sum = 15626250.00, compute time = 0.000007 sec
Rank 0: processed 2500 elements, partial sum = 3126250.00, compute time = 0.000007 sec

Rank 3: processed 2500 elements, partial sum = 21876250.00, compute time = 0.000007 sec
========================================
Timing Results:
  Scatter operation: 0.000510 seconds
  Reduce operation:  0.000021 seconds

Final Results:
  Total sum across all processes: 50005000.00
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$ mpirun -n 8 ./PartialSum
--------------------------------------------------------------------------
There are not enough slots available in the system to satisfy the 8
slots that were requested by the application:

  ./PartialSum

Either request fewer slots for your application, or make more slots
available for use.

A "slot" is the Open MPI term for an allocatable unit where we can
launch a process.  The number of slots available are defined by the
environment in which Open MPI processes are run:

  1. Hostfile, via "slots=N" clauses (N defaults to number of
     processor cores if not provided)
  2. The --host command line parameter, via a ":N" suffix on the
     hostname (N defaults to 1 if not provided)
  3. Resource manager (e.g., SLURM, PBS/Torque, LSF, etc.)
  4. If none of a hostfile, the --host command line parameter, or an
     RM is present, Open MPI defaults to the number of processor cores

In all the above cases, if you want Open MPI to default to the number
of hardware threads instead of the number of processor cores, use the
--use-hwthread-cpus option.

Alternatively, you can use the --oversubscribe option to ignore the
number of available slots when deciding the number of processes to
launch.
--------------------------------------------------------------------------
mirza@Mirza:~/Parallel-Programing-assignments/Example_05$

------------------------------------------------------------
 Cleaner results for you to read easily:

Run with 2 processes
Rank 0:
  Processed elements: 5000
  Partial sum: 12502500.00
  Compute time: 0.000030 sec
Rank 1:
  Processed elements: 5000
  Partial sum: 37502500.00
  Compute time: 0.000030 sec
Scatter operation time: 0.000313 sec
Reduce operation time:  0.000022 sec
Final total sum: 50005000.00
------------------------------------------------------------
Run with 4 processes
Rank 0:
  Processed elements: 2500
  Partial sum: 3126250.00
  Compute time: 0.000007 sec
Rank 1:
  Processed elements: 2500
  Partial sum: 9376250.00
  Compute time: 0.000007 sec
Rank 2:
  Processed elements: 2500
  Partial sum: 15626250.00
  Compute time: 0.000007 sec
Rank 3:
  Processed elements: 2500
  Partial sum: 21876250.00
  Compute time: 0.000007 sec
Scatter operation time: 0.000510 sec
Reduce operation time:  0.000021 sec
Final total sum: 50005000.00
------------------------------------------------------------
Run with 8 processes

Error from MPI:
There are not enough slots available in the system
to satisfy the 8 slots that were requested.

I also proide screenshots.