#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    // Branch-free minimum: b + ((a-b) & ((a-b)>>31))
    int diff = a - b;
    int result = b + (diff & (diff >> 31));
    
    printf("%d", result);
    return 0;
}
