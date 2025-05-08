# PushSwap

## Table of Contents
- [General Instructions](#general-instructions)
- [Mandatory Part](#mandatory-part)
  - [Rules](#rules)
  - [Example](#example)
  - [Arguments](#arguments)
  - [External Functions](#external-functions)
  - [Project Requirements](#project-requirements)
- [Usage](#usage)

## General Instructions
- Your projects must be written in C.
- Except for undefined behaviors, your functions should not terminate unexpectedly.
- All heap-allocated memory addresses must be properly freed when necessary. No exceptions will be tolerated.
- If the task requires submitting a Makefile, you must create a Makefile that compiles your source files with the flags `-Wall`, `-Wextra`, and `-Werror`. Use `cc` for compiling, and your Makefile must not relink.
- Your Makefile must at least contain the rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Mandatory Part

### Rules
- You have 2 stacks named `a` and `b`.
- Initially:
  - The `a` stack contains a random number of non-repeating positive and/or negative integers.
  - The `b` stack is empty.
- The goal is to sort the numbers in the `a` stack in ascending order using the following actions:
  - `sa` (swap a): Swap the top two elements of the `a` stack. Do nothing if there are less than two elements.
  - `sb` (swap b): Swap the top two elements of the `b` stack. Do nothing if there are less than two elements.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Move the top element of `b` stack to the top of `a` stack. Do nothing if `b` is empty.
  - `pb` (push b): Move the top element of `a` stack to the top of `b` stack. Do nothing if `a` is empty.
  - `ra` (rotate a): Shift all elements of the `a` stack up by one. The top element becomes the last one.
  - `rb` (rotate b): Shift all elements of the `b` stack up by one. The top element becomes the last one.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of the `a` stack down by one. The bottom element becomes the first one.
  - `rrb` (reverse rotate b): Shift all elements of the `b` stack down by one. The bottom element becomes the first one.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

### Example
To illustrate the behavior of the defined actions, let's try sorting a random list of integers. In this example, we'll assume both stacks grow from right to left.


```
----------------------------------------------------------------------------------------------------------
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```


### Arguments
- **stack a**: A list of integers.

### External Functions
- `read`, `write`, `malloc`, `free`, `exit`
- `ft_printf` or a custom alternative.

### Project Requirements
- You must create a Makefile that compiles your source files and upload it to your project repository. The Makefile must not relink.
- Global variables are forbidden.
- You have to write a program named `push_swap` that takes as an argument the `a` stack formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program should output the minimal list of actions required to sort the `a` stack such that the smallest number is at the top.
- Actions should be separated by a single newline character (`\n`). No other characters are allowed.
- The goal is to sort the stack with the least number of actions possible. During evaluation, the number of actions output by your program will be compared against a limit: the maximum allowed number of actions. If your program outputs a longer list or the integers are not correctly sorted, your grade will be 0.
- If no arguments are provided to the program, it should not output anything and should exit.
- In case of any error, the program should output "Error\n" to the standard error followed by an explicit error message of your choice. Examples of errors: some arguments are not integers, some arguments are larger than an integer, and/or there are duplicates.

### Usage
To run the program:
```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$ ./push_swap 0 one 2 3
Error
