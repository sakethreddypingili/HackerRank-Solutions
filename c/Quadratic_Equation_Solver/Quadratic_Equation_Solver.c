#include <stdio.h>
#include <math.h>

/**
 * Quadratic Equation Solver
 * Handles Real (Distinct/Equal) and Complex roots using the discriminant.
 */

int main() {
    double a, b, c;
    
    // Using double for precision during math operations
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        return 0;
    }

    double discriminant = (b * b) - (4.0 * a * c);

    if (discriminant > 0) {
        // Real and Distinct
        double r1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double r2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("Roots: %.2f, %.2f\n", r1, r2);
        printf("Type: Real and Distinct");
    } 
    else if (discriminant == 0) {
        // Real and Equal
        double r = -b / (2.0 * a);
        // Handle case where -0.00 might be printed instead of 0.00
        if (r == -0.0) r = 0.0; 
        printf("Roots: %.2f, %.2f\n", r, r);
        printf("Type: Real and Equal");
    } 
    else {
        // Complex Roots
        double realPart = -b / (2.0 * a);
        // We take the root of -discriminant to get a positive value for the imaginary part
        double imagPart = sqrt(-discriminant) / (2.0 * a);
        
        // Ensure the imaginary part displayed is positive in the output string
        if (imagPart < 0) imagPart = -imagPart;

        printf("Roots: %.2f + %.2fi, %.2f - %.2fi\n", realPart, imagPart, realPart, imagPart);
        printf("Type: Complex");
    }

    return 0;
}
