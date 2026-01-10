#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Extracts the last digits of two numbers and returns their sum.
 * 
 * Last digit extraction: number % 10 gives units place digit
 * Maximum sum: 9 + 9 = 18 (no overflow risk)
 * 
 * @param a First integer (0 ≤ a ≤ 10^9) 
 * @param b Second integer (0 ≤ b ≤ 10^9)  
 * @return Sum of last digits (0-18)
 */
int sumLastDigits(int a, int b) {
    // Extract last digit using modulo 10
    int lastDigitA = a % 10;
    int lastDigitB = b % 10;
    
    // Return sum of last digits
    return lastDigitA + lastDigitB;
}

int main() {
    int num1, num2;
    
    // Read two space-separated integers
    scanf("%d %d", &num1, &num2);
    
    // Calculate sum of last digits using required function
    int result = sumLastDigits(num1, num2);
    
    // Output in exact required format
    printf("The sum of last digits is: %d", result);
    
    return 0;
}
