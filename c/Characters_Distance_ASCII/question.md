# Characters Distance Calculator

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Easy
- **Category / Topics:** Character Manipulation, ASCII Arithmetic, Absolute Value
- **Language Used:** C

## Problem Statement
Given two lowercase English letters, calculate the alphabetical distance between them. The distance is defined as the number of letters between the two characters in the alphabet. The program must use ASCII value arithmetic to determine this distance.

## Input Specification
- **Input Type:** Two space-separated lowercase characters
- **Input Constraints:** 
  - Both characters must be lowercase letters (a-z)
  - char1 always comes before char2 in alphabetical order

## Output Specification
- **Output Type:** Formatted string with integer distance
- **Output Format:** `The distance between {char1} and {char2} is {value}`

## Constraints & Rules
- Input characters are guaranteed to be lowercase (a-z)
- First character always precedes the second alphabetically
- Only ASCII arithmetic operations are allowed
- No string manipulation functions permitted

## Core Concept(s) Used

### ASCII Character Distance
In ASCII encoding, consecutive letters have consecutive numeric values:
- 'a' = 97, 'b' = 98, 'c' = 99, ..., 'z' = 122
- The difference between two characters' ASCII values gives their positional distance

### Absolute Value Calculation
The solution implements absolute value using the ternary operator:
```c
value = (cal < 0) ? -cal : cal;
