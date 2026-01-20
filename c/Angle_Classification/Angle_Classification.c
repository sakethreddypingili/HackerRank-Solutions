#include <stdio.h>

/**
 * Classifies an angle based on clock hand rotation rules.
 * Handles multi-rotations and special cases for 0 and 360 degrees.
 */
int main() {
    int x;
    
    // Read the input angle 
    if (scanf("%d", &x) != 1) {
        return 0;
    }

    // Special Case: No rotation
    if (x == 0) {
        printf("Acute Angle");
        return 0;
    }

    int effective_angle = x % 360;

    // Special Case: Full Rotation (360, 720, etc.)
    if (x > 0 && effective_angle == 0) {
        printf("Full Rotation");
    } 
    // Acute Angle: (0 < angle < 90)
    else if (effective_angle < 90) {
        printf("Acute Angle");
    } 
    // Right Angle: (angle == 90)
    else if (effective_angle == 90) {
        printf("Right Angle");
    } 
    // Obtuse Angle: (90 < angle < 180)
    else if (effective_angle < 180) {
        printf("Obtuse Angle");
    } 
    // Straight Angle: (angle == 180)
    else if (effective_angle == 180) {
        printf("Straight Angle");
    } 
    // Reflex Angle: (180 < angle < 360)
    else {
        printf("Reflex Angle");
    }

    return 0;
}
