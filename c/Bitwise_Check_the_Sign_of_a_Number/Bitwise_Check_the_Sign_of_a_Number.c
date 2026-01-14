#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // Extract sign bit using arithmetic right shift by 31 positions
    // Positive/Zero: result = 0 (sign bit was 0)
    // Negative: result = -1 (sign bit was 1, arithmetic shift fills 1s)
    if ((n >> 31) == 0) {
        printf("Positive");
    } else {
        printf("Negative");
    }
    
    return 0;
}
