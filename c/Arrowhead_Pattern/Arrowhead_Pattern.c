#include <stdio.h>

/**
 * Main function to generate a symmetric arrowhead pattern.
 * The pattern expands to width n and then contracts.
 */
int main() {
    int n;

    // Read the input size
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Input validation: Arrowhead requires at least 2 rows to be meaningful
    if (n < 2) {
        printf("Shape Not Possible");
        return 0;
    }

    // Top half of the arrowhead (including the peak row n)
    for (int i = 1; i <= n; i++) {
        printf("*");

        // Rows greater than 1 require a second asterisk and internal spacing
        if (i > 1) {
            for (int k = 1; k <= i - 2; k++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    // Bottom half of the arrowhead (rows n-1 down to 1)
    for (int i = n - 1; i >= 1; i--) {
        printf("*");

        // Rows greater than 1 require a second asterisk and internal spacing
        if (i > 1) {
            for (int k = 1; k <= i - 2; k++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
