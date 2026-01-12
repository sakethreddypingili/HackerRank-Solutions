# Range Check

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Range Queries, Conditional Logic, Integer Comparison
- **Language Used:** C

## Problem Statement
Given three integers n, low, and high, determine if n falls within the inclusive range [low, high]. Output "In Range" if true, otherwise "Out of Range". The range includes both endpoints.

## Input Specification
- **Input Type:** Three space-separated integers
- **Input Constraints:**
  - `-10^9 ≤ n, low, high ≤ 10^9`

## Output Specification
- **Output Type:** String
- **Output Format:** Exactly "In Range" or "Out of Range" (case-sensitive)

## Constraints & Rules
- Large integer range requires `int` or `long long` (int sufficient for 32-bit systems)
- Inclusive range: low ≤ n ≤ high
- No assumptions about low ≤ high ordering
- Exact string matching required for output

## Core Concept(s) Used
### Inclusive Range Check
Boolean condition: `low ≤ n ≤ high` using chained comparisons.

### Integer Overflow Safety
Modern C compilers handle ±10^9 within `int` limits (typically ±2^31-1).

## Logic & Reasoning
The solution uses direct comparison `n >= low && n <= high`. This works regardless of whether low ≤ high because the condition checks both boundaries explicitly.

**Key insight:** Inclusive range means equality at boundaries counts as "In Range".

## Step-by-Step Algorithm

1. **Read inputs:** Three integers n, low, high
2. **Range check:** `if (n >= low && n <= high)`
3. **Output result:**
   - True → "In Range"
   - False → "Out of Range"

## Time & Space Complexity
- **Time Complexity:** O(1)
  Two comparisons only.
- **Space Complexity:** O(1)
  Three integer variables.

## Sample Execution

### Example 1
**Input:** `10 5 20`

**Processing:** `5 ≤ 10 ≤ 20` → True

**Output:** `In Range`

### Example 2
**Input:** `4 5 10`

**Processing:** `5 ≤ 4 ≤ 10` → False

**Output:** `Out of Range`

### Example 3
**Input:** `15 15 30`

**Processing:** `15 ≤ 15 ≤ 30` → True

**Output:** `In Range`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Boundary exact:** `n == low` or `n == high` → In Range
- **Outside bounds:** `n < low` or `n > high` → Out of Range
- **Equal bounds:** `low == high == n` → In Range
- **Large extremes:** `±10^9` values[1]
- **low > high:** Still correct (e.g., `10 20 5` → Out)

### Assumptions Made:
- Input integers within 32-bit signed range
- No input validation needed

## Common Mistakes & Pitfalls

1. **Exclusive range mistake**
   - ❌ `n > low && n < high`
   - ✅ `n >= low && n <= high`

2. **Assuming low ≤ high**
   - ❌ `if (low <= high && n >= low && n <= high)`
   - ✅ Direct condition works always

3. **Type overflow**
   - ❌ Using `short` or unsigned types
   - ✅ `int` sufficient

4. **scanf errors**
   - ❌ Missing `&` operators
   - ✅ `scanf("%d %d %d", &n, &low, &high)`

5. **Output mismatch**
   - ❌ Extra spaces, wrong case
   - ✅ Exact strings required

## Learning Outcome
- Inclusive vs exclusive range semantics
- Handling large integer constraints in C
- Efficient boolean condition chaining
- Precise input/output matching for competitive programming
- Direct algorithmic thinking without unnecessary functions
