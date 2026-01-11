#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Declare variables for all required data types
    int a;
    long b;
    char c;
    float d;
    double e;
    
    // Read all 5 values in single line
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    
    // Print each value on separate line with required precision
    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%c\n", c);
    printf("%.3f\n", d);
    printf("%.9lf", e);
    
    return 0;
}
