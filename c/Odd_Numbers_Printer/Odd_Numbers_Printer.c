#include <stdio.h>

/**
 * Odd Numbers Printer
 * Uses a step-increment of 2 to efficiently skip even numbers.
 */
int main() {
    int N;

    // Reading the range limit N
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    // Start at 1 (the first odd number)
    // Increment by 2 to hit only subsequent odd numbers (3, 5, 7...)
    for (int i = 1; i <= N; i += 2) {
        printf("%d ", i);
    }

    return 0;
}
