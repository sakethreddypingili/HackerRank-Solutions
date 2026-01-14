# Bitwise Swap Two Numbers

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Bitwise XOR, Variable Swapping, Bit Manipulation
- **Language Used:** C

## Problem Statement
Write a program to swap two integers A and B using only the bitwise XOR operator without using a temporary variable. The program reads two integers from separate lines and outputs the swapped values on separate lines.

## Input Specification
- **Input Type:** Two integers on separate lines
- **Input Constraints:**
  - -10⁵ ≤ A ≤ 10⁵
  - -10⁵ ≤ B ≤ 10⁵

## Output Specification
- **Output Type:** Two integers on separate lines
- **Output Format:**\
  `<swapped_value_of_A>`\
  `<swapped_value_of_B>`

## Constraints & Rules
- Must use only XOR operator (`^`) for swapping
- No temporary variable allowed
- Input provided on two separate lines
- Works with both positive and negative integers

## Core Concept(s) Used

### XOR Properties for Swapping
The XOR swap algorithm leverages three fundamental XOR properties:
1. **X ⊕ Y ⊕ Y = X** (XOR with same value twice returns original)
2. **X ⊕ Y ⊕ X = Y** (XOR with same value twice returns other value)
3. **X ⊕ X = 0** (XOR with itself yields zero)

### Three-Step XOR Algorithm
```c
Step 1: A = A ^ B  // A now contains combined bits
Step 2: B = A ^ B  // B gets original A (combined ^ original B = A)
Step 3: A = A ^ B  // A gets original B (combined ^ new B = original B)
```

## Logic & Reasoning

**Step-by-step transformation:**


Initial:\
`A=5 (0101), B=10 (1010)`

Step 1:\
`A = A ^ B = 0101 ^ 1010 = 1111 (15)`\
`B remains 1010 (10)`

Step 2:\
`B = A ^ B = 1111 ^ 1010 = 0101 (5)`\
`A remains 1111 (15)`

Step 3:\
`A = A ^ B = 1111 ^ 0101 = 1010 (10)`\
`B remains 0101 (5)`

Result:\
`A=10, B=5` ✓ Swapped!


**Why it works mathematically:**

After Step 1:\
`A = (A ^ B), B = B`\
After Step 2:\
`B = ((A ^ B) ^ B) = A ^ (B ^ B) = A ^ 0 = A`\
After Step 3:\
`A = ((A ^ B) ^ A) = (A ^ A) ^ B = 0 ^ B = B`


## Step-by-Step Algorithm

1. **Read input:**
   - Read integer A from first line
   - Read integer B from second line

2. **Execute XOR swap sequence:**

   `A = A ^ B;`
   `B = A ^ B;`
   `A = A ^ B;`


3. **Output results:**
   - Print A on first line
   - Print B on second line

## Time & Space Complexity

- **Time Complexity:** O(1)
  Three XOR operations performed.

- **Space Complexity:** O(1)
  No extra space used beyond input variables.

## Sample Execution

### Sample Input 0\
`5`\
`10`


Processing:\
`A=5(0101), B=10(1010)`\
`A=0101^1010=1111(15), B=10`\
`B=1111^1010=0101(5), A=15`\
`A=1111^0101=1010(10), B=5`

Output:\
`10`\
`5`


### Sample Input:\
`-7`\
`14`


Processing (32-bit two's complement):\
`A=-7(...11111001), B=14(...00001110)`\
`A=A^B=...11110111, B=14`\
`B=A^B=...00000111(-7), A=...11110111`\
`A=A^B=...00001110(14), B=-7`

Output:\
`14`\
`-7`


## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero values:** `0 5`, `5 0`
- **Negative numbers:** `-7 14`, `-100 100`
- **Boundary values:** `-100000 100000`
- **Same magnitude opposites:** `100 -100`

### Assumptions Made:
- Input integers within specified range
- Standard two's complement representation
- XOR operator behavior as defined in C standard

### Works Correctly Because:
- XOR preserves bit patterns including sign bits
- Algorithm independent of number representation
- No overflow issues (XOR doesn't carry)

## Common Mistakes & Pitfalls

1. **Wrong scanf format:**
   ```c
   ❌ scanf("%d %d", &A, &B);  // Expects space-separated
   ✅ scanf("%d", &A); scanf("%d", &B);  // Separate lines
   ```

2. **Incorrect XOR sequence:**
   ```c
   ❌ A ^= B; B ^= A;  // Only two steps (wrong)
   ✅ A ^= B; B ^= A; A ^= B;  // Three steps required
   ```

3. **Temporary variable usage:**
   ```c
   ❌ int temp = A; A = B; B = temp;
   ✅ A ^= B; B ^= A; A ^= B;  // XOR only
   ```

4. **Output format errors:**
   ```c
   ❌ printf("%d %d", A, B);  // Single line
   ✅ printf("%d\n%d\n", A, B);  // Two separate lines
   ```

5. **Operator precedence confusion:**
   ```c
   ❌ A = A ^ B ^ B;  // Wrong grouping
   ✅ A ^= B; B ^= A; A ^= B;  // Sequential assignment
   ```

## Learning Outcome

- Mastering XOR swap algorithm without temporary storage
- Understanding XOR properties: X⊕Y⊕Y=X, X⊕X=0
- Bit-level manipulation for data transformation
- Space-optimized swapping techniques
- Handling negative numbers with bitwise operations
