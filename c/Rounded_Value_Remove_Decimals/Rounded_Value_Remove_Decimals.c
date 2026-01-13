#include <stdio.h>

int main() {
    float num1;
    scanf("%f", &num1);
    
    int num2 = num1;  // Truncates decimal portion
    
    printf("Rounded Value = %d", num2);
    return 0;
}
