#include <stdio.h>

/**
 * Converts 24-hour format to 12-hour format (1-12)
 * @param hour 24-hour format (0-23)
 * @return 12-hour format hour (1-12)
 */
int convertTo12Hour(int hour) {
    if (hour == 0) {
        return 12;  // Midnight
    } else if (hour <= 12) {
        return hour;  // 1-12 remains same
    } else {
        return hour - 12;  // 13-23 becomes 1-11
    }
}

int main() {
    int hour, minutes;
    
    // Read 24-hour time input
    scanf("%d %d", &hour, &minutes);
    
    // Determine AM/PM period
    const char* period = (hour >= 12) ? "PM" : "AM";
    
    // Convert hour to 12-hour format
    int hour12 = convertTo12Hour(hour);
    
    // Print formatted 12-hour time
    printf("%02d:%02d %s\n", hour12, minutes, period);
    
    return 0;
}
