#include <stdio.h>

/**
 * Divisibility Duel
 * Logic: Prioritize the combined condition to handle "X defeats all!" correctly.
 */
int main() {
    // Use long long to handle inputs up to 10^9 safely
    long long x, y, z;

    if (scanf("%lld %lld %lld", &x, &y, &z) != 3) {
        return 0;
    }

    // Must check both conditions first to satisfy the priority rules
    if (x % y == 0 && x % z == 0) {
        printf("X defeats all!\n");
    } 
    else if (x % y == 0) {
        printf("Y triumphs over X!\n");
    } 
    else if (x % z == 0) {
        printf("Z outsmarts X!\n");
    } 
    else {
        printf("X remains undefeated!\n");
    }

    return 0;
}
