#include <math.h>
#include <omp.h>
#include "timestep.h"

double timestep_opt3(int ncells, double g, double sigma,
                     int * restrict celltype,
                     double * restrict H,
                     double * restrict U,
                     double * restrict V,
                     double * restrict dx,
                     double * restrict dy)
{
    double mymindt = 1.0e20;

    double wavespeed, xspeed, yspeed, dt;

    H  = __builtin_assume_aligned(H, 64);
    U  = __builtin_assume_aligned(U, 64);
    V  = __builtin_assume_aligned(V, 64);
    dx = __builtin_assume_aligned(dx, 64);
    dy = __builtin_assume_aligned(dy, 64);

#pragma omp simd private(wavespeed, xspeed, yspeed, dt) reduction(min:mymindt)
    for (int ic = 0; ic < ncells; ic++) {
        if (celltype[ic] == REAL_CELL) {
            wavespeed = sqrt(g * H[ic]);
            xspeed = (fabs(U[ic]) + wavespeed) / dx[ic];
            yspeed = (fabs(V[ic]) + wavespeed) / dy[ic];
            dt = sigma / (xspeed + yspeed);
            if (dt < mymindt)
                mymindt = dt;
        }
    }

    return mymindt;
}
