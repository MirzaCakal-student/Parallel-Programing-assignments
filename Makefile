CC = gcc

# Common SIMD / optimization flags
CFLAGS = -g -O3 -fstrict-aliasing -ftree-vectorize \
         -fopenmp-simd -march=native -mtune=native \
         -mprefer-vector-width=256 \
         -fopt-info-vec-optimized -fopt-info-vec-missed

LDFLAGS = -lm
OPT3_FLAGS = -fno-trapping-math -fno-math-errno

all: baseline opt1 opt2 opt3

# -------- Objects shared by all builds --------
timer.o: timer.c timer.h
	$(CC) $(CFLAGS) -c timer.c

# -------- main.c compiled per-target --------
main_base.o: main.c timer.h timestep.h
	$(CC) $(CFLAGS) -c main.c -o main_base.o

main_opt1.o: main.c timer.h timestep.h
	$(CC) $(CFLAGS) -DUSE_OPT1 -c main.c -o main_opt1.o

main_opt2.o: main.c timer.h timestep.h
	$(CC) $(CFLAGS) -DUSE_OPT2 -c main.c -o main_opt2.o

main_opt3.o: main.c timer.h timestep.h
	$(CC) $(CFLAGS) -DUSE_OPT3 -c main.c -o main_opt3.o

# -------- Baseline --------
timestep.o: timestep.c timestep.h
	$(CC) $(CFLAGS) -c timestep.c

baseline: main_base.o timer.o timestep.o
	$(CC) $(CFLAGS) -o $@ main_base.o timer.o timestep.o $(LDFLAGS)

# -------- Opt1 --------
timestep_opt1.o: timestep_opt1.c timestep.h
	$(CC) $(CFLAGS) -c timestep_opt1.c

opt1: main_opt1.o timer.o timestep_opt1.o
	$(CC) $(CFLAGS) -o $@ main_opt1.o timer.o timestep_opt1.o $(LDFLAGS)

# -------- Opt2 --------
timestep_opt2.o: timestep_opt2.c timestep.h
	$(CC) $(CFLAGS) -c timestep_opt2.c

opt2: main_opt2.o timer.o timestep_opt2.o
	$(CC) $(CFLAGS) -o $@ main_opt2.o timer.o timestep_opt2.o $(LDFLAGS)

# -------- Opt3 --------
timestep_opt3.o: timestep_opt3.c timestep.h
	$(CC) $(CFLAGS) $(OPT3_FLAGS) -c timestep_opt3.c

opt3: main_opt3.o timer.o timestep_opt3.o
	$(CC) $(CFLAGS) $(OPT3_FLAGS) -o $@ main_opt3.o timer.o timestep_opt3.o $(LDFLAGS)

clean:
	rm -f baseline opt1 opt2 opt3 *.o
