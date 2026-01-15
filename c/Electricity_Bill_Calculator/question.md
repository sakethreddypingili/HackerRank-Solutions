# Electricity Bill Calculator

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Conditional Logic, Arithmetic Calculations, Progressive Rates
- **Language Used:** C

## Problem Statement
The objective is to calculate the total electricity bill for a user based on the number of units consumed. The billing system uses a tiered (slab) pricing model where higher consumption is charged at higher rates. Additionally, a conditional discount is applied to the final amount if the total bill falls below or at a specific threshold.

## Input Specification
- **Input Type:** A single integer `n` representing consumption units.
- **Input Constraints:**
  - -10^6 ≤ n ≤ 10^6

## Output Specification
- **Output Type:** String / Formatted Float
- **Output Format:**
  - Valid: `The electricity bill is: [amount].` (Amount rounded to 2 decimal places)
  - Invalid: `Invalid Input!`

## Constraints & Rules
- **Tier 1:** 0 to 100 units → ₹5 per unit.
- **Tier 2:** 101 to 300 units → ₹7 per unit for the units in this range.
- **Tier 3:** Above 300 units → ₹10 per unit for the units in this range.
- **Discount:** If the calculated bill is ≤ ₹1,200, apply a 10% discount.
- **Validity:** Any negative input for units is considered invalid.

## Core Concept(s) Used

### Progressive Tiered Billing
In this system, units are not charged at a single flat rate. Instead, each "bracket" of units is charged at its own rate. For example, if 350 units are consumed, the first 100 are charged at ₹5, the next 200 at ₹7, and the final 50 at ₹10.



### Conditional Discounting
After the gross bill is calculated, a post-calculation condition is checked. The discount is applied based on the *total amount*, not the number of units.

## Logic & Reasoning
1. **Validation:** Check if `units < 0`. If so, flag as invalid.
2. **Gross Bill Calculation:**
   - If `units <= 100`: `bill = units * 5`
   - If `100 < units <= 300`: The first 100 units cost ₹500. The remaining `(units - 100)` cost ₹7.
   - If `units > 300`: The first 100 cost ₹500, the next 200 cost ₹1400 (Total ₹1900). The remaining `(units - 300)` cost ₹10.
3. **Discount Phase:**
   - Check if `gross_bill <= 1200`.
   - If true, `final_bill = gross_bill * 0.90`.
   - Else, `final_bill = gross_bill`.

## Step-by-Step Algorithm
1. Read input `n`.
2. If `n < 0`, print "Invalid Input!" and exit.
3. If `n <= 100`:
   - `bill = n * 5`
4. Else if `n <= 300`:
   - `bill = (100 * 5) + (n - 100) * 7`
5. Else:
   - `bill = (100 * 5) + (200 * 7) + (n - 300) * 10`
6. If `bill <= 1200`:
   - `bill = bill * 0.9`
7. Print formatted string with `bill` to two decimal places.

## Time & Space Complexity
- **Time Complexity:** O(1) — Constant time calculations.
- **Space Complexity:** O(1) — No extra storage structures used.

## Sample Execution

### Example 1
**Input:** `150`
**Processing:**
- Tier 1: 100 * 5 = 500
- Tier 2: 50 * 7 = 350
- Gross: 850
- 850 ≤ 1200, so apply 10% discount: 850 * 0.9 = 765.00
**Output:** `The electricity bill is: 765.00.`

### Example 2
**Input:** `450`
**Processing:**
- Tier 1: 500
- Tier 2: 1400
- Tier 3: 150 * 10 = 1500
- Gross: 3400
- 3400 > 1200, no discount.
**Output:** `The electricity bill is: 3400.00.`

## Edge Cases & Assumptions
- **Zero Units:** Handled as valid, results in 0.00.
- **Exactly 1200:** The discount applies (boundary condition).
- **Rounding:** Output must strictly follow the format `%.2f`.

## Common Mistakes & Pitfalls
- **Incorrect Tier Calculation:** Calculating the entire unit count at the highest rate (e.g., 450 * 10) instead of splitting it into tiers.
- **Order of Logic:** Applying the discount *before* calculating the total tiered bill.
- **Output Format:** Forgetting the trailing period `.` in the required output string "The electricity bill is: [amount].".

## Learning Outcome
- Implementing tiered logic structures.
- Managing multiple conditional logic gates (rates followed by discounts).
- Formatting double-precision output for financial calculations.
