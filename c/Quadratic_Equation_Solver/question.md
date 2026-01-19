# Roots of a Quadratic Equation

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Math, Discriminants, Complex Numbers, Formatted Output
- **Language Used:** C

## Problem Statement
The goal is to solve a quadratic equation of the form $ax^2 + bx + c = 0$. Given coefficients $a, b,$ and $c$, the program calculates the roots and determines if they are real and distinct, real and equal, or complex.

## Mathematical Theory

The roots are calculated using the **Quadratic Formula**:
$$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$



The expression inside the square root is the **Discriminant ($D$)**:
$$D = b^2 - 4ac$$

### Root Classification
- **$D > 0$:** Two real and distinct roots.
- **$D = 0$:** One real root (repeated), calculated as $\frac{-b}{2a}$.
- **$D < 0$:** Two complex roots. The roots take the form $\alpha \pm \beta i$, where:
  - Real part ($\alpha$) = $\frac{-b}{2a}$
  - Imaginary part ($\beta$) = $\frac{\sqrt{|D|}}{2a}$



## Core Concept(s) Used

### Discriminant Logic
The discriminant determines the "nature" of the roots before any actual square root operation is performed. This is essential because calculating `sqrt()` on a negative number in C will result in a `NaN` (Not a Number) error unless handled.

### Complex Number Representation
Since standard C `double` types cannot represent the imaginary unit $i$, we manually separate the real and imaginary components and print them with the character 'i' as a suffix.

## Step-by-Step Algorithm
1. Read the three integer coefficients $a, b, c$.
2. Calculate the discriminant $D = b^2 - 4ac$.
3. **If $D > 0$**:
   - Calculate $r_1 = \frac{-b + \sqrt{D}}{2a}$ and $r_2 = \frac{-b - \sqrt{D}}{2a}$.
   - Print roots and type "Real and Distinct".
4. **Else if $D = 0$**:
   - Calculate $r = \frac{-b}{2a}$.
   - Print root twice and type "Real and Equal".
5. **Else ($D < 0$)**:
   - Calculate the real part $\frac{-b}{2a}$.
   - Calculate the imaginary part $\frac{\sqrt{-D}}{2a}$.
   - Print in the format `real + imag i, real - imag i` and type "Complex".

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The calculation involves a fixed number of arithmetic operations.
- **Space Complexity:** $O(1)$ — Only a few floating-point variables are used for storage.

## Sample Execution Trace
**Input:** `1 2 5`
1. $a=1, b=2, c=5$
2. $D = 2^2 - 4(1)(5) = 4 - 20 = -16$
3. $D < 0$, so roots are complex.
4. Real part = $-2 / (2 \times 1) = -1.00$
5. Imaginary part = $\sqrt{16} / (2 \times 1) = 2.00$
**Output:** `Roots: -1.00 + 2.00i, -1.00 - 2.00iType: Complex`

## Common Mistakes & Pitfalls
- **Division by Zero:** The problem constraints state $a \neq 0$, otherwise it wouldn't be a quadratic equation.
- **Precision:** Ensure you use `double` for calculations and `%.2f` for printing to meet the 2 decimal place requirement.
- **Imaginary Sign:** For complex roots, always take the square root of the absolute value of $D$ (`sqrt(-D)`).
