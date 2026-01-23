#include <stdio.h>

/**
 * Main function to generate a sequence of n terms
 * where each term is double the previous one.
 */
int main() {
    int n;
    
    // Read input n
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Per problem constraints, if series doesn't exist, print nothing
    if (n <= 0) {
        return 0;
    }

    printf("<");

    // Use long long to prevent overflow for n up to 35
    long long current_term = 1;

    for (int i = 1; i <= n; i++) {
        // Print the current term
        printf("%lld", current_term);

        // If it's not the last term, print a space separator
        if (i < n) {
            printf(" ");
        }

        // Double the term for the next iteration
        current_term *= 2;
    }

    printf(">");

    return 0;
}
