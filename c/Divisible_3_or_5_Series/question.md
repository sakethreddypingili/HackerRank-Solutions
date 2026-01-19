# Divisible by 3 or 5 but not both

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Modulo Operator, Exclusive OR (XOR) Logic
- **Language Used:** C

## Problem Statement
The objective is to iterate through all integers from $1$ to $n$ and identify numbers that are divisible by either $3$ or $5$, but **excluding** those divisible by both (i.e., multiples of $15$).

## Logic & Reasoning

### The Exclusive OR (XOR) Concept
This problem is a classic application of **Symmetric Difference** in set theory or **XOR** in logic. We want numbers in the union of sets $Multiples(3)$ and $Multiples(5)$, excluding their intersection.



### Divisibility Rules
- **Divisible by 3:** `i % 3 == 0`
- **Divisible by 5:** `i % 5 == 0`
- **Divisible by both:** `i % 15 == 0` (or `i % 3 == 0 && i % 5 == 0`)

To implement "one or the other but not both," we can use the following logical expression:
`((i % 3 == 0) || (i % 5 == 0)) && !((i % 3 == 0) && (i % 5 == 0))`

Alternatively, in C, the inequality operator `!=` between two boolean checks acts as a logical XOR:
`(i % 3 == 0) != (i % 5 == 0)`



## Core Concept(s) Used

### The Modulo Operator (%)
The `%` operator returns the remainder of a division. If `i % k == 0`, then `i` is a multiple of `k`.

### Iteration
A `for` loop is used to traverse the range $[1, n]$. Note that the loop should start from $1$ because natural numbers are positive, and $0$ (though divisible by everything) is typically excluded unless specified.

## Step-by-Step Algorithm
1. Read the input integer $n$.
2. Start a loop from $i = 1$ to $n$.
3. For each $i$:
   - Check if $i$ is divisible by 3.
   - Check if $i$ is divisible by 5.
   - If **exactly one** of these is true, print the number followed by a space.
4. If no numbers match (e.g., $n < 3$), the loop finishes without printing anything.

## Time & Space Complexity
- **Time Complexity:** $O(n)$ — The loop runs $n$ times, performing constant-time arithmetic checks in each iteration.
- **Space Complexity:** $O(1)$ — Only a single integer variable for the input and the loop counter.

## Sample Execution Trace
**Input:** `15`
- $3, 6, 9, 12$: Divisible by 3, not 5 (Print)
- $5, 10$: Divisible by 5, not 3 (Print)
- $15$: Divisible by both 3 and 5 (Skip)
**Output:** `3 5 6 9 10 12 `

## Common Mistakes & Pitfalls
- **Including 15:** Simply checking `i % 3 == 0 || i % 5 == 0` is incorrect because it includes multiples of 15.
- **Starting from 0:** Your provided code starts from `i = 0`. Since `0 % 3 == 0` and `0 % 5 == 0` are both true, it is skipped by the "not both" logic, but generally, loops should start at 1 for "numbers between 1 and n."
