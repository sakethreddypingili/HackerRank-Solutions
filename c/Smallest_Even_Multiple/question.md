# Smallest Even Multiple

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Arithmetic Operators, Least Common Multiple (LCM), Parity
- **Language Used:** C

## Problem Statement
Given a positive integer $n$, find the smallest positive integer that is a multiple of both 2 and $n$. This is essentially asking for the **Least Common Multiple (LCM)** of $\{2, n\}$.

## Input Specification
- **Input Type:** A single positive integer $n$.
- **Constraints:** $1 \le n \le 150$.

## Output Specification
- **Output Type:** A single integer representing the smallest common multiple.

## Logic & Reasoning

To find the smallest multiple of both 2 and $n$:
1.  **If $n$ is even:** Then $n$ is already a multiple of 2. Since any number is a multiple of itself, $n$ is the smallest multiple of both $n$ and 2.
2.  **If $n$ is odd:** The smallest multiple of 2 is 2, 4, 6... To find a multiple of $n$ that is also even, we must multiply $n$ by 2.



### Mathematical Representation
Using the relationship between LCM and GCD:
$$LCM(2, n) = \frac{|2 \times n|}{GCD(2, n)}$$

- If $n$ is even, $GCD(2, n) = 2$, so $LCM = \frac{2n}{2} = n$.
- If $n$ is odd, $GCD(2, n) = 1$, so $LCM = \frac{2n}{1} = 2n$.



## Core Concept(s) Used

### Parity (Even/Odd)
In C, parity is checked using the modulo operator `%`. 
- `n % 2 == 0` evaluates to true for even numbers.
- `n % 2 != 0` evaluates to true for odd numbers.

## Step-by-Step Algorithm
1. Read the input integer $n$.
2. Check if $n$ is divisible by 2.
3. If **True** (n is even), print $n$.
4. If **False** (n is odd), print $n \times 2$.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — A single modulo check and an optional multiplication.
- **Space Complexity:** $O(1)$ — One integer variable for storage.

## Sample Execution

### Example 1
**Input:** `5`
- $5 \pmod 2 = 1$ (Odd)
- Result: $5 \times 2 = 10$.
**Output:** `10`

### Example 2
**Input:** `6`
- $6 \pmod 2 = 0$ (Even)
- Result: $6$.
**Output:** `6`

## Common Mistakes & Pitfalls
- **Confusing Multiple with Divisor:** Trying to divide $n$ by 2 instead of multiplying.
- **Handling 1:** For $n=1$, the answer is $2$, which the odd-check logic handles correctly.
