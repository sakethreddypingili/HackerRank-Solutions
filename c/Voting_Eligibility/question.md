# VotingEligibility

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Conditional Logic, Basic Input/Output, Decision Making
- **Language Used:** C

## Problem Statement
Given a single integer representing a person's age, determine whether they are eligible to vote. A person can vote if their age is 18 years or older. Output "Eligible" if they can vote, otherwise output "Not Eligible".

## Input Specification
- **Input Type:** Single integer
- **Input Constraints:**
  - `0 ≤ age ≤ 150`

## Output Specification
- **Output Type:** String
- **Output Format:** Exactly "Eligible" or "Not Eligible" (case-sensitive)

## Constraints & Rules
- Age is always a non-negative integer
- Age range is guaranteed to be between 0 and 150 inclusive
- No input validation required beyond reading the integer
- Output must match exactly without extra spaces or characters

## Core Concept(s) Used
### Conditional Statements
Basic if-else logic to make binary decisions based on a threshold comparison.

### Integer Comparison
Direct comparison of integer values against a constant threshold (18).

## Logic & Reasoning
The solution uses a single conditional check: if age is greater than or equal to 18, the person is eligible. This works because eligibility is defined by a clear numerical threshold with no additional conditions.

**Key observation:** The problem guarantees valid integer input within constraints, so no error handling or boundary validation is needed beyond the comparison itself.

## Step-by-Step Algorithm

1. **Read input:** Capture single integer age using standard input
2. **Compare age:** Check if `age ≥ 18`
3. **Decision branch:**
   - If true → Output "Eligible"
   - If false → Output "Not Eligible"
4. **Terminate:** Return 0 to indicate successful execution

## Time & Space Complexity
- **Time Complexity:** O(1)
  Single comparison and output operation.
- **Space Complexity:** O(1)
  Only one integer variable used.

## Sample Execution

### Example 1
**Input:** `20`

**Processing:** `20 ≥ 18` → True

**Output:** `Eligible`

### Example 2
**Input:** `17`

**Processing:** `17 ≥ 18` → False

**Output:** `Not Eligible`

### Example 3
**Input:** `18`

**Processing:** `18 ≥ 18` → True

**Output:** `Eligible`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Minimum voting age:** `18` → Eligible
- **Just below threshold:** `17` → Not Eligible
- **Minimum constraint:** `0` → Not Eligible
- **Maximum constraint:** `150` → Eligible

### Assumptions Made:
- Input is always a valid integer within specified constraints
- No floating-point or negative ages per constraints
- Standard input contains exactly one integer per test case

## Common Mistakes & Pitfalls

1. **Wrong comparison operator**
   - ❌ `age > 18` (misses exactly 18)
   - ✅ `age >= 18`

2. **Output formatting errors**
   - ❌ Extra spaces or wrong capitalization
   - ✅ Exact match: "Eligible" or "Not Eligible"

3. **Unnecessary complexity**
   - ❌ Using functions, arrays, or loops
   - ✅ Single if-else is sufficient

4. **scanf issues**
   - ❌ Forgetting `&` operator in `scanf("%d", &age)`
   - ✅ Always pass address of variable

## Learning Outcome
- Implementing simple conditional logic for real-world decision making
- Proper input/output handling with scanf/printf in C
- Understanding edge cases in threshold-based problems
- Writing clean, minimal solutions for basic programming challenges
