# Basic Data Types in C

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Data Types, Format Specifiers, scanf/printf, Precision Formatting
- **Language Used:** C

## Problem Statement
Read five space-separated values representing different C data types (int, long, char, float, double) and print each value on a separate line with specific formatting requirements for floating-point precision.

## Input Specification
- **Input Type:** Single line with 5 space-separated values
- **Input Order:** int, long, char, float, double
- **Input Format:** `3 12345678912345 a 334.23 14049.30493`

## Output Specification
- **Output Type:** 5 lines, each containing one value
- **Output Format:**
  `
  {int}
  {long}
  {char}
  {float with 3 decimal places}
  {double with 9 decimal places}
  `

## Constraints & Rules
- Input values provided in exact order: int → long → char → float → double
- Float must display exactly 3 decimal places
- Double must display exactly 9 decimal places
- No range constraints specified

## Core Concept(s) Used

### C Primitive Data Types & Format Specifiers
| Data Type | Format Specifier | Storage | Sample Value |
|-----------|------------------|---------|--------------|
| `int`     | `%d`             | 32-bit  | `3`          |
| `long`    | `%ld`            | 64-bit  | `12345678912345` |
| `char`    | `%c`             | 8-bit   | `'a'`        |
| `float`   | `%f`             | 32-bit  | `334.230`    |
| `double`  | `%lf` (scanf), `%lf` (printf) | 64-bit | `14049.304930000` |

### scanf Multi-Type Input
`scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e)` reads all values in one call using space-separated format specifiers.

### printf Precision Formatting
`
%.3f → 3 decimal places for float: 334.230
%.9lf → 9 decimal places for double: 14049.304930000
`

## Logic & Reasoning

The solution directly maps input format specifiers to corresponding data types and output requirements. Key insights:

1. **scanf reads all types sequentially** from single line using space-separated specifiers
2. **long requires `%ld`** (not `%d`) for 64-bit integers
3. **double scanf uses `%lf`** (not `%f`)
4. **Precision formatting** ensures exact decimal places regardless of input precision
5. **Each output on new line** except final double (matches sample output)

## Step-by-Step Algorithm

1. **Declare variables for all 5 data types:**
   ```c
   int a; long b; char c; float d; double e;
   ```

2. **Read all inputs in single scanf:**
   ```c
   scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
   ```

3. **Print each value on separate line:**
   - `int`: `%d\n`
   - `long`: `%ld\n`
   - `char`: `%c\n`
   - `float`: `%.3f\n`
   - `double`: `%.9lf`

## Time & Space Complexity

- **Time Complexity:** O(1) - Fixed 5 I/O operations
- **Space Complexity:** O(1) - 5 fixed-size variables

## Sample Execution

### Sample Input 0
`
3 12345678912345 a 334.23 14049.30493
`

### Processing
```c
int a = 3
long b = 12345678912345
char c = 'a' 
float d = 334.23 → formatted as 334.230
double e = 14049.30493 → formatted as 14049.304930000
```

### Sample Output 0
```c
3
12345678912345
a
334.230
14049.304930000
```

## Edge Cases & Assumptions

### Assumptions Made:
- Input always follows exact format (5 space-separated values)
- Values within standard C type ranges
- No malformed input or missing values

### Edge Cases Covered:
- Large long integers: `12345678912345`
- Floating-point precision variation
- Single character input
- Zero values for all types

## Common Mistakes & Pitfalls

1. **Wrong format specifier for long**
   - ❌ `scanf("%d", &b)` for long
   - ✅ `scanf("%ld", &b)` for long

2. **scanf double format specifier**
   - ❌ `scanf("%f", &e)` for double
   - ✅ `scanf("%lf", &e)` for double

3. **Incorrect precision formatting**
   - ❌ `printf("%f\n", d)` → too many decimals
   - ✅ `printf("%.3f\n", d)` → exactly 3 decimals

4. **Missing address operators**
   - ❌ `scanf("%d %ld", a, b)`
   - ✅ `scanf("%d %ld", &a, &b)`

5. **printf double specifier confusion**
   - ❌ `printf("%f", e)` for double
   - ✅ `printf("%lf", e)` for double

6. **Wrong newline placement**
   - ❌ Missing `\n` between outputs
   - ✅ Each value on separate line

## Learning Outcome

- Mastering C format specifiers for all primitive data types
- Understanding scanf multi-type input syntax
- Proper precision formatting for float (`.3f`) and double (`.9lf`)
- Distinguishing `%ld` (long) from `%d` (int) and `%lf` (double scanf) from `%f` (float)
- Sequential I/O operations with mixed data types
