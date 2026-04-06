#include <stdio.h>
#include <time.h>

// Recursive Fibonacci
long long fibonacci_recursive(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative Fibonacci
long long fibonacci_iterative(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    if (n <= 1) return n;

    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

// Measure execution time
double measure_time(long long (*func)(int), int n) {
    clock_t start = clock();
    func(n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    printf("==================================================\n");
    printf("FIBONACCI IMPLEMENTATION IN C\n");
    printf("==================================================\n");

    // Correctness test
    int test_values[] = { 0, 1, 5, 10, 15, 20 };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("\nCorrectness check:\n");
    for (int i = 0; i < num_tests; i++) {
        int n = test_values[i];
        long long rec = fibonacci_recursive(n);
        long long it = fibonacci_iterative(n);
        printf("  F(%d) = %lld (recursive) = %lld (iterative)\n", n, rec, it);
    }

    // Iterative performance
    printf("\nIterative method performance:\n");
    int large_n[] = { 1000, 5000, 10000 };
    for (int i = 0; i < 3; i++) {
        int n = large_n[i];
        double elapsed = measure_time(fibonacci_iterative, n);
        long long result = fibonacci_iterative(n);
        printf("  F(%d) = %lld... | time: %.6f sec\n", n, result, elapsed);
    }

    // Recursive performance (small n only)
    printf("\nRecursive method performance:\n");
    int small_n[] = { 10, 20, 30, 35 };
    for (int i = 0; i < 4; i++) {
        int n = small_n[i];
        double elapsed = measure_time(fibonacci_recursive, n);
        long long result = fibonacci_recursive(n);
        printf("  F(%d) = %lld | time: %.6f sec\n", n, result, elapsed);
    }

    return 0;
}