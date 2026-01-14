# Bitwise Unset Rightmost Bit

## Problem Overview
- **Platform:** HackerRank (Peacemakers 25 [BLR-1T])
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Bitwise AND, Rightmost Set Bit Clearing
- **Language Used:** C

## Problem Statement
Write a program to clear the rightmost set bit of an integer `n`. The result should be the number obtained after flipping the rightmost set bit to 0 while leaving other bits unchanged.

## Input Specification
- **Input Type:** Single integer `n`
- **Input Constraints:**
  - −2³¹ ≤ n ≤ 2³¹
  - 32-bit signed integer range

## Output Specification
- **Output Type:** Integer
- **Output Format:**
  - Print the modified integer with rightmost set bit cleared

## Constraints & Rules
- Handle full 32-bit signed integer range
- Works with positive, negative, and zero inputs
- Single bitwise operation solution preferred
- No loops or conditional bit position detection required

## Core Concept(s) Used

### Magic Formula: `n & (n-1)`
This is a well-known bitwise trick that clears exactly the rightmost set bit:

**How it works:**
1. `n-1` flips all bits to the right of the rightmost set bit (including the set bit itself)
2. `n & (n-1)` keeps all higher bits unchanged and clears the rightmost set bit

```
Example: n = 18 (10010)
n-1 = 17 (10001)
n & (n-1) = 10010 & 10001 = 10000 = 16 ✓
```

### Visual Bit Pattern:
```
n      = ...xxx10010  (rightmost 1 at position 1)
n-1    = ...xxx10001  (flips all bits after rightmost 1)
n&(n-1)= ...xxx10000  (only rightmost 1 becomes 0) ✓
```

**Works for powers of 2:**
```
n = 8 (1000) → n-1 = 7 (0111) → 1000 & 0111 = 0000 ✓
```

## Logic & Reasoning

**Mathematical Proof:**
The rightmost set bit is at position k where bit k = 1 and bits 0 to k-1 = 0.

```
n     = ...xxxxx100...000 (2^k + higher bits)
n-1   = ...xxxxx011...111 (flips bits 0 to k-1, clears bit k)
n&(n-1)= ...xxxxx000...000 ✓ (clears exactly bit k)
```

**Negative Numbers (Two's Complement):**
```
n = -8 = 1111...1000
n-1 = -9 = 1111...0111  
n&(n-1)= 1111...0000 ✓ (clears rightmost set bit)
```

**Zero Case:**
```
n = 0 → n-1 = -1 → 0 & -1 = 0 ✓ (no set bits to clear)
```

## Step-by-Step Algorithm

1. **Input Reading:**
   - Read single integer `n` using `scanf("%d", &num)`

2. **Bit Manipulation:**
   - Apply formula: `result = num & (num - 1)`

3. **Output:**
   - Print result using `printf("%d", result)`

4. **Program Termination:**
   - Return 0 for successful execution

## Time & Space Complexity

- **Time Complexity:** O(1)
  Single bitwise AND operation regardless of input size

- **Space Complexity:** O(1)
  Uses only one integer variable

## Sample Execution

### Sample Input 0: `18`
```
Binary:     10010
n-1:        10001
Result:   10010 & 10001 = 10000 (16)
Output: 16
```

### Sample Input 1: `8`
```
Binary:      1000
n-1:         0111
Result:    1000 & 0111 = 0000 (0)
Output: 0
```

### Additional Test Cases:
```
Input: 12 → 1100 & 1011 = 1000 (8)
Input: 0  → 0000 & 1111 = 0000 (0)
Input: 7  → 0111 & 0110 = 0110 (6)
Input: 1  → 0001 & 0000 = 0000 (0)
```

## Edge Cases & Assumptions

### Edge Cases Covered:
```
0             → 0 & -1 = 0 ✓
Power of 2 (16) → 10000 & 01111 = 0 ✓
All 1s (15)    → 1111 & 1110 = 1110 ✓
Minimum int    → Handles two's complement ✓
Maximum int    → Handles 32-bit range ✓
```

### Assumptions Made:
- Standard C integer (32-bit) with two's complement
- Input exactly matches constraint range
- No input validation required per problem spec

## Common Mistakes & Pitfalls

1. **Operator Precedence:**
   ```c
   ❌ num & num - 1    // Evaluates as (num & num) - 1
   ✅ num & (num - 1)  // Correct grouping
   ```

2. **Using shifts/loops:**
   ```c
   ❌ while(num & 1) num >>= 1;  // Finds position, too complex
   ✅ num & (num - 1);           // Direct solution
   ```

3. **Wrong bitwise operation:**
   ```c
   ❌ num ^ (num - 1)  // Flips multiple bits
   ✅ num & (num - 1)  // Clears single bit
   ```

4. **Integer overflow confusion:**
   ```c
   ❌ Special handling for INT_MIN  // Unnecessary
   ✅ Standard int arithmetic works ✓
   ```

5. **Output format errors:**
   ```c
   ❌ printf("%d\n", num);  // Extra newline
   ✅ printf("%d", num);    // Exact match
   ```

## Learning Outcome

- Master the `n & (n-1)` pattern for rightmost set bit clearing
- Understand how subtraction affects bit patterns
- Recognize applications in bit counting and power-of-2 detection
- Gain confidence with negative number bit manipulation
- Learn optimal O(1) solutions for common bit problems
