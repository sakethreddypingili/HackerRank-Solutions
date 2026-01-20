# Print All Factors of a Number

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy (Logic) / Medium (Efficiency)
- **Category / Topics:** Number Theory, Loops, Optimization
- **Language Used:** C

## Problem Statement
The task is to find and print all factors of a positive integer $N$ in ascending order. A factor is any integer that divides $N$ without leaving a remainder.

## Constraints & Challenges
- **$1 \le N \le 10^9$**
- **The Pitfall:** A simple loop from $1$ to $N$ ($O(N)$) will fail for $N = 10^9$. Modern CPUs handle roughly $10^8$ operations per second; a $10^9$ loop will likely exceed the time limit (TLE).
- **The Solution:** We only need to iterate up to $\sqrt{N}$ ($O(\sqrt{N})$).

## Logic & Reasoning

### Factor Pairing
Factors always exist in pairs. If $i$ is a factor of $N$, then $N/i$ is also a factor. 
For example, if $N = 36$:
- $2$ is a factor, so $36/2 = 18$ is also a factor.
- Both factors cannot be greater than $\sqrt{36}$ (which is 6). One must be $\le 6$ and the other must be $\ge 6$.



### Ascending Order Requirement
If we use the square root optimization, we find factors like $1$ and $36$, then $2$ and $18$. Printing them immediately would result in `1 36 2 18...`, which is not ascending. To solve this:
1. Iterate $1$ to $\sqrt{N}$ and print the smaller factors.
2. Iterate back from $\sqrt{N}$ to $1$ and print the corresponding larger factors ($N/i$).



## Step-by-Step Algorithm
1. Read input $N$.
2. **First Pass:** Loop $i$ from $1$ to $\sqrt{N}$. If $N \% i == 0$, print $i$.
3. **Second Pass:** Loop $i$ from $\sqrt{N}$ down to $1$. 
   - If $N \% i == 0$:
     - Calculate the partner factor: $j = N / i$.
     - **Crucial:** If $i$ is the square root (like $6 \times 6 = 36$), don't print it again to avoid duplicates.
     - Otherwise, print $j$.

## Time & Space Complexity
- **Time Complexity:** $O(\sqrt{N})$ — For $10^9$, this is only $\approx 31,622$ iterations, which is extremely fast.
- **Space Complexity:** $O(1)$ — No arrays are needed if we use two passes.

## Sample Execution Trace
**Input:** `25`
1. $\sqrt{25} = 5$.
2. **Pass 1:** - $i=1$ (Print 1), $i=5$ (Print 5).
3. **Pass 2:**
   - $i=5$: $25/5 = 5$. Since $5 == 5$, skip.
   - $i=1$: $25/1 = 25$. (Print 25).
**Output:** `1 5 25 `
