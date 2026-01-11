# Convert Time into Seconds

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Time Conversion, Integer Arithmetic, Function Modularity, Input/Output
- **Language Used:** C

## Problem Statement
Given three integers representing hours, minutes, and seconds, convert the entire time duration into total seconds. The program must read three space-separated integers, calculate the total seconds using proper time conversion formulas, and output the result in a specified format. The solution must use a separate function for the conversion logic rather than implementing everything in the main function.

## Input Specification
- **Input Type:** Three space-separated integers (hours, minutes, seconds)
- **Input Constraints:** 
  - 0 ≤ hours ≤ 100
  - 0 ≤ minutes < 60
  - 0 ≤ seconds < 60

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `Total seconds: {result}`

## Constraints & Rules
- Hours can range from 0 to 100
- Minutes must be between 0 and 59 (inclusive)
- Seconds must be between 0 and 59 (inclusive)
- Must create a function `int toSeconds(int hours, int minutes, int seconds)`
- Function must be called from main (entire logic cannot be in main)
- Input values are space-separated on a single line
- Output must not include a period at the end

## Core Concept(s) Used

### Time Unit Conversion
Time conversion follows standard relationships between units:
- **1 hour = 3,600 seconds** (60 minutes × 60 seconds)
- **1 minute = 60 seconds**
- **Total seconds = (hours × 3,600) + (minutes × 60) + seconds**

This formula converts any time duration in HH:MM:SS format into a single integer representing total seconds.

### Function Modularity and Separation of Concerns
The problem explicitly requires implementing the conversion logic in a separate function, demonstrating:
- **Code Reusability:** The conversion function can be called multiple times with different inputs
- **Testability:** Business logic is isolated from I/O operations
- **Maintainability:** Changes to conversion logic don't affect input/output handling

### Input Validation
While the problem states valid constraints, the provided solution template includes boundary checking to clamp values within acceptable ranges, ensuring robustness even with edge case inputs.

## Logic & Reasoning

The solution follows a straightforward approach:

1. **Read three integers** representing hours, minutes, and seconds
2. **Call the conversion function** with these values
3. **Calculate total seconds** using the standard time conversion formula
4. **Return and display** the result

**Why use the formula (hours × 3,600) + (minutes × 60) + seconds?**
- Hours are converted to seconds by multiplying by 3,600 (since 1 hour = 60 minutes and 1 minute = 60 seconds)
- Minutes are converted to seconds by multiplying by 60
- Existing seconds are added directly
- This gives the total time duration in seconds

**Why include validation logic?**
- The template code includes clamping logic to ensure hours stay below 100 and minutes/seconds stay below 60
- This prevents invalid time values from producing incorrect results
- Although the problem guarantees valid input, defensive programming is a good practice

## Step-by-Step Algorithm

1. **Define conversion function:**
   - Accept three integer parameters: hours, minutes, seconds
   - Validate/clamp inputs to ensure they fall within constraints (optional but recommended)
   - Calculate: `total = hours * 3600 + minutes * 60 + seconds`
   - Return the total seconds as an integer

2. **Read input in main:**
   - Declare three integer variables
   - Use scanf to read all three values from a single line

3. **Calculate total seconds:**
   - Call `toSeconds()` function with the three input values
   - Store the returned result

4. **Output result:**
   - Print formatted string: "Total seconds: " followed by the result
   - Do not include a period at the end

## Time & Space Complexity

- **Time Complexity:** O(1) - Constant time arithmetic operations (two multiplications and two additions)
- **Space Complexity:** O(1) - Only four integer variables used (hours, minutes, seconds, result)

## Sample Execution

### Example 1
**Input:** `1 0 0`

**Processing:**
- hours = 1, minutes = 0, seconds = 0
- total = 1 × 3600 + 0 × 60 + 0 = 3600

**Output:** `Total seconds: 3600`

### Example 2
**Input:** `0 10 30`

**Processing:**
- hours = 0, minutes = 10, seconds = 30
- total = 0 × 3600 + 10 × 60 + 30 = 0 + 600 + 30 = 630

**Output:** `Total seconds: 630`

### Example 3
**Input:** `2 15 45`

**Processing:**
- hours = 2, minutes = 15, seconds = 45
- total = 2 × 3600 + 15 × 60 + 45 = 7200 + 900 + 45 = 8145

**Output:** `Total seconds: 8145`

## Edge Cases & Assumptions

### Assumptions Made:
- Input is always three valid integers
- Numbers are space-separated on the same line
- No floating-point time values (e.g., 1.5 hours)
- Time values represent duration, not clock time (no AM/PM)

### Edge Cases Covered:
- **Zero time:** `0 0 0` → 0 seconds
- **Maximum hours:** `100 0 0` → 360,000 seconds
- **Maximum minutes:** `0 59 0` → 3,540 seconds
- **Maximum seconds:** `0 0 59` → 59 seconds
- **Maximum total:** `100 59 59` → 363,599 seconds
- **Only hours:** `5 0 0` → 18,000 seconds
- **Only minutes:** `0 45 0` → 2,700 seconds
- **Only seconds:** `0 0 30` → 30 seconds

### Not Required (per constraints):
- Handling negative time values
- Handling values exceeding the stated constraints
- Fractional seconds or minutes

## Common Mistakes & Pitfalls

1. **Incorrect conversion formula**
   - ❌ `hours * 60 + minutes * 60 + seconds` (wrong multiplier for hours)
   - ✅ `hours * 3600 + minutes * 60 + seconds`

2. **Putting all logic in main()**
   - ❌ Calculating total seconds directly in main without a function
   - ✅ Creating `toSeconds()` function and calling it from main

3. **Wrong output format**
   - ❌ `printf("Total seconds: %d.", result);` (includes period)
   - ✅ `printf("Total seconds: %d", result);` (no period)

4. **Incorrect scanf usage**
   - ❌ `scanf("%d", &hours, &minutes, &seconds);` (wrong format)
   - ✅ `scanf("%d %d %d", &hours, &minutes, &seconds);`

5. **Overflow concerns for large values**
   - With max input `100 59 59`, result is 363,599 seconds
   - Standard `int` (32-bit) supports up to ~2.1 billion, so no overflow risk

6. **Forgetting validation logic**
   - While the problem guarantees valid input, adding clamping logic makes the solution robust
   - The template includes boundary checks to prevent invalid time values

## Learning Outcome

- Understanding standard time unit conversion formulas and their application in programming
- Implementing modular functions to separate business logic from I/O operations
- Using arithmetic operations to perform unit conversions efficiently
- Applying input validation and boundary checking for robust code
