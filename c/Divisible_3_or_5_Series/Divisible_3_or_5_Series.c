#include <stdio.h>

/**
 * Divisible by 3 or 5 but not both
 * Generates the symmetric difference of multiples of 3 and 5.
 */
int main() {
    int n;

    // Read input upper limit
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Loop through the range 1 to n inclusive
    for (int i = 1; i <= n; ++i) {
        // Logical XOR implementation: 
        // True only if one condition is true and the other is false
        if ((i % 3 == 0) != (i % 5 == 0)) {
            printf("%d ", i);
        }
    }

    return 0;
}
