# Rounded Value - Remove Decimals

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Type Casting, Floating Point Truncation, Input/Output Formatting
- **Language Used:** C

## Problem Statement
Given a floating-point number as input, convert it to its integer equivalent by truncating (removing) the decimal portion. Display the result in the specified format "Rounded Value = {value}". The conversion should discard the fractional part regardless of its value, effectively performing a floor operation towards zero.

## Input Specification
- **Input Type:** Single floating-point number
- **Input Constraints:** N/A (no explicit constraints provided)

## Output Specification
- **Output Type:** Formatted string containing integer value
- **Output Format:** `Rounded Value = {integer_value}`

## Constraints & Rules
- Input is guaranteed to be a valid floating-point number
- No constraints on value range or precision
- Must handle both positive and negative numbers correctly
- Decimal portion must be completely removed (truncated)
- Exact output format required with spaces around equals sign

## Core Concept(s) Used

### Implicit Type Conversion (Truncation)
In C, assigning a `float` value to an `int` variable automatically truncates the decimal portion. The fractional part is discarded, and only the integer portion is retained. This is called truncation towards zero.

### Floating Point Representation
Floating-point numbers consist of:
- Sign bit
- Exponent
- Mantissa (fractional part)

When casting to integer, only the integer portion of the mantissa is preserved.

## Logic & Reasoning

**Truncation Behavior:**

`3.14 → 3`   (truncates .14)\
`10.48 → 10` (truncates .48) 
`-8.3 → -8`  (truncates .3)  
`0.99 → 0`   (truncates .99)  
`-0.5 → 0`  (truncates towards zero)

**Why simple casting works:**
1. C automatically truncates float to int by discarding fractional part
2. Works correctly for both positive and negative numbers
3. No special rounding logic required
4. Most efficient approach (single type conversion)

**Comparison with other methods:**
- `floor()`: Always rounds down (towards negative infinity)
- `ceil()`: Always rounds up (towards positive infinity)  
- `(int)num`: Truncates towards zero ✓

## Step-by-Step Algorithm

1. **Read Input:**
   - Declare a `float` variable `num1`
   - Use `scanf("%f", &num1)` to read floating-point input

2. **Convert to Integer:**
   - Declare an `int` variable `num2`
   - Assign `num2 = num1` (implicit truncation occurs)

3. **Format Output:**
   - Use `printf("Rounded Value = %d", num2)` to display result
   - `%d` format specifier prints integer value

4. **Return:**
   - Exit program successfully

## Time & Space Complexity

- **Time Complexity:** O(1)  
  Single type conversion and I/O operation.

- **Space Complexity:** O(1)  
  Two variables only (float + int).

## Sample Execution

### Example 1
**Input:** `3.14`

**Processing:**

num1 = `3.14` (float)
num2 = `3`    (int, truncates .14)


**Output:** `Rounded Value = 3`

---

### Example 2
**Input:** `10.48`

**Processing:**

num1 = `10.48` (float)  
num2 = `10`   (int, truncates .48)


**Output:** `Rounded Value = 10`

---

### Example 3
**Input:** `-8.3`

**Processing:**

num1 = `-8.3`  (float)
num2 = `-8`    (int, truncates .3)


**Output:** `Rounded Value = -8`

---

### Example 4
**Input:** `0.99`

**Processing:**

num1 = `0.99` (float)
num2 = `0`    (int, truncates .99)


**Output:** `Rounded Value = 0`

---

### Example 5
**Input:** `-0.75`

**Processing:**

num1 = `-0.75`  (float)\
num2 = `0`      (int, truncates towards zero)


**Output:** `Rounded Value = 0`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Positive fractions:** `3.14`, `0.99` → truncate to `3`, `0`
- **Negative fractions:** `-8.3`, `-0.75` → truncate to `-8`, `0`
- **Integer values:** `5.0`, `-10.0` → remain `5`, `-10`
- **Near-zero:** `0.0001`, `-0.0001` → both become `0`
- **Large numbers:** Scientific notation handled correctly

### Assumptions Made:
- Input scanner correctly parses all float formats
- No overflow issues with float-to-int conversion
- Standard C truncation behavior (towards zero)
- No precision boundary cases in test data

### Not Required:
- Mathematical rounding (floor/ceil)
- Input validation
- Multiple test cases
- Precision handling

## Common Mistakes & Pitfalls

1. **Wrong format specifier**
   - ❌ `printf("%f", num2)` → prints float format
   - ✅ `printf("%d", num2)` → prints integer

2. **Incorrect output format**
   - ❌ `printf("Rounded Value: %d", num2)`
   - ✅ `printf("Rounded Value = %d", num2)` ✓ (exact spacing)

3. **Using explicit cast unnecessarily**
   - ❌ `int num2 = (int)num1;`
   - ✅ `int num2 = num1;` (implicit cast is fine)

4. **Wrong casting direction**
   - ❌ `float num2 = num1;` → still float
   - ✅ `int num2 = num1;` → truncates to int

5. **Using math functions**
   - ❌ `#include <math.h>` and `floor(num1)`
   - ✅ Simple type casting (no library needed)

6. **Missing space in format**
   - ❌ `"Rounded Value=%d"` → `Rounded Value=3`
   - ✅ `"Rounded Value = %d"` → `Rounded Value = 3` ✓

## Learning Outcome

- Understanding implicit type conversion from float to int in C
- Mastering truncation behavior (towards zero) vs. mathematical rounding
- Learning precise output formatting with printf specifiers
- Recognizing when simple casting solves problems efficiently
- Handling both positive and negative floating-point truncation correctly
