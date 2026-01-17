# Divisibility Duel

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Arithmetic Operators, Modulo, Logical Operators, Conditional Priority
- **Language Used:** C

## Problem Statement
In a "duel" of numbers, contender $X$ must face off against challengers $Y$ and $Z$. The outcome of the duel is determined by whether $X$ is divisible by either or both of its challengers. You must determine if $X$ is defeated by $Y$, outsmarted by $Z$, overcomes both, or remains undefeated.

## Input Specification
- **Input Type:** Three space-separated integers $X$, $Y$, and $Z$.
- **Input Constraints:**
  - $1 \le X, Y, Z \le 10^9$

## Output Specification
- **Output Type:** String
- **Possible Results:** - `X defeats all!` (Divisible by both $Y$ and $Z$)
  - `Y triumphs over X!` (Divisible only by $Y$)
  - `Z outsmarts X!` (Divisible only by $Z$)
  - `X remains undefeated!` (Divisible by neither)

## Constraints & Rules
- The result is based on the **remainder** of division.
- **Divisibility Rule:** A number $A$ is divisible by $B$ if $A \pmod B = 0$.



## Core Concept(s) Used

### Modulo Operator (%)
The `%` operator returns the remainder of a division. For any two integers:
- If `X % Y == 0`, $X$ is a multiple of $Y$.
- If `X % Y != 0`, $X$ is not divisible by $Y$.

### Conditional Priority
In problems where multiple conditions can be true simultaneously (like being divisible by both $Y$ and $Z$), the **order** of your `if-else` statements is critical. You must check for the "most specific" case (both) before checking "general" cases (one or the other).

## Logic & Reasoning

The solution follows a logical hierarchy to ensure the correct result:

1.  **Check Both First:** If you check if $X$ is divisible by $Y$ first, and it is true, the program will print the $Y$ message and exit the `if-else` block, even if $X$ was also divisible by $Z$. To catch "X defeats all!", the combined check using `&&` must be at the top.
2.  **Individual Checks:** After ruling out both, we check $Y$ and $Z$ individually.
3.  **Default Case:** If none of the above match, $X$ is undefeated.



## Step-by-Step Algorithm
1.  Read integers $X$, $Y$, and $Z$.
2.  **Condition 1:** If $(X \pmod Y == 0)$ AND $(X \pmod Z == 0)$, print "X defeats all!".
3.  **Condition 2:** Else if $(X \pmod Y == 0)$, print "Y triumphs over X!".
4.  **Condition 3:** Else if $(X \pmod Z == 0)$, print "Z outsmarts X!".
5.  **Condition 4:** Otherwise, print "X remains undefeated!".

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — Performs at most two modulo operations and comparisons.
- **Space Complexity:** $O(1)$ — Only three integer variables are stored.

## Sample Execution

### Example 1
**Input:** `28 7 3`
**Processing:**
- `28 % 7 == 0` (True)
- `28 % 3 == 0` (False)
- Since only the $Y$ condition is true, output $Y$ message.
**Output:** `Y triumphs over X!`

### Example 2
**Input:** `30 5 6`
**Processing:**
- `30 % 5 == 0` (True)
- `30 % 6 == 0` (True)
- The first condition `(30 % 5 == 0 && 30 % 6 == 0)` is met.
**Output:** `X defeats all!`

## Common Mistakes & Pitfalls
- **Wrong Order:** Checking for $Y$ or $Z$ before checking "Both". This is the most common reason for failing test cases in this specific problem.
- **Data Types:** For values up to $10^9$, standard `int` in C is sufficient (as it typically supports up to $2 \times 10^9$), but `long long` is safer if calculations exceed that range.

## Learning Outcome
- Understanding the importance of **logic ordering** in conditional branches.
- Practical application of the **modulo operator** for divisibility tests.
- Mastery of **Logical AND (`&&`)** for compounding requirements.
