#include <stdio.h>

/**
 * Money Heist Passcode Correction
 * Uses an array for efficient index access and modulo for circular rotation.
 */
int main() {
    int passcode[10];

    // Read the initial 10-digit configuration
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &passcode[i]) != 1) return 0;
    }

    // Apply 3 corrections
    for (int i = 0; i < 3; i++) {
        int index, rotation;
        if (scanf("%d %d", &index, &rotation) == 2) {
            // Apply circular rotation using modulo 10
            passcode[index] = (passcode[index] + rotation) % 10;
        }
    }

    // Print the final corrected passcode
    for (int i = 0; i < 10; i++) {
        printf("%d%s", passcode[i], (i == 9) ? "" : " ");
    }
    printf("\n");

    return 0;
}
