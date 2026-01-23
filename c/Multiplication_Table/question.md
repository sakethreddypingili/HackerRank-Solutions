# Loops: Multiplication Table

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Arithmetic Operations, String Formatting
- **Language Used:** C

## Problem Statement
Generate a standard multiplication table for a given integer $n$. The table should display the products of $n$ multiplied by integers from 1 up to 10, following a specific "n x i = result" format.

## Input Specification
- **Input Type:** A single integer $n$.
- **Input Constraints:** $0 \le n \le 1000$

## Output Specification
- **Output Type:** A series of formatted strings.
- **Output Format:**
  - Each line should follow the pattern: `n x i = product`
  - $i$ ranges from 1 to 10 inclusive.

## Constraints & Rules
- The multiplier must start at 1 and end at 10.
- Standard spacing around the 'x' and '=' characters is required as per the sample output.

## Core Concept(s) Used

### Iteration (For Loop)
A `for` loop is used to execute a block of code a specific number of times. Here, it controls the multiplier, which increments by 1 in each step.

### Formatted Output
The `printf` function in C allows for structured output using format specifiers like `%d` for integers, enabling the creation of the multiplication string dynamically.



## Logic & Reasoning
The problem is a straightforward application of a fixed-iteration loop.
1. We read the base number $n$.
2. We initialize a loop counter $i$ at 1.
3. In each iteration, we calculate $n \times i$.
4. We print the values of $n$, $i$, and the product in the specified string format.
5. The loop continues until $i$ exceeds 10.

## Step-by-Step Algorithm
1. Read the input integer $n$.
2. Create a loop that iterates with a variable `i` starting from 1 to 10.
3. Inside the loop:
   - Compute `product = n * i`.
   - Print `n`, " x ", `i`, " = ", and `product`.
   - Move to a new line.
4. Exit the program.

## Time & Space Complexity
- **Time Complexity:** $O(1)$. Since the loop always runs exactly 10 times regardless of the input $n$, the execution time is constant.
- **Space Complexity:** $O(1)$. Only a single integer variable is required to store the input.

## Sample Execution
**Input:** `7`

**Processing:**
- $7 \times 1 = 7$
- $7 \times 2 = 14$
- ...
- $7 \times 10 = 70$

**Output:**  
`7 x 1 = 7 7 x 2 = 14 7 x 3 = 21 7 x 4 = 28 7 x 5 = 35 7 x 6 = 42 7 x 7 = 49 7 x 8 = 56 7 x 9 = 63 7 x 10 = 70`
## Edge Cases & Assumptions
- **n = 0:** The program will output $0 \times i = 0$ for all ten lines, which is mathematically correct.
- **n = 1000:** The maximum product is 10,000, which fits easily within a standard 32-bit `int`.

## Common Mistakes & Pitfalls
1. **Starting at 0:** Multiplication tables usually start at 1; starting at 0 would add an extra, often unwanted, line.
2. **Incorrect Spacing:** Missing spaces around 'x' or '=' can cause failure in automated test cases.
3. **Loop Boundary:** Using `i < 10` instead of `i <= 10`, resulting in a missing last line.

## Learning Outcome
- Mastering simple loop counters and boundaries.
- Understanding how to use variables inside formatted print statements.
- Applying basic arithmetic within an iterative context.
