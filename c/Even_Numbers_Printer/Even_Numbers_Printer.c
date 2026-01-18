#include <stdio.h>

/**
 * Even Numbers Printer
 * Optimizes performance by stepping through the loop by 2.
 */
int main() {
    int N;

    // Read input range limit
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    // Start at 2 (first even number in range 1-N)
    // Increment by 2 to hit only even numbers
    for (int i = 2; i <= N; i += 2) {
        printf("%d ", i);
    }

    return 0;
}
