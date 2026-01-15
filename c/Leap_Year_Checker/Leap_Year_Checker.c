#include <stdio.h>

/**
 * Main function to determine if a year is a leap year.
 * Follows Gregorian calendar rules and handles invalid inputs.
 */
int main() {
    int year;

    // Read the year input
    if (scanf("%d", &year) != 1) {
        return 0;
    }

    // Step 1: Validate input
    if (year <= 0) {
        printf("The given year %d is Invalid year.", year);
    } 
    // Step 2: Check for divisible by 400 (Leap Year)
    else if (year % 400 == 0) {
        printf("Yes, %d is a leap year.", year);
    } 
    // Step 3: Check for divisible by 100 (Not a Leap Year)
    else if (year % 100 == 0) {
        printf("No, %d is not a leap year.", year);
    } 
    // Step 4: Check for divisible by 4 (Leap Year)
    else if (year % 4 == 0) {
        printf("Yes, %d is a leap year.", year);
    } 
    // Step 5: Everything else (Not a Leap Year)
    else {
        printf("No, %d is not a leap year.", year);
    }

    return 0;
}
