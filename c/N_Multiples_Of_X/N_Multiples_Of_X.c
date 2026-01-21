#include <stdio.h>

/**
 * Problem: Print the first n multiples of x.
 * The multiples are calculated as x * 1, x * 2, ..., x * n.
 */
int main() {
    int n, x;

    // Read n (count) and x (base number)
    if (scanf("%d %d", &n, &x) != 2) {
        return 0;
    }

    // Iterate from 1 up to n to calculate each multiple
    for (int i = 1; i <= n; ++i) {
        // Calculate and print the product followed by a space
        printf("%d ", x * i);
    }

    return 0;
}
