#include <stdio.h>

int main() {
    int num, i;
    scanf("%d", &num);    // Read number
    scanf("%d", &i);      // Read bit position
    
    // Toggle i-th bit using XOR with mask
    num = num ^ (1 << i);
    
    printf("%d", num);    // Print result
    return 0;
}
