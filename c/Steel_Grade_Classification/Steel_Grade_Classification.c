#include <stdio.h>

/**
 * Main function to classify steel grade based on Hardness, Carbon content, 
 * and Tensile strength.
 */
int main() {
    int h, t;
    float c;

    // Read input properties
    if (scanf("%d %f %d", &h, &c, &t) != 3) {
        return 0;
    }

    // Evaluate the three conditions
    int cond1 = (h > 50);
    int cond2 = (c < 0.7);
    int cond3 = (t > 5600);

    int grade;
    const char* message;

    // Determine Grade and Message based on conditions
    if (cond1 && cond2 && cond3) {
        grade = 10;
        message = "All of the conditions met.";
    } else if (cond1 && cond2) {
        grade = 9;
        message = "Two conditions met.";
    } else if (cond2 && cond3) {
        grade = 8;
        message = "Two conditions met.";
    } else if (cond1 && cond3) {
        grade = 7;
        message = "Two conditions met.";
    } else if (cond1 || cond2 || cond3) {
        grade = 6;
        message = "Only one condition met.";
    } else {
        grade = 5;
        message = "None of the conditions met.";
    }

    // Print results
    printf("The grade of the steel is: %d\n", grade);
    printf("%s", message);

    return 0;
}
