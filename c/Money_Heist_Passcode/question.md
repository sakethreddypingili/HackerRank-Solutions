# Money Heist Passcode Correction

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Array/Variable Manipulation, Modular Arithmetic, Circular Buffer Logic
- **Language Used:** C

## Problem Statement
A vault is protected by a 10-digit passcode (0-9). Three digits in the current configuration are incorrect. You are given the indices of these incorrect digits and the rotation amount required to correct them. The dial is circular, meaning if you rotate past 9, it wraps back to 0.

## Input Specification
- **Line 1:** 10 space-separated integers (0-9) representing the current vault configuration.
- **Lines 2-4:** Three pairs of integers. Each pair consists of:
  - `index`: The 0-indexed position of the digit to change.
  - `rotation`: The number of steps to rotate the dial forward.

## Output Specification
- **Output Type:** 10 space-separated integers representing the corrected passcode.

## Constraints & Rules
- All passcode digits are $0 \le d \le 9$.
- Indices are $0 \le i \le 9$.
- **Wrap-around Rule:** $(Current + Rotation) \pmod{10}$.



## Core Concept(s) Used

### Circular Increment (Modular Arithmetic)
To handle the "wrap-around" effect where the number 9 goes back to 0, we use the modulo operator. 
The formula for the new digit is:
$$NewDigit = (OldDigit + Rotation) \pmod{10}$$



## Logic & Reasoning
1. **Input Management:** Since the problem asks for 10 distinct digits and then specific index-based updates, we can use either 10 individual variables or an array. An array is significantly more efficient for index-based access.
2. **Sequential Updates:** We receive three correction commands. Each command must be applied to the current state of the passcode.
3. **The Dial Logic:** If a digit is 7 and we rotate it by 5, the calculation is $7 + 5 = 12$. Since the dial only goes up to 9, $12 \pmod{10} = 2$.

## Step-by-Step Algorithm
1. Read 10 integers into an array `passcode[10]`.
2. For each of the three correction pairs:
   - Read `idx` and `rot`.
   - Update the digit at the index: `passcode[idx] = (passcode[idx] + rot) % 10`.
3. Print the 10 elements of the array separated by spaces.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — We always process exactly 10 digits and 3 updates.
- **Space Complexity:** $O(1)$ — We use a fixed-size array of 10 integers.

## Sample Execution

### Example 1
**Input Passcode:** `3 1 4 7 5 4 2 9 5 4`  
**Correction 1:** Index `1`, Rotation `5` $\rightarrow$ Digit at index 1 is `1`. $(1 + 5) \pmod{10} = 6$.  
**Correction 2:** Index `7`, Rotation `4` $\rightarrow$ Digit at index 7 is `9`. $(9 + 4) = 13 \rightarrow 13 \pmod{10} = 3$.  
**Correction 3:** Index `3`, Rotation `5` $\rightarrow$ Digit at index 3 is `7`. $(7 + 5) = 12 \rightarrow 12 \pmod{10} = 2$.  
**Final Output:** `3 6 4 2 5 4 2 3 5 4`

## Edge Cases & Assumptions
- **Rotation causing multiple wraps:** If rotation is 15, $d + 15$ still works correctly with $\pmod{10}$.
- **Zero Rotation:** The digit remains unchanged.

## Common Mistakes & Pitfalls
- **Hardcoding Variables:** Using 10 separate variables (like `num1`, `num2`...) makes the code extremely long and prone to copy-paste errors, as seen in the initial user code.
- **Incorrect Wrap Logic:** Using `if (val > 9) val -= 10` only works if the rotation is small. If rotation is 20, the `if` fails. Modulo `% 10` is the robust solution.
- **Indexing Errors:** Forgetting that arrays are 0-indexed.

## Learning Outcome
- Improved efficiency using **Arrays** for index-based data.
- Understanding **Modular Arithmetic** for circular systems.
- Reducing code redundancy by avoiding long `if-else` chains.
