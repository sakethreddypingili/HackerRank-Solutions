#include <stdio.h>

/**
 * Function to calculate tax based on progressive slabs.
 * Returns the tax amount, or -1.0 if the income is invalid.
 */
double calculate_tax(double income) {
    if (income < 0) {
        return -1.0;
    }

    double tax = 0.0;

    if (income <= 250000) {
        tax = 0.0;
    } 
    else if (income <= 500000) {
        tax = (income - 250000) * 0.05;
    } 
    else if (income <= 1000000) {
        // 5% on 2.5L to 5L (fixed 12500) + 20% on the rest
        tax = (250000 * 0.05) + (income - 500000) * 0.20;
    } 
    else {
        // 5% on 2.5L to 5L (12500) + 20% on 5L to 10L (100000) + 30% on the rest
        tax = (250000 * 0.05) + (500000 * 0.20) + (income - 1000000) * 0.30;
    }

    return tax;
}

int main() {
    double income;

    // Read income from standard input
    if (scanf("%lf", &income) != 1) {
        return 0;
    }

    double result = calculate_tax(income);

    if (result < 0) {
        printf("INVALID\n");
    } else {
        printf("%.2f\n", result);
    }

    return 0;
}
