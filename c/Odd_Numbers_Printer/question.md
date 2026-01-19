# Odd Numbers Printer

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Iteration, Arithmetic Sequences
- **Language Used:** C

## Problem Statement
The goal is to print every odd number starting from 1 up to a given limit $N$. Each number must be followed by a trailing space.

## Input Specification
- **Input:** A single integer $N$.
- **Constraints:** $0 \le N \le 10^6$.

## Output Specification
- **Output:** A space-separated sequence of odd integers (e.g., `1 3 5 ...`).

## Core Concept(s) Used

### Iteration with Step Values
Instead of checking every single number from 1 to $N$ with a conditional `if (i % 2 != 0)`, we can optimize the loop by starting at the first odd number (1) and incrementing by 2 (`i += 2`). 



### Odd Number Definition
An odd number is an integer that is not divisible by 2. When divided by 2, it leaves a remainder of 1. In a range starting from 1, the sequence is $1, 3, 5, 7, \dots$.

## Logic & Reasoning
The sequence of odd numbers forms an arithmetic progression where:
- **First term ($a$):** 1
- **Common difference ($d$):** 2

By setting the loop's increment to `i += 2`, the program only visits odd values. This is $O(N/2)$ complexity, which is twice as fast as checking every number in the range.



## Step-by-Step Algorithm
1. Read the input integer $N$.
2. Initialize a `for` loop with the starting value `i = 1`.
3. Set the termination condition to `i <= N`.
4. In each step:
   - Print the current value of `i` followed by a space.
   - Increment `i` by 2.
5. End the program when `i` exceeds $N$.

## Time & Space Complexity
- **Time Complexity:** $O(N)$ — Specifically $\approx N/2$ iterations.
- **Space Complexity:** $O(1)$ — Only the input variable and loop counter are stored in memory.

## Sample Execution Trace
**Input:** `10`
- `i = 1`: Print `1 `
- `i = 3`: Print `3 `
- `i = 5`: Print `5 `
- `i = 7`: Print `7 `
- `i = 9`: Print `9 `
- `i = 11`: $11 > 10$, Loop terminates.

## Common Mistakes & Pitfalls
- **Incorrect Step:** Using `i++` inside the loop without a conditional check will print all numbers (1, 2, 3...) instead of just odd ones.
- **Initialization:** Starting at `i = 0` would result in even numbers if using the `i += 2` step.
