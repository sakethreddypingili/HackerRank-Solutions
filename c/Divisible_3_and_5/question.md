# Divisible by 3 and 5

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Loops, Modulo Operator, Logical AND, Least Common Multiple (LCM)
- **Language Used:** C

## Problem Statement
The goal is to identify and print all integers between 1 and 100 (inclusive) that are divisible by both 3 and 5. Each matching number should be printed on a new line.

## Logic & Reasoning

### Divisibility by Both
For a number to be divisible by both 3 and 5, it must be a multiple of their **Least Common Multiple (LCM)**. 
- Since 3 and 5 are both prime numbers, their $LCM(3, 5) = 3 \times 5 = 15$.
- Therefore, any number divisible by both 3 and 5 is simply a multiple of 15.



### The Modulo Operator (%)
To check for divisibility in C, we use the `%` operator, which provides the remainder of a division. 
- `i % 3 == 0` checks if $i$ is a multiple of 3.
- `i % 5 == 0` checks if $i$ is a multiple of 5.
- The logical AND operator `&&` ensures both conditions are met.



## Core Concept(s) Used

### Iteration
We use a `for` loop to scan the range from 1 to 100.
```c
for (int i = 1; i <= 100; i++)
