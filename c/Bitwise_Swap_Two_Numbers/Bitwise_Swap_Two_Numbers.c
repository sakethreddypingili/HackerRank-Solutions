#include <stdio.h>

int main() {
    int A, B;
    
    // Read two integers from separate lines
    scanf("%d", &A);
    scanf("%d", &B);
    
    // XOR swap algorithm (no temporary variable)
    // Step 1: A = A ^ B
    A = A ^ B;
    
    // Step 2: B = A ^ B  → B becomes original A
    B = A ^ B;
    
    // Step 3: A = A ^ B  → A becomes original B
    A = A ^ B;
    
    // Output swapped values on separate lines
    printf("%d\n", A);
    printf("%d\n", B);
    
    return 0;
}
