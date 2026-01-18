# New Year Celebration Budget Planner

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Logical Operators, Percentage Calculations, Conditional Branching
- **Language Used:** C

## Problem Statement
Sharib, an event planner, needs to validate if a New Year celebration is feasible. The feasibility is determined by four specific criteria: total budget adherence, guest count limits, resource allocation percentages, and mandatory music requirements for larger groups.

## Feasibility Conditions
To receive a "Celebration Approved" status, **all** of the following must be true:

1.  **Budget Constraint:** `Total Cost <= Budget`.
2.  **Guest Constraint:** `5 < numGuests <= 50`.
3.  **Resource Allocation (At least one):**
    - `Decoration Cost < 30% of Budget`
    - **OR** `Total Food Cost < 50% of Budget`
4.  **Music Requirement:** If `numGuests > 25`, then `musicCost` must be greater than `0`.



## Core Concept(s) Used

### Compound Logical Operators
- **`&&` (AND):** Used to ensure all four major conditions are met.
- **`||` (OR):** Used inside the resource allocation check where only one of two sub-conditions needs to be true.

### Percentage Handling in C
When calculating percentages like 30% of a budget, using floating-point math (`0.3 * budget`) is common. However, because we are dealing with integers, care must be taken with precision.


## Logic & Reasoning
- **Total Food Cost:** Calculated as `numGuests * foodCostPerGuest`.
- **Total Cost:** The sum of food, decoration, music, and extra expenses.
- **The Music Logic:** This is a conditional requirement. If the guest count is low (≤ 25), the music condition is automatically satisfied (True). If the guest count is high, we must check the actual cost.



## Step-by-Step Algorithm
1.  Read the six input integers.
2.  Calculate `totalFoodCost` and `totalCost`.
3.  **Evaluate Condition A:** Is `totalCost <= budget`?
4.  **Evaluate Condition B:** Is `numGuests` between 6 and 50 inclusive?
5.  **Evaluate Condition C:** Is `decorationCost < (0.3 * budget)` OR `totalFoodCost < (0.5 * budget)`?
6.  **Evaluate Condition D:** If `numGuests > 25`, check if `musicCost > 0`. Otherwise, set to True.
7.  If (A AND B AND C AND D) are all true, print "Celebration Approved". Else, print "Celebration Denied".

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The program performs a constant number of arithmetic and logical operations.
- **Space Complexity:** $O(1)$ — Uses a fixed number of integer variables.

## Sample Execution Trace
**Input:** `1000 20 25 200 0 150`
- `totalFoodCost` = $20 \times 25 = 500$
- `totalCost` = $500 + 200 + 0 + 150 = 850$
- **A:** $850 \le 1000$ (True)
- **B:** $20$ is between 5 and 50 (True)
- **C:** $200 < 300$ (True) OR $500 < 500$ (False) $\rightarrow$ True
- **D:** $20 \le 25$, music check not required (True)
**Result:** Approved.
