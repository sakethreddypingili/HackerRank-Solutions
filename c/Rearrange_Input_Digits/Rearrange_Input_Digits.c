#include <stdio.h>

/**
 * Rearrange Input Digits
 * Strategy: Manual sorting using a swap-based decision tree.
 * This avoids the massive nesting of 24 permutations.
 */
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Digit Extraction
    int d1 = n / 1000;          // Thousands
    int d2 = (n / 100) % 10;    // Hundreds
    int d3 = (n / 10) % 10;     // Tens
    int d4 = n % 10;            // Units

    int temp;

    // Sorting d1 to be the largest
    if (d1 < d2) { temp = d1; d1 = d2; d2 = temp; }
    if (d1 < d3) { temp = d1; d1 = d3; d3 = temp; }
    if (d1 < d4) { temp = d1; d1 = d4; d4 = temp; }

    // Sorting d2 to be the second largest
    if (d2 < d3) { temp = d2; d2 = d3; d3 = temp; }
    if (d2 < d4) { temp = d2; d2 = d4; d4 = temp; }

    // Sorting d3 and d4
    if (d3 < d4) { temp = d3; d3 = d4; d4 = temp; }

    // Output concatenated digits
    printf("%d%d%d%d\n", d1, d2, d3, d4);

    return 0;
}
