/* 
   File:        fraction.cpp
   Author:      Dominic Griffith
   Description: Implementation of the Fraction class
*/

#include "fraction.h"
#include "fraction_exception.h"

using namespace std;

ostream& operator << (ostream& os, const Fraction& frac) { //
   if(frac.num == 0){
      os << "0";
   }
   else if(frac.den == 1){
      os << frac.num;
   }
   else if(frac.den < 0) {
      os << " -" << frac.num << "/" << (frac.den*-1);
   }
   else {
      os << frac.num << "/" << frac.den;
   }
   return os;
}
istream& operator>> (istream& is, Fraction& frac) { //
   char ch;

   is >> frac.num;
   is >> ch; 
   is >> frac.den;

   if(frac.num < 0 && frac.den < 0) {
      frac.num *= -1;
      frac.den *= -1;
   }
   if(frac.den == 0) {
      throw FractionException();
   }

   frac.reduceFraction();

   return is;
}

Fraction::Fraction(int num,int den) { // constructor
   this->num = num;
   if(den == 0) {
      throw FractionException();
   }
   else {
      this->den = den;
      reduceFraction();
   }
}      
Fraction::Fraction() { // constructor //
   num = 0;
   den = 1;
}                

void Fraction::setNumbers(int num,int den) {
   this->num = num;
   if(den == 0) {
      throw FractionException();
   }
   else {
      this->den = den;
      reduceFraction();
   }
}
float Fraction::getFloat(void) {
   return ((float)this->num/(float)this->den);
}

// Overloaded assignment operator
Fraction& Fraction::operator=(const Fraction & frac) {
   this->num = frac.num;
   this->den = frac.den;
   return *this;
}

// Overloaded relational operators
int Fraction::operator==(const Fraction & frac) const {  //maybe try to use getfloat
   return(this->num == frac.num && this->den == frac.den); //could also do cross product to see
}
int Fraction::operator!=(const Fraction & frac) const {
   return(this->num != frac.num || this->den != frac.den);
}
int Fraction::operator>(const Fraction & frac) const {
   return(((float)this->num/(float)this->den) > ((float)frac.num/(float)frac.den));
}
int Fraction::operator>=(const Fraction & frac) const {
   return(((float)this->num/(float)this->den) >= ((float)frac.num/(float)frac.den));
}
int Fraction::operator<(const Fraction & frac) const {
   return(((float)this->num/(float)this->den) < ((float)frac.num/(float)frac.den));
}
int Fraction::operator<=(const Fraction & frac) const {
   return(((float)this->num/(float)this->den) <= ((float)frac.num/(float)frac.den));
}

// Overloaded arithmetic operators
Fraction Fraction::operator+(const Fraction & frac) {
   Fraction f((this->num * frac.den + this->den * frac.num), (this->den * frac.den));
   return f;
}
Fraction Fraction::operator-(const Fraction & frac) {
   Fraction f((this->num * frac.den - this->den * frac.num), (this->den * frac.den));
   return f;
}
Fraction Fraction::operator*(const Fraction & frac) {
   Fraction f(this->num*frac.num, this->den*frac.den);
   return f;
}
Fraction Fraction::operator/(const Fraction & frac) {
   int newden = this->den*frac.num;
   if(newden == 0) {
      throw FractionException();
   }
   Fraction f(this->num*frac.den, newden);
   return f;
}


Fraction& Fraction::operator+=(const Fraction & frac) { 
   this->num = (this->num * frac.den + this->den * frac.num);
   this->den = (this->den * frac.den);
   reduceFraction();
   return *this;
}
Fraction& Fraction::operator-=(const Fraction & frac) {
   this->num = (this->num * frac.den - this->den * frac.num);
   this->den = (this->den * frac.den);
   reduceFraction();
   return *this;
}
Fraction& Fraction::operator*=(const Fraction & frac) {
   this->num = (this->num*frac.num);
   this->den = (this->den*frac.den);
   reduceFraction();
   return *this;
}
Fraction& Fraction::operator/=(const Fraction & frac) {
   this->num = (this->num*frac.den);
   int newden = this->den*frac.num;
   if(newden == 0) {
      throw FractionException();
   }
   this->den = (newden);
   reduceFraction();
   return *this;
}


void Fraction::reduceFraction() {
   if(this->num != 0) {
      int bigger = (this->num > this->den ? this->num : this->den);
      int smaller = (this->num < this->den ? this->num : this->den);
      int rem = bigger % smaller;
      while (rem != 0) {
         bigger = smaller;
         smaller = rem;
         rem = bigger % smaller;
      }
      this->num /= smaller;
      this->den /= smaller;
   }
}