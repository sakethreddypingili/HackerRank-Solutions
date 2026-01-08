# Sum of Two Numbers

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Basic Arithmetic, Integer Operations, Input/Output
- **Language Used:** C

## Problem Statement
Given two integers as input, compute their sum and display the result in a specified format. The program must read two space-separated integers, add them together, and output the result with proper formatting.

## Input Specification
- **Input Type:** Two space-separated integers
- **Input Constraints:** 
  - -10⁴ ≤ a, b ≤ 10⁴
  - Both inputs are guaranteed to be valid integers

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `The sum of {a} and {b} is {sum}.`

## Constraints & Rules
- Input values range from -10,000 to 10,000
- Both positive and negative integers are allowed
- Inputs are always valid (no error handling required)
- Output must include a period at the end

## Core Concept(s) Used

### Integer Arithmetic
Addition is one of the fundamental arithmetic operations in programming. In C, the `+` operator performs integer addition when used with `int` data types. The result is also an integer.

### Function Modularity
The solution separates the calculation logic into its own function, demonstrating good software engineering practices:
- **Separation of Concerns:** I/O operations separate from business logic
- **Reusability:** Calculation function can be called multiple times
- **Testability:** Easier to test individual components

### Integer Range in C
Standard `int` in C typically uses 32 bits, supporting values from -2³¹ to 2³¹-1 (approximately ±2.1 billion), which safely accommodates the problem's constraint of ±10,000.

## Logic & Reasoning

The solution is straightforward:
1. Two integers are read from input
2. A dedicated function performs the addition operation
3. The result is formatted and printed

**Why use a separate function?**
- Demonstrates modular programming principles
- Makes code more maintainable
- Allows easy modification of calculation logic without touching I/O code

**Why this works:**
- Integer addition in C is a direct hardware operation
- No overflow risk given the constraints (sum range: -20,000 to 20,000)
- Format specifier `%d` correctly handles both positive and negative integers

## Step-by-Step Algorithm

1. **Define calculation function:**
   - Accept two integer parameters
   - Return their sum

2. **Read input:**
   - Declare two integer variables
   - Use scanf to read both values from a single line

3. **Calculate:**
   - Call calculation function with both input values
   - Store the result

4. **Output:**
   - Print formatted string with all three values (operands and result)
   - Include period at the end

## Time & Space Complexity

- **Time Complexity:** O(1) - Single addition operation and constant-time I/O
- **Space Complexity:** O(1) - Only three integer variables used (a, b, sum)

## Sample Execution

### Example 1
**Input:** `3 5`

**Processing:**
- a = 3, b = 5
- sum = 3 + 5 = 8

**Output:** `The sum of 3 and 5 is 8.`

### Example 2
**Input:** `10 20`

**Processing:**
- a = 10, b = 20
- sum = 10 + 20 = 30

**Output:** `The sum of 10 and 20 is 30.`

### Example 3 (Negative Numbers)
**Input:** `-5 3`

**Processing:**
- a = -5, b = 3
- sum = -5 + 3 = -2

**Output:** `The sum of -5 and 3 is -2.`

## Edge Cases & Assumptions

### Assumptions Made:
- Input is always two valid integers
- No input validation required per problem statement
- Numbers are space-separated on the same line

### Edge Cases Covered:
- **Boundary values:** -10,000 and 10,000
- **Negative numbers:** Both, one, or neither operand can be negative
- **Zero:** One or both operands can be zero
- **Maximum sum:** 10,000 + 10,000 = 20,000
- **Minimum sum:** -10,000 + (-10,000) = -20,000

### Not Required (per constraints):
- Overflow checking (constraints prevent overflow)
- Input validation
- Floating-point numbers

## Common Mistakes & Pitfalls

1. **Missing period in output format**
   - ❌ `printf("The sum of %d and %d is %d", a, b, c);`
   - ✅ `printf("The sum of %d and %d is %d.", a, b, c);`

2. **Wrong format specifier**
   - ❌ Using `%f` for integers
   - ✅ Using `%d` for integer values

3. **Incorrect scanf format**
   - ❌ `scanf("%d", &a); scanf("%d", &b);` (works but inefficient)
   - ✅ `scanf("%d %d", &a, &b);` (reads both at once)

4. **Forgetting address operator**
   - ❌ `scanf("%d %d", a, b);`
   - ✅ `scanf("%d %d", &a, &b);`

5. **Unnecessary complexity**
   - ❌ Using arrays or loops for two numbers
   - ✅ Simple variable declaration and addition

## Learning Outcome

- Understanding basic integer arithmetic operations in C
- Implementing modular functions for separation of concerns
- Proper use of scanf for reading multiple space-separated values
- Formatted output with printf and proper string interpolation
