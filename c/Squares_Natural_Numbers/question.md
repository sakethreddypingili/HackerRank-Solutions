# Squares of Natural Numbers

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Arithmetic Operations, Exponential Growth
- **Language Used:** C

## Problem Statement
The objective is to iterate through natural numbers starting from 1 up to a user-defined limit $N$, calculating and printing the square of each number ($i^2$). Each result must be separated by a space.

## Logic & Reasoning

### Calculating Squares
The square of a number is the product of the number multiplied by itself:
$$Square = i \times i$$


While the `pow(i, 2)` function from `math.h` can be used, it is generally more efficient in C to use simple multiplication (`i * i`) for integer squares, as it avoids the overhead of floating-point conversions.

### Iteration Process
A `for` loop is ideal for this task as the range (1 to $N$) is clearly defined.


## Core Concept(s) Used

### For Loop Structure
The loop is initialized at 1 and continues as long as the counter is less than or equal to $N$.
```c
for (int i = 1; i <= N; ++i)

```

### Output Formatting

The problem requires a space after every number. Using `printf("%d ", ...)` ensures that each square is followed by a literal space character, satisfying the requirement for the trailing space.

## Step-by-Step Algorithm

1. Declare an integer variable `N` to store the upper limit.
2. Read the value of `N` from standard input.
3. Start a loop from `i = 1` to `N`.
4. Inside the loop, calculate .
5. Print the result followed by a space.
6. Repeat until  exceeds .

## Time & Space Complexity

* **Time Complexity:**  — The loop runs exactly  times.
* **Space Complexity:**  — Only a constant amount of memory is used for variables `N` and `i`.

## Sample Execution Trace

**Input:** `5`

* `i = 1`:  Output: `1 `
* `i = 2`:  Output: `4 `
* `i = 3`:  Output: `9 `
* `i = 4`:  Output: `16 `
* `i = 5`:  Output: `25 `
**Final Output:** `1 4 9 16 25 `

## Common Mistakes & Pitfalls

* **Integer Overflow:** If  were much larger than ,  could exceed the capacity of a standard 32-bit `int`. However, with , the maximum square is , which fits safely within an `int` (limit ).
* **Floating Point Precision:** Using `pow()` returns a `double`. While `%.0f` works, small precision errors in more complex floating-point math can sometimes lead to unexpected results when converting back to integers. Simple multiplication is safer for pure integers.
