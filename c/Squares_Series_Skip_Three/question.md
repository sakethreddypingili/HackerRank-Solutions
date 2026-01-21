# Loops: Squares Series (Filtered)

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Arithmetic Operators, Conditional Filtering
- **Language Used:** C

## Problem Statement
Generate a sequence of the first $N$ perfect squares ($1, 4, 9, 16, 25, \dots$), with a specific constraint: any square that is divisible by 3 must be excluded from the output. The program should continue generating squares until exactly $N$ valid numbers have been printed.

## Input Specification
- **Input Type:** A single integer $N$.
- **Input Constraints:** $0 \le N \le 1000$

## Output Specification
- **Output Type:** A sequence of integers.
- **Output Format:** A single line containing the numbers, each separated by a space.

## Constraints & Rules
- The output must contain exactly $N$ numbers (unless $N=0$).
- Squares divisible by 3 (e.g., 9, 36, 81) must be skipped.
- The series starts from $1^2$.

## Core Concept(s) Used

### Perfect Squares
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself ($i \times i$).

### Modulo Operator
The modulo operator (`%`) is used to determine divisibility. If `square % 3 == 0`, the number is a multiple of 3 and should be filtered out.



## Logic & Reasoning
The solution requires a counter to keep track of how many valid numbers have been printed, distinct from the iterator used to calculate the squares. 

1. We initialize a counter `count` at 0 and an iterator `i` at 1.
2. We enter a loop that runs until `count` reaches $N$.
3. Inside the loop, we calculate the square of `i`.
4. We check if this square is divisible by 3.
5. If **not** divisible by 3, we print the square, increment `count`, and then increment `i`.
6. If it **is** divisible by 3, we simply increment `i` and continue searching for the next valid square without incrementing `count`.

## Step-by-Step Algorithm
1. Read the target count $N$ from input.
2. Initialize `count = 0` and base number `i = 1`.
3. While `count < N`:
    a. Calculate `square = i * i`.
    b. If `square % 3 != 0`:
        i. Print `square` followed by a space.
        ii. Increment `count`.
    c. Increment `i`.
4. End program.

## Time & Space Complexity
- **Time Complexity:** $O(N)$. Although we skip some numbers, the number of iterations is proportional to $N$ because we are guaranteed to find a valid square at least 2 out of every 3 integers.
- **Space Complexity:** $O(1)$. We only use a few integer variables regardless of the size of $N$.

## Sample Execution
**Input:** `5`

| Iteration (i) | Square | Square % 3 == 0? | Action | Count |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | No | Print 1 | 1 |
| 2 | 4 | No | Print 4 | 2 |
| 3 | 9 | Yes | Skip | 2 |
| 4 | 16 | No | Print 16 | 3 |
| 5 | 25 | No | Print 25 | 4 |
| 6 | 36 | Yes | Skip | 4 |
| 7 | 49 | No | Print 49 | 5 |

**Output:** `1 4 16 25 49`

## Edge Cases & Assumptions
- **N = 0:** The loop condition `count < 0` is false immediately; nothing is printed.
- **Large N:** With $N=1000$, the $i$ value will exceed 1000. Since $1500^2$ is $2,250,000$, a standard 32-bit `int` is sufficient.

## Common Mistakes & Pitfalls
1. **Incrementing Count Every Time:** Incrementing the counter even when a number is skipped will result in fewer than $N$ numbers in the output.
2. **Infinite Loops:** Forgetting to increment the base iterator `i` outside of the `if` condition.
3. **Space Formatting:** A trailing space at the very end is usually acceptable in competitive programming, but one should be aware of strict presentation requirements.

## Learning Outcome
- Managing multiple counters (one for loop control, one for successful hits).
- Implementing conditional logic to filter data streams.
- Understanding the relationship between mathematical properties (perfect squares) and programming logic.
