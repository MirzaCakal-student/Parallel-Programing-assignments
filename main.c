//
// Created by Mirza Cakal (based on Adnan Hajro's week-5 base code)
// Global Sum Precision Assignment
//

#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "sum_algorithms.h"

#define ORDERS_OF_MAGNITUDE 1.0e9

// ---------------------------
// TIMER FUNCTIONS
// ---------------------------
void cpu_timer_start(struct timespec *tstart_cpu) {
    clock_gettime(CLOCK_MONOTONIC, tstart_cpu);
}

double cpu_timer_stop(struct timespec tstart_cpu) {
    struct timespec tstop_cpu, tresult;
    clock_gettime(CLOCK_MONOTONIC, &tstop_cpu);

    tresult.tv_sec = tstop_cpu.tv_sec - tstart_cpu.tv_sec;
    tresult.tv_nsec = tstop_cpu.tv_nsec - tstart_cpu.tv_nsec;

    return (double)tresult.tv_sec + (double)tresult.tv_nsec * 1.0e-9;
}

// ---------------------------
// MAIN PROGRAM
// ---------------------------
int main(int argc, char *argv[])
{
    printf("========================================\n");
    printf(" Global Sum Precision and Performance Test\n");
    printf("========================================\n\n");

    /*
     * Test with different array sizes - powers of 2 from 2^10 to 2^27
     *
     * We use powers of 2 because:
     * 1. Pairwise summation divides cleanly
     * 2. They reflect natural sizes for parallel problems
     * 3. It lets us observe exponential error scaling
     */
    for (int pow_of_two = 10; pow_of_two <= 27; pow_of_two++) {

        long ncells = (long)pow(2.0, (double)pow_of_two);
        long ncellsdiv2 = ncells / 2;

        printf("----------------------------------------\n");
        printf("TESTING WITH 2^%d = %ld elements\n", pow_of_two, ncells);
        printf("----------------------------------------\n");

        // Define value pattern for the Leblanc problem
        double high_value = 1.0e-1;
        double low_value  = 1.0e-1 / ORDERS_OF_MAGNITUDE;

        // Accurate reference sum
        double accurate_sum = (double)ncellsdiv2 * high_value +
                              (double)ncellsdiv2 * low_value;

        // Allocate memory
        double *energy = (double *)malloc(ncells * sizeof(double));
        if (energy == NULL) {
            fprintf(stderr, "❌ Error: Failed to allocate memory for %ld elements\n", ncells);
            return 1;
        }

        // Initialize array
        for (long i = 0; i < ncells; i++) {
            energy[i] = (i < ncellsdiv2) ? high_value : low_value;
        }

        printf("Expected accurate sum: %-17.16lg\n\n", accurate_sum);

        struct timespec timer;
        double runtime;
        double test_sum;
        long double long_sum;

        //Standard double summation
       
        cpu_timer_start(&timer);
        test_sum = do_sum(energy, ncells);
        runtime = cpu_timer_stop(timer);
        printf("Standard double  -> sum: %-17.16lg diff: %-12.6lg rel_diff: %-10.6lg time: %.6lf s\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum) / accurate_sum, runtime);


        //Long double summation
        
        cpu_timer_start(&timer);
        long_sum = do_longdouble_sum(energy, ncells);
        runtime = cpu_timer_stop(timer);
        printf("Long double      -> sum: %-17.16Lg diff: %-12.6Lg rel_diff: %-10.6Lg time: %.6lf s\n",
               long_sum, (long_sum - accurate_sum), (long_sum - accurate_sum) / accurate_sum, runtime);

   
        //Pairwise summation
       
        cpu_timer_start(&timer);
        test_sum = do_pairwise_sum(energy, ncells);
        runtime = cpu_timer_stop(timer);
        printf("Pairwise sum     -> sum: %-17.16lg diff: %-12.6lg rel_diff: %-10.6lg time: %.6lf s\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum) / accurate_sum, runtime);

        //Kahan summation
        
        cpu_timer_start(&timer);
        test_sum = do_kahan_sum(energy, ncells);
        runtime = cpu_timer_stop(timer);
        printf("Kahan sum        -> sum: %-17.16lg diff: %-12.6lg rel_diff: %-10.6lg time: %.6lf s\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum) / accurate_sum, runtime);

        //Knuth summation
        
        cpu_timer_start(&timer);
        test_sum = do_knuth_sum(energy, ncells);
        runtime = cpu_timer_stop(timer);
        printf("Knuth sum        -> sum: %-17.16lg diff: %-12.6lg rel_diff: %-10.6lg time: %.6lf s\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum) / accurate_sum, runtime);

        free(energy);
        printf("\n");
    }

    printf("========================================\n");
    printf("All tests complete!\n");
    printf("========================================\n");

    return 0;
}
