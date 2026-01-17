# Investment Risk Management System

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Complex Conditionals, Risk Modeling, Decision Trees
- **Language Used:** C

## Problem Statement
The goal is to classify an investor's portfolio into **Low**, **Medium**, or **High** risk levels based on three factors: **Age**, **Annual Income**, and **Risk Tolerance**. The system simulates how a real investment advisor might prioritize aggressive growth for younger clients and stability for retirees.

## Input Specification
- **Age:** Integer ($0 < \text{Age} < 100$)
- **Annual Income:** Integer ($0 < \text{Income} < 1,000,000$)
- **Risk Tolerance:** Integer ($1$: Low, $2$: Medium, $3$: High)

## Output Specification
- A single string describing the risk level and a recommendation.

---

## Decision Logic Breakdown



### 1. High Risk Portfolio
- **Rule 1:** Age $< 30$ (Automatic High Risk regardless of other factors).
- **Rule 2:** Age is $30$ to $50$ **AND** Income $> 75,000$ **AND** Tolerance is $3$ (High).
- **Rule 3:** Age $> 50$ **AND** Income $> 75,000$ **AND** Tolerance is $3$ (High).

### 2. Medium Risk Portfolio
- **Rule 1:** Age is $30$ to $50$ **AND** Income $\le 75,000$ **AND** Tolerance is $2$.
- **Rule 2:** Age is $30$ to $50$ **AND** Income $> 75,000$ **AND** Tolerance is $1$ or $2$.

### 3. Low Risk Portfolio
- **Rule 1:** Age $> 50$ **UNLESS** (Income $> 75,000$ AND Tolerance is $3$).
- **Rule 2:** Income $\le 30,000$ **AND** Tolerance is $1$ or $2$.

---

## Core Concept(s) Used

### Logical Priority
In many programming challenges, conditions can overlap. The most efficient way to solve this is to check for the **most aggressive** or **most specific** criteria first. In this case, checking for "High Risk" first simplifies the logic for "Medium" and "Low" because we can assume the "High Risk" criteria haven't been met.

### Boolean Negation (`!`) and Compound Logic
Handling the "Unless" condition for Low Risk requires careful use of `&&` and `||`. For example: `age > 50 && !(income > 75000 && tolerance == 3)`.



## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The program executes a fixed number of logical checks.
- **Space Complexity:** $O(1)$ — Only a few integer variables are used to store inputs.

## Sample Execution Trace

**Input:** `51 80000 3`
1. **Check High Risk:** Age ($51$) is $> 50$, Income ($80,000$) is $> 75,000$, and Tolerance is $3$.
2. **Result:** High Risk Portfolio.

**Input:** `35 85000 1`
1. **Check High Risk:** Under 30? No. High income/tolerance? No.
2. **Check Medium Risk:** Age is between 30-50, Income is high, Tolerance is 1 (matches Rule 2).
3. **Result:** Medium Risk Portfolio.

## Common Mistakes & Pitfalls
- **Overlapping Ranges:** Failing to use `else if` can cause multiple messages to print if the input satisfies two categories.
- **Handling "Above 50":** Ensure the boundary is correct (usually `age > 50` means 51 and older).
- **Tolerance Mapping:** Confusing the integers (1, 2, 3) with the risk labels.
