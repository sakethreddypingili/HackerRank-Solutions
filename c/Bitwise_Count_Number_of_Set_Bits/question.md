# Bitwise Count Number of Set Bits

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Population Count, Bitwise AND, Left Shift
- **Language Used:** C

## Problem Statement
Write a program to count the number of set bits in the first 4 bits (rightmost bits) of an integer `n`. Use bitwise operators to solve the problem.

## Input Specification
- **Input Type:** Single integer `n`
- **Input Constraints:**
  - −2³¹ ≤ n ≤ 2³¹
  - 32-bit signed integer range

## Output Specification
- **Output Type:** Integer
- **Output Format:** Print the count of set bits (1s) in the first 4 rightmost bits

## Constraints & Rules
- Count only first 4 bits (bits 0, 1, 2, 3)
- Handle negative numbers correctly (two's complement)
- Use bitwise operations exclusively
- Fixed 4-bit window regardless of number magnitude

## Core Concept(s) Used

### Bit Position Checking with Left Shift
**Core Technique:** `(n & (1 << i))` checks if bit `i` is set

```
1 << 0 = 0001  → checks bit 0
1 << 1 = 0010  → checks bit 1  
1 << 2 = 0100  → checks bit 2
1 << 3 = 1000  → checks bit 3
```

**How it works:**
```
If bit i is 1:  (1... & 1...) = 1... (non-zero ✓)
If bit i is 0:  (0... & 1...) = 0... (zero ✗)
```

### First 4 Bits Mask Alternative
```
n & 0xF  → extracts bits 0-3: 00001111 mask
Then count set bits in result
```

## Logic & Reasoning

**Sequential Bit Testing:**
```
For each position i (0 to 3):
1. Create mask: 1 << i
2. AND with n: n & mask  
3. Non-zero result = bit i is set
4. Increment counter
```

**Sample: n = 29 (11101)**
```
Bit 0: 11101 & 00001 = 00001 ✓ count=1
Bit 1: 11101 & 00010 = 00000 ✗ count=1  
Bit 2: 11101 & 00100 = 00100 ✓ count=2
Bit 3: 11101 & 01000 = 01000 ✓ count=3
Output: 3 ✓
```

**Negative Numbers (Two's Complement):**
```
n = -8 = ...11111000
Bits 0-3: 1000 → 1 set bit ✓
```

## Step-by-Step Algorithm

1. **Read input** `n` using `scanf`
2. **Initialize counter** `count = 0`
3. **Loop 4 times** (i = 0 to 3):
   - Check if `(n & (1 << i)) != 0`
   - If true, increment `count`
4. **Print result** `count`

## Time & Space Complexity

- **Time Complexity:** O(1)
  Fixed 4 iterations regardless of input size

- **Space Complexity:** O(1)
  Constant variables only

## Sample Execution

### Sample Input 0: `29`
```
Binary:  ...11101
Check:   
Bit0: 11101 & 00001 = 00001 ✓ (1)
Bit1: 11101 & 00010 = 00000 ✗ (1)  
Bit2: 11101 & 00100 = 00100 ✓ (2)
Bit3: 11101 & 01000 = 01000 ✓ (3)
Output: 3
```

### Sample Input 1: `15`
```
Binary:  ...1111
All 4 bits set ✓
Output: 4
```

### Additional Test Cases:
```
0   → 0000 → 0 set bits
8   → 1000 → 1 set bit  
7   → 0111 → 3 set bits
-1  → 1111 → 4 set bits
```

## Edge Cases & Assumptions

### Edge Cases Covered:
```
0          → 0000 → count=0 ✓
15         → 1111 → count=4 ✓
-1         → 1111 → count=4 ✓ (two's complement)
8          → 1000 → count=1 ✓
-8         → 1000 → count=1 ✓
INT_MIN    → handles bit 0-3 correctly ✓
```

### Assumptions Made:
- Two's complement representation for negatives
- 32-bit `int` with standard bit shifting
- Input within specified constraints

## Common Mistakes & Pitfalls

1. **Wrong shift direction:**
   ```c
   ❌ num >> i   // Shifts number, not mask
   ✅ 1 << i     // Creates position mask
   ```

2. **Infinite loop:**
   ```c
   ❌ for(i=0; num; i++)  // Depends on input
   ✅ for(i=0; i<4; i++)  // Fixed 4 bits
   ```

3. **Missing non-zero check:**
   ```c
   ❌ if(num & (1<<i))    // Works due to implicit 0 check
   ✅ if(num & (1<<i))    // Same, but explicit is clearer
   ```

4. **Sign extension issues:**
   ```c
   ❌ 1U << i     // Unsigned prevents issues
   ✅ 1 << i      // Signed works for i<31 ✓
   ```

5. **Counting all bits:**
   ```c
   ❌ while(num) count += num&1, num>>=1;
   ✅ Fixed 4-bit loop only
   ```

## Learning Outcome

- Systematic bit position testing with masks
- Left shift for bit position creation
- Fixed-window bit counting (first N bits)
- Two's complement handling in bit operations
- O(1) solution for bounded bit positions
