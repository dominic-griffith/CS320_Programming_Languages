/*
 * p4: This program is that keeps track of a counter and makes use of pre-increment and post-increment operations
 * Dominic Griffith
 * CS320-01
 * 11/11/21
*/

#include "counter.h"
#include <iostream>

using namespace std;

// (C) Application Tester
int  main() {
    Counter c1, c2;
    cout << "c1:" << c1.getCount() << ", "
        << "c2:" << c2.getCount() << endl;

    ++c1; //error in test code
    for(int i =0; i < 100; ++i)
        ++c2;
    cout << "c1:" << c1.getCount() << ", "
        << "c2:" << c2.getCount() << endl;

    c1++;
    c2++;
    cout << "c1:" << c1.getCount() << ", "
        << "c2:" << c2.getCount() << endl;

    Counter c3;
    Counter c4(2);
    cout << "c3:" << c3.getCount() << ", "
        << "c4:" << c4.getCount() << endl;

    c3 = c4++;
    cout << "c3:" << c3.getCount() << ", "
        << "c4:" << c4.getCount() << endl;

    c3 = ++c4;
    cout << "c3:" << c3.getCount() << ", "
        << "c4:" << c4.getCount() << endl;

    return 0;
}