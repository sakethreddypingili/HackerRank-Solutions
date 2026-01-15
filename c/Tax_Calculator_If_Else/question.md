# Tax Calculator (If-Else)

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Statements, Arithmetic Operations, Tax Slabs
- **Language Used:** C

## Problem Statement
The goal is to calculate the total income tax payable based on a progressive tax slab system. Tax is calculated only on income exceeding specific thresholds. If the input income is negative, it is considered invalid.

## Input Specification
- **Input Type:** A single floating-point number (double) representing the annual income.
- **Input Constraints:**
  - -10^7 ≤ income ≤ 10^7

## Output Specification
- **Output Type:** Floating-point number or String.
- **Output Format:**
  - If income is valid: Total tax payable formatted to 2 decimal places.
  - If income is invalid: "INVALID".

## Constraints & Rules
- **Income ≤ 2,50,000:** 0% Tax.
- **2,50,000 < Income ≤ 5,00,000:** 5% on amount exceeding 2,50,000.
- **5,00,000 < Income ≤ 10,00,000:** 5% on the first 2,50,000 bracket + 20% on amount exceeding 5,00,000.
- **Income > 10,00,000:** 5% on the first 2,50,000 bracket + 20% on the next 5,00,000 bracket + 30% on amount exceeding 10,00,000.
- **Invalid Input:** Any income less than 0 must result in "INVALID".

## Core Concept(s) Used

### Progressive Taxation
This problem uses a "slab-based" system where different portions of the total income are taxed at different rates. Only the income falling within a specific range is taxed at that range's rate.

### Floating Point Precision
Since tax involves percentages and currency, using `double` ensures precision, and `%.2f` formatting is used to round the output to two decimal places.

## Logic & Reasoning
The solution employs a cascaded `if-else if-else` structure to determine which slab the total income falls into. 

1. **Validation:** Check if income is negative first.
2. **Slab 1 (0 - 2.5L):** Tax is 0.
3. **Slab 2 (2.5L - 5L):** Subtract the base (250,000) and multiply by 0.05.
4. **Slab 3 (5L - 10L):** Calculate the full tax of the previous slab (5% of 250,000 = 12,500) and add 20% of the amount exceeding 5,00,000.
5. **Slab 4 (> 10L):** Calculate full taxes of all previous slabs (12,500 + 1,00,000) and add 30% of the amount exceeding 10,00,000.

## Step-by-Step Algorithm
1. Read the input `income`.
2. If `income < 0`, print "INVALID" and terminate.
3. If `income <= 250000`:
   - `tax = 0`
4. Else if `income <= 500000`:
   - `tax = (income - 250000) * 0.05`
5. Else if `income <= 1000000`:
   - `tax = (250000 * 0.05) + (income - 500000) * 0.20`
6. Else:
   - `tax = (250000 * 0.05) + (500000 * 0.20) + (income - 1000000) * 0.30`
7. Print the `tax` formatted to 2 decimal places.

## Time & Space Complexity
- **Time Complexity:** O(1) - The number of operations is constant regardless of the input size.
- **Space Complexity:** O(1) - Only a few variables are used to store income and tax.

## Sample Execution

### Example 1
**Input:** `450000`
**Processing:**
- Slab 2 applies: (450,000 - 250,000) = 200,000
- 200,000 * 0.05 = 10,000.00
**Output:** `10000.00`

### Example 2
**Input:** `856734`
**Processing:**
- Slab 3 applies:
- 5% of (500,000 - 250,000) = 12,500
- 20% of (856,734 - 500,000) = 0.20 * 356,734 = 71,346.80
- Total = 12,500 + 71,346.80 = 83,846.80
**Output:** `83846.80`

## Edge Cases & Assumptions
- **Income exactly at slab boundaries:** The logic uses `<=` to ensure boundary values (like 5,00,000) are taxed at the lower tier's calculation.
- **Negative Income:** Explicitly handled by the first condition to print "INVALID".
- **Zero Income:** Handled by the first slab, resulting in 0.00.

## Common Mistakes & Pitfalls
1. **Cumulative vs. Flat Tax:** Calculating tax on the *entire* amount at the highest rate rather than applying the slabs progressively.
2. **Precision Loss:** Using `float` instead of `double` for large financial calculations.
3. **Missing "INVALID":** Forgetting to check for negative input values as per constraints.

## Learning Outcome
- Implementing progressive logic using conditional branches.
- Handling floating-point precision in financial applications.
- Translating real-world business rules into programmatic logic.
