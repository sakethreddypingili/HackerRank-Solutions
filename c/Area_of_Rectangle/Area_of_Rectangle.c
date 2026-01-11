#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate area of rectangle
int area(int length, int width) {
    return length * width;
}

int main() {
    int length, width;
    
    // Read input dimensions
    scanf("%d %d", &length, &width);
    
    // Calculate area using the function
    int result = area(length, width);
    
    // Print formatted output
    printf("The area is: %d units", result);
    
    return 0;
}
