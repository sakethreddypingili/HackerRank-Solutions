#include <stdio.h>

/**
 * Geometric Figure Classifier
 * Validates existence based on Euclidean geometry laws before classifying.
 */

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) {
        printf("Circle\n");
    } 
    else if (n == 3) {
        int a, b, c, A, B, C;
        scanf("%d %d %d %d %d %d", &a, &b, &c, &A, &B, &C);

        // Basic Validation
        if (a <= 0 || b <= 0 || c <= 0 || A <= 0 || B <= 0 || C <= 0 || (A + B + C != 180)) {
            printf("Invalid Figure\n");
        }
        // Triangle Inequality
        else if (!(a + b > c && a + c > b && b + c > a)) {
            printf("Invalid Figure\n");
        }
        else {
            // Check Side-Angle Consistency (In triangle, equal sides must have equal opposite angles)
            // This logic assumes A is opposite a, B opposite b, etc.
            int consistency = 1;
            if ((a == b && A != B) || (b == c && B != C) || (a == c && A != C)) consistency = 0;
            if ((A == B && a != b) || (B == C && b != c) || (A == C && a != c)) consistency = 0;

            if (!consistency) {
                printf("Invalid Figure\n");
            } else if (a == b && b == c) {
                // All equilateral triangles must have 60 degree angles
                if (A == 60 && B == 60 && C == 60) printf("Equilateral Triangle\n");
                else printf("Invalid Figure\n");
            } else if (a == b || b == c || a == c) {
                printf("Isosceles Triangle\n");
            } else {
                printf("Scalene Triangle\n");
            }
        }
    } 
    else if (n == 4) {
        int a, b, c, d, A, B, C, D;
        scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &A, &B, &C, &D);

        // Basic Validation
        if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || A <= 0 || B <= 0 || C <= 0 || D <= 0 || (A + B + C + D != 360)) {
            printf("Invalid Figure\n");
        } else {
            // Square: All sides equal, all angles 90
            if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90) {
                printf("Square\n");
            }
            // Rectangle: Opposite sides equal, all angles 90
            else if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {
                printf("Rectangle\n");
            }
            // Rhombus: All sides equal, opposite angles equal
            else if (a == b && b == c && c == d && A == C && B == D) {
                printf("Rhombus\n");
            }
            // Parallelogram: Opposite sides equal, opposite angles equal
            else if (a == c && b == d && A == C && B == D) {
                printf("Parallelogram\n");
            } else {
                printf("Invalid Figure\n");
            }
        }
    } 
    else {
        printf("Invalid Figure\n");
    }

    return 0;
}
