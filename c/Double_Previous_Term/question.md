# Loops: Double the Previous Term

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Geometric Progression, Powers of 2
- **Language Used:** C

## Problem Statement
Generate a sequence of $n$ terms where the first term is 1 and every subsequent term is exactly double the value of the term preceding it. The sequence must be enclosed within angle brackets (`< >`) and separated by single spaces.

## Input Specification
- **Input Type:** A single integer $n$.
- **Input Constraints:** $0 \le n \le 35$

## Output Specification
- **Output Type:** A formatted string containing the numeric sequence.
- **Output Format:** - Starts with `<`
  - Numbers separated by a single space
  - Ends with `>`
  - If $n \le 0$ or no series exists, the program should produce no output.

## Constraints & Rules
- The series must start at 1.
- Each term $T_i = 2 \times T_{i-1}$.
- Must handle the formatting of spaces such that no trailing space exists before the closing `>`.
- Given $n \le 35$, the values will eventually exceed the capacity of a standard 32-bit signed integer.

## Core Concept(s) Used

### Geometric Progression
This is a classic geometric progression where the first term $a = 1$ and the common ratio $r = 2$. The $i$-th term is defined as $2^{(i-1)}$.



### Data Type Capacity
In C, a standard 32-bit `int` can store values up to $2,147,483,647$. Since $2^{30}$ is roughly 1 billion, $2^{31}$ and above will cause an overflow. To handle $n$ up to 35, we must use `long long` to store the terms.

## Logic & Reasoning
The solution requires an iterative approach to calculate and print terms.
1. **Validation:** If $n$ is 0 or less, the problem states not to print anything.
2. **Opening Bracket:** Print `<` immediately.
3. **Looping:** Iterate from 1 to $n$.
4. **Separation:** Print a space *before* every term except the first one to avoid a trailing space.
5. **Calculation:** Maintain a variable that doubles each time. Using `long long` ensures that $2^{34}$ (approx 17 billion) does not overflow.
6. **Closing Bracket:** Print `>` after the loop.

## Step-by-Step Algorithm
1. Read the input integer $n$.
2. Check if $n > 0$. If not, exit.
3. Print `<`.
4. Initialize a `long long` variable `current_term = 1`.
5. For `i` from 1 to `n`:
   - Print `current_term`.
   - If `i < n`, print a space.
   - Update `current_term = current_term * 2`.
6. Print `>`.

## Time & Space Complexity
- **Time Complexity:** $O(n)$, where $n$ is the number of terms. The loop runs exactly $n$ times.
- **Space Complexity:** $O(1)$, as we only store the input $n$ and the current term.

## Sample Execution

### Input
`5`

### Processing
1. Start: `<`
2. $i=1$: Print `1`, space. $Term = 2$
3. $i=2$: Print `2`, space. $Term = 4$
4. $i=3$: Print `4`, space. $Term = 8$
5. $i=4$: Print `8`, space. $Term = 16$
6. $i=5$: Print `16`. $Term = 32$
7. End: `>`

### Output
`<1 2 4 8 16>`

## Edge Cases & Assumptions
- **n = 0:** No output produced.
- **n = 35:** The 35th term is $2^{34}$. A `long long` is required as this value is $17,179,869,184$, which exceeds the 2.1 billion limit of a standard `int`.
- **Formatting:** The space must be *between* numbers, not after the last number.

## Common Mistakes & Pitfalls
1. **Integer Overflow:** Using `int` for $n > 31$.
2. **Trailing Spaces:** Printing `<1 2 4 >` instead of `<1 2 4>`.
3. **Off-by-one:** Calculating $2^n$ as the last term instead of $2^{n-1}$.

## Learning Outcome
- Handling geometric sequences in code.
- Managing strict output formatting requirements.
- Recognizing when to use `long long` to prevent integer overflow.
