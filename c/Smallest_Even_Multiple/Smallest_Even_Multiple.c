#include <stdio.h>

/**
 * Smallest Even Multiple
 * Computes the Least Common Multiple (LCM) of 2 and n.
 */
int main() {
    int n;

    // Reading input n
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    /* * Logic:
     * If n is already even, it is the smallest multiple of both 2 and n.
     * If n is odd, the smallest multiple of both is n * 2.
     */
    if (n % 2 == 0) {
        printf("%d\n", n);
    } else {
        printf("%d\n", n * 2);
    }

    return 0;
}
