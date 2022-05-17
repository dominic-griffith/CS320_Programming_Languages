/* 
   File:        driver.cpp
   Author:      Dominic Griffith
   Description: A driver program to demonstrate that your Fraction class works correctly
*/

#include "fraction_exception.h"
#include "fraction.h"

using namespace std;


int main() {
    try {
        Fraction f1, f2, result;

        //Fraction f2(8, 4);
        
        
        cout << "Enter fraction: num/den" << endl;
        cin >> f1;
        
        cout << "Enter fraction: num/den" << endl;
        cin >> f2;

        //f2.setNumbers(1, 2);

        //test ==
        bool boolean = f1 == f2;
        if (boolean) {
            cout << f1 << " == " << f2 << endl;
        }
        else {
            cout << f1 << " not == " << f2 << endl;
        }
        //test !=
        boolean = f1 != f2;
        if (boolean) {
            cout << f1 << " != " << f2 << endl;
        }
        else {
            cout << f1 << " not != " << f2 << endl;
        }
        //test >
        boolean = f1 > f2;
        if (boolean) {
            cout << f1 << " > " << f2 << endl;
        }
        else {
            cout << f1 << " not > " << f2 << endl;
        }
        //test >=
        boolean = f1 >= f2;
        if (boolean) {
            cout << f1 << " >= " << f2 << endl;
        }
        else {
            cout << f1 << " not >= " << f2 << endl;
        }
        //test <
        boolean = f1 < f2;
        if (boolean) {
            cout << f1 << " < " << f2 << endl;
        }
        else {
            cout << f1 << " not < " << f2 << endl;
        }
        //test <=
        boolean = f1 <= f2;
        if (boolean) {
            cout << f1 << " <= " << f2 << endl;
        }
        else {
            cout << f1 << " not <= " << f2 << endl;
        }



        //test +
        result = f1 + f2;
        cout << f1 << " + " << f2 << " = " << result << endl;
        //test -
        result = f1 - f2;
        cout << f1 << " - " << f2 << " = " << result << endl;
        //test *
        result = f1 * f2;
        cout << f1 << " * " << f2 << " = " << result << endl;
        //test /
        result = f1 / f2;
        cout << f1 << " / " << f2 << " = " << result << endl;
        


        //STILL NEED TO DO

        //test +=
        cout << f1;
        f1 += f2;
        cout << " + " << f2 << " = " << f1 << endl;
        //test -=
        cout << f1;
        f1 -= f2;
        cout << " - " << f2 << " = " << f1 << endl;
        //test *=
        cout << f1;
        f1 *= f2;
        cout << " * " << f2 << " = " << f1 << endl;
        //test /=  
        cout << f1;
        f1 /= f2;
        cout << " / " << f2 << " = " << f1 << endl;

    }
    catch(const FractionException& e) {
        cerr << e.what() << endl;
    }
    return 0;
};