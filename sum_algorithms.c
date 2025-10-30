#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

// Standard sum (double precision)
double do_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    for (long i = 0; i < ncells; i++) {
        sum += var[i];
    }
    return sum;
}

// Long double summation
long double do_longdouble_sum(double* restrict var, long ncells)
{
    long double sum = 0.0L;
    for (long i = 0; i < ncells; i++) {
        sum += (long double)var[i];
    }
    return sum;
}

// Pairwise recursive summation
static double pairwise_recursive(double *var, long start, long end)
{
    if (end - start == 1) return var[start];
    long mid = start + (end - start) / 2;
    double left = pairwise_recursive(var, start, mid);
    double right = pairwise_recursive(var, mid, end);
    return left + right;
}

double do_pairwise_sum(double* restrict var, long ncells)
{
    return pairwise_recursive(var, 0, ncells);
}

// Kahan summation algorithm
double do_kahan_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    double c = 0.0;
    for (long i = 0; i < ncells; i++) {
        double y = var[i] - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

// Knuth summation algorithm
double do_knuth_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    double err = 0.0;
    for (long i = 0; i < ncells; i++) {
        double x = var[i];
        double temp = sum + x;
        if (fabs(sum) >= fabs(x))
            err += (sum - temp) + x;
        else
            err += (x - temp) + sum;
        sum = temp;
    }
    return sum + err;
}
