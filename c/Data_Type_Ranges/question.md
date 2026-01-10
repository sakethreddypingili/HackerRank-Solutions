# Data Type Ranges

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** C Standard Library, Data Types, Limits Headers, Type Ranges
- **Language Used:** C

## Problem Statement
Write a C program that displays the minimum and maximum values for all standard integer, unsigned integer, character, and floating-point data types using predefined constants from `limits.h` and `float.h`. The output must follow the exact specified format without hardcoding any values.

## Input Specification
- **Input Type:** None
- **Input Constraints:** No input required

## Output Specification
- **Output Type:** Formatted strings
- **Output Format:** Exactly 15 lines in the specified format:

short: {min} to {max}
int: {min} to {max}
...
long double: {min} to {max}


## Constraints & Rules
- Must use macros from `limits.h` and `float.h` exclusively
- No hardcoded numeric values allowed
- Exact output format required (including spacing and precision)
- Unsigned types always start from 0
- Must compile and run on standard C compilers
- Values may vary slightly by architecture/compiler

## Core Concept(s) Used

### Standard C Limits Headers
C provides standardized header files containing macros for type limits:
- **`limits.h`**: Integer and character type boundaries (`INT_MIN`, `FLT_MAX`, etc.)
- **`float.h`**: Floating-point type characteristics (`DBL_MIN`, `LDBL_MAX`, etc.)

### Type-Safe Format Specifiers
Each printf format specifier matches its corresponding type:
- `%d / %ld / %lld` for signed integers
- `%u / %lu / %llu` for unsigned integers  
- `%e / %Le` for scientific notation floats
- `%hd / %hu` for short types

## Logic & Reasoning

The solution leverages C's standardized limits macros, ensuring:
1. **Portability**: Works across different compilers/architectures
2. **Precision**: Uses exact format specifiers to avoid overflow/truncation
3. **Compliance**: No hardcoded values, purely using standard constants
4. **Efficiency**: Single printf per line, no calculations needed

Key insight: Unsigned minimum is always 0, signed minimums are negative, and floating-point ranges use scientific notation (`%e`).

## Step-by-Step Algorithm

1. **Include required headers:**
   - `stdio.h` for printf
   - `limits.h` for integer/char limits
   - `float.h` for floating-point limits

2. **Print integer ranges (signed):**
   - Use `SHRT_MIN/MAX`, `INT_MIN/MAX`, `LONG_MIN/MAX`, `LLONG_MIN/MAX`

3. **Print unsigned integer ranges:**
   - Print "0 to {MAX}" using `USHRT_MAX`, `UINT_MAX`, etc.

4. **Print character ranges:**
   - Use `CHAR_MIN/MAX`, `UCHAR_MAX`

5. **Print floating-point ranges:**
   - Use `%e` format with `FLT_MIN/MAX`, `DBL_MIN/MAX`, `LDBL_MIN/MAX`

## Time & Space Complexity
- **Time Complexity:** O(1) - Fixed 15 printf statements
- **Space Complexity:** O(1) - No dynamic allocation, only stack variables

## Sample Execution

**Input:** (None)

**Processing:**
```c
SHRT_MIN → -32768
SHRT_MAX → 32767
INT_MIN → -2147483648
INT_MAX → 2147483647
FLT_MIN → 1.175494e-38
FLT_MAX → 3.402823e+38
```

**Output:**
```c
short: -32768 to 32767
int: -2147483648 to 2147483647
long: -9223372036854775808 to 9223372036854775807
long long: -9223372036854775808 to 9223372036854775807
unsigned short: 0 to 65535
unsigned int: 0 to 4294967295
unsigned long: 0 to 18446744073709551615
unsigned long long: 0 to 18446744073709551615
char: -128 to 127
unsigned char: 0 to 255
float: 1.175494e-38 to 3.402823e+38
double: 2.225074e-308 to 1.797693e+308
long double: 3.362103e-4932 to 1.189731e+4932
```

## Edge Cases & Assumptions

### Assumptions Made:
- Standard C compiler with `limits.h` and `float.h` support
- 32/64-bit architecture (values shown are typical)
- `long` and `long long` may vary by platform

### Edge Cases Covered:
- **Largest negative values**: `LLONG_MIN` requires `%lld` (not `%ld`)
- **Unsigned ranges**: Always print "0 to {MAX}"
- **Floating-point precision**: `%e` ensures scientific notation

### Platform Dependencies:

long double precision varies significantly:
- x86: 80-bit extended precision
- x86_64: Often same as double
- ARM: Varies by implementation


1. **Wrong format specifiers**
- ❌ printf("%d to %d", LONG_MIN, LONG_MAX);    `// Wrong for long`
- ✅ printf("%ld to %ld", LONG_MIN, LONG_MAX);

2. **Missing headers**
- ❌ printf("%lld", LLONG_MIN);    `// Undefined without limits.h`
- ✅ #include <limits.h>

3. **Hardcoding values**
- ❌ printf("short: -32768 to 32767");    `// Fails on different platforms`
- ✅ printf("short: %hd to %hd", SHRT_MIN, SHRT_MAX);

4. **Long double formatting**
- ❌ printf("%e", LDBL_MAX);    `// Insufficient precision`
- ✅ printf("%Le", LDBL_MAX);    `// Long double specifier`

5. **Integer overflow in display**
- ❌ printf("%d", INT64_MIN);    `// Truncates on 32-bit int`
- ✅ printf("%lld", LLONG_MIN);    `// Correct 64-bit specifier`
   
## Learning Outcome
- Master C's `limits.h` and `float.h` for portable type boundaries
- Understand precise format specifiers for all integer/float variants
- Recognize platform dependencies in `long`/`long double` sizes
- Apply standardized macros instead of hardcoded platform-specific values
