//
// Created by Adnan Hajro
//

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include "timer.h"

int main(int argc, char *argv[])
{
    int rank, nprocs;
    int ncells = 10000;
    struct timespec tstart_time;

    // Process initialization with communicator, getting rank and number of processes
    MPI_Init(&argc, &argv);
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &nprocs);


    // Calculate the size of array portion for each process
    // Calculate the starting and ending index for each process
    // You can use the book chapter for this week to help you calculate bounds properly
    // Your code here..

    /* We split ncells among nprocs as evenly as possible:
       base = ncells / nprocs
       remainder = ncells % nprocs
       For ranks < remainder -> they get base+1 elements
       For ranks >= remainder -> they get base elements
       This scheme ensures sum(nsizes) == ncells. */

    int base = ncells / nprocs;
    int rem = ncells % nprocs;

    int nsize_local;        // number of elements assigned to this rank
    int start_index_local;  // starting index in the global array for this rank (if needed)

    if (rank < rem) {
        nsize_local = base + 1;
        start_index_local = rank * (base + 1);
    } else {
        nsize_local = base;
        start_index_local = rem * (base + 1) + (rank - rem) * base;
    }

    // Main process creates and initializes the global array
    double *a_global = NULL;
    if (rank == 0) {
        a_global = (double *)malloc(ncells * sizeof(double));
        if (a_global == NULL) {
            fprintf(stderr, "Rank 0: failed to allocate a_global\n");
            MPI_Abort(comm, 1);
        }

        printf("Main process initializing array of %d elements\n", ncells);

        for (int i = 0; i < ncells; i++) {
            a_global[i] = (double)(i + 1); // store 1..ncells
        }
        printf("Array initialization complete\n\n");
    }

    // Set up arrays for sizes and offsets for scatter operation
    int *nsizes = (int *)malloc(nprocs * sizeof(int));
    int *offsets = (int *)malloc(nprocs * sizeof(int));
    if (nsizes == NULL || offsets == NULL) {
        fprintf(stderr, "Rank %d: failed to allocate nsizes/offsets\n", rank);
        MPI_Abort(comm, 2);
    }

    // You need to use one of the collective communication calls to provide nsize from all processes to
    // each process and store it in "nsizes" array declared above. Look at MPI_Allgather!
    MPI_Allgather(&nsize_local, 1, MPI_INT, nsizes, 1, MPI_INT, comm);

   
    offsets[0] = 0;
    for (int i = 1; i < nprocs; i++) {
        offsets[i] = offsets[i - 1] + nsizes[i - 1];
    }

    // Allocate local array on each process
    // Your code here..
    double *a_local = (double *)malloc(nsize_local * sizeof(double));
    if (a_local == NULL) {
        fprintf(stderr, "Rank %d: failed to allocate a_local of size %d\n", rank, nsize_local);
        MPI_Abort(comm, 3);
    }

    cpu_timer_start(&tstart_time);

    // Explain what Scatterv does
    /* MPI_Scatterv splits (scatters) different amounts of data to each process. 
    On the root (rank 0), a_global is the send buffer and nsizes/displs describe how many
    elements and where each rank's data starts. Each receiving process provides a_local
    and its receive count (nsize_local). */

    MPI_Scatterv(a_global, nsizes, offsets, MPI_DOUBLE,
                 a_local, nsize_local, MPI_DOUBLE, 0, comm);

    double scatter_time = cpu_timer_stop(tstart_time);

   
    cpu_timer_start(&tstart_time);

    double local_sum = 0.0;
    for (int i = 0; i < nsize_local; i++) {
        local_sum += a_local[i];
    }

    double compute_time = cpu_timer_stop(tstart_time);

    printf("Rank %d: processed %d elements, partial sum = %.2f, compute time = %lf sec\n",
           rank, nsize_local, local_sum, compute_time);

    double total_sum = 0.0;

    cpu_timer_start(&tstart_time);

    // Use reduce collective communication call to get the total sum of all local sums
    // Your code here..
    // We use MPI_Reduce with MPI_SUM so rank 0 receives the total sum.
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, comm);

    double reduce_time = cpu_timer_stop(tstart_time);

    // Explain why only rank 0 needs to deallocate the resources
    /* a_global was only allocated by rank 0 root. Other ranks never allocated it, 
    so only rank 0 should free it to avoid double free or freeing NULL incorrectly. */

    if (rank == 0) {
        printf("\n========================================\n");
        printf("Timing Results:\n");
        printf("  Scatter operation: %lf seconds\n", scatter_time);
        printf("  Reduce operation:  %lf seconds\n", reduce_time);
        printf("\n");
        printf("Final Results:\n");
        printf("  Total sum across all processes: %.2f\n", total_sum);

        free(a_global);
    }

    free(a_local);
    free(nsizes);
    free(offsets);

    MPI_Finalize();
    return 0;
}
