# Characters Distance

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** ASCII Operations, Character Arithmetic, Basic Input/Output
- **Language Used:** C

## Problem Statement
Given two lowercase alphabetic characters as input, compute the alphabetical distance between them and display the result in a specified format. The first character is guaranteed to appear before the second character in alphabetical order.

The distance is defined as the number of positions separating the two characters in the English alphabet. The solution must rely on ASCII arithmetic to determine this distance.

## Input Specification
- **Input Type:** Two space-separated lowercase characters
- **Input Constraints:**
  - Characters range from `a` to `z`
  - The first character always appears before the second alphabetically
  - Inputs are guaranteed to be valid lowercase letters

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `The distance between {char1} and {char2} is {value}`

## Constraints & Rules
- Input characters are strictly lowercase alphabetic characters
- Alphabetical order of input characters is guaranteed
- ASCII arithmetic must be used for calculation
- No input validation or error handling is required
- No string manipulation functions are needed

## Core Concept(s) Used

### ASCII Arithmetic
In the C programming language, characters are internally represented using ASCII values. Lowercase English letters have consecutive ASCII values ranging from 97 (`'a'`) to 122 (`'z'`). Because of this sequential encoding, subtracting the ASCII value of one character from another directly yields the alphabetical distance.

### Character to Integer Conversion
When characters are used in arithmetic expressions in C, they are automatically converted to their corresponding integer (ASCII) values. This implicit conversion allows direct subtraction of characters without explicit casting.

## Logic & Reasoning

The solution follows a simple and efficient approach:
1. Two characters are read from input
2. Their ASCII values are implicitly used during subtraction
3. The difference between the second and first character gives the distance

**Why this works:**
- ASCII values for lowercase letters are consecutive
- The problem guarantees `char1 < char2`, so the result is always non-negative
- No additional checks or absolute value operations are required

**Why ASCII arithmetic is sufficient:**
- Alphabet positions directly map to ASCII order
- Subtraction accurately reflects the number of positions between characters

## Step-by-Step Algorithm

1. **Read input:**
   - Declare two `char` variables
   - Use `scanf` to read both characters from a single line

2. **Calculate distance:**
   - Subtract the first character from the second using ASCII arithmetic
   - Store the result in an integer variable

3. **Output:**
   - Print the formatted string containing both characters and the distance value

## Time & Space Complexity

- **Time Complexity:** O(1)  
  Only a single subtraction operation is performed.

- **Space Complexity:** O(1)  
  Only two characters and one integer variable are used.

## Sample Execution

### Example 1
**Input:** `a c`

**Processing:**
- ASCII('a') = 97
- ASCII('c') = 99
- Distance = 99 − 97 = 2

**Output:** `The distance between a and c is 2`

### Example 2
**Input:** `b f`

**Processing:**
- ASCII('b') = 98
- ASCII('f') = 102
- Distance = 102 − 98 = 4

**Output:** `The distance between b and f is 4`

### Example 3
**Input:** `m n`

**Processing:**
- ASCII('m') = 109
- ASCII('n') = 110
- Distance = 110 − 109 = 1

**Output:** `The distance between m and n is 1`

## Edge Cases & Assumptions

### Assumptions Made:
- Input always contains two valid lowercase characters
- Characters are always provided in correct alphabetical order
- No malformed input will be given

### Edge Cases Covered:
- **Consecutive letters:** `m n` → distance = 1
- **Maximum distance:** `a z` → distance = 25
- **Minimum distance:** Adjacent characters
- **Same character:** Not applicable per problem constraints

### Not Required (per constraints):
- Absolute value handling
- Input validation
- Uppercase or non-alphabetic characters

## Common Mistakes & Pitfalls

1. **Using absolute value unnecessarily**
   - ❌ Applying `abs(char2 - char1)`
   - ✅ Direct subtraction is sufficient due to guaranteed order

2. **Wrong return type**
   - ❌ Returning `char` instead of `int`
   - ✅ Distance should be stored and returned as `int`

3. **Incorrect format specifier**
   - ❌ Using `%c` for distance value
   - ✅ Use `%d` for integer output

4. **Overcomplicating the solution**
   - ❌ Using loops or arrays
   - ✅ Simple character subtraction is enough

## Learning Outcome

- Understanding ASCII representation of characters in C
- Performing arithmetic operations directly on character data types
- Using implicit type conversion between `char` and `int`
- Implementing efficient constant-time solutions
- Producing formatted output using `printf`
