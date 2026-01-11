
**Maximum possible sum:** 9 + 9 = 18 (no overflow risk)

## Step-by-Step Algorithm

1. **Define required function:**
   - Signature: `int sumLastDigits(int a, int b)`
   - Extract `a % 10` and `b % 10`
   - Return their sum

2. **Read input in main:**
   - Use `scanf("%d %d", &a, &b)` for two space-separated integers

3. **Process:**
   - Call `sumLastDigits(a, b)`
   - Store returned value

4. **Output exactly:**
   - `printf("The sum of last digits is: %d", result)`

## Time & Space Complexity

- **Time Complexity:** O(1) - Two modulo operations and one addition
- **Space Complexity:** O(1) - Four integer variables maximum

## Sample Execution

### Example 1
**Input:** `42 59`

**Processing:**
- Last digit of 42 = 42 % 10 = 2
- Last digit of 59 = 59 % 10 = 9
- Sum = 2 + 9 = 11

**Output:** `The sum of last digits is: 11`

### Example 2  
**Input:** `100 9`

**Processing:**
- Last digit of 100 = 100 % 10 = 0
- Last digit of 9 = 9 % 10 = 9
- Sum = 0 + 9 = 9

**Output:** `The sum of last digits is: 9`

### Example 3
**Input:** `123456789 987654321`

**Processing:**
- Last digit of 123456789 = 9
- Last digit of 987654321 = 1
- Sum = 9 + 1 = 10

**Output:** `The sum of last digits is: 10`

## Edge Cases & Assumptions

### Edge Cases Covered:
- **Zero values:** `0 0` → `0 + 0 = 0`
- **Single digit:** `5 7` → `5 + 7 = 12`
- **Maximum values:** `1000000000 999999999` → `0 + 9 = 9`
- **All nines:** `19 29` → `9 + 9 = 18` (maximum sum)

### Assumptions Made:
- Input always valid (two integers, space-separated)
- No negative numbers per constraints
- Standard C `int` sufficient for 10⁹ values

## Common Mistakes & Pitfalls

1. **Wrong function name**
   - ❌ `int calculate(int a, int b)`
   - ✅ `int sumLastDigits(int a, int b)`

2. **Incorrect output format**
   - ❌ `printf("Sum: %d", result);`
   - ✅ `printf("The sum of last digits is: %d", result);`

3. **Modulo other numbers**
   - ❌ `a % 100` (gets last two digits)
   - ✅ `a % 10` (gets last digit only)

4. **scanf mistakes**
   - ❌ `scanf("%d%d", &a, &b);` (no space)
   - ✅ `scanf("%d %d", &a, &b);`

5. **All logic in main**
   - ❌ Direct calculation without function call
   - ✅ Use required `sumLastDigits()` function

6. **Integer overflow confusion**
   - Sum is always 0-18, never overflows even 8-bit `int`

## Learning Outcome

- Master modulo operator `%` for digit extraction
- Understand exact function signature requirements in coding platforms
- Apply precise output formatting matching problem specifications
- Recognize when O(1) operations suffice for large input ranges
