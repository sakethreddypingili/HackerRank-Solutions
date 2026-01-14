#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    // Clear rightmost set bit: n & (n-1)
    num = num & (num - 1);
    
    printf("%d", num);
    return 0;
}
