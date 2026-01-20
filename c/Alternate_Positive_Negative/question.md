# Alternate Positive/Negative Sequence

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Modulo Operator, Signed Integers
- **Language Used:** C

## Problem Statement
The task is to generate a sequence of $n$ terms starting from 1. The numbers should increment by 1 in absolute value, but the sign must alternate: positive for odd-positioned terms and negative for even-positioned terms.



## Logic & Reasoning

### Identifying the Pattern
If we look at the sequence: $1, -2, 3, -4, 5, -6, \dots$
- Term 1: `1` (Odd index, Positive)
- Term 2: `-2` (Even index, Negative)
- Term 3: `3` (Odd index, Positive)
- Term 4: `-4` (Even index, Negative)

The pattern is directly tied to the parity (even or odd nature) of the current number $i$.

### Mathematical Logic
To determine the sign, we use the **Modulo Operator (%)**:
- If $i \pmod 2 == 0$ (Even): Multiply the number by $-1$.
- If $i \pmod 2 \neq 0$ (Odd): Keep the number positive.



## Core Concept(s) Used

### For Loop Iteration
The loop starts at $1$ and runs exactly $n$ times. Since the problem asks for the first $n$ terms, the condition is `i <= n`.

### Conditional Branching
An `if-else` statement is used inside the loop to check the parity of the current iterator.

## Step-by-Step Algorithm
1. Read the total number of terms $n$ from the user.
2. Initialize a `for` loop with $i = 1$.
3. In each iteration:
   - Check if $i$ is even using `i % 2 == 0`.
   - If **Even**: Print $-i$ followed by a space.
   - If **Odd**: Print $i$ followed by a space.
4. Continue until $i$ reaches $n$.

## Time & Space Complexity
- **Time Complexity:** $O(n)$ — The loop executes exactly $n$ times.
- **Space Complexity:** $O(1)$ — Only one integer variable is used for input and one for the iterator.

## Sample Execution Trace
**Input:** `4`
- `i = 1`: $1 \pmod 2 \neq 0 \rightarrow$ Output: `1 `
- `i = 2`: $2 \pmod 2 = 0 \rightarrow$ Output: `-2 `
- `i = 3`: $3 \pmod 2 \neq 0 \rightarrow$ Output: `3 `
- `i = 4`: $4 \pmod 2 = 0 \rightarrow$ Output: `-4 `
**Final Output:** `1 -2 3 -4 `

## Common Mistakes & Pitfalls
- **Incorrect Starting Point:** Starting the loop from $0$ instead of $1$.
- **Missing Spaces:** Forgetting the space character in `printf("%d ", ...)`.
- **Large $n$:** While $10000$ is well within the limits of a 32-bit `int`, always ensure the data type can handle the constraints.
