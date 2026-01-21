# Pattern: Reverse Number Stair Pattern

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Nested Loops, Pattern Printing
- **Language Used:** C

## Problem Statement
Generate a numerical "staircase" pattern based on a starting integer $N$. The pattern begins with a full sequence from $N$ down to 1 in the first row. Each subsequent row decreases the starting number by 1 while always ending at 1, effectively reducing the length of the row until the final row contains only the number 1.

## Input Specification
- **Input Type:** A single integer $N$.
- **Input Constraints:** $1 \le N \le 100$

## Output Specification
- **Output Type:** Character/Numerical Grid
- **Output Format:** - $N$ rows of numbers.
  - Numbers within a row are separated by a single space.
  - Each row ends with a newline.

## Constraints & Rules
- The sequence in any row $i$ must strictly follow a descending order ending at 1.
- The total number of rows printed must be $N$.

## Core Concept(s) Used

### Nested Loops
Pattern printing typically requires a 2D approach:
1. **Outer Loop:** Manages the row count (from 1 to $N$).
2. **Inner Loop:** Manages the content of each specific row (the descending numbers).

### Arithmetic Progression in Grids
To determine the starting number of each row, we observe that Row 1 starts at $N$, Row 2 starts at $N-1$, and Row $i$ starts at $N - (i - 1)$.



## Logic & Reasoning
The pattern can be visualized as a right-angled triangle where the hypotenuse is on the left.
- **Row count:** There are $N$ rows.
- **Row Length:** The first row has $N$ elements, the second has $N-1$, and the $i$-th row has $N - i + 1$ elements.
- **Value Logic:** In row $i$, we want to start printing from the value $(N - i + 1)$ and decrement until we reach 1.

**Example for N=5:**
- Row 1 ($i=0$): Starts at 5, ends at 1. Length = 5.
- Row 2 ($i=1$): Starts at 4, ends at 1. Length = 4.
- Row 3 ($i=2$): Starts at 3, ends at 1. Length = 3.

## Step-by-Step Algorithm
1. Read the input integer $N$.
2. Create an outer loop using variable `i` from 0 up to $N-1$.
3. Inside the outer loop, determine the starting value for the current row: `start_val = N - i`.
4. Create an inner loop using variable `j` starting from `start_val` down to 1.
5. In the inner loop:
   - Print the current value of `j`.
   - Print a space.
6. After the inner loop completes, print a newline character `\n`.
7. Repeat until the outer loop finishes.

## Time & Space Complexity
- **Time Complexity:** $O(N^2)$. The total number of elements printed is the sum of the first $N$ integers: $\frac{N(N+1)}{2}$.
- **Space Complexity:** $O(1)$. No data structures are used; numbers are printed directly to the standard output.

## Sample Execution
**Input:** `3`

**Processing:**
- Row 0: `start_val = 3 - 0 = 3`. Inner loop prints `3 2 1`.
- Row 1: `start_val = 3 - 1 = 2`. Inner loop prints `2 1`.
- Row 2: `start_val = 3 - 2 = 1`. Inner loop prints `1`.

**Output:**

```

3 2 1
2 1
1

```

## Edge Cases & Assumptions
- **N = 1:** The program prints only `1` and a newline.
- **Spaces:** The problem asks for spaces between numbers. While most competitive programming platforms ignore trailing spaces at the end of a line, the logic ensures spaces are handled reasonably between digits.

## Common Mistakes & Pitfalls
1. **Starting Value Calculation:** Incorrectly starting every row with $N$ but varying the length, which would produce a different pattern.
2. **Loop Bounds:** Using `j > 1` instead of `j >= 1`, which would cause the number 1 to be missing from the output.
3. **Missing Newlines:** Forgetting to print `\n` after the inner loop, resulting in all numbers appearing on a single line.

## Learning Outcome
- Mastery of nested loop structures for 2D output.
- Converting visual patterns into mathematical loop constraints.
- Handling decrementing iterators in C.
