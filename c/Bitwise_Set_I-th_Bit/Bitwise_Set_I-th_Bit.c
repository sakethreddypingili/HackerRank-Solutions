#include <stdio.h>

int main() {
    int n, i;
    
    // Read input: n on first line, i on second line
    scanf("%d", &n);
    scanf("%d", &i);
    
    // Create mask with 1 at position i
    int mask = 1 << i;
    
    // Set i-th bit using bitwise OR
    int result = n | mask;
    
    // Output result
    printf("%d\n", result);
    
    return 0;
}
