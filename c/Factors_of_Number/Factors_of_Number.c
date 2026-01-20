#include <stdio.h>
#include <math.h>

/**
 * Print All Factors of a Number
 * Optimized to O(sqrt(N)) to handle N up to 10^9.
 */
int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    // First pass: Print all factors up to sqrt(n)
    long long i;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%lld ", i);
        }
    }

    // i is now just above sqrt(n). We move back down.
    i--; 

    // Second pass: Print the partner factors (n/i) in ascending order
    for (; i >= 1; i--) {
        if (n % i == 0) {
            long long partner = n / i;
            // Avoid printing the square root twice (e.g., 5*5=25)
            if (partner != i) {
                printf("%lld ", partner);
            }
        }
    }

    return 0;
}
