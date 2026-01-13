# Bitwise Unset i-th Bit

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Bitwise Operators, Bit Clearing, Masking
- **Language Used:** C

## Problem Statement
Given an integer `n` and a bit position `i`, unset (clear) the i-th bit of `n` using only bitwise operators. Bits are numbered from right to left starting at position 0 (least significant bit). The operation should set the specified bit to 0 regardless of its previous state, while preserving all other bits.

## Input Specification
- **Input Type:** Two integers on separate lines
  - First line: Integer `n` (the number to modify)
  - Second line: Integer `i` (bit position to unset, 0-based from right)
- **Input Constraints:**
  - -10^9 ≤ n ≤ 10^9 (32-bit signed integer range)
  - 0 ≤ i ≤ 31 (valid bit positions)

## Output Specification
- **Output Type:** Single integer
- **Output Format:** The modified value of `n` after unsetting the i-th bit

## Constraints & Rules
- Must use only bitwise operators (no arithmetic division/modulo)
- Bit positions use 0-based indexing from right (LSB = position 0)
- Handles both positive and negative numbers correctly
- Position `i` guaranteed to be valid (0-31)

## Core Concept(s) Used

### Bitwise NOT (~) Operator
The unary NOT operator inverts all bits: 0 becomes 1, 1 becomes 0. Applied to a single set bit, it creates a mask with all bits set except at the target position.

### Left Shift (<<) Operator
Shifts a value left by specified positions, effectively multiplying by 2^i. Used to position a single set bit at the target location.

### Bitwise AND (&) Operator
Clears bits where the mask has 0s, preserves bits where mask has 1s. Perfect for selectively clearing specific bits.

## Logic & Reasoning

**Standard algorithm to unset i-th bit: `n & ~(1 << i)`**

**Step-by-step breakdown:**

1. **Create position mask:** `1 << i`
   - Shifts 1 left by i positions: sets only the i-th bit
   
2. **Invert the mask:** `~(1 << i)`
   - Flips all bits: i-th bit becomes 0, all others become 1
   
3. **Clear target bit:** `n & ~(1 << i)`
   - AND operation clears i-th bit (0 & anything = 0)
   - Preserves all other bits (1 & original = original)

**Visual Example (n=29, i=3):**
```
n     = 29 = 00011101
1<<3  =  8 = 00001000
~(1<<3)=247= 11110111
-----------------------------
n & ~  = 21 = 00010101 ✓ (bit 3 cleared)
```

**Why it works for any initial bit state:**
- If i-th bit was 0: 0 & 0 = 0 (unchanged)
- If i-th bit was 1: 1 & 0 = 0 (cleared)

## Step-by-Step Algorithm

1. **Read Input:**
   - Read integer `num` from first line
   - Read integer `i` from second line

2. **Create Clearing Mask:**
   - Compute `1 << i` (sets i-th bit)
   - Invert with `~` to get clearing mask

3. **Apply Bit Clearing:**
   - `num = num & ~(1 << i)`

4. **Output Result:**
   - Print modified `num`

## Time & Space Complexity

- **Time Complexity:** O(1)
  Three bitwise operations only.

- **Space Complexity:** O(1)
  Single integer variable modified in-place.

## Sample Execution

### Example 1
**Input:**
```
5
1
```

**Binary Processing:**
```
n    = 5  = 00000101 (bit 1 = 0)
1<<1 = 2  = 00000010
~(1<<1)=253= 11111101
-----------------------------
Result= 5  = 00000101 (unchanged, bit 1 was already 0)
```

**Output:** `5`

---

### Example 2
**Input:**
```
29
3
```

**Binary Processing:**
```
n     = 29 = 00011101 (bit 3 = 1)
1<<3  =  8 = 00001000
~(1<<3)=247= 11110111
-----------------------------
Result= 21 = 00010101 (bit 3 cleared: 1→0)
```

**Output:** `21`

---

### Example 3 (Negative Number)
**Input:**
```
-16
2
```

**Binary Processing (32-bit 2's complement):**
```
n      = -16 = 11111111...11110000 (bit 2 = 0)
1<<2   =     4 = 00000000...00000100
~(1<<2)=     = 11111111...11111011
---------------------------------------
Result = -20 = 11111111...11111011 (bit 2 remains 0)
```

**Output:** `-20`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Bit already unset:** `5,1` → no change
- **Bit set:** `29,3` → successfully cleared
- **Position 0 (LSB):** Clears least significant bit
- **Position 31 (MSB):** Clears sign bit (for negatives)
- **Negative numbers:** Two's complement handled correctly
- **Zero input:** `0,i` → remains 0

### Assumptions Made:
- Standard 32-bit integer representation
- Two's complement for negative numbers
- Left shift behavior for positive 1
- No overflow in `1 << i` (i ≤ 31)

## Common Mistakes & Pitfalls

1. **Wrong operator precedence**
   ```c
   ❌ num & ~1 << i    // Shifts ~1, not 1
   ✅ num & ~(1 << i)  // Correct grouping
   ```

2. **Using OR instead of AND**
   ```c
   ❌ num | ~(1 << i)  // Sets other bits incorrectly
   ✅ num & ~(1 << i)  // Clears target bit only
   ```

3. **Single line input assumption**
   ```c
   ❌ scanf("%d %d", &num, &i)  // Wrong format
   ✅ Two separate scanf calls  // Matches input format
   ```

4. **Right shift confusion**
   ```c
   ❌ 1 >> i            // Wrong direction
   ✅ 1 << i            // Positions mask correctly
   ```

5. **Missing parentheses**
   ```c
   ❌ num & ~1 << i     // Operator precedence issue
   ✅ num & ~(1 << i)   // Explicit grouping
   ```

## Learning Outcome

- Mastering bit clearing using AND with inverted mask
- Understanding mask creation with left shift and NOT
- Proper operator precedence in compound bitwise expressions
- Handling multi-line input correctly in competitive programming
- Bit manipulation works identically for positive/negative integers
