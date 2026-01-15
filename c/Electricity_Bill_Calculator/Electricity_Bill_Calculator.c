#include <stdio.h>

/**
 * Calculates the electricity bill based on tiered pricing and discounts.
 */
void calculate_and_print_bill(int n) {
    if (n < 0) {
        printf("Invalid Input!");
        return;
    }

    double bill = 0.0;

    // Calculate gross bill based on slabs
    if (n <= 100) {
        bill = n * 5.0;
    } else if (n <= 300) {
        bill = (100 * 5.0) + (n - 100) * 7.0;
    } else {
        bill = (100 * 5.0) + (200 * 7.0) + (n - 300) * 10.0;
    }

    // Apply 10% discount if the bill is 1200 or less
    if (bill <= 1200.0) {
        bill = bill * 0.90;
    }

    // Print with exactly two decimal places
    printf("The electricity bill is: %.2f.", bill);
}

int main() {
    int n;

    // Read input consumption units
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    calculate_and_print_bill(n);

    return 0;
}
