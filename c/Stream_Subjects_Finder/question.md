# Stream Subjects Finder

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Hard (Logic complexity)
- **Category / Topics:** Nested Switch-Case, Character Handling, Input Formatting
- **Language Used:** C

## Problem Statement
The goal is to build a lookup system for a university curriculum. Given a student's academic year (1–4) and branch code (C, E, or M), the program must output the corresponding subjects. A unique condition exists for the 4th year where students can opt for an internship, requiring a third input to determine the output.

## Constraints & Rules
- **Prohibition:** `if-else` statements are strictly forbidden. 
- **Requirement:** Internship status must be handled via `switch`.
- **Branches:** - `C`: CSE
  - `E`: ECE
  - `M`: Mechanical
- **Invalid Inputs:** Any year outside 1–4 or branch outside {C, E, M} must output `-1`.

## Core Concept(s) Used

### Nested Switch Statements
To maintain clean logic without `if-else`, we use nested `switch` blocks. The outer switch evaluates the **Year**, while the inner switches evaluate the **Branch** and **Internship Status**.



### Input Sequencing
Input reading must be dynamic. The `INTERNSHIP_STATUS` input is only provided by the system if the `YEAR` is 4. Reading it prematurely for other years could lead to runtime errors or incorrect values.

## Logic & Reasoning
1. **Year 1:** Generally has common subjects across all branches in many universities. The problem reflects this by providing a single set of subjects regardless of branch code.
2. **Year 2 & 3:** These require a branch check to print specialized subjects.
3. **Year 4:** This is the most complex path. 
   - First, read the `internship` integer.
   - Switch on `internship`:
     - If `1`: Print the internship message.
     - If `0`: Perform another nested switch on `branch` to print regular subjects.
4. **Error Handling:** Every switch includes a `default` case to catch invalid branch characters or years and print `-1`.

## Step-by-Step Algorithm
1. Read `year` and `branch`.
2. **Outer Switch (year):**
   - **Case 1:** Print Physics, Chemistry, Maths.
   - **Case 2 & 3:** - Nested Switch (branch).
     - Print specific subjects for 'C', 'E', or 'M'.
   - **Case 4:**
     - Read `internship`.
     - Nested Switch (internship).
     - Case 1: Print Internship message.
     - Case 0: Double-Nested Switch (branch) for regular subjects.
3. **Default Cases:** Ensure all invalid paths lead to `printf("-1")`.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — Hash-like jump table performance of switch statements.
- **Space Complexity:** $O(1)$ — Uses minimal fixed variables.

## Sample Execution

### Example: Year 4 Mechanical with Internship
**Input:** `4 M 1`
**Processing:**
- Outer Switch hits `case 4`.
- `scanf` reads `1`.
- Internship Switch hits `case 1`.
**Output:** `Enrolled into Internship Program`

## Common Mistakes & Pitfalls
- **Missing Break:** Forgetting `break` in a switch case causes "fall-through," where the code executes the next case's logic accidentally.
- **Character Matching:** Using "C" (string) instead of 'C' (character constant).
- **Input Order:** Trying to read the internship status at the very start of the program for all years.
