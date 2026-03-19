# C Data Structures Lab

## Overview
This is an educational C programming lab focused on data structures — specifically Lists (array-based) and Stacks. Students implement functions in `exercises.c` and run `bash test.sh` to compile and test their solutions.

## Project Structure
- `exercises.c` — Student implementation file (edit this to complete exercises)
- `test.c` — Test suite (do not modify)
- `test.sh` — Build and test script; compiles with `gcc`, runs tests, optionally pushes to GitHub
- `arraylist.h` / `arraylist.c` — Array-based List ADT implementation
- `stack.h` — Stack ADT (wraps arraylist with push/pop/top naming)
- `log` — Automatically updated log of test run history

## Running Tests
The workflow runs `bash test.sh` automatically. It:
1. Compiles `test.c` (which includes `exercises.c` and `arraylist.c`) using `gcc -g -Wall -Werror`
2. Runs `./a.out` and displays test results
3. Optionally pushes progress to GitHub (requires a Personal Access Token)

## Exercises
1. **crea_lista()** — Create a List and add integers 1–10
2. **sumaLista(List*)** — Sum all elements in the list
3. **eliminaElementos(List*, int)** — Remove all occurrences of an element from the list
4. **copia_pila(Stack*, Stack*)** — Copy all elements from one stack to another (preserving order)
5. **parentesisBalanceados(char*)** — Check if a string has balanced parentheses

## Build System
- **Language:** C (GCC 14.3.0)
- **Compiler flags:** `-g -Wall -Werror`
- **No external dependencies** — uses standard C library only

## Workflow
- **Start application**: `bash test.sh` (console output)
