# Bitwise Extract the i-th Bit

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Bitwise Operators, Right Shift, Bit Masking
- **Language Used:** C

## Problem Statement
Given an integer `n` and a bit position `i`, extract and return the value of the i-th bit of `n`. The bit positions are counted from right to left using 0-based indexing, where position 0 represents the least significant bit (rightmost bit). The output should be either 1 if the bit at position `i` is set, or 0 if it is not set.

## Input Specification
- **Input Type:** Two space-separated integers
  - `n`: The number whose bit needs to be extracted
  - `i`: The bit position to extract (0-based indexing from right)
- **Input Constraints:**
  - -2^31 ≤ n ≤ 2^31 (standard 32-bit signed integer range)
  - 0 ≤ i ≤ 31 (valid bit positions for 32-bit integers)

## Output Specification
- **Output Type:** Single integer
- **Output Format:** Either `0` or `1`, representing the value of the i-th bit

## Constraints & Rules
- Bit positions use 0-based indexing starting from the rightmost bit
- The number `n` can be positive, negative, or zero
- Bit position `i` is guaranteed to be within valid range (0-31)
- Must handle signed integers correctly (two's complement representation)
- Solution must use bitwise operations for extraction

## Core Concept(s) Used

### Right Shift Operator (>>)
The right shift operator (`>>`) shifts all bits in a number to the right by a specified number of positions [web:18]. In C, the right shift on signed integers performs an arithmetic shift, preserving the sign bit [web:22].

### Bit Masking with AND
The bitwise AND operator (`&`) with mask `1` isolates a single bit by setting all other bits to 0 [web:16]. When combined with right shift, it efficiently extracts any specific bit position.

### Bit Position Indexing
Bits are indexed from right to left starting at position 0:

Example: 21 in binary = `10101`
Position:               `43210`

- Position 0: rightmost bit (LSB)
- Position 4: leftmost bit (MSB for this 5-bit number)

### Two's Complement Representation
For negative numbers, the two's complement system is used [web:22]. The sign bit (bit 31 for 32-bit integers) determines if the number is negative. Right shift operations preserve the sign bit during arithmetic shifts.

## Logic & Reasoning

The solution uses a two-step approach to extract the i-th bit:

**Step 1: Right Shift**
- `n >> i` shifts all bits of `n` to the right by `i` positions
- This brings the i-th bit to position 0 (the rightmost position)
- Example: `21 >> 2` shifts `10101` right by 2 → `00101`

**Step 2: Mask with AND**
- `(n >> i) & 1` applies a mask to isolate only the bit at position 0
- The mask `1` in binary is `00...001`
- This operation zeroes out all bits except the rightmost bit
- Example: `00101 & 00001` → `00001` = 1

**Why this works:**
- Right shift brings any bit position to the LSB location [web:18]
- AND operation with 1 isolates only that bit [web:20]
- The result is always either 0 or 1
- Works correctly for both positive and negative numbers

**Efficiency:**
- Both operations are single-cycle CPU instructions
- Time complexity is O(1)
- No loops or conditional logic needed

## Step-by-Step Algorithm

1. **Read Input:**
   - Declare two integer variables: `n` (number) and `i` (bit position)
   - Use `scanf` to read both values from standard input

2. **Extract Bit:**
   - Perform right shift: `n >> i` to move the i-th bit to position 0
   - Apply bitwise AND with 1: `(n >> i) & 1` to isolate the bit
   - Store the result in variable `bit`

3. **Output Result:**
   - Print the extracted bit value (0 or 1) using `printf`

4. **Return:**
   - Exit the program successfully

## Time & Space Complexity

- **Time Complexity:** O(1)  
  Two bitwise operations (shift and AND) execute in constant time.

- **Space Complexity:** O(1)  
  Only three integer variables are used for storage.

## Sample Execution

### Example 1
**Input:** `21 2`

**Binary Representation of 21:** `10101`

**Processing:**

n = `21` = `10101` (binary)
i = `2`

Step 1: Right shift by `2` positions
`21 >> 2 = 10101 >> 2 = 00101 = 5`

Step 2: Apply mask with 1
`5 & 1 = 00101 & 00001 = 00001 = 1`


**Bit at position 2:** `1`

**Output:** `1`

---

### Example 2
**Input:** `0 5`

**Binary Representation of 0:** `00000`

**Processing:**

n = `0 = 00000` (binary)
`i = 5`

Step 1: Right shift by 5 positions
`0 >> 5 = 00000 >> 5 = 00000 = 0`

Step 2: Apply mask with 1
`0 & 1 = 00000 & 00001 = 00000 = 0`


**Bit at position 5:** `0`

**Output:** `0`

---

### Example 3
**Input:** `15 3`

**Binary Representation of 15:** `1111`

**Processing:**

n = `15 = 1111` (binary)
`i = 3`

Step 1: Right shift by 3 positions
`15 >> 3 = 1111 >> 3 = 0001 = 1`

Step 2: Apply mask with 1
`1 & 1 = 0001 & 0001 = 0001 = 1`


**Bit at position 3:** `1`

**Output:** `1`

---

### Example 4 (Negative Number)
**Input:** `-8 2`

**Binary Representation of -8 (32-bit two's complement):**
`
11111111111111111111111111111000
`

**Processing:**

`n = -8`
`i = 2`

Step 1: Right shift by 2 positions
`-8 >> 2 = ...11111000 >> 2 = ...11111110 = -2`

Step 2: Apply mask with 1
`-2 & 1 = ...11111110 & 00000001 = 00000000 = 0`


**Bit at position 2:** `0`

**Output:** `0`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero input:** `n = 0` → all bits are 0
- **Negative numbers:** Two's complement handled correctly
- **Position 0:** Extract LSB (least significant bit)
- **Position 31:** Extract MSB (most significant bit / sign bit)
- **All bits set:** `n = -1` (all 1s in two's complement)
- **Power of 2:** Numbers like 1, 2, 4, 8, 16 (single bit set)

### Assumptions Made:
- Input integers are within specified constraints
- Bit position `i` is always valid (0-31)
- Standard two's complement representation for signed integers
- No input validation required

### Not Required:
- Handling positions outside 0-31 range
- Error messages for invalid input
- Multiple test case handling
- Conversion to binary string for display

## Common Mistakes & Pitfalls

1. **Incorrect order of operations**
   - ❌ `n & 1 >> i` (wrong operator precedence)
   - ✅ `(n >> i) & 1` (correct: shift first, then mask)

2. **Using left shift instead of right shift**
   - ❌ `(n << i) & 1` (shifts away from position 0)
   - ✅ `(n >> i) & 1` (brings bit to position 0)

3. **Wrong masking value**
   - ❌ `(n >> i) & i` (using position as mask)
   - ✅ `(n >> i) & 1` (always mask with 1)

4. **Alternative approach confusion**
   - Alternative: `(n & (1 << i)) >> i` (shift mask left, then extract)
   - Simplified: `(n >> i) & 1` (more readable and efficient)

5. **Not handling negative numbers**
   - ❌ Assuming arithmetic shift issues
   - ✅ The solution works correctly for signed integers

6. **Forgetting parentheses**
   - ❌ Relying on operator precedence without clarity
   - ✅ Using parentheses for readability: `(n >> i) & 1`

## Learning Outcome

- Understanding bitwise right shift operator and its application in bit extraction
- Learning how to isolate specific bits using shift and mask operations
- Mastering 0-based bit indexing from right to left
- Understanding two's complement representation for negative integers
- Recognizing efficient bit manipulation techniques for low-level operations
- Applying fundamental bitwise operations to solve practical problems
