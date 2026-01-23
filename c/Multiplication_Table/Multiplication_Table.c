#include <stdio.h>

/**
 * Main function to generate a multiplication table for n from 1 to 10.
 */
int main() {
    int n;

    // Read the input number n
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Loop from 1 to 10 to generate the table
    for (int i = 1; i <= 10; ++i) {
        // Print the multiplication result in the specified format
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
