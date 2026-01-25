#include <stdio.h>

/**
 * Main function to generate an isosceles triangle pattern.
 * Validates input and uses nested loops for spacing and symbol placement.
 */
int main() {
    int n;

    // Read the number of rows from standard input
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Input validation: Sample inputs define n < 2 as impossible shapes
    if (n < 2) {
        printf("Shape Not Possible");
        return 0;
    }

    // Outer loop manages the row number
    for (int i = 1; i <= n; i++) {

        // First inner loop: Print leading spaces to center the triangle
        for (int k = 1; k <= n - i; k++) {
            printf(" ");
        }

        // Second inner loop: Print the odd number of asterisks for the current row
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        // Advance to the next line
        printf("\n");
    }

    return 0;
}
