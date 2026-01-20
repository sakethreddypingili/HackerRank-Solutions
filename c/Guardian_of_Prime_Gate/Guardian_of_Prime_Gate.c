#include <stdio.h>
#include <math.h>

/**
 * num_prime_check
 * Returns 1 if the number has a factor (is Composite),
 * Returns 0 if no factors are found (is Prime).
 * Optimized to run in O(sqrt(N)) time.
 */
int is_composite(int num) {
    if (num < 2) return 0; // Handled in main, but safe to include
    
    int limit = (int)sqrt(num);
    for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) {
            return 1; // Factor found, it's composite
        }
    }
    return 0; // No factors found, it's prime
}

int main() {
    long long num; // Using long long to safely handle 10^9 range
    if (scanf("%lld", &num) != 1) {
        return 0;
    }

    // Numbers <= 1 are neither Prime nor Composite
    if (num <= 1) {
        printf("None\n");
    } 
    else {
        if (is_composite(num)) {
            printf("Composite\n");
        } else {
            printf("Prime\n");
        }
    }

    return 0;
}
