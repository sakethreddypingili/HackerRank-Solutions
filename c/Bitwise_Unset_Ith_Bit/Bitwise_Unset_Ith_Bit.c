#include <stdio.h>

int main() {
    int num, i;
    scanf("%d", &num);    // Read number
    scanf("%d", &i);      // Read bit position
    
    // Unset i-th bit: AND with inverted mask
    num = num & ~(1 << i);
    
    printf("%d", num);    // Print result
    return 0;
}
