# Steel Grade Classification

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Statements, Boolean Logic, Multi-level Decision Making
- **Language Used:** C

## Problem Statement
The quality of steel is determined by three specific physical properties: Hardness, Carbon Content, and Tensile Strength. Based on which combinations of these criteria are met, the steel is assigned a grade ranging from 5 to 10. The goal is to evaluate the input properties and output both the numerical grade and a descriptive message regarding how many conditions were satisfied.

## Input Specification
- **Input Type:** Three space-separated values:
  - `h`: Hardness (Integer)
  - `c`: Carbon content (Float)
  - `t`: Tensile strength (Integer)
- **Input Constraints:**
  - 0 ≤ h ≤ 500
  - 0.0 ≤ c ≤ 1.0
  - 0 ≤ t ≤ 50000

## Output Specification
- **Output Type:** Two messages (Grade and Status)
- **Output Format:**
  - `The grade of the steel is: [grade]`
  - Followed by: `All of the conditions met.`, `Two conditions met.`, `Only one condition met.`, or `None of the conditions met.`

## Constraints & Rules
The conditions are:
1.  **Condition 1:** Hardness > 50
2.  **Condition 2:** Carbon content < 0.7
3.  **Condition 3:** Tensile strength > 5600

| Grade | Conditions Met |
| :--- | :--- |
| **10** | All three (1, 2, and 3) |
| **9** | 1 and 2 |
| **8** | 2 and 3 |
| **7** | 1 and 3 |
| **6** | Any single condition (1, 2, or 3) |
| **5** | None |

## Core Concept(s) Used

### Truth Table Mapping
The problem is essentially a truth table where three binary inputs (Conditions 1, 2, and 3) map to specific outputs. Using boolean variables to store the result of each condition simplifies the logic.



[Image of logic gate truth table for three inputs]


### Short-Circuit Evaluation
In C, the `&&` (AND) and `||` (OR) operators allow for efficient evaluation. However, for this problem, it is best to evaluate all three conditions upfront to easily determine the total count of met criteria.

## Logic & Reasoning
1.  **Evaluate Individually:** Store the result of the three conditions in boolean-like integer variables (`cond1`, `cond2`, `cond3`).
2.  **Determine Grade:** Use a hierarchical `if-else if` structure. We start with the most restrictive case (Grade 10 - all three met) and move down to the least restrictive.
3.  **Determine Message:** The message is dependent on the total number of conditions met. 
    - Grades 7, 8, and 9 all imply exactly two conditions were met.
    - Grade 6 implies exactly one.
    - Grade 5 implies zero.

## Step-by-Step Algorithm
1.  Read `h`, `c`, and `t`.
2.  Define:
    - `c1 = (h > 50)`
    - `c2 = (c < 0.7)`
    - `c3 = (t > 5600)`
3.  If `c1 && c2 && c3`, Grade = 10.
4.  Else if `c1 && c2`, Grade = 9.
5.  Else if `c2 && c3`, Grade = 8.
6.  Else if `c1 && c3`, Grade = 7.
7.  Else if `c1 || c2 || c3`, Grade = 6.
8.  Else, Grade = 5.
9.  Print the grade.
10. Print the corresponding count message based on the determined grade.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — A fixed number of comparisons and print operations.
- **Space Complexity:** $O(1)$ — Only a few primitive variables are used.

## Sample Execution

### Example 1
**Input:** `55 0.6 5000`
**Processing:**
- Cond 1: 55 > 50 (True)
- Cond 2: 0.6 < 0.7 (True)
- Cond 3: 5000 > 5600 (False)
- Result: Conditions 1 and 2 are met → Grade 9.
**Output:** `The grade of the steel is: 9`
`Two conditions met.`

## Edge Cases & Assumptions
- **Boundary Values:** The problem specifies "greater than" and "less than." Values exactly at the threshold (e.g., Hardness = 50) do not satisfy the condition.
- **Data Types:** Hardness and Tensile Strength are integers, while Carbon content must be handled as a float/double.

## Common Mistakes & Pitfalls
- **Incorrect Order:** Checking if only one condition is met (`Grade 6`) before checking if two are met will result in an incorrect grade. Always check the most specific conditions first.
- **Floating Point Comparison:** Although Carbon content is a float, the comparison `< 0.7` is generally safe here; however, in some systems, precision issues can occur.
- **Missing "only" in Grade 6:** The requirement is for "Only one condition met."

## Learning Outcome
- Implementing multi-variable classification logic.
- Understanding priority in conditional branching.
- Mapping discrete logical states to specific output messages.
