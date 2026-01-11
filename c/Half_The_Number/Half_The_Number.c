#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate half of a number as float
float calculate(float num) {
    return num / 2;
}

int main() {
    int num;
    
    // Read integer input
    scanf("%d", &num);
    
    // Calculate half value
    float half = calculate(num);
    
    // Print formatted output with 2 decimal places
    printf("Half of %d is %.2f", num, half);
    
    return 0;
}
