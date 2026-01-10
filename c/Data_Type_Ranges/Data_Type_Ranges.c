#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    /* * Integer Types
     * Using specific format specifiers:
     * %hd = short, %d = int, %ld = long, %lld = long long
     */
    printf("short: %hd to %hd\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    
    /* * Unsigned Integer Types
     * Minimum is always 0.
     * %hu = unsigned short, %u = unsigned int, %lu = unsigned long, %llu = unsigned long long
     */
    printf("unsigned short: 0 to %hu\n", USHRT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);
    printf("unsigned long long: 0 to %llu\n", ULLONG_MAX);
    
    /* * Character Types
     * Printed as integers (%d) to show numeric range.
     * char promotes to int in printf.
     */ 
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: 0 to %d\n", UCHAR_MAX);
    
    /* * Floating-Point Types
     * Using %e for scientific notation.
     * Note: FLT_MIN/DBL_MIN represent the smallest positive normalized number.
     * %Le is required for long double.
     */
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    
    return 0;
}
