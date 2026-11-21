# Arbitrary Precision Calculator (APC)

A command-line calculator written in C that performs arithmetic operations on numbers of virtually unlimited length, overcoming the size limits of standard C data types (`int`, `long`).

## Features
* **Operations:** Addition (`+`), Subtraction (`-`), Multiplication (`x`), and Division (`/`)
* **Data Structure:** Uses Doubly Linked Lists to dynamically store digits and traverse bidirectional carries/borrows
* **Edge Cases:** Handles negative numbers, sign propagation, leading zeros, and CLI argument validation
* **Build System:** Modular C architecture automated with an incremental `Makefile`

## Project Structure
* `main.c` – Entry point and operation routing
* `apc.c` / `apc.h` – CLI validation, list utilities, and function prototypes
* `add.c`, `sub.c`, `mul.c`, `div.c` – Core arithmetic modules
* `Makefile` – Incremental build configuration

## How to Build & Run

Compile the project:
```bash
make
./apc <operand1> <operator> <operand2>
make clean
