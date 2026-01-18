# Even Numbers Printer

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Iteration, Arithmetic Progression
- **Language Used:** C

## Problem Statement
The goal is to print every even number between 1 and a user-provided limit $N$. Each even number must be followed by a space.

## Input Specification
- **Input:** A single integer $N$.
- **Constraints:** $0 \le N \le 10^6$.

## Output Specification
- **Output:** A space-separated list of even integers (e.g., `2 4 6 ...`).

## Core Concept(s) Used

### Iteration with Step Values
While many loops increment by 1 (`i++`), we can optimize this process by starting at the first even number (2) and incrementing by 2 (`i += 2`). This effectively skips all odd numbers, making the program more efficient.



### Even Number Definition
An even number is any integer divisible by 2. In a range starting from 1, the sequence of even numbers is $2, 4, 6, 8, \dots$.

## Logic & Reasoning
There are two common ways to solve this:
1.  **Check every number:** Loop from 1 to $N$ and use `if (i % 2 == 0)` to print.
2.  **Skip odd numbers:** Start at 2 and add 2 in each step. 
    - **Pros:** Executes half as many iterations as the first method.
    - **Cons:** Must handle the case where $N < 2$ (the loop simply won't run, which is correct).



## Step-by-Step Algorithm
1. Read the input integer $N$.
2. Initialize a `for` loop with `i = 2`.
3. Set the loop condition to `i <= N`.
4. In each iteration:
   - Print the current value of `i` followed by a space.
   - Increment `i` by 2 (`i = i + 2`).
5. Terminate the program.

## Time & Space Complexity
- **Time Complexity:** $O(N/2)$ which simplifies to $O(N)$. The loop runs exactly $\lfloor N/2 \rfloor$ times.
- **Space Complexity:** $O(1)$ — Only the variable `N` and the iterator `i` are stored.

## Sample Execution
**Input:** `10`
- `i = 2`: Print `2 `
- `i = 4`: Print `4 `
- `i = 6`: Print `6 `
- `i = 8`: Print `8 `
- `i = 10`: Print `10 `
- `i = 12`: $12 > 10$, Loop terminates.

## Common Mistakes & Pitfalls
- **Starting at 0:** While 0 is even, the problem asks for the range "1 to N". Usually, natural even numbers are expected to start from 2.
- **Infinite Loops:** Ensure the increment `i += 2` is present, otherwise `i` will stay 2 forever.
