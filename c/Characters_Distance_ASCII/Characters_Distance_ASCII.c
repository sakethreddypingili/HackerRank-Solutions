#include <stdio.h>

/**
 * Calculates the alphabetical distance between two characters
 * @param char1: first character
 * @param char2: second character
 * @return: absolute distance between the characters
 */
char calculate(char char1, char char2) {
    int cal = char1 - char2;              // Calculate ASCII difference
    int value = (cal < 0) ? -cal : cal;   // Apply absolute value using ternary
    return value;
}

int main() {
    char char1, char2;                              // Input characters
    scanf("%c %c", &char1, &char2);                 // Read two space-separated chars
    
    int distance = calculate(char1, char2);         // Calculate distance
    
    printf("The distance between %c and %c is %d", char1, char2, distance);
    return 0;
}
