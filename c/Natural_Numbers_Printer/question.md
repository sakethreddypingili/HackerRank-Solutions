# Natural Numbers Printer

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Iteration, Output Formatting
- **Language Used:** C

## Problem Statement
The objective is to print all natural numbers starting from 1 up to a given positive integer $N$. Each number must be followed by a space.

## Input Specification
- **Input Type:** A single positive integer $N$.
- **Constraints:** $0 \le N \le 10^6$.
  - Note: If $N=0$, the loop should not execute, resulting in no output (which is correct as 0 is not a natural number).

## Output Specification
- **Output Type:** A sequence of space-separated integers.
- **Example:** For $N=5$, output is `1 2 3 4 5 `.

## Core Concept(s) Used

### The `for` Loop
A `for` loop is used to execute a block of code a specific number of times. It consists of three parts:
1. **Initialization:** Setting a starting value (e.g., `int i = 1`).
2. **Condition:** The loop runs as long as this is true (e.g., `i <= N`).
3. **Increment:** Updating the counter after each iteration (e.g., `++i`).



### Standard Output (`printf`)
In C, `printf("%d ", i);` is used to print the integer value of `i` followed by a literal space character.

## Logic & Reasoning
- **Starting Point:** Natural numbers begin at 1. Therefore, our iterator starts at 1.
- **Ending Point:** The problem specifies "from 1 to N," so the condition must include $N$ (using the `<=` operator).
- **Space Handling:** The requirement states *each* number is followed by a space, including the last one. This simplifies the logic as we don't need a special condition to skip the space for the final digit.



## Step-by-Step Algorithm
1. Declare an integer variable `N`.
2. Read the value of `N` from the user using `scanf`.
3. Start a `for` loop with an iterator `i` initialized to 1.
4. Set the loop condition to `i <= N`.
5. Inside the loop, print `i` followed by a space.
6. Increment `i` by 1 after each print.
7. Return 0 to indicate successful program termination.

## Time & Space Complexity
- **Time Complexity:** $O(N)$ — The program performs $N$ print operations.
- **Space Complexity:** $O(1)$ — Only a single integer variable is used regardless of the size of $N$.

## Sample Execution
**Input:** `5`
- `i = 1`: Prints `1 `
- `i = 2`: Prints `2 `
- `i = 3`: Prints `3 `
- `i = 4`: Prints `4 `
- `i = 5`: Prints `5 `
- `i = 6`: Condition `6 <= 5` is false; loop ends.

## Common Mistakes & Pitfalls
- **Off-by-one Error:** Using `i < N` instead of `i <= N`, which would skip the last number.
- **Starting at 0:** Natural numbers start at 1. Starting at 0 would print an extra number not requested by the prompt.
- **Data Type Limits:** While $10^6$ fits in a standard 32-bit `int`, always be mindful of constraints for larger values.
