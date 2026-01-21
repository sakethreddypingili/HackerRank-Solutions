# Collatz Sequence

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Conditional Logic, Sequence Generation
- **Language Used:** C

## Problem Statement
The Collatz sequence is generated from a starting positive integer $n$ by applying specific operations repeatedly until the value reaches 1. If the current number is even, it is divided by 2. If it is odd, it is multiplied by 3 and incremented by 1. The goal is to print the entire sequence from the starting value to 1, formatted with arrows.

## Input Specification
- **Input Type:** A single positive integer $n$.
- **Input Constraints:**
  - 1 ≤ n ≤ 10^5

## Output Specification
- **Output Type:** String / Numeric Sequence
- **Output Format:**
  - A single line containing the sequence of numbers.
  - Each number separated by a " -> " (space, arrow, space).

## Constraints & Rules
- The sequence must always terminate at 1.
- The input $n$ is a positive integer.
- Strict formatting is required for the separators.

## Core Concept(s) Used

### Collatz Conjecture
The Collatz conjecture (or $3n + 1$ problem) suggests that no matter what value of $n$ you start with, the sequence will always eventually reach 1.

### Iterative Transformation
The sequence is built using a simple rule-based iteration:
- **Even Rule:** $n = n / 2$
- **Odd Rule:** $n = 3n + 1$



## Logic & Reasoning
The solution employs a `while` loop that continues execution as long as the current value of $n$ is not 1. To handle the formatting requirement (where arrows appear *between* numbers but not after the final 1), the program prints the current number first.

If the number is 1, the loop terminates. If the number is greater than 1, an arrow is printed, the mathematical transformation is applied based on the parity (even/odd) of the current $n$, and the loop repeats.

## Step-by-Step Algorithm
1. Read the input integer `n`.
2. Start a loop that runs indefinitely or until `n` equals 1.
3. Print the current value of `n`.
4. Check if `n` is equal to 1:
   - If yes, break the loop.
   - If no, print the string " -> ".
5. Check if `n` is even (`n % 2 == 0`):
   - If even, update `n = n / 2`.
   - If odd, update `n = 3 * n + 1`.
6. Return to step 3.

## Time & Space Complexity
- **Time Complexity:** O(k), where k is the number of steps in the Collatz sequence for $n$. While the maximum value of $k$ for $n \le 10^5$ is relatively small (under 400 steps), the conjecture is mathematically unproven for all $n$.
- **Space Complexity:** O(1), as the solution only stores the current value of $n$ and does not use any additional data structures like arrays.

## Sample Execution

### Input
`6`

### Processing
1. `6` is even $\rightarrow 6/2 = 3$ (Print: 6 ->)
2. `3` is odd $\rightarrow 3(3)+1 = 10$ (Print: 3 ->)
3. `10` is even $\rightarrow 10/2 = 5$ (Print: 10 ->)
4. `5` is odd $\rightarrow 3(5)+1 = 16$ (Print: 5 ->)
5. `16` is even $\rightarrow 16/2 = 8$ (Print: 16 ->)
6. `8` is even $\rightarrow 8/2 = 4$ (Print: 8 ->)
7. `4` is even $\rightarrow 4/2 = 2$ (Print: 4 ->)
8. `2` is even $\rightarrow 2/2 = 1$ (Print: 2 ->)
9. `1` reached. (Print: 1)

### Output
`6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1`

## Edge Cases & Assumptions
- **Input n = 1:** The loop should print `1` and terminate immediately without any arrows.
- **Large Values:** For $n = 10^5$, intermediate values in the Collatz sequence can exceed the maximum value of a 32-bit signed integer. However, for $n \le 10^5$, the values remain within the range of a standard 32-bit `int`.

## Common Mistakes & Pitfalls
1. **Trailing Arrows:** Printing an arrow after the final `1` (e.g., `... 2 -> 1 ->`).
2. **Infinite Loops:** Forgetting to update the value of `n` inside the loop.
3. **Integer Overflow:** Using a data type that is too small if $n$ were significantly larger (e.g., $10^{12}$).

## Learning Outcome
- Implementing conditional logic within a loop structure.
- Formatting output strings to match specific requirements (separator management).
- Understanding basic sequence generation algorithms.
