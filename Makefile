# ===============================
# Example_03 – Vectorization Task
# ===============================

CC = gcc
CFLAGS = -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd \
         -march=native -mtune=native -mprefer-vector-width=256 \
         -fopt-info-vec-optimized -fopt-info-vec-missed
LDFLAGS = -lm

# ---------------------------------------
#  Executable builds
# ---------------------------------------

all: baseline opt1 opt2 opt3

# Baseline = original timestep.c
baseline: main.c timer.c timestep.c
	$(CC) $(CFLAGS) -o baseline main.c timer.c timestep.c $(LDFLAGS)

# Optimized versions
opt1: main.c timer.c timestep_opt1.c
	$(CC) $(CFLAGS) -o opt1 main.c timer.c timestep_opt1.c $(LDFLAGS)

opt2: main.c timer.c timestep_opt2.c
	$(CC) $(CFLAGS) -o opt2 main.c timer.c timestep_opt2.c $(LDFLAGS)

opt3: main.c timer.c timestep_opt3.c
	$(CC) $(CFLAGS) -fno-trapping-math -fno-math-errno -o opt3 main.c timer.c timestep_opt3.c $(LDFLAGS)

# ---------------------------------------
#  Clean
# ---------------------------------------
clean:
	rm -f baseline opt1 opt2 opt3 *.o

# ---------------------------------------
#  LIKWID run targets
# ---------------------------------------

run-baseline: baseline
	LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./baseline

run-opt1: opt1
	LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt1

run-opt2: opt2
	LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt2

run-opt3: opt3
	LIKWID_PIN=0 likwid-perfctr -C 0 -g FLOPS_DP ./opt3

.PHONY: all clean run-baseline run-opt1 run-opt2 run-opt3
