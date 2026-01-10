#include <stdio.h>

/**
 * Converts a lowercase character to uppercase using ASCII arithmetic
 * @param b: lowercase character to convert
 * @return: corresponding uppercase character
 */
char convert(char b) {
    return b - 32;  // ASCII difference between lowercase and uppercase
}

int main() { 
    char a;              // Input lowercase character
    scanf("%c", &a);     // Read single character from input
    
    char b = convert(a); // Convert to uppercase
    
    printf("The uppercase of %c is %c", a, b);
    return 0;
}
