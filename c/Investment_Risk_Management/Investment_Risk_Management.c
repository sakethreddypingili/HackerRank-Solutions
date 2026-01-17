#include <stdio.h>

/**
 * Investment Risk Management System
 * Classifies portfolios based on age, income, and risk appetite.
 */

int main() {
    int age, income, tolerance;

    // Standard scanf to handle inputs potentially on new lines
    if (scanf("%d %d %d", &age, &income, &tolerance) != 3) {
        return 0;
    }

    // 1. High Risk Logic (Checked first as it's the most aggressive category)
    if (age < 30 || 
       ((age >= 30 && age <= 50) && income > 75000 && tolerance == 3) ||
       (age > 50 && income > 75000 && tolerance == 3)) {
        printf("High Risk Portfolio: Suitable for aggressive investors with high-risk tolerance.\n");
    }
    
    // 2. Medium Risk Logic
    else if (((age >= 30 && age <= 50) && income <= 75000 && tolerance == 2) ||
             ((age >= 30 && age <= 50) && income > 75000 && (tolerance == 1 || tolerance == 2))) {
        printf("Medium Risk Portfolio: Balanced risk for moderate returns.\n");
    }
    
    // 3. Low Risk Logic
    else if ((age > 50 && !(income > 75000 && tolerance == 3)) ||
             (income <= 30000 && (tolerance == 1 || tolerance == 2))) {
        printf("Low Risk Portfolio: Suitable for conservative investments.\n");
    }

    return 0;
}
