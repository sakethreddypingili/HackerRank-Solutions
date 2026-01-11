# 5th Multiple of Joined Number

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Integer Arithmetic, Mathematical Operations, Function Design, Basic Input/Output
- **Language Used:** C

## Problem Statement
Given four single digits (each ranging from 0 to 9), combine them sequentially to form a 4-digit integer and then multiply the result by 5. The solution must implement a separate function to perform the calculation rather than placing all logic in the main function.

For example, if the input digits are 1, 2, 3, 4, they should be combined to form 1234, which is then multiplied by 5 to produce 6170.

## Input Specification
- **Input Type:** Four space-separated single-digit integers
- **Input Constraints:**
  - Each digit ranges from 0 to 9 (inclusive)
  - Digits are provided in the order they should appear in the final number

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `The number is: {result}`
  - Where `{result}` is the 4-digit number multiplied by 5

## Constraints & Rules
- All four inputs are single digits (0–9)
- Digits must be combined in the exact order provided
- A separate function must be created: `int buildNumber(int a, int b, int c, int d)`
- The main function should only handle input/output and call the calculation function
- No string manipulation or conversion functions are required

## Core Concept(s) Used

### Positional Number System
Numbers in the decimal system are represented using positional notation, where each digit's value depends on its position. A 4-digit number ABCD can be mathematically expressed as:

\[ ABCD = A \times 10^3 + B \times 10^2 + C \times 10^1 + D \times 10^0 \]

### Modular Programming
The problem explicitly requires separating logic into functions, demonstrating good software engineering practices. This approach improves code readability, maintainability, and testability by isolating specific computational tasks.

### Integer Arithmetic
The solution relies on basic integer multiplication and addition operations to construct the final number and compute its fifth multiple.

## Logic & Reasoning

The solution follows a structured approach:
1. Four individual digits are received as input
2. These digits are mathematically combined using positional values
3. The resulting 4-digit number is multiplied by 5

**Why this works:**
- Each digit is multiplied by its corresponding power of 10 based on position
- The first digit represents thousands (× 1000)
- The second digit represents hundreds (× 100)
- The third digit represents tens (× 10)
- The fourth digit represents ones (× 1)
- Summing these values produces the complete 4-digit number

**Why a separate function is required:**
- Enforces separation of concerns
- Makes the code more maintainable and testable
- Follows the problem's explicit architectural requirement

## Step-by-Step Algorithm

1. **Read input:**
   - Declare four integer variables to store the input digits
   - Use `scanf` to read all four digits from a single line

2. **Create calculation function:**
   - Define `int buildNumber(int a, int b, int c, int d)`
   - Multiply first digit by 1000
   - Multiply second digit by 100
   - Multiply third digit by 10
   - Keep fourth digit as is
   - Sum all values to form the 4-digit number
   - Multiply the result by 5
   - Return the final value

3. **Call function from main:**
   - Pass the four input digits to `buildNumber`
   - Store the returned result

4. **Output:**
   - Print the formatted string with the calculated result

## Time & Space Complexity

- **Time Complexity:** O(1)  
  Only a fixed number of arithmetic operations are performed regardless of input values.

- **Space Complexity:** O(1)  
  Only a constant amount of memory is used for storing four input digits and the result.

## Sample Execution

### Example 1
**Input:** `1 2 3 4`

**Processing:**
- Digit combination: 1×1000 + 2×100 + 3×10 + 4 = 1234
- Multiplication: 1234 × 5 = 6170

**Output:** `The number is: 6170`

### Example 2
**Input:** `9 0 7 1`

**Processing:**
- Digit combination: 9×1000 + 0×100 + 7×10 + 1 = 9071
- Multiplication: 9071 × 5 = 45355

**Output:** `The number is: 45355`

### Example 3
**Input:** `0 0 0 5`

**Processing:**
- Digit combination: 0×1000 + 0×100 + 0×10 + 5 = 5
- Multiplication: 5 × 5 = 25

**Output:** `The number is: 25`

## Edge Cases & Assumptions

### Assumptions Made:
- All inputs are valid single-digit integers (0–9)
- Input format is always correct (four space-separated integers)
- No input validation is required

### Edge Cases Covered:
- **Leading zeros:** `0 0 0 5` → forms 5, result = 25
- **All zeros:** `0 0 0 0` → forms 0, result = 0
- **All nines:** `9 9 9 9` → forms 9999, result = 49995
- **Mixed values:** Any combination of digits from 0–9

### Not Required:
- Validation for non-digit inputs
- Handling of negative numbers
- String parsing or conversion

## Common Mistakes & Pitfalls

1. **Placing all logic in main()**
   - ❌ Writing the calculation directly in `main` function
   - ✅ Creating a separate `buildNumber` function as required

2. **Incorrect positional multiplication**
   - ❌ Using wrong powers of 10 (e.g., a×100 instead of a×1000)
   - ✅ First digit × 1000, second × 100, third × 10, fourth × 1

3. **Wrong function signature**
   - ❌ Using different parameter names or return type
   - ✅ Exact signature: `int buildNumber(int a, int b, int c, int d)`

4. **Forgetting to multiply by 5**
   - ❌ Returning only the combined 4-digit number
   - ✅ Multiplying the combined number by 5 before returning

5. **Incorrect output format**
   - ❌ Printing just the number without the required text
   - ✅ Using exact format: `The number is: {result}`

## Learning Outcome

- Understanding positional number systems and place value in decimal representation
- Implementing modular code design by separating logic into functions
- Performing mathematical transformations using basic arithmetic operations
- Following specific function signature requirements in competitive programming
- Producing formatted output that matches exact specifications
