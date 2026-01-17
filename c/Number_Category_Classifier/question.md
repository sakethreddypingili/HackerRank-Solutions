# Number Category Classifier

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Logical Operators, Prime Factorization, Perfect Squares, Lexicographic Priority
- **Language Used:** C

## Problem Statement
The goal is to classify an integer $N$ into one of five categories (A, B, C, D, or E) based on specific mathematical properties. If a number satisfies multiple categories, the program must output the one that comes first alphabetically (lexicographically).

## Categories & Rules

| Category | Condition |
| :--- | :--- |
| **A** | $N$ is divisible by 2 AND 3, but NOT by 5. |
| **B** | $N > 20$ AND $N$ is a product of two distinct primes in range $[2, 11]$. |
| **C** | $N$ is a two-digit number AND divisible by (3 OR 7), but NOT both (XOR logic). |
| **D** | $N$ is a perfect square AND $N < 200$. |
| **E** | None of the above conditions are met. |



## Core Concept(s) Used

### Lexicographic Order
The problem states: "Output the category that comes first in lexicographic order." This means we should check conditions in the order: A, then B, then C, then D. An `if-else if` ladder naturally handles this priority by stopping as soon as the first true condition is met.

### Product of Distinct Primes (Semiprimes)
For Category B, we look for numbers $n = p \times q$ where $p, q \in \{2, 3, 5, 7, 11\}$ and $p \neq q$. 
The set of valid numbers for Category B ($N > 20$) includes:
- $3 \times 7 = 21$
- $2 \times 11 = 22$
- $3 \times 11 = 33$
- $5 \times 7 = 35$
- $5 \times 11 = 55$
- $7 \times 11 = 77$

### Exclusive OR (XOR) Divisibility
For Category C, the number must be divisible by 3 or 7, but not both. This is represented logically as:
$((N \% 3 == 0) \neq (N \% 7 == 0))$

## Logic & Reasoning
1. **Category A:** Uses the modulo operator to check remainders for 2, 3, and 5.
2. **Category B:** Since the range of primes is small $[2, 11]$, we can pre-calculate the valid products or check the factors manually.
3. **Category C:** Requires checking if the number is in the range $[10, 99]$ or $[-99, -10]$ and applying the XOR divisibility logic.
4. **Category D:** A perfect square can be checked by comparing $N$ against the list of squares of integers from 1 to 14 ($14^2 = 196$).



## Step-by-Step Algorithm
1. Read the input integer $N$.
2. Check **Category A**: `(N % 6 == 0 && N % 5 != 0)`.
3. If not A, check **Category B**: Check if $N > 20$ and $N$ matches the pre-defined distinct prime products.
4. If not B, check **Category C**: Check if $N$ is two-digit and `(N % 3 == 0) ^ (N % 7 == 0)`.
5. If not C, check **Category D**: Check if $N$ is in the set $\{1, 4, 9, \dots, 196\}$.
6. If none match, print **E**.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — All checks are constant time comparisons.
- **Space Complexity:** $O(1)$ — No dynamic memory allocation.

## Sample Execution

### Example 1
**Input:** `21`
- **A?** Divisible by 3 but not 2. (False)
- **B?** $21 > 20$ and $21 = 3 \times 7$ (distinct primes). (True)
**Output:** `B`

### Example 2
**Input:** `30`
- **A?** Divisible by 2, 3, and 5. (False, because it's divisible by 5).
- **B?** $30 = 2 \times 3 \times 5$ (not a product of exactly *two* distinct primes). (False)
- **C?** Two-digit, divisible by 3, not divisible by 7. (True)
**Output:** `C`

## Common Mistakes & Pitfalls
- **Lexicographic Priority:** Forgetting to check Category A before others.
- **Distinct Primes:** Including numbers like $4 (2 \times 2)$ or $9 (3 \times 3)$; the primes must be *distinct*.
- **Negative Two-Digits:** Category C usually considers absolute values for "two-digit" constraints (10-99 and -10 to -99).
