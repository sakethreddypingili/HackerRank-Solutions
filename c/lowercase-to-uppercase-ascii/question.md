# Lowercase to UPPERCASE ASCII Converter

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Character Manipulation, ASCII Arithmetic, Basic I/O
- **Language Used:** C

## Problem Statement
Given a single lowercase English letter as input, convert it to its uppercase equivalent using ASCII value arithmetic and display the result in a specified format. The conversion must be performed without using built-in character manipulation functions.

## Input Specification
- **Input Type:** Single character
- **Input Constraints:** Must be a lowercase English alphabet letter ('a' to 'z')

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `The uppercase of {charLower} is {charUpper}`

## Constraints & Rules
- Input is guaranteed to be a lowercase letter (no validation required)
- Built-in functions like `toupper()` or `strupr()` are prohibited
- Conversion must use ASCII value arithmetic only
- No string processing libraries should be used

## Core Concept(s) Used

### ASCII Character Encoding
In the ASCII standard, characters are represented as numeric values. Lowercase and uppercase letters have a fixed relationship:
- Lowercase 'a' to 'z': ASCII values 97 to 122
- Uppercase 'A' to 'Z': ASCII values 65 to 90
- **Key Insight:** The difference between any lowercase letter and its uppercase equivalent is exactly 32

### Character Arithmetic in C
Characters in C are stored as integers (their ASCII values), allowing arithmetic operations to be performed directly on `char` data types. Subtracting 32 from a lowercase character's ASCII value yields its uppercase counterpart.

## Logic & Reasoning

The solution works because of the consistent 32-unit offset in ASCII:
- 'a' (97) - 32 = 'A' (65)
- 'b' (98) - 32 = 'B' (66)
- 'z' (122) - 32 = 'Z' (90)

By creating a dedicated conversion function, we achieve:
1. **Modularity:** Separation of conversion logic from I/O operations
2. **Reusability:** Function can be called multiple times if needed
3. **Clarity:** Clear intent with a single-purpose function

## Step-by-Step Algorithm

1. **Define conversion function:**
   - Accept a character parameter
   - Subtract 32 from the character
   - Return the result

2. **Read input:**
   - Declare a character variable
   - Use input function to read single character

3. **Convert:**
   - Call conversion function with input character
   - Store the uppercase result

4. **Output:**
   - Print formatted string with both original and converted characters

## Time & Space Complexity

- **Time Complexity:** O(1) - Single arithmetic operation and constant-time I/O
- **Space Complexity:** O(1) - Only two character variables used

## Sample Execution

### Example 1
**Input:** `a`

**Processing:**
- ASCII value of 'a' = 97
- 97 - 32 = 65
- ASCII value 65 = 'A'

**Output:** `The uppercase of a is A`

### Example 2
**Input:** `g`

**Processing:**
- ASCII value of 'g' = 103
- 103 - 32 = 71
- ASCII value 71 = 'G'

**Output:** `The uppercase of g is G`

## Edge Cases & Assumptions

### Assumptions Made:
- Input is always a valid lowercase letter ('a' to 'z')
- No input validation is required per problem constraints
- Single character input (not a string)

### Edge Cases Covered:
- First letter: 'a' → 'A'
- Last letter: 'z' → 'Z'
- Middle letters: All maintain the 32-offset rule

### Not Handled (per constraints):
- Uppercase input
- Non-alphabetic characters
- Multiple characters

## Common Mistakes & Pitfalls

1. **Wrong arithmetic operation**
   - ❌ Adding 32 instead of subtracting: `b + 32`
   - ✅ Correct: `b - 32`

2. **Using prohibited functions**
   - ❌ `toupper(ch)` or `strupr()`
   - ✅ Manual ASCII arithmetic

3. **Forgetting address operator in scanf**
   - ❌ `scanf("%c", a)`
   - ✅ `scanf("%c", &a)`

4. **Incorrect format specifier**
   - ❌ Using `%s` for single character
   - ✅ Using `%c` for character I/O

5. **Hardcoding conversions**
   - ❌ Using if-else or switch statements for each letter
   - ✅ Using arithmetic formula that works for all letters

## Learning Outcome

- Understanding how characters are stored as integers in memory
- Performing arithmetic operations on character data types
- Implementing modular functions for code reusability
- Recognizing implicit type conversions between char and int in C
