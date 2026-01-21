#include <stdio.h>

/**
 * Main function to generate and print the Collatz sequence.
 * The sequence starts at a given n and ends at 1.
 */
int main() {
    int n;
    
    // Read starting integer
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    while (1) {
        // Print current number in the sequence
        printf("%d", n);

        // Terminate sequence once 1 is reached
        if (n == 1) {
            break;
        }

        // Print separator
        printf(" -> ");

        // Apply Collatz rules
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }

    return 0;
}
