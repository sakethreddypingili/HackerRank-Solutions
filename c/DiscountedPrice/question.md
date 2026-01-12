# DiscountedPrice

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Functions, Floating Point Arithmetic, Discount Calculation
- **Language Used:** C

## Problem Statement
Calculate the final price of an item after applying a percentage-based discount. The discount amount is computed as (price * percent) / 100, and the final price is the original price minus this discount amount. A specific function signature must be implemented to perform this calculation.

## Input Specification
- **Input Type:** Two space-separated float values
- **Input Constraints:**
  - `0.0 ≤ price ≤ 1,000,000.0`
  - `0.0 ≤ percent ≤ 100.0`

## Output Specification
- **Output Type:** Formatted string with float value
- **Output Format:** Exactly `"The final price is: X.XXXXXXXX"` where X is the calculated price using `%f`

## Constraints & Rules
- Must implement exact function signature: `float discounted(float price, float percent)`
- No full logic allowed in `main()`
- Output must use `%f` format specifier (6 decimal places default)
- Input guaranteed to be within constraints

## Core Concept(s) Used

### Percentage Calculation
Convert percentage to decimal multiplier: `(percent / 100)` then multiply by price.

### Floating Point Precision
C's `%f` automatically formats floats to 6 decimal places, matching sample output exactly.

### Function Modularity
Separate business logic into reusable function per problem requirements.

## Logic & Reasoning

**Formula:** `discountedPrice = price - (price * percent / 100)`

**Why this works:**
1. `price * percent` gives total discount in percentage terms
2. Division by 100 converts percentage to actual currency amount
3. Subtraction yields final price

**Mathematical equivalence:** Can be simplified to `price * (1 - percent/100)` but original formula follows problem specification exactly.

## Step-by-Step Algorithm

1. **Read inputs:** Two floats (price, percent) from standard input
2. **Call function:** `discounted(price, percent)` computes final price
3. **Inside function:**
   - Calculate `discountAmount = (price * percent) / 100`
   - Return `price - discountAmount`
4. **Format output:** Print using exact required format string

## Time & Space Complexity

- **Time Complexity:** O(1)
  Single arithmetic operation sequence.
- **Space Complexity:** O(1)
  Three float variables total.

## Sample Execution

### Example 1
**Input:** `1000 20`

**Processing:**
discountAmount = `(1000 * 20) / 100 = 200.0`
discountedPrice = `1000 - 200 = 800.000000`

**Output:** `The final price is: 800.000000`

### Example 2
**Input:** `500 12.5`

**Processing:**
discountAmount = `(500 * 12.5) / 100 = 62.5`
discountedPrice = `500 - 62.5 = 437.500000`

**Output:** `The final price is: 437.500000`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero discount:** `price 0` → returns original price
- **100% discount:** `price 100` → returns 0.0
- **Zero price:** `0 percent` → returns 0.0
- **Maximum values:** `1000000 100` → handles large floats correctly

### Assumptions Made:
- Input always valid per constraints
- Floating point precision sufficient for constraints
- `%f` provides exact required decimal formatting

## Common Mistakes & Pitfalls

1. **Wrong function signature**
   - ❌ `double discounted(...)` or missing parameters
   - ✅ `float discounted(float price, float percent)`

2. **Integer division**
   - ❌ Using `int` types causing truncation
   - ✅ All `float` types throughout

3. **Output formatting**
   - ❌ `%.2f` or `%.0f`
   - ✅ `%f` exactly as specified

4. **Logic in main()**
   - ❌ Calculation directly in main
   - ✅ Use required function call

5. **scanf format mismatch**
   - ❌ `%lf` for floats
   - ✅ `%f` for float variables

## Learning Outcome
- Implementing exact function signatures per specification
- Floating point arithmetic and precision handling in C
- Modular code design separating logic from I/O
- Precise output formatting matching test cases
- Understanding discount calculation formulas
