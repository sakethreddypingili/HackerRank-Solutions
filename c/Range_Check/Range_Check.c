#include <stdio.h>

/**
 * Range Check: Determines if number is within inclusive bounds
 */
int main() {
    int n, low, high;
    
    // Read three integers from input
    scanf("%d %d %d", &n, &low, &high);
    
    // Check if n is in inclusive range [low, high]
    if (n >= low && n <= high) {
        printf("In Range");
    } else {
        printf("Out of Range");
    }
    
    return 0;
}
