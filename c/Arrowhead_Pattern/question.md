# Pattern: Arrowhead

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Nested Loops, Symmetric Patterns, Conditional Logic
- **Language Used:** C

## Problem Statement
Generate an arrowhead pattern using asterisks (`*`) based on an integer input $n$. The pattern starts with a single asterisk, expands outward row by row until it reaches a maximum width at row $n$, and then narrows symmetrically back to a single asterisk. Each row contains two asterisks separated by increasing (and then decreasing) spaces, except for the first and last rows which contain a single asterisk.

## Input Specification
- **Input Type:** A single integer $n$.
- **Input Constraints:** $-50 \le n \le 50$

## Output Specification
- **Output Type:** Character-based pattern or error string.
- **Output Format:** - A symmetric arrowhead pattern of $2n - 1$ rows.
  - Print "Shape Not Possible" if $n < 2$.

## Constraints & Rules
- The pattern must be vertically symmetric.
- Invalid inputs (values where a triangle/arrowhead cannot be visually established, specifically $n < 2$) must be handled gracefully.
- Rows 1 and $2n-1$ consist of exactly one asterisk.
- Intermediate rows consist of two asterisks with spaces in between.

## Core Concept(s) Used

### Hollow Triangle Logic
The arrowhead is essentially the left boundary and the hypotenuse of a triangle. The number of spaces between the two asterisks in row $i$ is calculated as $i - 2$.



### Vertical Symmetry
To achieve symmetry, the program is divided into two main parts:
1. **The Increasing Part:** Rows 1 to $n$.
2. **The Decreasing Part:** Rows $n-1$ down to 1.

## Logic & Reasoning
The arrowhead shape is built by managing the "gap" between the leading asterisk and the trailing asterisk.
- In the **Top Half** (including the peak at $n$), the gap starts at 0 (for $i=1$, only one `*` is printed) and grows to $n-2$.
- In the **Bottom Half**, the gap shrinks from $n-3$ back to 0.

By checking `if (i > 1)`, we handle the special case where the first and last rows of each section only require a single asterisk, avoiding negative loop iterations for spaces.

## Step-by-Step Algorithm
1. Read input $n$.
2. If $n < 2$, print "Shape Not Possible" and exit.
3. **Upper Half (Row 1 to $n$):**
   - For each row $i$:
     - Print `*`.
     - If $i > 1$:
       - Print $i - 2$ spaces.
       - Print `*`.
     - Print a newline.
4. **Lower Half (Row $n-1$ down to 1):**
   - For each row $i$:
     - Print `*`.
     - If $i > 1$:
       - Print $i - 2$ spaces.
       - Print `*`.
     - Print a newline.

## Time & Space Complexity
- **Time Complexity:** $O(n)$, where $n$ is the input value. Although there are nested loops, the total number of characters printed is linear relative to the total number of rows.
- **Space Complexity:** $O(1)$, as we only use a few integer variables for loop control.

## Sample Execution
**Input:** `3`

**Upper Part:**
- Row 1: `*`
- Row 2: `*` + (2-2=0 spaces) + `*` $\rightarrow$ `**`
- Row 3: `*` + (3-2=1 space) + `*` $\rightarrow$ `* *`

**Lower Part:**
- Row 2: `*` + (2-2=0 spaces) + `*` $\rightarrow$ `**`
- Row 1: `*`

**Output:**
## Edge Cases & Assumptions
- **n < 2:** According to sample requirements, $n=1$ or negative values are invalid.
- **Trailing Spaces:** There are no trailing spaces after the second asterisk in each row.

## Common Mistakes & Pitfalls
- **Gap Calculation:** Using $i-1$ instead of $i-2$ for spaces will cause the second asterisk to be misaligned.
- **Symmetry Break:** Forgetting to start the second loop at $n-1$, which would result in the middle row (the widest part) being printed twice.

## Learning Outcome
- Implementing multi-part loops for symmetric output.
- Handling conditional logic inside loops to manage special characters (single vs. double asterisks).
- Error handling for geometric constraints.
