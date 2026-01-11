# Area of a Rectangle

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Functions, Modular Programming, Basic Arithmetic, I/O Operations
- **Language Used:** C

## Problem Statement
Calculate the area of a rectangle given its length and width. The solution must implement a separate function to perform the calculation rather than computing the area directly in the main function. This problem emphasizes modular programming principles and proper function design in C.

## Input Specification
- **Input Type:** Two space-separated integers
- **Input Constraints:** 
  - 1 ≤ length ≤ 10⁶
  - 1 ≤ width ≤ 10⁶

## Output Specification
- **Output Type:** Formatted string
- **Output Format:** `The area is: {result} units`

## Constraints & Rules
- Must NOT write the entire logic in main()
- Must create a separate function `int area(int length, int width)`
- Function must be called from main()
- Function should return the computed area
- Both dimensions are guaranteed to be positive integers

## Core Concept(s) Used

### Rectangle Area Formula
The area of a rectangle is calculated by multiplying its length by its width. Mathematically expressed as:

**Area = Length × Width**

This fundamental geometric formula determines the amount of space occupied within the rectangle's boundary.

### Modular Programming with Functions
Modular programming divides a program into separate functions, each responsible for a specific task. Benefits include:

- **Code Reusability:** Functions can be called multiple times without rewriting code
- **Maintainability:** Isolated logic makes debugging and updates easier
- **Readability:** Clear function names document the program's intent
- **Collaboration:** Multiple programmers can work on different functions simultaneously

### Function Components in C
A C function consists of:

1. **Declaration/Prototype:** Informs the compiler about function existence, return type, and parameters
2. **Definition:** Contains the actual implementation (function body)
3. **Function Call:** Invokes the function from another part of the program

## Logic & Reasoning
The solution separates concerns by delegating the calculation to a dedicated function. The main function handles input/output operations, while the area function performs the mathematical computation. This approach:

- Adheres to the single responsibility principle
- Makes the code testable and maintainable
- Follows the problem's explicit requirement for modular design

The area calculation uses integer multiplication, which is safe within the given constraints (maximum result: 10⁶ × 10⁶ = 10¹², well within int range on most systems).

## Step-by-Step Algorithm
1. **Declare function prototype (optional but recommended):**
   - Specify return type as int
   - Define parameters: length and width (both int)

2. **Define the area calculation function:**
   - Accept two integer parameters
   - Multiply length by width
   - Return the result

3. **In main function:**
   - Declare variables for length and width
   - Read input values using scanf
   - Call the area function with input values
   - Store the returned result
   - Print formatted output with the calculated area

4. **Return success status from main**

## Time & Space Complexity
- **Time Complexity:** O(1) - Single multiplication operation with constant-time I/O
- **Space Complexity:** O(1) - Fixed number of integer variables regardless of input size

## Sample Execution
### Example 1
**Input:** `5 4`

**Processing:**
- Length = 5, Width = 4
- Function call: `area(5, 4)`
- Calculation: 5 × 4 = 20
- Return value: 20

**Output:** `The area is: 20 units`

### Example 2
**Input:** `10 4`

**Processing:**
- Length = 10, Width = 4
- Function call: `area(10, 4)`
- Calculation: 10 × 4 = 40
- Return value: 40

**Output:** `The area is: 40 units`

## Edge Cases & Assumptions

### Assumptions Made:
- Input values are always positive integers within specified range
- No input validation required per problem constraints
- Standard C integer type can handle maximum result (10¹²)
- Input format is always two space-separated integers

### Edge Cases Within Constraints:
- Minimum dimensions: area(1, 1) = 1
- Maximum dimensions: area(1000000, 1000000) = 1000000000000
- Square: area(5, 5) = 25
- Rectangular: area(100, 1) = 100

### Not Applicable:
- Zero or negative dimensions (outside constraints)
- Floating-point dimensions
- Invalid input format

## Common Mistakes & Pitfalls

1. **Writing logic in main() instead of separate function**
   - ❌ `int area = length * width;` directly in main()
   - ✅ Creating `int area(int length, int width)` function

2. **Incorrect function signature**
   - ❌ `void area(int length, int width)` (no return value)
   - ✅ `int area(int length, int width)` (returns integer result)

3. **Not returning the calculated value**
   - ❌ Function calculates but doesn't return result
   - ✅ `return length * width;`

4. **Wrong output format**
   - ❌ `printf("Area = %d\n", result);`
   - ✅ `printf("The area is: %d units", result);`

5. **Forgetting to call the function**
   - ❌ Defining function but not calling it from main()
   - ✅ `int result = area(length, width);`

6. **Incorrect scanf usage**
   - ❌ `scanf("%d%d", length, width);` (missing & operator)
   - ✅ `scanf("%d %d", &length, &width);`

## Learning Outcome

- Understanding modular programming principles and function-based code organization in C
- Implementing user-defined functions with proper return types and parameters
- Separating computation logic from input/output operations for better code structure
- Applying basic geometric formulas programmatically
