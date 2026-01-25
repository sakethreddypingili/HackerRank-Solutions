# Isosceles Triangle Pattern

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Nested Loops, Pattern Printing, Conditional Logic
- **Language Used:** C

## Problem Statement
Generate a centered isosceles triangle pattern using asterisks (`*`) for a given number of rows $n$. Each row must consist of leading spaces followed by an odd number of asterisks to maintain symmetry. If the input $n$ is too small to form a triangle (specifically $n < 2$ based on problem requirements), an error message must be displayed.

## Input Specification
- **Input Type:** A single integer $n$.
- **Input Constraints:** $-50 \le n \le 50$

## Output Specification
- **Output Type:** Character pattern or string message.
- **Output Format:**
  - $n$ rows of a centered triangle.
  - Print `Shape Not Possible` if the input is invalid.

## Constraints & Rules
- The triangle must be centered using leading spaces.
- Each row $i$ (starting from 1) contains $2i - 1$ asterisks.
- The number of leading spaces for row $i$ is $n - i$.

## Core Concept(s) Used

### Centering via Padding
In a text-based console, an isosceles triangle is created by calculating the necessary offset for each row. By printing a decreasing number of spaces as we move down the rows, the asterisks appear centered.



### Odd Number Sequence
To form a symmetric peak and expand outward, each row must contain an odd number of symbols. This is represented by the arithmetic sequence $1, 3, 5, \dots, (2n - 1)$.

## Logic & Reasoning
The solution utilizes three layers of loop logic:
1.  **Outer Loop:** Controls the current row number ($i$) from $1$ to $n$.
2.  **Space Loop (Inner 1):** Prints $n - i$ spaces. This ensures the peak of the triangle ($i=1$) has the most indentation.
3.  **Asterisk Loop (Inner 2):** Prints $2i - 1$ asterisks. This ensures that every row is centered relative to the ones above and below it.

**Validation Logic:**
The code includes a guard clause. Per Sample Input 1, $n=1$ is not considered a valid triangle for this specific pattern, so any value less than 2 triggers the "Shape Not Possible" output.

## Step-by-Step Algorithm
1.  Read integer $n$.
2.  If $n < 2$, print "Shape Not Possible" and terminate.
3.  For $i$ from 1 to $n$:
    a. For $k$ from 1 to $(n - i)$, print a space `" "`.
    b. For $j$ from 1 to $(2 * i - 1)$, print an asterisk `*`.
    c. Print a newline character `\n`.
4.  End the program.

## Time & Space Complexity
- **Time Complexity:** $O(n^2)$, as the total number of characters printed is approximately $\sum_{i=1}^{n} (n+i)$, which scales quadratically with $n$.
- **Space Complexity:** $O(1)$, since we only use a constant number of integer variables.

## Sample Execution

### Input: `3`

| Row (i) | Spaces ($n-i$) | Asterisks ($2i-1$) | Output Line |
| :--- | :--- | :--- | :--- |
| 1 | 2 | 1 | `  *` |
| 2 | 1 | 3 | ` ***` |
| 3 | 0 | 5 | `*****` |

## Edge Cases & Assumptions
- **Negative/Zero Input:** Handled by the $n < 2$ condition.
- **n = 1:** Specifically returns "Shape Not Possible".
- **Maximum Constraint (50):** $50$ rows will fit within standard console buffers and integer limits.

## Common Mistakes & Pitfalls
1.  **Incorrect Asterisk Count:** Using $2i$ instead of $2i-1$ results in an even-sided shape that isn't perfectly centered.
2.  **Missing Spaces:** Neglecting the space loop results in a left-aligned right-angled triangle.
3.  **Trailing Newlines:** Ensure the newline only occurs after the asterisk loop finishes for that row.

## Learning Outcome
- Mastery of nested loops for two-dimensional output.
- Application of simple linear equations to coordinate geometry on a grid.
- Input validation and graceful error handling.
