#include <stdio.h>

/**
 * Voting Eligibility Checker
 * Determines if a person can vote based on age >= 18
 */
int main() {
    int age;
    
    // Read single integer input
    scanf("%d", &age);
    
    // Check eligibility and output result
    if (age >= 18) {
        printf("Eligible");
    } else {
        printf("Not Eligible");
    }
    
    return 0;
}
