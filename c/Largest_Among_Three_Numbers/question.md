# If-Else: Largest Among Three Numbers

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Statements, Control Flow, Comparison Logic
- **Language Used:** C

## Problem Statement
Write a program that reads three integers and determines which one is the largest among them. The program must use conditional logic to compare the three numbers and output the largest value with a specific message format [attached_file:1].

## Input Specification
- **Input Type:** Three space-separated integers
- **Input Constraints:**
  - Each integer a, b, c satisfies: −10³ ≤ a, b, c ≤ 10³

## Output Specification
- **Output Type:** String with integer
- **Output Format:**
  - Print: `The largest number is : <value>`
  - Where `<value>` is the largest integer among the three inputs

## Constraints & Rules
- All three integers must be within the range [−1000, 1000] [attached_file:1]
- Input consists of exactly three integers separated by spaces
- The program must handle cases where numbers may be equal
- Output must follow the exact format including spacing and punctuation

## Core Concept(s) Used

### Conditional Statements (If-Else)
Conditional statements allow programs to execute different code blocks based on whether conditions evaluate to true or false. The if-else construct provides branching logic for decision-making [web:5][web:9].

### Comparison Operators
Comparison operators (>, <, >=, <=, ==, !=) evaluate relationships between values and return boolean results. For finding the maximum, the greater-than operator (>) is used to establish ordering between numbers [web:9][web:14].

### Logical Operators
Logical AND (&&) combines multiple conditions, requiring all conditions to be true for the overall expression to evaluate as true. This enables simultaneous comparison of one number against multiple others [web:12].

### Array-Based Approach
An alternative approach uses arrays to store the numbers, then iterates through the array to find the maximum value using a simple loop with comparison logic [attached_file:1].

## Logic & Reasoning

The solution uses an array-based iteration approach instead of nested if-else statements for several advantages:

**Why the array iteration method works:**
1. All three numbers are stored in a single array structure, enabling uniform processing
2. A loop iterates through array elements, maintaining a running maximum
3. Each element is compared against the current maximum; if greater, it becomes the new maximum
4. After all comparisons, the maximum value is guaranteed to be found

**Comparison with traditional if-else:**
- Traditional nested if-else requires multiple comparison branches (e.g., checking if a>b AND a>c, then b>a AND b>c, etc.) [web:5][web:9]
- Array iteration is more scalable - the same logic works for finding maximum among any count of numbers
- The loop approach is cleaner and requires fewer lines of code

**Why this handles equal numbers correctly:**
- Using `>` (strictly greater) ensures that when numbers are equal, the first occurrence in array order is retained
- The algorithm doesn't fail when two or all three numbers are identical

## Step-by-Step Algorithm

1. **Declare Variables:**
   - Create an integer array of size 3 to store the three input numbers
   - Create an integer variable `largest` to track the maximum value
   - Create loop counter variable `i`

2. **Read Input:**
   - Use `scanf` to read three space-separated integers a, b, and c
   - Store them in the array: arr[0] = a, arr[1] = b, arr[2] = c

3. **Initialize Maximum:**
   - Set `largest = arr[0]` (assume first element is initially the maximum)

4. **Iterate and Compare:**
   - Loop from index i = 1 to i < 3
   - For each element arr[i]:
     - If arr[i] > largest, update largest = arr[i]

5. **Output Result:**
   - Print the result using the format: "The largest number is : <largest>"

6. **Return:**
   - Exit program successfully with return 0

## Time & Space Complexity

- **Time Complexity:** O(n) where n = 3, effectively O(1)  
  The algorithm performs a constant number of iterations (2 comparisons in the loop). Since the input size is fixed at 3, this simplifies to constant time.

- **Space Complexity:** O(1)  
  The program uses a fixed-size array of 3 elements and a constant number of variables, independent of input size.

## Sample Execution

### Example 1
**Input:** `5 10 15`

