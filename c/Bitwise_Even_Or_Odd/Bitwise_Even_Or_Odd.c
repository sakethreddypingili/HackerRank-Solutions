#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    // Check the least significant bit using bitwise AND
    if (num & 1) {
        printf("Odd");
    } else {
        printf("Even");
    }
    
    return 0;
}
