#include <stdio.h>
#include "timestep.h"
#define NCELLS 10000000

static double H[NCELLS], U[NCELLS], V[NCELLS], dx[NCELLS], dy[NCELLS];
static int celltype[NCELLS];

int main()
{
    double g = 9.80, sigma = 0.95;
    double mymindt;

    for (int ic = 0; ic < NCELLS; ic++) {
        H[ic] = 10.0;
        U[ic] = 0.0;
        V[ic] = 0.0;
        dx[ic] = 0.5;
        dy[ic] = 0.5;
        celltype[ic] = REAL_CELL;
    }
    H[NCELLS/2] = 20.0;

#if defined(USE_OPT1)
    mymindt = timestep_opt1(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
#elif defined(USE_OPT2)
    mymindt = timestep_opt2(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
#elif defined(USE_OPT3)
    mymindt = timestep_opt3(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
#else
    mymindt = timestep(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
#endif

    printf("Minimum dt is %lf\n", mymindt);
    return 0;
}
