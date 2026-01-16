#include <stdio.h>

/**
 * Program to classify a triangle based on three stick lengths.
 * Validates existence first, then checks side equality.
 */
int main() {
    int a, b, c;

    // Read input stick lengths
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 0;
    }

    // Output the lengths in the required format
    printf("Lengths: [%d, %d, %d]\n", a, b, c);

    // Step 1: Validate using Triangle Inequality Theorem
    // A triangle is invalid if the sum of any two sides is less than or equal to the third.
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Type: Invalid\n");
        printf("Cannot form a valid shape.");
    } 
    // Step 2: Check for Equilateral (all sides equal)
    else if (a == b && b == c) {
        printf("Type: Equilateral\n");
        printf("All sides are of the same length.");
    } 
    // Step 3: Check for Isosceles (at least two sides equal)
    // Since we already checked for Equilateral, this will only catch 'Exactly two'
    else if (a == b || b == c || a == c) {
        printf("Type: Isosceles\n");
        printf("Exactly two sides are equal.");
    } 
    // Step 4: Default to Scalene (no sides equal)
    else {
        printf("Type: Scalene\n");
        printf("All sides are of different lengths.");
    }

    return 0;
}
