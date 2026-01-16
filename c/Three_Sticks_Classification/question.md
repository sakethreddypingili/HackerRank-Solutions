# Three Sticks Classification

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Geometry, Conditional Statements, Triangle Inequality Theorem
- **Language Used:** C

## Problem Statement
Given the lengths of three sticks, determine if they can form a valid triangle. If they can, classify the triangle as Equilateral, Isosceles, or Scalene based on the lengths of the sides. If the side lengths do not satisfy the mathematical requirements for a triangle, classify it as an Invalid shape.

## Input Specification
- **Input Type:** Three space-separated integers ($a, b, c$).
- **Input Constraints:**
  - $1 \le a, b, c \le 10^6$

## Output Specification
- **Output Type:** String (Formatted across three logical sections).
- **Output Format:**
  - `Lengths: [a, b, c]`
  - `Type: [Classification]`
  - `[Description of the shape]`

## Constraints & Rules

### Triangle Inequality Theorem
For three lengths to form a valid triangle, the sum of any two sides must be strictly greater than the third side:
1. $a + b > c$
2. $a + c > b$
3. $b + c > a$



### Classification Rules
- **Equilateral:** $a = b = c$
- **Isosceles:** Exactly two sides are equal (e.g., $a = b \neq c$).
- **Scalene:** $a \neq b, b \neq c, a \neq c$.
- **Invalid:** Any case where the Triangle Inequality Theorem is violated.



[Image of types of triangles based on sides]


## Core Concept(s) Used

### Validation First
In geometry problems, validation must occur before classification. If the triangle inequality is not met, the relationships between the sides (like equality) are irrelevant because the "shape" cannot exist in Euclidean space.

### Logical Hierarchy
- **Step 1:** Check for Invalidity.
- **Step 2:** Check for Equilateral (strictest equality).
- **Step 3:** Check for Isosceles (partial equality).
- **Step 4:** Default to Scalene.

## Logic & Reasoning
The most critical part of the logic is the "Invalid" check. A common mistake is using `>=` instead of `>`. If the sum of two sides equals the third side (e.g., 1, 2, 3), the "triangle" is actually a flat line (degenerate triangle) and is considered "Invalid" for this problem.

By checking `a == b && b == c` first for Equilateral, we ensure that the subsequent `a == b || b == c || a == c` check only catches cases where *exactly* two sides are equal.

## Step-by-Step Algorithm
1. Read three integers $a$, $b$, and $c$.
2. **Invalidity Check:** If $(a+b \le c)$ OR $(a+c \le b)$ OR $(b+c \le a)$, output "Invalid" messages.
3. **Equilateral Check:** If $(a == b)$ AND $(b == c)$, output "Equilateral" messages.
4. **Isosceles Check:** If $(a == b)$ OR $(b == c)$ OR $(a == c)$, output "Isosceles" messages.
5. **Scalene Check:** Otherwise, output "Scalene" messages.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — Performs a fixed number of integer comparisons.
- **Space Complexity:** $O(1)$ — Uses only three integer variables to store side lengths.

## Sample Execution

### Example 1
**Input:** `1 2 3`
**Processing:**
- $1 + 2 = 3$. Since $3 \le 3$ is true, the condition $(a+b \le c)$ is met.
- Result: Invalid.
**Output:**
`Lengths: [1, 2, 3]`
`Type: Invalid`
`Cannot form a valid shape.`

### Example 2
**Input:** `8 8 10`
**Processing:**
- Valid check: $8+8 > 10$, $8+10 > 8$ (All True).
- Equality check: $(8 == 8)$ is true.
- Result: Isosceles.
**Output:**
`Lengths: [8, 8, 10]`
`Type: Isosceles`
`Exactly two sides are equal.`

## Edge Cases & Assumptions
- **Degenerate Triangles:** Lengths like 2, 2, 4 are treated as "Invalid" because they cannot form a closed 2D shape with area.
- **Large Inputs:** The constraints go up to $10^6$, which fits within a standard 32-bit `int`, but their sum ($2 \times 10^6$) also safely fits in an `int`.

## Common Mistakes & Pitfalls
1. **Missing Parentheses:** In C, it's good practice to wrap logical groups in parentheses to ensure correct evaluation order.
2. **Wrong Inequality:** Using `a + b < c` instead of `a + b <= c` for the invalid check (missing the equality case).
3. **Redundant Logic:** Checking for Scalene with `a != b && b != c && a != c` is unnecessary if it is the final `else` in the chain.

## Learning Outcome
- Implementing geometric validation logic.
- Understanding the importance of order in `if-else` chains (Equilateral vs. Isosceles).
- Correct application of the Triangle Inequality Theorem.
