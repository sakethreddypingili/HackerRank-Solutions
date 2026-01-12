# Bitwise Even or Odd

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bitwise Operations, Bit Manipulation, Parity Check
- **Language Used:** C

## Problem Statement
Given an integer N, determine whether it is even or odd using only bitwise operators. The solution must not use the modulus (%) operator for the calculation. Instead, the problem requires leveraging bit-level operations to check the parity of the number.

## Input Specification
- **Input Type:** Single integer N
- **Input Constraints:**
  - -10^5 ≤ N ≤ 10^5
  - Integer value within standard int range

## Output Specification
- **Output Type:** String
- **Output Format:**
  - Print `Even` if N is an even number
  - Print `Odd` if N is an odd number

## Constraints & Rules
- The modulus operator (%) is prohibited for this solution
- Must use bitwise operators exclusively for parity determination
- Input range supports both positive and negative integers
- Solution must handle negative numbers correctly

## Core Concept(s) Used

### Bitwise AND Operation
The bitwise AND operator (`&`) compares each bit of two operands and returns 1 only if both corresponding bits are 1. When applied with the number 1, it effectively isolates the least significant bit (LSB) of any integer [web:5].

### Least Significant Bit (LSB)
In binary representation, the rightmost bit is called the LSB. For integers:
- If LSB = 1, the number is odd
- If LSB = 0, the number is even

This property holds true regardless of whether the number is positive or negative, because two's complement representation maintains the LSB parity [web:5][web:11].

### Binary Representation Pattern
- Even numbers always end with 0 in binary (e.g., 4 = 100, 6 = 110, 8 = 1000)
- Odd numbers always end with 1 in binary (e.g., 3 = 011, 5 = 101, 7 = 111)

## Logic & Reasoning

The solution exploits the fundamental property of binary representation where the LSB determines parity.

**Why `num & 1` works:**
1. The number 1 in binary is represented as `...00001` (all zeros except the LSB)
2. When performing `num & 1`, all bits except the LSB are masked to 0
3. The result is:
   - 1 if the LSB of num is 1 (odd number)
   - 0 if the LSB of num is 0 (even number)

**Why this works for negative numbers:**
- Two's complement representation preserves the LSB parity
- Example: -4 in binary (32-bit) = 11111111111111111111111111111100 (LSB = 0, even)
- Example: -5 in binary (32-bit) = 11111111111111111111111111111011 (LSB = 1, odd)

**Advantages over modulus operator:**
- Bitwise AND is faster (single CPU cycle)
- Modulus involves division, which is computationally expensive
- Demonstrates understanding of low-level bit manipulation

## Step-by-Step Algorithm

1. **Read Input:**
   - Declare an integer variable `num`
   - Use `scanf` to read the integer from standard input

2. **Perform Bitwise Check:**
   - Compute `num & 1`
   - This isolates the least significant bit

3. **Conditional Output:**
   - If `num & 1` equals 1 → Print "Odd"
   - If `num & 1` equals 0 → Print "Even"

4. **Return:**
   - Exit the program successfully

## Time & Space Complexity

- **Time Complexity:** O(1)  
  Single bitwise AND operation is performed, which executes in constant time.

- **Space Complexity:** O(1)  
  Only one integer variable is used for storage.

## Sample Execution

### Example 1
**Input:** `4`

**Binary Representation:** 100

**Processing:**

num = `4` = `100` (binary)
`1`       = `001` (binary)
-----------------
num & `1` = `000` (binary) = `0`

**Output:** `Even`

---

### Example 2
**Input:** `19`

**Binary Representation:** 10011

**Processing:**

num = `19` = `10011` (binary)
`1`        = `00001` (binary)
---------------------
num & `1`  = `00001` (binary) = `1`

**Output:** `Odd`

---

### Example 3
**Input:** `-8`

**Binary Representation (32-bit):** 11111111111111111111111111111000

**Processing:**

num = `-8` = `...11111000` (binary)
`1`        = `...00000001` (binary)
-------------------------
num & `1`  = `...00000000` (binary) = `0`


**Output:** `Even`

---

### Example 4
**Input:** `-7`

**Binary Representation (32-bit):** 11111111111111111111111111111001

**Processing:**

num = `-7` = `...11111001` (binary)
`1`       = `...00000001` (binary)
-------------------------
num & `1`  = `...00000001` (binary) = `1`


**Output:** `Odd`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero:** 0 is considered even (LSB = 0)
- **Negative even numbers:** -2, -4, -100 → LSB = 0
- **Negative odd numbers:** -1, -3, -99 → LSB = 1
- **Boundary values:** -100000, 100000

### Assumptions Made:
- Input is always a valid integer
- No input validation is required
- Standard input/output streams are available
- The system uses standard two's complement representation for negative numbers

### Not Required:
- Error handling for non-integer input
- Validation for out-of-range values
- Multiple test case handling (single input only)

## Common Mistakes & Pitfalls

1. **Using modulus operator**
   - ❌ `if (num % 2 == 0)`
   - ✅ `if (num & 1)`

2. **Incorrect bitwise operator**
   - ❌ Using `|` (OR) or `^` (XOR) instead of `&` (AND)
   - ✅ Always use bitwise AND with 1

3. **Wrong comparison logic**
   - ❌ `if (num & 1 == 0)` → operator precedence issue
   - ✅ `if ((num & 1) == 0)` or `if (num & 1)`

4. **Misunderstanding negative numbers**
   - ❌ Assuming bitwise operations don't work on negatives
   - ✅ Two's complement ensures LSB parity is preserved

5. **Overthinking the solution**
   - ❌ Using bit shifting or complex logic
   - ✅ Simple `num & 1` is sufficient

## Learning Outcome

- Understanding bitwise AND operator and its practical application for parity checking
- Learning how least significant bit determines even/odd property
- Recognizing efficiency benefits of bitwise operations over arithmetic operations
- Understanding two's complement representation for negative integers
- Mastering bit-level manipulation techniques for optimization
