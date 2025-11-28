# Expression Parser in C

A command-line calculator written in C that parses and evaluates mathematical expressions. This project implements Dijkstra's Shunting Yard algorithm to convert standard infix expressions into Reverse Polish Notation (RPN), which is then evaluated to produce the final result.

## Usage Examples

Run the compiled `parser` from your terminal, providing the expression as a series of arguments. Each number, operator, and parenthesis must be a separate argument.

**Important**: The multiplication operator (`*`) must be quoted to prevent the shell from treating it as a wildcard. The same goes for parentheses

* **Basic Arithmetic:**
    ```bash
    ./parser 3 + 5 "*" 2
    ```
    **Result:** `13.00`

* **With Parentheses:**
    ```bash
    ./parser "(" 3 + 5 ")" "*" 2
    ```
    **Result:** `16.00`

* **Parentheses AND precedences:**
    ```bash
    ./parser 10 + "(" -5 "*" 2 ")" / 5
    ```
    **Result:** `8.00`

## Supported Operations

This parser currently supports the four main mathematical operations:
* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)

It correctly handles operator precedence and grouping with parentheses. 

**Important**: Unfortunately, the program still cannot manage the cases in which one or more of the input tokens are written without spaces.
