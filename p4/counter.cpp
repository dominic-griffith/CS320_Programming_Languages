/*
 * p4: This program is that keeps track of a counter and makes use of pre-increment and post-increment operations
 * Dominic Griffith
 * CS320-01
 * 11/11/21
*/

#include "counter.h"

using namespace std;

// (B) Implementation of class
Counter::Counter() {
    counter = 0;
}
Counter::Counter(int counter) {
    this->counter = counter;
}
int Counter::getCount() {
    return counter;
}
Counter Counter::operator++() {
    Counter c1;
    c1.counter = ++counter;
    return c1;
}
Counter Counter::operator++(int value) {
    Counter c1;
    c1.counter = counter++;
    return c1;
}