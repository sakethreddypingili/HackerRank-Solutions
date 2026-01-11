
***

## solution.c

```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Checks if two numbers have the same last digit (without modulo)
 * @param num1 First number
 * @param num2 Second number
 * @return 1 if same last digit, 2 if different
 */
int checkLastDigit(int num1, int num2) {
    // Extract last digit: num - (num/10)*10
    int lastDigit1 = num1 - (num1 / 10) * 10;
    int lastDigit2 = num2 - (num2 / 10) * 10;
    
    return (lastDigit1 == lastDigit2) ? 1 : 2;
}

int main() {
    int num1, num2;
    
    // Read two integers
    scanf("%d %d", &num1, &num2);
    
    // Check if last digits match
    int result = checkLastDigit(num1, num2);
    
    // Output YES or NO
    if (result == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}
