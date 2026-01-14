#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    // Check if last two bits are 00 using bitwise AND with 3 (11 in binary)
    // Multiple of 4 always ends with 00 in binary
    if ((num & 3) == 0) {
        printf("Yes");
    } else {
        printf("No");
    }
    
    return 0;
}
