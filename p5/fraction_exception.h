/* 
   File:        fraction_exception.h
   Author:      Dominic Griffith
   Description: The exception class
*/

#ifndef FRACTIONEXCEPTION_H
#define FRACTIONEXCEPTION_H

#include <exception>
using namespace std;


class FractionException: public exception {
    public:
        const char* what() const throw() {
            return "ZeroDivisonError";
            exit(1);
        }
};

#endif