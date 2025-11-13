CC = gcc
CFLAGS = -fopenmp -Wall -std=c11 -march=native -O3
LDFLAGS = -lm

# Stencil source files
SOURCES = stencil_opt2.c stencil_opt4.c stencil_opt6.c

# Executables with same base names as sources
EXECUTABLES = $(SOURCES:.c=)

# Utility object files
UTILS = timer.o malloc2D.o

# Default target: build everything
all: $(EXECUTABLES)
	@echo "All stencil executables built successfully!"

# Generic rule for building each stencil version
%: %.c $(UTILS)
	@echo "Building $@..."
	$(CC) $(CFLAGS) $< $(UTILS) -o $@ $(LDFLAGS)

# Compile timer utility
timer.o: timer.c timer.h
	@echo "Compiling timer..."
	$(CC) $(CFLAGS) -c timer.c -o $@

# Compile malloc2D utility
malloc2D.o: malloc2D.c malloc2D.h
	@echo "Compiling malloc2D..."
	$(CC) $(CFLAGS) -c malloc2D.c -o $@

# Run targets (optional)
run-opt2: stencil_opt2
	./stencil_opt2

run-opt4: stencil_opt4
	./stencil_opt4

run-opt6: stencil_opt6
	./stencil_opt6

# Clean
clean:
	@echo "Cleaning up..."
	rm -f $(EXECUTABLES) $(UTILS)

# Clean and rebuild
rebuild: clean all

.PHONY: all clean rebuild run-opt2 run-opt4 run-opt6
