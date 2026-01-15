# Leap Year Checker

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Logic, Modular Arithmetic
- **Language Used:** C

## Problem Statement
The objective is to determine whether a specific year $Y$ is a leap year based on Gregorian calendar rules. A year is a leap year if it is divisible by 4, but centuries (divisible by 100) are only leap years if they are also divisible by 400. Additionally, the program must identify and handle invalid years (non-positive integers).

## Input Specification
- **Input Type:** Single integer $Y$
- **Input Constraints:**
  - $-10^5 \le Y \le 10^5$

## Output Specification
- **Output Type:** String
- **Output Format:**
  - `The given year [Y] is Invalid year.` (if $Y \le 0$)
  - `Yes, [Y] is a leap year.`
  - `No, [Y] is not a leap year.`

## Constraints & Rules
- **Invalidity:** Any year less than or equal to 0 is considered invalid.
- **Leap Year Rule 1:** Divisible by 4.
- **Leap Year Rule 2:** If divisible by 100, it must be divisible by 400.
- **Precedence:** The century rule (100/400) overrides the basic "divisible by 4" rule.

## Core Concept(s) Used

### Leap Year Logic

The Gregorian leap year criteria can be summarized as:
$((Year \pmod 4 == 0) \text{ AND } (Year \pmod{100} \neq 0)) \text{ OR } (Year \pmod{400} == 0)$.

### Modulo Operator (%)
The modulo operator returns the remainder of a division. For leap year checks, we look for a remainder of 0 to confirm divisibility.

## Logic & Reasoning
The logic follows a hierarchical filtering process:
1. **Validation:** First, filter out non-positive years as "Invalid".
2. **Century Check (Special Case):** Check if the year is divisible by 400. If so, it is automatically a leap year (e.g., 2000).
3. **Century Check (General):** If not divisible by 400 but divisible by 100, it is **not** a leap year (e.g., 1900).
4. **Basic Check:** If neither of the above, check if it is divisible by 4. If yes, it is a leap year.
5. **Default:** If none of these conditions are met, it is not a leap year.

## Step-by-Step Algorithm
1. Read the integer `year`.
2. If `year <= 0`, print the invalid message.
3. If `year % 400 == 0`, it is a leap year.
4. Else if `year % 100 == 0`, it is not a leap year.
5. Else if `year % 4 == 0`, it is a leap year.
6. Else, it is not a leap year.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The checks are simple arithmetic operations performed in constant time.
- **Space Complexity:** $O(1)$ — Only a single integer variable is required.

## Sample Execution

### Example 1
**Input:** `2000`
**Processing:**
- $2000 > 0$ (Valid)
- $2000 \pmod{400} == 0$ (True)
**Output:** `Yes, 2000 is a leap year.`

### Example 2
**Input:** `1900`
**Processing:**
- $1900 > 0$ (Valid)
- $1900 \pmod{400} \neq 0$
- $1900 \pmod{100} == 0$ (True)
**Output:** `No, 1900 is not a leap year.`

## Edge Cases & Assumptions
- **Negative Years:** Handled as "Invalid".
- **Year Zero:** Handled as "Invalid".
- **Centuries:** 1600, 2000, 2400 are leap years; 1700, 1800, 1900, 2100 are not.

## Common Mistakes & Pitfalls
- **Operator Precedence:** Forgetting that divisible by 100 is a stricter condition than divisible by 4.
- **Logical OR usage:** Trying to combine all conditions into one complex `if` statement and getting the `&&` and `||` logic mixed up.
- **Invalid Range:** Forgetting to handle the $Y \le 0$ constraint mentioned in the problem description.

## Learning Outcome
- Mastering nested or sequential conditional statements.
- Understanding the application of modular arithmetic in date/time algorithms.
- Handling input validation alongside business logic.
