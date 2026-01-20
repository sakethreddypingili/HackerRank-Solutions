# The Guardian of Prime Gate

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Primality Testing, Number Theory, Optimization
- **Language Used:** C

## Problem Statement
In the kingdom of Zabiria, you must classify a given integer $N$ into one of three categories:
1.  **Prime:** A natural number greater than 1 that has no positive divisors other than 1 and itself.
2.  **Composite:** A natural number greater than 1 that has more than two divisors.
3.  **None:** Numbers that are neither prime nor composite (specifically numbers $\le 1$).

## Logic & Reasoning

### Primality Definition
- **$N \le 1$**: By definition, these are neither prime nor composite.
- **$N = 2, 3$**: The smallest prime numbers.
- **$N > 1$**: We check for factors. If a factor exists, it is **Composite**; otherwise, it is **Prime**.



### Optimization: The Square Root Rule
To check if a number $n$ is prime, you don't need to check all numbers up to $n-1$. If $n$ has a factor, at least one factor must be less than or equal to $\sqrt{n}$. 
- **Example:** To check if 37 is prime, we only check divisors up to $\sqrt{37} \approx 6.08$ (i.e., 2, 3, 4, 5, 6).



### Handling Constraints
The constraints are $-10^9 \le N \le 10^9$. 
- Negative numbers and 0/1 are handled by the `if (num <= 1)` check.
- Since $N$ can be up to $10^9$, an $O(N)$ loop would be too slow ($10^9$ operations). The $O(\sqrt{N})$ approach reduces this to $\approx 31,622$ operations, which is nearly instantaneous.

## Core Concept(s) Used

### Trial Division
We iterate from $i = 2$ to $\sqrt{N}$. If $N \pmod i == 0$ at any point, we immediately know the number is composite and can `break` the loop.



## Step-by-Step Algorithm
1. Read the input integer $N$.
2. If $N \le 1$:
   - Print "None".
3. Else:
   - Calculate `limit = sqrt(N)`.
   - Loop $i$ from 2 to `limit`:
     - If $N$ is divisible by $i$, set a flag `isPrime = false` and break.
   - If flag remains `true`, print "Prime".
   - Else, print "Composite".

## Time & Space Complexity
- **Time Complexity:** $O(\sqrt{N})$ — The loop runs at most $\sqrt{N}$ times.
- **Space Complexity:** $O(1)$ — No additional memory is used beyond a few variables.

## Sample Execution Trace
**Input:** `7`
1. $7 > 1$, proceed to check.
2. $\sqrt{7} \approx 2.64$. Loop $i$ from 2 to 2.
3. $7 \pmod 2 \neq 0$.
4. Loop ends. Flag remains True.
**Output:** `Prime`

**Input:** `1`
1. $1 \le 1$ is True.
**Output:** `None`
