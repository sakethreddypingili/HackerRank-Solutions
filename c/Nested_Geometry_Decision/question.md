# Nested Geometry Decision

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Geometry, Nested Conditionals, Logic Validation
- **Language Used:** C

## Problem Statement
The objective is to classify a 2D geometric figure based on the number of sides, side lengths, and interior angles. The program must handle circles ($n=0$), triangles ($n=3$), and quadrilaterals ($n=4$). A significant portion of the challenge lies in validating whether the provided dimensions and angles can mathematically form a valid closed figure.

## Input Specification
- **n:** Number of sides (0, 3, or 4).
- **Sides (a, b, c, d):** Three integers for $n=3$, four for $n=4$.
- **Angles (A, B, C, D):** Three integers for $n=3$, four for $n=4$.

## Output Specification
- A single string identifying the figure (e.g., `Equilateral Triangle`, `Square`, `Circle`).
- `Invalid Figure` if geometry rules are violated.

## Constraints & Rules

### Triangle Validation ($n=3$)
1. **Triangle Inequality Theorem:** The sum of any two sides must be strictly greater than the third side ($a+b > c$, $a+c > b$, $b+c > a$).
2. **Angle Sum Property:** Interior angles must sum exactly to $180^\circ$.
3. **Side-Angle Consistency:** In a valid triangle, equal sides must be opposite equal angles.



[Image of triangle types based on sides and angles]


### Quadrilateral Validation ($n=4$)
1. **Angle Sum Property:** Interior angles must sum exactly to $360^\circ$.
2. **Side/Angle Pairing:** Specific properties define distinct quadrilaterals:
   - **Square:** 4 equal sides AND 4 $90^\circ$ angles.
   - **Rectangle:** Opposite sides equal AND 4 $90^\circ$ angles.
   - **Rhombus:** 4 equal sides AND opposite angles equal.
   - **Parallelogram:** Opposite sides equal AND opposite angles equal.



## Core Concept(s) Used

### Nested Logic Gates
The solution is structured as a "Filter." We first filter by the number of sides, then filter for "Invalidity" (negative sides, wrong angle sums), and finally drill down into specific classifications.

### Side-Angle Relationship
The problem specifically mentions that for Isosceles triangles, "two sides are equal and the two angles opposite to the equal sides are congruent." This requires checking if $Side\_A = Side\_B$ matches the condition for $Angle\_A = Angle\_B$ (or whichever angles are opposite those sides).

## Logic & Reasoning
- **Circle:** If $n=0$, it is always a circle (no side/angle inputs provided).
- **Triangle:** - If all sides are equal and all angles are $60^\circ$, it's `Equilateral`.
  - If exactly two sides are equal, it's `Isosceles`.
  - If all sides/angles are different, it's `Scalene`.
- **Quadrilateral:**
  - `Square` and `Rhombus` both have 4 equal sides; they are distinguished by their angles.
  - `Rectangle` and `Parallelogram` both have opposite sides equal ($a=c, b=d$); they are distinguished by their angles.

## Step-by-Step Algorithm
1. Read $n$.
2. If $n=0$, output `Circle`.
3. If $n=3$:
   - Read 3 sides and 3 angles.
   - Check if any side/angle $\le 0$.
   - Check if angle sum is $180$.
   - Check Triangle Inequality.
   - Check side-angle consistency (e.g., if two sides are equal, their corresponding angles must be equal).
   - Classify based on equality.
4. If $n=4$:
   - Read 4 sides and 4 angles.
   - Check if any side/angle $\le 0$ or angle $\ge 180$.
   - Check if angle sum is $360$.
   - Classify based on the properties of Square, Rectangle, Rhombus, or Parallelogram.
5. Else, output `Invalid Figure`.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — A fixed number of comparisons.
- **Space Complexity:** $O(1)$ — Storing a small number of integer variables.

## Sample Execution
**Input:** `4 4 6 4 6 110 70 110 70`
- $n=4$: Quadrilateral.
- Sides: $a=4, b=6, c=4, d=6$ (Opposite sides $a=c$ and $b=d$ are equal).
- Angles: $110, 70, 110, 70$ (Sum $= 360$, Opposite angles equal).
- Result: `Parallelogram`.

## Common Mistakes & Pitfalls
1. **Angle Sum:** Forgetting that integers can sum to 180 or 360 but still be invalid (e.g., a $0^\circ$ angle).
2. **Order of Checks:** Checking for a Parallelogram before a Rectangle. Since all Rectangles are Parallelograms, the more specific check (Rectangle) must come first.
3. **Triangle Inequality:** Using $\ge$ instead of $>$. A degenerate triangle ($a+b=c$) is an `Invalid Figure`.
