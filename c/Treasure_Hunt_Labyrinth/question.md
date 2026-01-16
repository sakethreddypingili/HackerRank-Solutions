# Treasure Hunt Labyrinth

## Problem Overview
- **Platform:** HackerRank
- **Difficulty:** Medium
- **Category / Topics:** Nested Conditionals, Logic Puzzles, Decision Trees
- **Language Used:** C

## Problem Statement
Design a text-based adventure game where a player navigates a labyrinth. The player makes sequential decisions (Path -> Challenge -> Reward). Each step requires specific input, and any incorrect decision or failed puzzle result in an immediate "Game Over." Only a specific sequence of correct choices leads to the ultimate treasure.

## Input Specification
- **Input Type:** A sequence of integers representing choices and puzzle answers.
- **Input Constraints:**
  - Path Choice: 1 (Left), 2 (Middle), 3 (Right)
  - Swamp Choice: 1 (Foot), 2 (Bridge)
  - Bridge Luck: 1 (Sturdy), 2 (Collapse)
  - Middle Puzzle: 3-digit integer
  - Right Puzzle: Integer sequence answer
  - Chest Choice: 1 (Gold), 2 (Silver), 3 (Bronze)

## Output Specification
- **Output Type:** String messages for each step.
- **Output Format:**
  - Decision logs: `Player chooses the [Path] path.`, `Player found a bridge.`, etc.
  - Final Outcome: `Congratulations!! You won the treasure.` or various `Game Over!` messages.

## Constraints & Rules

### The Decision Tree


1. **Entrance:**
   - **1 (Left):** Goes to Swamp.
   - **2 (Middle):** Goes to Maze Puzzle.
   - **3 (Right):** Goes to Vault Sequence.

2. **The Puzzles:**
   - **Maze Number:** A 3-digit number where $2^{nd} = 4 \times 3^{rd}$, $1^{st} = 2^{nd} - 3$, and $Sum = 15$.
     - *Calculation:* Let digits be $x, y, z$. $y=4z$. $x=y-3 \rightarrow x=4z-3$.
     - $(4z-3) + (4z) + (z) = 15 \rightarrow 9z = 18 \rightarrow z=2$.
     - $y=8, x=5$. **Number = 582.**
   - **Vault Sequence:** 2, 6, 12, 20, __?
     - *Pattern:* $1^2+1=2, 2^2+2=6, 3^2+3=12, 4^2+4=20, 5^2+5=30$. **Answer = 30.**

3. **Final Room:**
   - **Chest 1 (Gold):** Trap/Lose.
   - **Chest 2 (Silver):** Empty/Lose.
   - **Chest 3 (Bronze):** Win.

## Core Concept(s) Used

### Nested If-Else Statements
The game is structured as a tree. Using nested `if-else` allows the program to stop execution along a branch as soon as a "Game Over" condition is met, while allowing successful players to proceed to deeper levels of input.

### Short-Circuiting with `return 0`
To handle the "Game Over" states efficiently, the program can use `return 0` within a branch to exit the `main` function immediately, preventing subsequent logic from executing erroneously.

## Logic & Reasoning
- The program must read inputs only when the player reaches that specific stage.
- Each path has a different number of required inputs (Swamp might need 3, Maze needs 2).
- Logical consistency in the output strings is vital as per the problem's strict formatting.

## Step-by-Step Algorithm
1. Read `path`.
2. **If path == 1:**
   - Print "Left path" message.
   - Read `swamp_choice`. If 1, print "Game Over" and exit.
   - If 2, print "found a bridge", read `bridge_status`. If 2, print "Game Over" and exit.
   - If 1, proceed to **Chest Logic**.
3. **If path == 2:**
   - Print "Middle path" message.
   - Read `puzzle_ans`. If `puzzle_ans == 582`, proceed to **Chest Logic**.
   - Else, print "Game Over" and exit.
4. **If path == 3:**
   - Print "Right path" message.
   - Read `seq_ans`. If `seq_ans == 30`, proceed to **Chest Logic**.
   - Else, print "Game Over" and exit.
5. **Chest Logic:**
   - Read `chest_choice`.
   - 1: Print "All that glitters is not gold, Game Over!"
   - 2: Print "All your efforts were for nothing, Game Over!"
   - 3: Print "Congratulations!! You won the treasure."

## Time & Space Complexity
- **Time Complexity:** $O(1)$ — The program processes a fixed number of inputs and comparisons.
- **Space Complexity:** $O(1)$ — Only a few integer variables are used.

## Sample Execution

### Example: Successful Right Path
**Input:** `3 30 3`
**Processing:**
- Path 3: "Player chooses the Right path."
- Puzzle 30: "Player solved the puzzle."
- Chest 3: "Congratulations!! You won the treasure."

## Edge Cases & Assumptions
- **Invalid Paths:** The problem implies path inputs will be 1, 2, or 3.
- **Sequential Input:** Inputs are provided only as needed by the logic.

## Common Mistakes & Pitfalls
- **Input Syncing:** Using `scanf` inside conditional branches is necessary because not all paths use the same number of inputs.
- **Puzzle Calculation:** Miscalculating the Maze number (582) or Sequence (30).
- **Output Strings:** Missing punctuation or case sensitivity (e.g., "Game Over!" vs "game over").

## Learning Outcome
- Mastering complex nested decision structures.
- Translating multi-step story logic into code.
- Implementing puzzle-based conditional gates.
