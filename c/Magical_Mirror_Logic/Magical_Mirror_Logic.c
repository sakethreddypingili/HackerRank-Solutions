#include <stdio.h>

/**
 * Function to evaluate mystical conditions and determine the verdict.
 */
void evaluate_mirror(int n) {
    // Check if the number is a natural number
    if (n <= 0) {
        printf("The verdict for the number %d is: INVALID\n", n);
        return;
    }

    // Evaluate conditions (1 if True, 0 if False)
    int cond1 = (n % 2 == 0 && n > 10);
    int cond2 = (n > 15 && n % 3 == 0);
    int cond3 = (n % 7 == 0);

    // Count how many conditions are met
    int count = cond1 + cond2 + cond3;

    // Output formatting
    printf("The verdict for the number %d is: ", n);

    if (count == 3) {
        printf("SUPERNATURAL\n");
    } else if (count == 2) {
        printf("MIRACULOUS\n");
    } else if (count == 1) {
        printf("MAGICAL\n");
    } else {
        printf("NORMAL\n");
    }
}

int main() {
    int n;
    
    // Read the input number
    if (scanf("%d", &n) == 1) {
        evaluate_mirror(n);
    }

    return 0;
}
