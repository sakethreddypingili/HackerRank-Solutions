# Rearrange Input Digits (Descending)

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Hard (due to strict restrictions)
- **Category / Topics:** Nested Conditionals, Digit Extraction, Sorting Logic
- **Language Used:** C

## Problem Statement
Given a 4-digit integer $N$, rearrange its digits in descending order. The catch is that you **must not** use any arrays, loops, or library sorting functions. You must rely entirely on nested `if-else` statements to perform the comparison and ordering.

## Constraints & Rules
- $1000 \le N \le 9999$.
- **Strict Prohibition:** No arrays (`int a[4]`), no loops (`for`, `while`), and no `sort()` functions.
- **Output:** The digits printed together without spaces (e.g., `8532`).

## Core Concept(s) Used

### Digit Extraction
To work with individual digits, we use the modulo (`%`) and division (`/`) operators:
- **Digit 1 (Units):** $N \pmod{10}$
- **Digit 2 (Tens):** $(N / 10) \pmod{10}$
- **Digit 3 (Hundreds):** $(N / 100) \pmod{10}$
- **Digit 4 (Thousands):** $N / 1000$

### Hardcoded Decision Tree
Since we cannot use loops or arrays, we must simulate a sorting algorithm manually. This is effectively a **Decision Tree** where we compare variables $a, b, c, d$ against each other to find the maximum, then the second maximum, and so on.



## Logic & Reasoning
The most robust way to solve this without getting lost in a mess of 24 possible permutations ($4!$) is to use a "Swap" logic based on individual comparisons. 

1. **Extraction:** Get digits into four variables: `a, b, c, d`.
2. **Comparison Passes:**
   - Compare `a` and `b`, swap if $a < b$.
   - Compare `a` and `c`, swap if $a < c$.
   - Compare `a` and `d`, swap if $a < d$.
   *(At this point, `a` is guaranteed to be the largest).*
3. **Subsequent Passes:** Repeat the process for `b` to find the second largest, and finally for `c` and `d`.



## Step-by-Step Algorithm
1. Read the 4-digit integer.
2. Extract digits into variables `d1, d2, d3, d4`.
3. Use a temporary variable `temp` to perform swaps:
   - If `d1 < d2`: swap `d1` and `d2`.
   - If `d1 < d3`: swap `d1` and `d3`.
   - If `d1 < d4`: swap `d1` and `d4`.
   - If `d2 < d3`: swap `d2` and `d3`.
   - If `d2 < d4`: swap `d2` and `d4`.
   - If `d3 < d4`: swap `d3` and `d4`.
4. Print `d1, d2, d3, d4` in sequence.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — We perform exactly 6 comparisons every time.
- **Space Complexity:** $O(1)$ — Only a few integer variables are used.

## Sample Execution
**Input:** `2583`
1. **Initial:** $d1=2, d2=5, d3=8, d4=3$
2. **d1 vs d2:** $2 < 5$, swap $\rightarrow$ $d1=5, d2=2$
3. **d1 vs d3:** $5 < 8$, swap $\rightarrow$ $d1=8, d3=5$
4. **d1 vs d4:** $8 > 3$, no swap.
5. **d2 vs d3:** $2 < 5$, swap $\rightarrow$ $d2=5, d3=2$
6. **d2 vs d4:** $5 > 3$, no swap.
7. **d3 vs d4:** $2 < 3$, swap $\rightarrow$ $d3=3, d4=2$
**Final:** `8532`
