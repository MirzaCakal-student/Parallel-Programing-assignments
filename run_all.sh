#!/bin/bash
echo "Running all AoSoA tests..."
for test in test_1K test_10K test_100K test_1M test_10M; do
    make $test
done

echo "Merging results..."
echo "N,V,Time(ms)" > combined_results.csv
grep -h -v "N," results_N*.csv >> combined_results.csv

echo "All done! Combined file ready: combined_results.csv"

