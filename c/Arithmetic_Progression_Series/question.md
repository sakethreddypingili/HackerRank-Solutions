# Loops: Arithmetic Progression

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Arithmetic Progression, Loops, Sequences
- **Language Used:** C

## Problem Statement
Generate the first $n$ terms of an Arithmetic Progression (AP). An Arithmetic Progression is a sequence of numbers in which the difference between any two consecutive terms is constant. This difference is known as the common difference ($d$).

## Input Specification
- **Input Type:** - A single integer $n$ (number of terms).
    - Two integers $a$ (first term) and $d$ (common difference).
- **Input Constraints:**
    - $0 \le n \le 1000$
    - $-1000 \le a \le 1000$
    - $-1000 \le d \le 1000$

## Output Specification
- **Output Type:** Sequence of integers.
- **Output Format:** The first $n$ terms in a single line, separated by spaces.

## Constraints & Rules
- The sequence must start exactly at $a$.
- If $n=0$, no output should be produced.
- The common difference $d$ can be positive, negative, or zero.

## Core Concept(s) Used

### Arithmetic Progression Formula
The $i$-th term ($T_i$) of an arithmetic progression can be calculated using the formula:
$$T_i = a + (i - 1) \cdot d$$
where:
- $a$ is the first term.
- $d$ is the common difference.
- $i$ is the position of the term in the sequence ($1, 2, 3, \dots, n$).



## Logic & Reasoning
The solution involves iterating $n$ times. In each iteration, we calculate the current term. There are two primary ways to implement this:
1. **Formula-based:** Use the mathematical formula $a + (i-1)d$ for each iteration. This is robust and prevents cumulative rounding errors (though not an issue with integers).
2. **Additive-based:** Start with $a$ and repeatedly add $d$ to the current value.

This solution uses the formula-based approach within a `for` loop to ensure the $i$-th term is mapped correctly to its position.

## Step-by-Step Algorithm
1. Read the number of terms $n$.
2. Read the first term $a$ and common difference $d$.
3. Initialize a loop variable `i` from 1 to $n$.
4. In each iteration:
   - Calculate the term: `current_term = a + (i - 1) * d`.
   - Print `current_term` followed by a space.
5. Exit the loop and terminate.

## Time & Space Complexity
- **Time Complexity:** $O(n)$, where $n$ is the number of terms. Each term is calculated and printed once.
- **Space Complexity:** $O(1)$, as we only store a fixed number of integer variables.

## Sample Execution

### Input
  5 2 3
### Processing
- Term 1 ($i=1$): $2 + (1-1) \cdot 3 = 2$
- Term 2 ($i=2$): $2 + (2-1) \cdot 3 = 5$
- Term 3 ($i=3$): $2 + (3-1) \cdot 3 = 8$
- Term 4 ($i=4$): $2 + (4-1) \cdot 3 = 11$
- Term 5 ($i=5$): $2 + (5-1) \cdot 3 = 14$

### Output
`2 5 8 11 14`

## Edge Cases & Assumptions
- **$n=0$:** The loop condition `i <= 0` will fail immediately; nothing prints.
- **$d=0$:** All terms will be equal to $a$.
- **Negative $d$:** The sequence will decrease (e.g., $10, 7, 4, \dots$).
- **Negative $a$:** The sequence starts from a negative value.

## Common Mistakes & Pitfalls
- **Off-by-one error:** Using `i * d` instead of `(i-1) * d`, which would skip the first term $a$.
- **Input Order:** Misinterpreting the input format; $n$ is provided on a separate line from $a$ and $d$.
- **Trailing Spaces:** While usually ignored by judges, some systems are sensitive to the space after the last digit.

## Learning Outcome
- Applying mathematical sequences to programming logic.
- Understanding the relationship between loop indices and sequence terms.
- Managing multiple variable inputs using `scanf`.
