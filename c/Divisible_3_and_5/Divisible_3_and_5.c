#include <stdio.h>

/**
 * Divisible by 3 and 5
 * Prints multiples of 15 in the range [1, 100].
 */
int main() {
    // Range is 1 to 100 inclusive
    for (int i = 1; i <= 100; i++) {
        // Condition: Divisible by 3 AND divisible by 5
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
