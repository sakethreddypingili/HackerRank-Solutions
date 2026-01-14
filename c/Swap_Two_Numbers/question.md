# Swap Two Numbers

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Basic Programming, Variable Swapping, Input/Output
- **Language Used:** C

## Problem Statement
Write a program to swap two unique integers `a` and `b`. Read both numbers from input and output the swapped values in the specified format.

## Input Specification
- **Input Type:** Two space-separated integers
- **Input Constraints:**
  - -10⁶ ≤ a ≤ 10⁶
  - -10⁶ ≤ b ≤ 10⁶
  - a and b are unique (a ≠ b)

## Output Specification
- **Output Type:** Two formatted lines
- **Output Format:**

  a = ` <value_of_original_b> `\
  b = ` <value_of_original_a> `


## Constraints & Rules
- Numbers are guaranteed to be unique
- Input contains exactly two integers
- Output must follow exact format with newlines
- No temporary variable required for swapping

## Core Concept(s) Used

### Direct Value Assignment
The solution leverages the fact that both input values are read into separate variables before printing. By directly printing the swapped values, no actual variable swapping is needed in memory.

### Input/Output Redirection
Instead of swapping variable contents through assignment operations, the program reads both values and immediately outputs them in reversed order using `printf`.

### Format String Efficiency
Using a single `printf` statement with `\n` for line separation eliminates the need for multiple print calls.

## Logic & Reasoning

**Direct Output Approach:**

Input: `a=10, b=5`\
Read:  `a←10, b←5`\
Print: `"a = " + b + "\nb = " + a`\
Output:\ `a = 5`\
        `b = 10`
        

**Why this works:**
- Variables store original values throughout execution
- Printing order determines "swapped" appearance
- No memory overhead from temporary storage
- Single I/O operation for output

**Alternative approaches (not used):**
- Temporary variable: `int temp = a; a = b; b = temp;`\
- Arithmetic: `a = a + b; b = a - b; a = a - b;` (risky with overflow)\
- XOR bitwise: `a ^= b; b ^= a; a ^= b;` (unnecessary complexity)

## Step-by-Step Algorithm

1. **Declare variables:**
   - Two `int` variables `a` and `b`

2. **Read input:**
   - Use `scanf("%d %d", &a, &b)` to read both numbers

3. **Output swapped values:**
   - Print `"a = %d\nb = %d"` with arguments `b, a`

4. **Exit successfully**

## Time & Space Complexity

- **Time Complexity:** O(1)
  Single input read and single output operation.

- **Space Complexity:** O(1)
  Only two integer variables used.

## Sample Execution

### Sample Input 0: `10 5`

Input read:
`a = 10, b = 5`

Output generation:
printf("a = %d\nb = %d", b, a)
→ printf("a = %d\nb = %d", 5, 10)

Output:
`a = 5`\
`b = 10`


### Sample Input 1: `-5 6`

Input read:
`a = -5, b = 6`

Output generation:
printf("a = %d\nb = %d", 6, -5)

Output:\
`a = 6`\
`b = -5`


### Additional Test Case: `0 100`

Input: `0 100`
Output:
`a = 100`\
`b = 0`


## Edge Cases & Assumptions

### Edge Cases Covered:
- **Boundary values:** `-1000000 1000000`
- **Zero values:** `0 1`, `0 -1`
- **Negative values:** `-5 6`, `-100 -200`
- **Large values:** Within 10⁶ constraint ✓

### Assumptions Made:
- Input always contains exactly two integers
- Numbers are unique (a ≠ b) per constraints
- Standard input format with space separation
- No malformed input

### Not Required:
- Input validation
- Handling duplicate values
- Multiple test cases
- Temporary variable swapping

## Common Mistakes & Pitfalls

1. **Incorrect output format:**
   ```c
   ❌ printf("a=%d b=%d", b, a);  // Missing newlines
   ✅ printf("a = %d\nb = %d", b, a);
   ```

2. **Actual swapping instead of printing:**
   ```c
   ❌ int temp = a; a = b; b = temp; printf("a = %d\nb = %d", a, b);
   ✅ printf("a = %d\nb = %d", b, a);  // Direct output
   ```

3. **Wrong format specifiers:**
   ```c
   ❌ printf("a = %s\nb = %s", b, a);  // %s for strings
   ✅ printf("a = %d\nb = %d", b, a);  // %d for integers
   ```

4. **scanf issues:**
   ```c
   ❌ scanf("%d", &a, &b);  // Only reads one number
   ✅ scanf("%d %d", &a, &b);  // Reads both
   ```

5. **Missing spaces in output:**
   ```c
   ❌ printf("a=%d\nb=%d", b, a);  // No spaces around =
   ✅ printf("a = %d\nb = %d", b, a);  // Correct format
   ```

## Learning Outcome

- Efficient I/O handling without unnecessary variable manipulation
- Understanding problem requirements vs implementation details
- Format string precision for exact output matching
- Direct output techniques for simple data transformations
- Recognizing when "swapping" is purely presentational
