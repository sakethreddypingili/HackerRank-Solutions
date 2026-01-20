#include <stdio.h>

/**
 * Alternate Positive/Negative Sequence
 * Prints i if odd, -i if even.
 */
int main() {
    int n;
    
    // Read the number of terms n
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Iterate from 1 to n
    for (int i = 1; i <= n; i++) {
        // Check if i is even
        if (i % 2 == 0) {
            // Even numbers are printed as negative
            printf("%d ", -i);
        } else {
            // Odd numbers are printed as positive
            printf("%d ", i);
        }
    }

    return 0;
}
