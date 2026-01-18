#include <stdio.h>

/**
 * New Year Celebration Budget Planner
 * Evaluates event feasibility based on budget, guest count, and allocation rules.
 */
int main() {
    int budget, numGuests, foodPerGuest, decorationCost, musicCost, extraExpenses;

    // Reading inputs
    if (scanf("%d %d %d %d %d %d", &budget, &numGuests, &foodPerGuest, 
              &decorationCost, &musicCost, &extraExpenses) != 6) {
        return 0;
    }

    // Calculations
    long totalFoodCost = (long)numGuests * foodPerGuest;
    long totalCost = totalFoodCost + decorationCost + musicCost + extraExpenses;

    // 1. Total cost check
    int isUnderBudget = (totalCost <= budget);

    // 2. Guest count check
    int validGuestCount = (numGuests > 5 && numGuests <= 50);

    // 3. Resource allocation check (At least one must hold)
    // decorationCost < 30% of budget OR foodCost < 50% of budget
    int validAllocation = (decorationCost < 0.3 * budget) || (totalFoodCost < 0.5 * budget);

    // 4. Music arrangement check for large groups
    int musicRequirementMet = 1;
    if (numGuests > 25 && musicCost <= 0) {
        musicRequirementMet = 0;
    }

    // Final Approval Logic
    if (isUnderBudget && validGuestCount && validAllocation && musicRequirementMet) {
        printf("Celebration Approved\n");
    } else {
        printf("Celebration Denied\n");
    }

    return 0;
}
