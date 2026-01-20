#include <stdio.h>

/**
 * Squares of Natural Numbers
 * Prints i*i for every i from 1 to N.
 */
int main() {
    int N;

    // Read the range limit from the user
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    // Standard for loop from 1 to N
    for (int i = 1; i <= N; ++i) {
        // Calculate square using multiplication for better efficiency
        int square = i * i;
        
        // Print the square followed by a space
        printf("%d ", square);
    }

    return 0;
}
