# Bitwise Check the Sign of a Number

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bitwise Operators, Bit Manipulation, Sign Bit Detection
- **Language Used:** C

## Problem Statement
Given an integer n, determine whether the number is positive (including zero) or negative using only bitwise operators. Comparison operators such as `<`, `>`, `<=`, or `>=` are prohibited.

## Input Specification
- **Input Type:** Single integer
- **Input Constraints:**
  - Range: −2³¹ ≤ n < 2³¹
  - Valid 32-bit signed integer

## Output Specification
- **Output Type:** String
- **Output Format:**
  - Print "Positive" if n ≥ 0
  - Print "Negative" if n < 0

## Constraints & Rules
- Comparison operators (`<`, `>`, `<=`, `>=`) are not allowed
- Must use bitwise operators for sign detection
- Input is guaranteed to be within 32-bit signed integer range
- Zero is considered positive

## Core Concept(s) Used

### Two's Complement Representation
In C programming, signed integers are represented using two's complement notation. The Most Significant Bit (MSB) serves as the sign bit: 0 indicates a positive number (or zero), while 1 indicates a negative number.

### Arithmetic Right Shift
The right shift operator (`>>`) shifts bits to the right by a specified number of positions. For signed integers, arithmetic right shift preserves the sign bit by filling vacated positions with the sign bit itself. When a negative number is right-shifted by 31 positions (in 32-bit systems), the result is -1 (all bits set to 1). For positive numbers or zero, the result is 0.

### Sign Bit Extraction
By right-shifting a 32-bit signed integer by 31 positions (`n >> 31`), we effectively extract the sign bit into the least significant position. This yields 0 for non-negative numbers and -1 for negative numbers.

## Logic & Reasoning

The solution leverages the sign bit property of two's complement representation:

1. In a 32-bit signed integer, bit 31 (leftmost bit) is the sign bit
2. Right-shifting by 31 positions moves the sign bit to the rightmost position
3. For negative numbers: sign bit is 1, so `n >> 31` yields -1 (all 1s in binary)
4. For positive numbers or zero: sign bit is 0, so `n >> 31` yields 0

**Why this works:**
- The right shift operation automatically handles sign extension
- No explicit comparison is needed; the shift result directly indicates the sign
- The operation works uniformly across all values in the valid range

## Step-by-Step Algorithm

1. **Read input:**
   - Declare an integer variable `n`
   - Use `scanf` to read the integer from standard input

2. **Extract sign bit:**
   - Perform arithmetic right shift: `n >> 31`
   - This shifts all bits 31 positions to the right

3. **Determine sign:**
   - If the result equals 0, the number is positive or zero
   - If the result is non-zero (specifically -1), the number is negative

4. **Output result:**
   - Print "Positive" for non-negative numbers
   - Print "Negative" for negative numbers

## Time & Space Complexity

- **Time Complexity:** O(1)  
  A single bitwise shift operation is performed.

- **Space Complexity:** O(1)  
  Only one integer variable is used.

## Sample Execution

### Example 1
**Input:** `100`

**Processing:**
- Binary representation of 100: `0000 0000 0000 0000 0000 0000 0110 0100`
- Sign bit (bit 31): 0
- `100 >> 31` = 0
- Result: 0 indicates positive

**Output:** `Positive`

### Example 2
**Input:** `-100`

**Processing:**
- Binary representation of -100 (two's complement): `1111 1111 1111 1111 1111 1111 1001 1100`
- Sign bit (bit 31): 1
- `-100 >> 31` = -1 (all bits become 1)
- Result: -1 (non-zero) indicates negative

**Output:** `Negative`

### Example 3
**Input:** `0`

**Processing:**
- Binary representation: `0000 0000 0000 0000 0000 0000 0000 0000`
- Sign bit: 0
- `0 >> 31` = 0
- Result: 0 indicates positive

**Output:** `Positive`

## Edge Cases & Assumptions

### Assumptions Made:
- Input is always a valid 32-bit signed integer
- Zero is treated as positive per problem requirements
- Right shift behavior follows arithmetic right shift for signed integers

### Edge Cases Covered:
- **Zero:** `0 >> 31` = 0 → "Positive"
- **Maximum positive value:** `2147483647 >> 31` = 0 → "Positive"
- **Minimum negative value:** `-2147483648 >> 31` = -1 → "Negative"
- **Small negative numbers:** `-1 >> 31` = -1 → "Negative"
- **Small positive numbers:** `1 >> 31` = 0 → "Positive"

### Platform-Specific Considerations:
- The solution assumes arithmetic right shift for signed integers
- This is standard behavior in C for signed types on most platforms
- The code is portable across systems using two's complement representation

## Common Mistakes & Pitfalls

1. **Using comparison operators**
   - ❌ Writing `if (n < 0)` violates the problem constraints
   - ✅ Use bitwise shift to extract sign information

2. **Incorrect shift amount**
   - ❌ Using `n >> 32` causes undefined behavior
   - ✅ Use `n >> 31` for 32-bit integers

3. **Checking equality incorrectly**
   - ❌ Comparing with 1 instead of 0: `if ((n >> 31) == 1)`
   - ✅ Compare with 0: `if ((n >> 31) == 0)` for positive/zero

4. **Forgetting zero case**
   - ❌ Treating zero as a separate case
   - ✅ Zero is included in the positive category

5. **Using logical shift instead of arithmetic shift**
   - ❌ Using unsigned integers causes logical right shift
   - ✅ Use signed integers for arithmetic right shift with sign extension

## Learning Outcome

- Understanding two's complement representation of signed integers
- Mastering bitwise right shift operator for sign detection
- Implementing conditional logic without comparison operators
- Leveraging hardware-level operations for efficient sign checking
- Recognizing the relationship between MSB and number sign in binary systems
