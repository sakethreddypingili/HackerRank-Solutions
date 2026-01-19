#include <stdio.h>

/**
 * Next-Day Date Calculator
 * Handles leap years, month roll-overs, and year transitions using nested if-else.
 */
int main() {
    int day, month, year;
    if (scanf("%d %d %d", &day, &month, &year) != 3) {
        return 0;
    }

    int maxDay;

    // 1. Determine the maximum days in the current month
    if (month == 2) {
        // Leap year check
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } 
    else {
        maxDay = 31;
    }

    // 2. Calculate the next day logic
    if (day < maxDay) {
        day++;
    } 
    else {
        day = 1;
        if (month == 12) {
            month = 1;
            year++;
        } else {
            month++;
        }
    }

    // 3. Formatted output: %02d ensures leading zeros for DD and MM
    printf("%02d-%02d-%d\n", day, month, year);

    return 0;
}
