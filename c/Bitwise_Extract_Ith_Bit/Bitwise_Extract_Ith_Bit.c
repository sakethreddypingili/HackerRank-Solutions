#include <stdio.h>

int main() {
    int n, i;
    scanf("%d %d", &n, &i);

    // Extract the i-th bit by right shifting and masking with 1
    int bit = (n >> i) & 1;
    printf("%d", bit);

    return 0;
}
