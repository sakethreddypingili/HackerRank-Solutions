# Magical Mirror of Orlon

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Statements, Logical Operators, Boolean Accumulation
- **Language Used:** C

## Problem Statement
In the kingdom of Orlon, a magical mirror evaluates a single natural number $N$ based on three ancient conditions. Depending on how many conditions the number satisfies (zero to three), it is assigned a status: SUPERNATURAL, MIRACULOUS, MAGICAL, or NORMAL. If the number is not a natural number (i.e., $N \le 0$), the mirror responds with "INVALID".

## Input Specification
- **Input Type:** A single integer $N$.
- **Input Constraints:**
  - $-10^6 \le N \le 10^6$

## Output Specification
- **Output Type:** String
- **Output Format:**
  - `The verdict for the number [N] is: [RESULT]`
  - Possible Results: `SUPERNATURAL`, `MIRACULOUS`, `MAGICAL`, `NORMAL`, or `INVALID`.

## Constraints & Rules
The mirror checks three specific mystical conditions:
1. **Condition 1:** The number is **even** and **greater than 10**.
2. **Condition 2:** The number is **greater than 15** and a **multiple of 3**.
3. **Condition 3:** The number is a **multiple of 7**.

**Verdict Mapping:**
- **3 Conditions Met:** `SUPERNATURAL`
- **2 Conditions Met:** `MIRACULOUS`
- **1 Condition Met:** `MAGICAL`
- **0 Conditions Met:** `NORMAL`
- **$N \le 0$:** `INVALID`

## Core Concept(s) Used

### Condition Accumulation
Instead of writing complex nested `if-else` blocks for every possible combination of rules, we can evaluate each condition independently. By treating the boolean result of each condition as an integer (1 for True, 0 for False), the sum of these results tells us exactly how many conditions were met.

### Modulo Arithmetic
The modulo operator (`%`) is used to check divisibility.
- `n % 2 == 0` checks if a number is even.
- `n % 3 == 0` checks for multiples of 3.
- `n % 7 == 0` checks for multiples of 7.

## Logic & Reasoning
The solution follows a linear evaluation path:
1. **Validation:** Check if $N$ is a natural number ($N > 0$). If $N \le 0$, it is "INVALID".
2. **Independent Testing:** Check rule 1, rule 2, and rule 3 separately.
3. **Counting:** Add the results of the three checks.
4. **Final Branching:** Use the total count to determine the specific keyword to print. This is more efficient than checking every logical permutation (e.g., "if 1 and 2 but not 3").

## Step-by-Step Algorithm
1. Read the input integer $N$.
2. If $N \le 0$, print the `INVALID` message and terminate.
3. Initialize a counter `satisfied = 0`.
4. If ($N$ is even AND $N > 10$), increment `satisfied`.
5. If ($N > 15$ AND $N$ is multiple of 3), increment `satisfied`.
6. If ($N$ is multiple of 7), increment `satisfied`.
7. Use an `if-else` ladder to check the value of `satisfied`:
   - If 3: `SUPERNATURAL`
   - If 2: `MIRACULOUS`
   - If 1: `MAGICAL`
   - If 0: `NORMAL`
8. Print the formatted verdict string.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The number of logical comparisons is constant.
- **Space Complexity:** $O(1)$ — Only a few integer variables are used.

## Sample Execution

### Example 1
**Input:** `14`
**Processing:**
- Cond 1: (14 is even) AND (14 > 10) → **True**
- Cond 2: (14 > 15) AND (14 % 3 == 0) → **False**
- Cond 3: (14 % 7 == 0) → **True**
- **Total Count:** 2
**Output:** `The verdict for the number 14 is: MIRACULOUS`

### Example 2
**Input:** `42`
**Processing:**
- Cond 1: (42 is even) AND (42 > 10) → **True**
- Cond 2: (42 > 15) AND (42 % 3 == 0) → **True**
- Cond 3: (42 % 7 == 0) → **True**
- **Total Count:** 3
**Output:** `The verdict for the number 42 is: SUPERNATURAL`

## Edge Cases & Assumptions
- **Natural Numbers:** The mirror only entertains numbers $> 0$. Zero and negative numbers are explicitly invalid.
- **Compound Conditions:** For Condition 1 and 2, both parts of the rule must be true (using logical AND).
- **Boundary Values:** Numbers like 10 or 15 do not satisfy "greater than" conditions unless they are strictly larger than the threshold.

## Common Mistakes & Pitfalls
- **Implicit Truthiness:** Forgetting to check $N > 10$ in Rule 1, assuming all even numbers are valid.
- **Logic Overlap:** Trying to check for "exactly 1" or "exactly 2" using complex `&&` and `||` chains which often leads to bugs. Accumulating a sum is the most reliable method.
- **Output Precision:** Ensure the string exactly matches the required format including the colon and spacing.

## Learning Outcome
- Implementing multi-rule validation systems.
- Utilizing boolean-to-integer conversion for count-based logic.
- Understanding the difference between independent conditions and mutually exclusive results.
