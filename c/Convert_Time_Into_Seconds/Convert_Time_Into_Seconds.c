#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Converts time given in hours, minutes, and seconds to total seconds.
 * 
 * Formula: total_seconds = (hours * 3600) + (minutes * 60) + seconds
 * 
 * @param hours The number of hours (0-100)
 * @param minutes The number of minutes (0-59)
 * @param seconds The number of seconds (0-59)
 * @return The total time in seconds
 */
int toSeconds(int hours, int minutes, int seconds) {
    // Clamp hours to valid range [0, 99]
    hours = (hours < 0) ? 0 : hours;    
    hours = (hours >= 100) ? 99 : hours;
    
    // Clamp minutes to valid range [0, 59]
    minutes = (minutes < 0) ? 0 : minutes;
    minutes = (minutes >= 60) ? 59 : minutes;
    
    // Clamp seconds to valid range [0, 59]
    seconds = (seconds < 0) ? 0 : seconds;
    seconds = (seconds >= 60) ? 59 : seconds;
    
    // Convert to total seconds using standard formula
    int value = hours * 3600 + minutes * 60 + seconds;
    
    return value;
}

int main() {
    int hours, minutes, seconds;
    
    // Read three space-separated integers
    scanf("%d %d %d", &hours, &minutes, &seconds);
    
    // Calculate total seconds using conversion function
    int result = toSeconds(hours, minutes, seconds);
    
    // Output in required format
    printf("Total seconds: %d", result);
    
    return 0;
}