**Processing:**
```
arr = {5, 10, 15}[1]
largest = arr = 5

Iteration 1 (i=1):
  arr = 10 > 5 → largest = 10[2]

Iteration 2 (i=2):
  arr = 15 > 10 → largest = 15[3]

Final largest = 15
```

**Output:** `The largest number is : 15`

---

### Example 2
**Input:** `88 76 76`

**Processing:**
```
arr = {88, 76, 76}[1]
largest = arr = 88

Iteration 1 (i=1):
  arr = 76 > 88 → False (no update)[2]

Iteration 2 (i=2):
  arr = 76 > 88 → False (no update)[3]

Final largest = 88
```

**Output:** `The largest number is : 88`

---

### Example 3
**Input:** `-50 -30 -40`

**Processing:**
```
arr = {-50, -30, -40}[1]
largest = arr = -50

Iteration 1 (i=1):
  arr = -30 > -50 → True → largest = -30[2]

Iteration 2 (i=2):
  arr = -40 > -30 → False (no update)[3]

Final largest = -30
```

**Output:** `The largest number is : -30`

---

### Example 4
**Input:** `100 100 100`

**Processing:**
```
arr = {100, 100, 100}[1]
largest = arr = 100

Iteration 1 (i=1):
  arr = 100 > 100 → False (no update)[2]

Iteration 2 (i=2):
  arr = 100 > 100 → False (no update)[3]

Final largest = 100
```

**Output:** `The largest number is : 100`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **All three numbers equal:** Returns the common value (e.g., 100 100 100 → 100) [attached_file:1]
- **Two numbers equal (largest):** Returns the equal value (e.g., 88 76 76 → 88)
- **Two numbers equal (smallest):** Returns the distinct larger value (e.g., 5 15 15 → 15)
- **Negative numbers:** Correctly handles negative integers using comparison logic (e.g., -50 -30 -40 → -30)
- **Mixed positive and negative:** Works with combinations (e.g., -10 5 0 → 5)
- **Boundary values:** Handles extremes like -1000 and 1000
- **Zero included:** Treats zero as a valid number (e.g., 0 -5 3 → 3)

### Assumptions Made:
- Input always consists of exactly three integers
- Input format is always space-separated integers on a single line
- No input validation is required (inputs are guaranteed to be within constraints)
- Output format must exactly match the specified string template

### Not Required:
- Error handling for non-integer input
- Validation for out-of-range values
- Handling more or fewer than three numbers
- Sorting the numbers

## Common Mistakes & Pitfalls

1. **Incorrect output format**
   - ❌ `printf("The largest number is: %d", value);` (missing space before colon)
   - ✅ `printf("The largest number is : %d", value);` (space before colon required)

2. **Using >= instead of > in loop**
   - ❌ `if(arr[i] >= largest)` → May give incorrect result for equal values depending on logic
   - ✅ `if(arr[i] > largest)` → Correctly maintains first maximum occurrence

3. **Not initializing largest correctly**
   - ❌ `int largest = 0;` → Fails when all numbers are negative
   - ✅ `int largest = arr[0];` → Always starts with a valid value from input

4. **Wrong loop boundaries**
   - ❌ `for(int i = 0; i < 3; i++)` → Compares arr[0] with itself unnecessarily
   - ✅ `for(int i = 1; i < 3; i++)` → Starts comparison from second element

5. **Overthinking with nested if-else**
   - ❌ Using complex nested if-else chains when array iteration is simpler [web:5]
   - ✅ Loop-based approach is cleaner and more maintainable

6. **Forgetting to return value from function**
   - ❌ Function without return statement when value is needed in main
   - ✅ Ensure function returns the computed largest value [attached_file:1]

## Learning Outcome

- Understanding how to use conditional logic and comparison operators to determine maximum values
- Learning array-based iteration as an alternative to nested if-else structures for finding extrema
- Recognizing that loop-based solutions scale better than hardcoded conditional branches
- Mastering proper variable initialization and loop boundary selection for comparison algorithms
- Understanding how to handle edge cases like equal values and negative numbers in comparison problems
