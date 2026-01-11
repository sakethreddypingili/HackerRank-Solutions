#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to split 3-digit number into individual digits
void split(int n) {
    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int units = n % 10;
    
    printf("%d %d %d", hundreds, tens, units);
}

int main() {
    int number;
    
    // Read 3-digit input
    scanf("%d", &number);
    
    // Extract and print digits using function
    split(number);
    
    return 0;
}
