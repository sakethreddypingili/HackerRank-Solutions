#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    int count = 0;
    
    // Check first 4 bits (positions 0,1,2,3)
    for (int i = 0; i < 4; i++) {
        if (num & (1 << i)) {
            count++;
        }
    }
    
    printf("%d", count);
    return 0;
}
