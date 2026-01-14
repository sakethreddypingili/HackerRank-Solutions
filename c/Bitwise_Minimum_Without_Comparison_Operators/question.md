# Bitwise Minimum Without Comparison Operators

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bit Manipulation, Sign Bit Extraction, Arithmetic Right Shift
- **Language Used:** C

## Problem Statement
Write a program to find the minimum of two integers `a` and `b` without using any comparison operators (`<, >, <=, >=`). Use only bitwise operators and logical operators to determine which number is smaller.

## Input Specification
- **Input Type:** Two space-separated integers `a` and `b`
- **Input Constraints:**
  - −10⁹ ≤ a,b ≤ 10⁹
  - 32-bit signed integer range

## Output Specification
- **Output Type:** Integer
- **Output Format:** Print the smaller of the two integers

## Constraints & Rules
- No comparison operators (`<, >, <=, >=`) allowed
- No conditional branching (`if-else`) preferred
- Must handle negative numbers correctly
- Full 32-bit integer range support required

## Core Concept(s) Used

### Sign Bit Extraction via Arithmetic Right Shift
**Key Formula:** `b + ((a - b) & ((a - b) >> 31))`

**How it works:**
1. `(a - b)` computes the difference
2. `diff >> 31` extracts sign bit (1 for negative, 0 for positive)
3. `diff & sign` selects entire `diff` if negative, 0 if positive
4. `b + result` gives minimum value

```
Case 1: a >= b (diff >= 0)
diff >> 31 = 0
diff & 0 = 0  
b + 0 = b ✓ (minimum)

Case 2: a < b (diff < 0)  
diff >> 31 = -1 (all 1s)
diff & -1 = diff
b + diff = b + (a - b) = a ✓ (minimum)
```

### Arithmetic vs Logical Right Shift
```
Arithmetic >> (preserves sign bit): -2 >> 31 = -1 (111...1)
Logical >>> (zero fills): -2 >>> 31 = 0 (000...0)
```

## Logic & Reasoning

**Step-by-step breakdown:**
```
Sample: a=5, b=3
1. diff = 5-3 = 2 (>0)
2. sign = 2 >> 31 = 0  
3. mask = 2 & 0 = 0
4. result = 3 + 0 = 3 ✓

Sample: a=-7, b=2
1. diff = -7-2 = -9 (<0)
2. sign = -9 >> 31 = -1
3. mask = -9 & -1 = -9
4. result = 2 + (-9) = -7 ✓
```

**Why no branching needed:**
The formula mathematically selects minimum without conditional jumps.

## Step-by-Step Algorithm

1. **Read inputs** `a` and `b` using `scanf("%d %d", &a, &b)`
2. **Compute difference** `diff = a - b`
3. **Extract sign** `sign = diff >> 31`
4. **Create mask** `mask = diff & sign`
5. **Calculate minimum** `result = b + mask`
6. **Print result** `printf("%d", result)`

## Time & Space Complexity

- **Time Complexity:** O(1)
  Fixed number of bitwise/arithmetic operations

- **Space Complexity:** O(1)
  Constant number of integer variables

## Sample Execution

### Sample Input 0: `5 3`
```
diff = 5-3 = 2
sign = 2 >> 31 = 0
mask = 2 & 0 = 0
result = 3 + 0 = 3
Output: 3
```

### Sample Input 1: `-7 2`
```
diff = -7-2 = -9  
sign = -9 >> 31 = -1
mask = -9 & -1 = -9
result = 2 + (-9) = -7
Output: -7
```

### Additional Test Cases:
```
10 10 → diff=0 → sign=0 → result=10 ✓ (equal case)
-5 -3 → diff=-2 → sign=-1 → result=-5 ✓
0 100 → diff=-100 → sign=-1 → result=0 ✓
```

## Edge Cases & Assumptions

### Edge Cases Covered:
```
INT_MIN INT_MAX → Handles full range ✓
a == b → Returns either ✓
Both negative → Correct minimum ✓
One positive, one negative → Correct ✓
Zero cases → Works correctly ✓
```

### Assumptions Made:
- 32-bit `int` with arithmetic right shift (`>>`)
- Two's complement representation
- No integer overflow in subtraction (per constraints)
- Standard C behavior for negative right shifts

## Common Mistakes & Pitfalls

1. **Using logical shift (`>>>`):**
   ```c
   ❌ diff >>> 31  // Fills with 0s, breaks negatives
   ✅ diff >> 31   // Arithmetic shift preserves sign
   ```

2. **Wrong formula order:**
   ```c
   ❌ a + ((b-a) & ((b-a)>>31))  // Gives maximum
   ✅ b + ((a-b) & ((a-b)>>31))  // Gives minimum
   ```

3. **Missing parentheses:**
   ```c
   ❌ b + (a-b) & ((a-b)>>31)  // Wrong precedence
   ✅ b + ((a-b) & ((a-b)>>31))
   ```

4. **Using unsigned types:**
   ```c
   ❌ unsigned int  // Logical shift only
   ✅ signed int    // Arithmetic shift required
   ```

5. **Branching implementation:**
   ```c
   ❌ if ((a-b)>>31 == 0) return b; else return a;
   ✅ b + ((a-b)&((a-b)>>31))  // Branch-free
   ```

## Learning Outcome

- Sign bit extraction using arithmetic right shift
- Branch-free minimum/maximum computation
- Mathematical equivalence of conditional logic
- Two's complement behavior with shifts
- Bitwise optimization techniques for interviews
