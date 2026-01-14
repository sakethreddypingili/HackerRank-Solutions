# Bitwise Check for Multiple of 4

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bitwise AND, Multiples Check, Bit Manipulation
- **Language Used:** C

## Problem Statement
Write a program to check if a given integer `n` is a multiple of 4 using only bitwise operators. Modulus (`%`), division (`/`), and loops are strictly prohibited.

## Input Specification
- **Input Type:** Single integer `n`
- **Input Constraints:**
 - −10⁵ ≤ n ≤ 10⁵

## Output Specification
- **Output Type:** String
- **Output Format:**
  - Print "Yes" if n is multiple of 4
  - Print "No" otherwise

## Constraints & Rules
- No modulus operator (`%`) allowed
- No division operator (`/`) allowed
- No loops allowed
- Must use only bitwise operations
- Works with negative numbers

## Core Concept(s) Used

### Binary Representation of Multiples of 4
Multiples of 4 always end with `00` in binary:
```
4  = 00000100  → Yes
8  = 00001000  → Yes  
12 = 00001100  → Yes
16 = 00010000  → Yes
6  = 00000110  → No (ends with 10)
7  = 00000111  → No (ends with 11)
```

### Bitwise Masking with 3 (11 in binary)
```
3 in decimal = 00000011 in binary
n & 3 checks last two bits:
- Multiple of 4: last two bits = 00 → n & 3 = 0
- Not multiple: last two bits = 01, 10, or 11 → n & 3 ≠ 0
```

## Logic & Reasoning

**Key Insight:** A number is divisible by 4 if its last two bits are both 0.

```
Check: (n & 3) == 0

Examples:
4  & 3 = 00000100 & 00000011 = 00000000 = 0 → Yes
6  & 3 = 00000110 & 00000011 = 00000010 = 2 → No  
7  & 3 = 00000111 & 00000011 = 00000011 = 3 → No
12 & 3 = 00001100 & 00000011 = 00000000 = 0 → Yes
```

**Why it works for negative numbers:**
Two's complement preserves the last two bits pattern:
```
-4 = 11111100 & 00000011 = 00000000 = 0 → Yes
-6 = 11111010 & 00000011 = 00000010 = 2 → No
```

## Step-by-Step Algorithm

1. **Read integer** `n` using `scanf`
2. **Mask last two bits:** `n & 3`
3. **Check result:**
   - If `(n & 3) == 0` → Print "Yes"
   - Else → Print "No"

## Time & Space Complexity

- **Time Complexity:** O(1)
  Single bitwise AND operation.

- **Space Complexity:** O(1)
  Single integer variable.

## Sample Execution

### Sample Input 0: `4`
```
Binary: 00000100
Mask:   00000011 (3)
Result: 00000100 & 00000011 = 00000000 = 0
Output: Yes
```

### Sample Input 1: `400`
```
Binary: 110010000 (last bits: 00)
400 & 3 = 0
Output: Yes
```

### Additional Cases:
```
Input: 6   → 00000110 & 11 = 10 ≠ 0 → No
Input: -4  → 11111100 & 11 = 00 = 0 → Yes  
Input: -8  → 11111000 & 11 = 00 = 0 → Yes
Input: 7   → 00000111 & 11 = 11 ≠ 0 → No
```

## Edge Cases & Assumptions

### Edge Cases Covered:
```
0   → 00000000 & 11 = 00 → Yes (0 is multiple of 4)
4   → 00000100 & 11 = 00 → Yes
-4  → 11111100 & 11 = 00 → Yes
100000 → 11000011010100000 & 11 = 00 → Yes
99999  → ...011 & 11 = 11 ≠ 0 → No
```

### Assumptions Made:
- Input within specified range
- Standard two's complement for negatives
- No input validation needed

## Common Mistakes & Pitfalls

1. **Using prohibited operators:**
   ```c
   ❌ if (n % 4 == 0)
   ✅ if ((n & 3) == 0)
   ```

2. **Wrong mask value:**
   ```c
   ❌ n & 2  // Only checks second bit
   ✅ n & 3  // Checks last TWO bits
   ```

3. **Missing parentheses:**
   ```c
   ❌ if (n & 3 == 0)  // Wrong precedence
   ✅ if ((n & 3) == 0)
   ```

4. **Output format errors:**
   ```c
   ❌ printf("yes");  // Wrong case
   ✅ printf("Yes");
   ```

5. **Modulo 2 confusion:**
   ```c
   ❌ n & 1  // Checks even/odd only
   ✅ n & 3  // Checks multiple of 4
   ```

## Learning Outcome

- Bit masking to check specific bit patterns
- Last two bits determine divisibility by 4
- Bitwise AND more efficient than division
- Two's complement preserves divisibility patterns
- Constant-time divisibility checking
