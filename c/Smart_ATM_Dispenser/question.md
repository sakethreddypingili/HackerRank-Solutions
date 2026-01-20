# Smart ATM Note Dispensing Machine

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Arithmetic Operators, Greedy Algorithm, Modular Arithmetic
- **Language Used:** C

## Problem Statement
The goal is to simulate a "Precision Dispensing Algorithm" for an ATM. Given a withdrawal amount $A$, the system must calculate the minimum number of currency notes required using only three denominations: **₹500**, **₹200**, and **₹100**. The system must prioritize the highest denominations first.

## Logic & Reasoning

### The Greedy Strategy
This is a classic application of a **Greedy Algorithm**. To minimize the total number of notes, we always subtract the largest possible denomination first. 



### Mathematical Operations
- **Integer Division (`/`):** Used to find out how many notes of a specific denomination fit into the current amount.
- **Modulo Operator (`%`):** Used to find the remaining balance after dispensing the higher-value notes.



## Core Concept(s) Used

### Sequential Reduction
The amount is reduced in steps:
1.  Calculate 500s: $\text{count} = \text{Amount} / 500$.
2.  Update balance: $\text{Remaining} = \text{Amount} \pmod{500}$.
3.  Calculate 200s: $\text{count} = \text{Remaining} / 200$.
4.  Update balance: $\text{Remaining} = \text{Remaining} \pmod{200}$.
5.  Calculate 100s: $\text{count} = \text{Remaining} / 100$.

## Step-by-Step Algorithm
1. Read the input amount $A$.
2. Check if $A \le 0$. If true, print "Invalid amount" and exit.
3. Divide $A$ by 500 to get the number of ₹500 notes.
4. Update $A$ to the remainder ($A \pmod{500}$).
5. Divide the new $A$ by 200 to get the number of ₹200 notes.
6. Update $A$ to the remainder ($A \pmod{200}$).
7. Divide the new $A$ by 100 to get the number of ₹100 notes.
8. Print the counts in the specified format.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The program executes a fixed sequence of calculations regardless of the input size.
- **Space Complexity:** $O(1)$ — Only a few integer variables are used.

## Sample Execution Trace
**Input:** `1200`
1.  **500s:** $1200 / 500 = 2$. Remainder = $200$.
2.  **200s:** $200 / 200 = 1$. Remainder = $0$.
3.  **100s:** $0 / 100 = 0$.
**Output:**
```text
500-rupee notes: 2
200-rupee notes: 1
100-rupee notes: 0
