# Program 5 - A Fraction Class with overloaded operators
## The Program:

For this assignment, you will develop a C++ class called Fraction.   Your class will provide a wide range of functions for handling fractions.   Your project will consist of a header file fraction.h (provided), a fraction.cpp file which contains the implementation,  an exception class named  FractionException,  a driver program called driver.cpp, and a makefile.    You are responsible for writing the fraction.cpp class the fraction_exception.h class, and the driver.cpp program which will demonstrate that your program functions correctly, and a makefile to compile your project.  You must implement all of the prototypes specified in the header file.  Thus, the project consists of:

* fraction.h    head file provided.
* fraction.cpp    implementation of the Fraction class.
* fraction_exception.h    The exception class.
* driver.cpp    A driver program to demonstrate that your Fraction class works correctly.
* makefile    The Makefile to compile your project.  Your Makefile must include the following flags:   -g -std=c++11 -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

## Additional Details:

* You may not modify the header file in any way.
* You must implement all of the function prototypes in the header file.
* Fractions should always be stored in reduced form.  Your private reduceFraction() method should use the iterative GCD algorithm (also known as Euclid's Algorithm).
* Fractions must be printing using the standard a/b format with two exceptions.  If the numerator is 0, then you will just print 0 rather than 0/b.  If the denominator is 1, you will print just the numerator rather than a/1.  As above, you must not print an fraction that is not in lowest possible form.
* Fractions read from the keyboard are formatted as a/b.
* Any operation that results in a zero denominator must throw a FractionException.  You must have a try/catch block in your driver program to catch such exceptions.  Should a FractionException be thrown, your driver will terminate gracefully with an the error message "ZeroDivisonError".
* When printing fractions, a negative sign may never appear before a denominator. A fraction that is negative must have the negative sign before the numerator. i.e. you must print -3/4, not 3/-4.
