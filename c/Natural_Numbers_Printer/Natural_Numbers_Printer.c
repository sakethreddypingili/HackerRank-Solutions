#include <stdio.h>

/**
 * Natural Numbers Printer
 * Prints numbers from 1 to N followed by a space.
 */
int main() {
    int N;

    // Read the limit N from standard input
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    // Loop from 1 up to and including N
    for (int i = 1; i <= N; ++i) {
        // Print current number followed by a space
        printf("%d ", i);
    }

    return 0;
}
