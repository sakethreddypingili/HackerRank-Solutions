#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Combines four digits into a 4-digit number and multiplies by 5
 * @param a First digit (thousands place)
 * @param b Second digit (hundreds place)
 * @param c Third digit (tens place)
 * @param d Fourth digit (ones place)
 * @return The combined 4-digit number multiplied by 5
 */
int buildNumber(int a, int b, int c, int d) {
    // Combine digits using positional notation
    int combined = a * 1000 + b * 100 + c * 10 + d;
    
    // Multiply by 5 and return
    return combined * 5;
}

int main() {
    int digit1, digit2, digit3, digit4;
    
    // Read four space-separated digits
    scanf("%d %d %d %d", &digit1, &digit2, &digit3, &digit4);
    
    // Calculate result using the buildNumber function
    int result = buildNumber(digit1, digit2, digit3, digit4);
    
    // Print formatted output
    printf("The number is: %d", result);
    
    return 0;
}
