# Angle Classification

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Geometry, Modular Arithmetic, Conditional Logic
- **Language Used:** C

## Problem Statement
The task is to classify an angle $x$ (in degrees) formed by rotating the hour hand of a clock, while the minute hand remains fixed at 12:00. Because the rotation can exceed 360 degrees, the angle must be normalized. The classification follows standard geometric definitions with a specific rule for zero rotation.

## Input Specification
- **Input Type:** A single integer $x$.
- **Input Constraints:**
  - $0 \le x \le 10^6$

## Output Specification
- **Output Type:** String
- **Output Format:**
  - `Acute Angle`, `Right Angle`, `Obtuse Angle`, `Straight Angle`, `Reflex Angle`, or `Full Rotation`.

## Constraints & Rules
The classification logic depends on the normalized value of the angle within a $360^\circ$ circle:

| Angle ($x$) | Classification |
| :--- | :--- |
| $x = 0$ or $(x \pmod{360} < 90 \text{ and } x \pmod{360} \neq 0)$ | Acute Angle |
| $x \pmod{360} = 90$ | Right Angle |
| $90 < x \pmod{360} < 180$ | Obtuse Angle |
| $x \pmod{360} = 180$ | Straight Angle |
| $180 < x \pmod{360} < 360$ | Reflex Angle |
| $x > 0$ and $x \pmod{360} = 0$ | Full Rotation |



[Image of types of angles: acute, right, obtuse, straight, reflex, and full rotation]


## Core Concept(s) Used

### Circular Normalization (Modulo Operator)
Since the hour hand can rotate multiple times ($x > 360$), we use the modulo operator (`% 360`) to find the effective position of the hand. For example, $400^\circ$ is effectively $400 \pmod{360} = 40^\circ$.

### Special Cases (0 and 360)
- **Zero Rotation ($0^\circ$):** Explicitly defined as an `Acute Angle`.
- **Full Rotation ($360^\circ$):** Even though $360 \pmod{360} = 0$, the problem distinguishes a full circle as `Full Rotation`.

## Logic & Reasoning
1. **Handle Multi-rotations:** Compute the effective angle using `x % 360`. 
2. **Handle the "Full Rotation" Exception:** If the original input is greater than 0 but the effective angle is 0, it means the hand landed exactly on 12:00 after one or more full circles. This must be printed as `Full Rotation`.
3. **Handle $0^\circ$:** If the input is exactly 0, print `Acute Angle`.
4. **Standard Classification:** For all other values, use an `if-else` ladder to check the range of the effective angle.

## Step-by-Step Algorithm
1. Read the input `x`.
2. If `x == 0`, print `Acute Angle`.
3. Calculate `effective_angle = x % 360`.
4. If `x > 0` AND `effective_angle == 0`, print `Full Rotation`.
5. Else if `effective_angle < 90`, print `Acute Angle`.
6. Else if `effective_angle == 90`, print `Right Angle`.
7. Else if `effective_angle < 180`, print `Obtuse Angle`.
8. Else if `effective_angle == 180`, print `Straight Angle`.
9. Else, print `Reflex Angle`.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — Performs one modulo operation and a few comparisons.
- **Space Complexity:** $O(1)$ — No additional data structures are required.

## Sample Execution

### Example 1
**Input:** `400`
**Processing:**
- $400 \pmod{360} = 40$
- $40 < 90$
**Output:** `Acute Angle`

### Example 2
**Input:** `360`
**Processing:**
- $360 > 0$ and $360 \pmod{360} = 0$
**Output:** `Full Rotation`

## Edge Cases & Assumptions
- **Constraint $x=0$:** Specifically handled to return `Acute Angle`.
- **Very large $x$:** $10^6 \pmod{360}$ is handled correctly by the `int` type.
- **Clock Mechanics:** Minute hand is stationary, simplifying the problem to a single-vector rotation.

## Common Mistakes & Pitfalls
- **Confusing 0 with 360:** Using only `x % 360` will treat $360^\circ$ and $0^\circ$ as the same. They must be separated to distinguish between `Full Rotation` and `Acute Angle`.
- **Incorrect Range Boundaries:** Using `<=` instead of `<` for Acute or Obtuse angles, which would misclassify Right or Straight angles.

## Learning Outcome
- Mastery of modular arithmetic for circular/periodic data.
- Handling special edge cases that deviate from the standard mathematical pattern.
- Understanding the importance of logical order in range-based conditions.
