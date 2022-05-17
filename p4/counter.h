/*
 * p4: This program is that keeps track of a counter and makes use of pre-increment and post-increment operations
 * Dominic Griffith
 * CS320-01
 * 11/11/21
*/

#ifndef COUNTER_H       // If stuff in this file is not defined yet
#define COUNTER_H       // then define it beginning here.
  
// (A) Interface
class Counter { // The class definition goes here,
    private:
        int counter;

    public:
        Counter();
        Counter(int);
        int getCount();
        Counter operator++();
        Counter operator++(int);

}; //Semicolon
#endif                  // and the definition ends here.