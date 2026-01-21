# Loops: N Multiples of X

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Arithmetic Operations, Basic Input/Output
- **Language Used:** C

## Problem Statement
The objective is to generate and display the first $n$ multiples of a given integer $x$. A multiple is defined as the product of $x$ and an integer $i$, where $i$ ranges from 1 to $n$.

## Input Specification
- **Input Type:** Two space-separated integers, $n$ and $x$.
- **Input Constraints:**
  - $0 \le n \le 1000$ (Number of multiples)
  - $-1000 \le x \le 1000$ (The base number)

## Output Specification
- **Output Type:** A sequence of integers.
- **Output Format:** A single line containing $n$ integers, each separated by a space.

## Constraints & Rules
- If $n = 0$, the program should produce no output.
- The multiplier $i$ starts at 1 and increments by 1 until it reaches $n$.
- The solution must handle negative values for $x$ correctly.

## Core Concept(s) Used

### Arithmetic Multiples
A multiple of a number $x$ is the product of $x$ and any integer. In this problem, we specifically look for the sequence $\{x \cdot 1, x \cdot 2, x \cdot 3, \dots, x \cdot n\}$.

### For-Loop Iteration
A `for` loop is the most efficient way to handle a known number of iterations ($n$). It allows for a clean initialization, condition check, and increment in a single line.



[Image of for loop execution flow chart]


## Logic & Reasoning
The program needs to repeat a multiplication and printing task exactly $n$ times. 
1. **Iteration:** We use a loop counter $i$ starting from 1.
2. **Calculation:** In each step, we calculate the product of the base number $x$ and the current counter $i$.
3. **Output:** The result is printed immediately followed by a space. Because the constraints on $n$ and $x$ are relatively small ($\pm 1000$), the maximum product ($\pm 1,000,000$) fits comfortably within a standard 32-bit signed integer.

## Step-by-Step Algorithm
1. Read integers `n` and `x` from standard input.
2. Initialize a loop with a counter `i` set to 1.
3. Continue the loop as long as `i` is less than or equal to `n`.
4. Inside the loop:
   - Calculate `result = x * i`.
   - Print `result` followed by a space.
   - Increment `i` by 1.
5. Exit the program.

## Time & Space Complexity
- **Time Complexity:** $O(n)$, where $n$ is the number of multiples requested. The loop runs exactly $n$ times.
- **Space Complexity:** $O(1)$, as we only use a constant amount of extra space for the variables `n`, `x`, and `i`.

## Sample Execution

### Example 1
**Input:** `5 6`

| Iteration (i) | Calculation (6 * i) | Output |
| :--- | :--- | :--- |
| 1 | 6 * 1 | 6 |
| 2 | 6 * 2 | 12 |
| 3 | 6 * 3 | 18 |
| 4 | 6 * 4 | 24 |
| 5 | 6 * 5 | 30 |

**Result:** `6 12 18 24 30 `

---

### Example 2
**Input:** `4 -2`

**Processing:**
- $-2 \cdot 1 = -2$
- $-2 \cdot 2 = -4$
- $-2 \cdot 3 = -6$
- $-2 \cdot 4 = -8$

**Result:** `-2 -4 -6 -8 `

## Edge Cases & Assumptions
- **n = 0:** The loop condition `i <= 0` is false immediately, so nothing is printed.
- **x = 0:** All multiples will be 0 (e.g., `0 0 0...`).
- **Negative x:** Handled naturally by standard integer multiplication.
- **Large n and x:** The maximum value is $1000 \cdot 1000 = 1,000,000$, which is well within the `int` limit of $\approx 2.1$ billion.

## Common Mistakes & Pitfalls
1. **Starting index:** Starting the loop at `i = 0` instead of `i = 1`, which would result in the first output being 0.
2. **Loop condition:** Using `i < n` instead of `i <= n`, which would print $n-1$ multiples instead of $n$.
3. **Integer Overflow:** Not a concern here due to constraints, but relevant if $n$ or $x$ were $> 50,000$.

## Learning Outcome
- Mastering basic loop structures and control flow.
- Understanding how to map mathematical sequences to iterative code.
- Managing simple user inputs and formatted standard output.
