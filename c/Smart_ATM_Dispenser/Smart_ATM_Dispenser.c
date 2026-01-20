#include <stdio.h>

/**
 * Smart ATM Note Dispensing Machine
 * Follows a greedy approach to minimize the total number of notes.
 */
int main() {
    int amount;
    
    // Read the withdrawal amount
    if (scanf("%d", &amount) != 1) {
        return 0;
    }

    // Input Validation
    if (amount <= 0) {
        printf("Invalid amount\n");
        return 0;
    }

    // Denomination Calculation (Priority: 500 -> 200 -> 100)
    int notes500 = amount / 500;
    amount %= 500;

    int notes200 = amount / 200;
    amount %= 200;

    int notes100 = amount / 100;

    // Formatted Output
    printf("500-rupee notes: %d\n", notes500);
    printf("200-rupee notes: %d\n", notes200);
    printf("100-rupee notes: %d\n", notes100);

    return 0;
}
