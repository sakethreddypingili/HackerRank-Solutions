# Half the Number

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Type Casting, Floating-Point Arithmetic, Precision Formatting, Functions
- **Language Used:** C

## Problem Statement
Write a program that takes an integer input and outputs half its value as a floating-point number with exactly 2 decimal places. The solution must handle both positive and negative integers correctly.

## Input Specification
- **Input Type:** Single integer
- **Input Constraints:** Can be positive or negative integer

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `Half of {num} is {halfValue}` where halfValue shows 2 decimal places

## Constraints & Rules
- Input can be positive or negative
- Output must use float division (not integer division)
- Output must display exactly 2 decimal places
- No specific range constraints mentioned

## Core Concept(s) Used

### Implicit vs Explicit Type Conversion
`
Integer Division (Wrong): 7 / 2 = 3 (truncates decimal)
Float Division (Correct): 7 / 2.0 = 3.5 (preserves decimal)
`
### printf Precision Formatting
The `%.2f` format specifier forces floating-point output to exactly 2 decimal places:
- `5.0` → `5.00`
- `3.5` → `3.50`
- `-4.0` → `-4.00`

### Negative Number Handling
Arithmetic operations preserve the sign:
- `-8 / 2.0 = -4.0`
- Negative sign automatically maintained through division

## Logic & Reasoning

The key challenge is ensuring **float division** rather than integer division. Simply dividing two integers (`int / int`) performs truncation. The solution uses:

1. **Type promotion**: Integer input automatically converts to float when passed to float function
2. **Float division**: `float / 2` ensures decimal precision
3. **Format specifier**: `%.2f` guarantees 2 decimal places regardless of value

## Step-by-Step Algorithm

1. **Define calculation function:**
   - Accept float parameter (promotes int input automatically)
   - Return half value using float division
   
2. **In main():**
   - Read integer input using `%d`
   - Call calculation function
   - Print formatted output using original integer and calculated float

3. **Output formatting:**
   - `%d` for original integer input
   - `%.2f` for half value with 2 decimal places

## Time & Space Complexity

- **Time Complexity:** O(1) - Single division operation
- **Space Complexity:** O(1) - Two variables only

## Sample Execution

### Example 1
**Input:** `10`

**Processing:**
`10` → `float(10.0)`
`10.0 / 2 = 5.0`
printf("Half of 10 is %.2f", 5.0) → "Half of 10 is 5.00"

**Output:** `Half of 10 is 5.00`

### Example 2
**Input:** `7`

**Processing:**
`7` → `float(7.0)`
`7.0 / 2 = 3.5`
printf("Half of 7 is %.2f", 3.5) → "Half of 7 is 3.50"

**Output:** `Half of 7 is 3.50`

### Example 3
**Input:** `-8`

**Processing:**
-`8` → `float(-8.0)`
-`8.0 / 2 = -4.0`
printf("Half of -8 is %.2f", -4.0) → "Half of -8 is -4.00"

**Output:** `Half of -8 is -4.00`

## Edge Cases & Assumptions

### Assumptions Made:
- Input is always valid integer
- No range limits specified (int sufficient)
- Standard C floating-point precision adequate

### Edge Cases Covered:
- Zero: `0` → `Half of 0 is 0.00`
- Negative even: `-8` → `-4.00`
- Negative odd: `-7` → `-3.50`
- Large values: Precision maintained by float

## Common Mistakes & Pitfalls

1. **Integer division truncation**
   - ❌ `int half = num / 2;` → `7/2 = 3`
   - ✅ `float half = num / 2.0;` → `7/2.0 = 3.5`

2. **Wrong precision formatting**
   - ❌ `printf("%.1f", 5.0);` → `5.0`
   - ✅ `printf("%.2f", 5.0);` → `5.00`

3. **Incorrect output format**
   - ❌ `printf("Half: %.2f", half);`
   - ✅ `printf("Half of %d is %.2f", num, half);`

4. **Function parameter mismatch**
   - ❌ `float calculate(int num)` without promotion
   - ✅ `float calculate(float num)` with automatic promotion

5. **Missing decimal places for whole numbers**
   - ❌ `printf("%f", 5.0);` → `5.000000`
   - ✅ `printf("%.2f", 5.0);` → `5.00`

## Learning Outcome

- Understanding type promotion from int to float in function calls
- Mastering printf precision formatting (`%.2f`)
- Avoiding integer division truncation pitfalls
- Proper handling of negative numbers in arithmetic operations
