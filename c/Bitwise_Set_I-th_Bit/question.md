# Bitwise Set Ith Bit

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Bitwise Operators, Binary Operations
- **Language Used:** C

## Problem Statement
Given an integer `n` and a bit position `i`, set the i-th bit of `n` (where i=0 is the least significant bit) using only bitwise operators. The updated value of `n` with the i-th bit set to 1 must be returned.

## Input Specification
- **Input Type:** Two integers on separate lines
- **Input Constraints:**
  - First line: integer `n`
  - Second line: integer `i`

## Output Specification
- **Output Type:** Single integer
- **Output Format:** The value of `n` after setting the i-th bit to 1

## Constraints & Rules
- \(-10^9 ≤ n ≤ 10^9\)
- \(0 ≤ i ≤ 31\)
- Use only bitwise operators (no arithmetic assignment like `n += ...`)
- Works with both positive and negative numbers using two's complement

## Core Concept(s) Used
**Bitwise OR (`|`)**: Sets a specific bit to 1 without affecting other bits. If either operand has a 1 in a position, the result has 1.

**Left Shift (`<<`)**: Creates a mask with a single 1 at position `i` by shifting 1 left by `i` positions.

## Logic & Reasoning
To set the i-th bit of `n` to 1:
1. Create a mask `1 << i` (shifts 1 to position i)
2. Perform `n | mask` (OR operation sets i-th bit to 1, preserves other bits)

**Why this works:**
- OR with 1 sets target bit to 1
- OR with 0 preserves existing bits
- Left shift positions the 1 exactly at bit i

## Step-by-Step Algorithm
1. Read integer `n`
2. Read bit position `i`
3. Create mask: `mask = 1 << i`
4. Set i-th bit: `result = n | mask`
5. Output `result`

## Time & Space Complexity
- **Time Complexity:** O(1)  
  Single bitwise shift and OR operation.
- **Space Complexity:** O(1)  
  Constant extra space for mask variable.

## Sample Execution

### Sample Input 0
`10`
`3`

**Processing:**
- `n = 10` (binary: `...0001010`)
- `i = 3`, mask = `1<<3` = `8` (binary: `...0001000`)
- `10 | 8` = `...0001110` = `14`

**Output:** `14`

### Sample Input 1
`5`
`1`

**Processing:**
- `n = 5` (binary: `...0000101`)
- `i = 1`, mask = `1<<1` = `2` (binary: `...0000010`)
- `5 | 2` = `...0000111` = `7`

**Output:** `7`

## Edge Cases & Assumptions
**Edge Cases Covered:**
- `i = 0`: Sets least significant bit
- `i = 31`: Sets sign bit for 32-bit integers
- Bit already set: `n | mask` preserves it (idempotent)
- Negative numbers: Works with two's complement

**Assumptions:**
- Input follows exact format (two integers)
- `i` always valid (0-31)
- Standard 32-bit integer representation

## Common Mistakes & Pitfalls
1. **Using assignment instead of bitwise OR**
   - ❌ `n += (1<<i)`
   - ✅ `n | (1<<i)`

2. **Reading input incorrectly**
   - ❌ `scanf("%d%d", &n, &i)` (expects single line)
   - ✅ Separate `scanf` calls for each line

3. **Arithmetic instead of bitwise**
   - ❌ `n = n + (1<<i)`
   - ✅ `n | (1<<i)` (preserves other bits)

4. **Forgetting parentheses**
   - ❌ `1 << i | n`
   - ✅ `(1 << i) | n`

5. **Sign extension issues**
   - ✅ Left shift on `1` (positive) works correctly

## Learning Outcome
- Mastering bitwise OR for bit setting operations
- Understanding left shift for mask creation
- Handling multi-line input in C correctly
- Bit manipulation works identically for positive/negative integers
- Idempotent nature of bit setting (`already_set | 1 = 1`)
