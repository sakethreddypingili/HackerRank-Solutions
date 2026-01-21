#include <stdio.h>

/**
 * Main function to generate the first n terms of an 
 * Arithmetic Progression (AP).
 */
int main() {
    int n, a, d;

    // Read the number of terms
    if (scanf("%d", &n) != 1) return 0;

    // Read the first term and the common difference
    if (scanf("%d %d", &a, &d) != 2) return 0;

    // Iterate through n terms
    for (int i = 1; i <= n; ++i) {
        // Calculate the i-th term using the formula: a + (i-1)d
        int current_term = a + (i - 1) * d;
        
        // Print the term followed by a space
        printf("%d ", current_term);
    }

    return 0;
}
