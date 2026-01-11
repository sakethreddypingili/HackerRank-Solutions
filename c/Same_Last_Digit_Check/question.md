# Check if Two Numbers Have Same Last Digit

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bitwise Operations, Integer Arithmetic, Modulo Alternative, Function Design
- **Language Used:** C

## Problem Statement
Given two integers `a` and `b`, determine if they share the same last digit (units place). Output "YES" if both numbers end with the same digit, otherwise output "NO". Bonus challenge: implement without using the modulo operator `%`.

## Input Specification
- **Input Type:** Two space-separated integers
- **Input Constraints:**
  - `0 ≤ a, b ≤ 10^9`

## Output Specification
- **Output Type:** Single word
- **Output Format:** `"YES"` or `"NO"` (exact case, no quotes)

## Constraints & Rules
- Numbers can be as large as 1 billion
- Zero is a valid input and has last digit 0
- Must create a separate function for the comparison logic
- Bonus: Avoid using modulo operator `%`

## Core Concept(s) Used

### Last Digit Extraction
The last digit of any integer `n` can be extracted using:
- **Modulo method:** `n % 10`
- **Division method:** `n - (n/10)*10`

### Bitwise AND Optimization
Last digit comparison can be done efficiently using bitwise operations:
`
(n & 15) == (m & 15)
`
The value `15` (binary `1111`) masks the last 4 bits, preserving only the last digit.

## Logic & Reasoning

**Primary Approach (Division-based):**
`
lastDigit(n) = n - (n/10)*10
`
- `n/10` performs integer division (truncates decimal)
- `(n/10)*10` gives the number without last digit
- Subtracting gives exactly the last digit

**Why this works:**
- Works for all non-negative integers including 0
- Integer division automatically floors the result
- No modulo operator required

**Bitwise Alternative:**
- `n & 15` extracts last 4 bits (0-15 range covers digits 0-9)
- Direct comparison of masked values

## Step-by-Step Algorithm

1. **Read input:**
   - Scan two integers `a` and `b`

2. **Extract last digits using function:**
   `
   lastDigitA = a - (a/10)*10
   lastDigitB = b - (b/10)*10
   `

3. **Compare digits:**
   - If equal, return indicator for "YES"
   - Else return indicator for "NO"

4. **Output result:**
   - Print "YES" or "NO" based on function result

## Time & Space Complexity

- **Time Complexity:** O(1)
  Constant-time arithmetic operations only.

- **Space Complexity:** O(1)
  Only a few integer variables used.

## Sample Execution

### Example 1
**Input:** `57 87`

**Processing:**
- Last digit of 57: `57 - (57/10)*10 = 57 - 5*10 = 7`
- Last digit of 87: `87 - (87/10)*10 = 87 - 8*10 = 7`
- `7 == 7` → YES

**Output:** `YES`

### Example 2
**Input:** `123 456`

**Processing:**
- Last digit 123: `3`
- Last digit 456: `6`
- `3 != 6` → NO

**Output:** `NO`

### Example 3
**Input:** `100 0`

**Processing:**
- Last digit 100: `0`
- Last digit 0: `0`
- `0 == 0` → YES

**Output:** `YES`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero inputs:** `0 0` → YES, `100 0` → YES
- **Single digits:** `5 5` → YES
- **Large numbers:** `999999999 123456789` → NO
- **Same number:** `42 42` → YES

### Assumptions:
- All inputs are non-negative integers per constraints
- No overflow concerns (int handles up to 10^9 safely)

## Common Mistakes & Pitfalls

1. **Using modulo operator (misses bonus)**
   - ❌ `num1 % 10 == num2 % 10`
   - ✅ `num - (num/10)*10` technique

2. **Function return confusion**
   - ❌ Returning boolean directly
   - ✅ Return integer flags (1=YES, 2=NO) for clear main logic

3. **Case sensitivity**
   - ❌ `Yes`, `yes`, `YEs`
   - ✅ Exactly `"YES"` or `"NO"`

4. **Missing newline**
   - ❌ `printf("YES");`
   - ✅ `printf("YES\n");` (though not strictly required here)

5. **Integer overflow handling**
   - ❌ Assuming `long long` needed
   - ✅ `int` sufficient for 10^9 constraint

## Learning Outcome

- Multiple techniques for last digit extraction (modulo vs division)
- Bitwise operations as modulo alternatives
- Function design for reusable logic separation
- Handling edge cases with zero and large numbers
- Precise output formatting requirements
