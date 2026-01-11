# Convert 24-Hour Time to 12-Hour Format

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Time Conversion, Conditional Logic, String Formatting, Input/Output Handling
- **Language Used:** C

## Problem Statement
Convert a given time from 24-hour format (HH:MM) to 12-hour format (hh:mm AM/PM). The input consists of two integers representing hours (0-23) and minutes (0-59). The output must display the time with proper leading zeros, correct hour conversion, and appropriate AM/PM designation.

## Input Specification
- **Input Type:** Two space-separated integers
- **Input Constraints:**
  - `0 ≤ h ≤ 23` (hours in 24-hour format)
  - `0 ≤ m ≤ 59` (minutes)

## Output Specification
- **Output Type:** Formatted time string
- **Output Format:** `{hh}:{mm} AM/PM`
  - `hh` = hours in 12-hour format (01-12, with leading zero)
  - `mm` = minutes (always two digits with leading zero)
  - AM/PM based on 24-hour to 12-hour conversion rules

## Constraints & Rules
- Hours range: 0-23 (24-hour format)
- Minutes range: 0-59
- Output hours must be 01-12 (not 00 or 13-23)
- Minutes must always display two digits with leading zeros
- 00:00-11:59 → AM, 12:00-23:59 → PM
- A separate helper function should handle hour conversion logic

## Core Concept(s) Used

### 12-Hour vs 24-Hour Time Conversion
The 24-hour system maps to 12-hour format through specific rules:
- `00` → `12 AM`
- `01-11` → `01-11 AM` 
- `12` → `12 PM`
- `13-23` → `01-11 PM`

### Formatted Output in C
The `%02d` format specifier ensures two-digit output with leading zeros:
- `%02d` prints numbers 0-9 as `00-09`
- `%d` prints numbers 10-59 as `10-59`

### Modular Function Design
Separating hour conversion logic into a dedicated function improves code readability and maintainability.

## Logic & Reasoning

**Hour Conversion Rules:**
1. `hour == 0` → return `12` (midnight)
2. `1 ≤ hour ≤ 11` → return `hour` (morning hours)
3. `hour ≥ 12` → return `hour - 12` (afternoon/evening hours)

**AM/PM Logic:**
- Hours `0-11` → AM
- Hours `12-23` → PM

**Why this works:**
- Direct arithmetic conversion handles all cases efficiently
- `%02d` automatically provides leading zeros
- Simple threshold checks determine AM/PM designation

## Step-by-Step Algorithm

1. **Read input:**
   - Scan two integers: hour (0-23), minutes (0-59)

2. **Determine AM/PM:**
   - If hour ≥ 12, set "PM", else set "AM"

3. **Convert hour to 12-hour format:**
   - If hour = 0, return 12
   - If 1 ≤ hour ≤ 11, return hour
   - Else return hour - 12

4. **Format and print output:**
   - Use `%02d:%02d %s` format with converted hour, original minutes, and AM/PM

## Time & Space Complexity

- **Time Complexity:** O(1)
  Single pass through conditional logic regardless of input size.

- **Space Complexity:** O(1)
  Constant memory usage for input variables and string pointer.

## Sample Execution

### Example 1
**Input:** `00 10`

**Processing:**
- Hour: 00 → 12, AM
- Minutes: 10 (unchanged)
- Format: `12:10 AM`

**Output:** `12:10 AM`

### Example 2
**Input:** `15 45`

**Processing:**
- Hour: 15 → 15-12 = 3, PM
- Minutes: 45 (unchanged)
- Format: `03:45 PM`

**Output:** `03:45 PM`

### Example 3
**Input:** `12 30`

**Processing:**
- Hour: 12 → 12, PM
- Minutes: 30 (unchanged)

**Output:** `12:30 PM`

### Example 4
**Input:** `9 45`

**Processing:**
- Hour: 9 → 9, AM
- Minutes: 45 (unchanged)

**Output:** `09:45 AM`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Midnight:** `00:00` → `12:00 AM`
- **Noon:** `12:00` → `12:00 PM`
- **Single digit hours:** `9:45` → `09:45 AM`
- **Single digit minutes:** `14:05` → `02:05 PM`
- **Boundary values:** `23:59` → `11:59 PM`

### Assumptions:
- Input always follows constraints (0≤h≤23, 0≤m≤59)
- No malformed input or validation required

## Common Mistakes & Pitfalls

1. **Missing leading zeros**
   - ❌ `printf("%d:%d %s", hour, min, period)`
   - ✅ `printf("%02d:%02d %s", hour, min, period)`

2. **Incorrect hour 00 handling**
   - ❌ Treating 00 as 0 hour
   - ✅ Converting 00 to 12 AM

3. **Wrong PM hour conversion**
   - ❌ `hour % 12` (12 becomes 0)
   - ✅ `hour - 12` for hours ≥ 12

4. **AM/PM logic errors**
   - ❌ Using `hour > 12` instead of `≥ 12`
   - ✅ `hour >= 12` includes 12 PM correctly

5. **No newline in output**
   - ❌ Missing `\n` in printf
   - ✅ Always include newline for proper output

## Learning Outcome

- Master 24-hour to 12-hour time conversion logic
- Use C format specifiers (`%02d`) for consistent output formatting
- Implement clean modular functions for specific tasks
- Handle edge cases in time arithmetic (midnight, noon)
- Apply conditional logic for multiple conversion rules
