#include <stdio.h>
#include <stdbool.h>

/**
 * Number Category Classifier
 * Uses an if-else if ladder to ensure lexicographic priority.
 */

bool is_perfect_square(int n) {
    if (n < 1 || n >= 200) return false;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) return true;
    }
    return false;
}

bool is_distinct_prime_product(int n) {
    // Primes in [2, 11]: 2, 3, 5, 7, 11
    // Possible products: 6, 10, 14, 15, 21, 22, 33, 35, 55, 77
    int valid_products[] = {6, 10, 14, 15, 21, 22, 33, 35, 55, 77};
    for (int i = 0; i < 10; i++) {
        if (n == valid_products[i]) return true;
    }
    return false;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Category A check
    if (n % 2 == 0 && n % 3 == 0 && n % 5 != 0) {
        printf("A\n");
    }
    // Category B check
    else if (n > 20 && is_distinct_prime_product(n)) {
        printf("B\n");
    }
    // Category C check
    else if (((n >= 10 && n <= 99) || (n <= -10 && n >= -99)) && 
             ((n % 3 == 0) != (n % 7 == 0))) {
        printf("C\n");
    }
    // Category D check
    else if (is_perfect_square(n)) {
        printf("D\n");
    }
    // Default Category E
    else {
        printf("E\n");
    }

    return 0;
}
