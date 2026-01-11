# Break 3 Digit Number into Individual Digits

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Mathematical Operations, Modular Programming, Digit Manipulation, Integer Division
- **Language Used:** C

## Problem Statement
Given a 3-digit number ABC, extract the individual digits A, B, and C using mathematical operations and print them separately. The solution must implement a separate function `void split(int n)` rather than performing the digit extraction directly in main().

## Input Specification
- **Input Type:** Single 3-digit integer
- **Input Constraints:** 100 ≤ n ≤ 999

## Output Specification
- **Output Type:** Space-separated integers
- **Output Format:** `{A} {B} {C}` (hundreds, tens, units digits)

## Constraints & Rules
- Must create function `void split(int n)` - no parameters other than n
- Must call function from main()
- Input guaranteed to be 3-digit number (100-999)
- No input validation required
- Print digits in order: hundreds, tens, units

## Core Concept(s) Used

### Integer Division and Modulo Operations
Extracting digits from a number uses positional mathematics:

For number ABC (where `A×100 + B×10 + C`):
- Units digit (C): `n % 10`
- Tens digit (B):  `(n / 10) % 10`
- Hundreds digit `(A): n / 100`

### Void Function Design
A `void` function performs operations but returns no value. Results are communicated through:
- Direct output (printf inside function)
- Modified parameters passed by reference (arrays/pointers)
- Global variables (not recommended)

## Logic & Reasoning

The solution uses integer division (`/`) and modulo (`%`) operators to extract positional digits:

Example: `n = 456`
1. Units: `456 % 10 = 6`
2. Tens:  `(456 / 10) % 10 = 45 % 10 = 5`
3. Hundreds: `456 / 100 = 4`

Since the function signature is fixed as `void split(int n)`, the cleanest approach is direct printing within the function. This eliminates the need for arrays or global variables while meeting all requirements.

## Step-by-Step Algorithm

1. **In main():**
   - Read single integer input
   - Call `split(n)` function
   
2. **In split(int n) function:**
   - Extract units digit: `n % 10`
   - Extract tens digit: `(n / 10) % 10`
   - Extract hundreds digit: `n / 100`
   - Print digits in order: hundreds, tens, units (space-separated)

## Time & Space Complexity

- **Time Complexity:** O(1) - Fixed 3 arithmetic operations
- **Space Complexity:** O(1) - No additional data structures

## Sample Execution

### Example 1
**Input:** `456`

**Processing:**
```
456 % 10 = 6 (units)
(456 / 10) % 10 = 45 % 10 = 5 (tens)  
456 / 100 = 4 (hundreds)
```

**Output:** `4 5 6`

### Example 2
**Input:** `902`

**Processing:**

902 % 10 = 2 (units)  
(902 / 10) % 10 = 90 % 10 = 0 (tens)
902 / 100 = 9 (hundreds)

**Output:** `9 0 2`

## Edge Cases & Assumptions

### Assumptions Made:
- Input always valid 3-digit number (100-999)
- No validation required per constraints
- Integer division truncates toward zero

### Edge Cases Covered:
- Minimum: 100 → `1 0 0`
- Maximum: 999 → `9 9 9`
- Zero in middle: 902 → `9 0 2`
- All identical: 555 → `5 5 5`

## Common Mistakes & Pitfalls

1. **Wrong digit extraction order**
   - ❌ Printing units first: `printf("%d %d %d", n%10, (n/10)%10, n/100);`
   - ✅ Hundreds first: `printf("%d %d %d", n/100, (n/10)%10, n%10);`

2. **Performing logic in main()**
   - ❌ `printf("%d %d %d", n/100, (n/10)%10, n%10);` in main
   - ✅ Create `void split(int n)` function

3. **Incorrect function signature**
   - ❌ `void split(int n, int arr[])` or other parameters
   - ✅ `void split(int n)` exactly as specified

4. **Wrong output format**
   - ❌ `printf("%d-%d-%d\n", ...);` or other separators
   - ✅ `printf("%d %d %d", ...);` (spaces only, no newline)

5. **Unnecessary input validation**
   - ❌ `if (n < 100 || n > 999)` checks
   - ✅ No validation (guaranteed valid input)

6. **Modulo precedence confusion**
   - ❌ `(n/10)%10` missing parentheses
   - ✅ `(n/10)%10` with proper grouping

## Learning Outcome

- Mastering integer division and modulo operations for digit extraction
- Understanding void functions that handle output directly
- Following strict function signature requirements in programming problems
- Applying mathematical position-based decomposition to programming
