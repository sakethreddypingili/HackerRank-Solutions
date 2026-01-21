#include <stdio.h>

/**
 * Problem: Generate N squares, skipping those divisible by 3.
 */
int main() {
    int n;
    int count = 0;
    int i = 1;

    // Read the number of elements required in the series
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Continue until we have successfully printed N numbers
    while (count < n) {
        int square = i * i;

        // Check if the square is not divisible by 3
        if (square % 3 != 0) {
            printf("%d ", square);
            count++; // Only increment count when a number is printed
        }
        
        // Increment the base number to check the next square
        i++;
    }

    return 0;
}
