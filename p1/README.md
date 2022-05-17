# Program 1 - Dynamic Stack
One aspect of parsing a sentence in a programming language grammar is build a parse tree. We will simulate one representation of the parsing procedure by using a stack ADT.  In this implementation, only the operands are pushed onto the stack.  We will use postfix notation (operands precede the operator).

### Objectives: C programming passing by value, by reference; defining types; pointer types.


## Task 1
Download stackd.h  Download stackd.hfrom Piazza or Canvas.  Write answers to the following questions:
1. List the user-defined data types.
2. What is the purpose of #ifndef (and its associated #define and #endif).
3. What are function prototypes?


## Task 2
Download stackd.c  Download stackd.c from Piazza or Canvas.  Perform the following steps.
1. Compile this file:  gcc -ansi -c stackd.c  Note many types are not defined. These definitions are in the header file
2. Edit this file to use stackd.h, by adding:  #include ″stackd.h″ on the first line.  Recompile.
3. Note the new file stackd.o.  What is a “.o” file?
4. Look at the function Push. Describe the mechanism to access a member of a struct using a pointer.
5. Look at the function InitStack.  The formal paramenter is: stack *s_ptr.  What is a stack pointer? What value does it contain? What thing does it point to?  What is NULL?


## Task 3
Edit a new file p1.c  Download p1.c.  This will be the driver for the program and contains a main function.  It enforces an old standard: ANSI.  This file MUST compile and run on edoras.
1. Using a series of Push and Pop functions, simulate a postfix evaluation of the expression:  5 9 8 + 4 6 * * 7 * +
Hint:  Push the numerical values.  Pop two operands when an operator is encountered. Push the result back on the stack.

Compile command:  gcc -ansi -Wall p1.c stackd.o


## Task 4
Implement a new function in stackd.c called StackPrint() that prints the contents of the stack from top to bottom.  Use this function to show the content of the stack after each Push operation and at the end of the program

Deliverable 1:  Answers to questions in Task 1 and 2 (upload to Gradescope).

Deliverable 2:  C files – stackd.c, stackd.h, and p1.c (upload to Gradescope)
