#include <stdio.h>

/**
 * Calculates the sum of two integers
 * @param a: first integer
 * @param b: second integer
 * @return: sum of a and b
 */
int calculate(int a, int b) {
    return a + b;  // Integer addition
}

int main() {
    int a, b;                       // Input integers
    scanf("%d %d", &a, &b);         // Read two space-separated integers
    
    int c = calculate(a, b);        // Calculate sum
    
    printf("The sum of %d and %d is %d.", a, b, c);
    return 0;
}
