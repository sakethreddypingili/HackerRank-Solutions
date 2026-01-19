# Next-Day Date Calculator

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Advanced
- **Category / Topics:** Nested Logic, Date Arithmetic, Gregorian Calendar Rules
- **Language Used:** C

## Problem Statement
Given a specific date (Day, Month, Year), the program must calculate the date of the next consecutive day. This requires handling varied month lengths, the transition from December to January, and the specific rules governing leap years in February.

## Calendar Logic Rules

### 1. Leap Year Calculation
A year is a leap year if:
- It is divisible by 400 **OR**
- It is divisible by 4 **AND** not divisible by 100.



### 2. Month Lengths
- **31 Days:** January (1), March (3), May (5), July (7), August (8), October (10), December (12).
- **30 Days:** April (4), June (6), September (9), November (11).
- **February (2):** 29 days in a leap year, 28 days otherwise.



## Core Concept(s) Used

### Condition Nesting
Because the problem forbids loops and switches, we use a hierarchical `if-else` structure:
1. Identify the **Month**.
2. Determine the **Max Days** for that specific month (considering leap year for February).
3. Compare the **Current Day** against the **Max Days**.
4. Handle the "Carry Over" (increment month if day resets, increment year if month resets).

### Formatted Output
The requirement is `DD-MM-YYYY`. In C, `%02d` is used to ensure that single-digit days or months (like `5`) are printed with a leading zero (`05`).

## Step-by-Step Algorithm
1. Read input `day`, `month`, `year`.
2. **If Month is February**:
   - Check Leap Year condition.
   - If day < MaxDay (28 or 29), increment day.
   - Else, set day to 1 and month to 3.
3. **Else if Month has 31 Days (excluding December)**:
   - If day < 31, increment day.
   - Else, set day to 1 and increment month.
4. **Else if Month is December**:
   - If day < 31, increment day.
   - Else, set day to 1, month to 1, and increment year.
5. **Else (Month has 30 Days)**:
   - If day < 30, increment day.
   - Else, set day to 1 and increment month.
6. Print the result using `%02d-%02d-%d`.

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — A fixed number of logical checks are performed.
- **Space Complexity:** $O(1)$ — Only three integer variables are stored.

## Sample Execution Trace
**Input:** `31 12 2023`
- `month == 12` is true.
- `day < 31` is false.
- `day = 1`, `month = 1`, `year = 2023 + 1 = 2024`.
**Output:** `01-01-2024`
