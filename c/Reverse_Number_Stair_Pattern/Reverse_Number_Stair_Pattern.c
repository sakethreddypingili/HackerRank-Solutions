#include <stdio.h>

/**
 * Main function to generate a reverse number stair pattern.
 * The pattern starts from N to 1 and reduces the start point each row.
 */
int main() {
    int n;

    // Read input N
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Outer loop for the number of rows
    for (int i = 0; i < n; i++) {
        // The starting value for each row decreases as 'i' increases
        int start_val = n - i;

        // Inner loop to print numbers from start_val down to 1
        for (int j = start_val; j >= 1; j--) {
            printf("%d", j);
            
            // Print space between numbers
            if (j > 1) {
                printf(" ");
            }
        }
        
        // Move to the next line after finishing a row
        printf("\n");
    }

    return 0;
}
