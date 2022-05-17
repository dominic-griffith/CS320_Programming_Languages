/*
 * File: p1.c -- C driver for dynamic stack
 *
 * Dominic Griffith
 * CS320-01
 * 09/19/21
 *
 */
#include "stackd.h"

void show(stack s)
{
   PrintStack(s); printf("---\n");
}

int main(void)
{
   stack s;
   el_t e;

   /* TODO:  Demonstrate the operation of this postfix expression.
    *        5 9 8 + 4 6 * * 7 * +
    */
   InitStack(&s);
   e = 5;
   Push(&s, e);
   show(s);

   e = 9;
   Push(&s, e);
   show(s);

   e = 8;
   Push(&s, e);
   show(s);

   Pop(&s, &e);
   Pop(&s, &e);
   e = 8 + 9;
   Push(&s, e);
   show(s);

   e = 4;
   Push(&s, e);
   show(s);

   e = 6;
   Push(&s, e);
   show(s);

   Pop(&s, &e);
   Pop(&s, &e);
   e = 6 * 4;
   Push(&s, e);
   show(s);

   Pop(&s, &e);
   Pop(&s, &e);
   e = 24 * 17;
   Push(&s, e);
   show(s);

   e = 7;
   Push(&s, 7);
   show(s); 

   Pop(&s, &e);
   Pop(&s, &e);
   e = 7 * 408;
   Push(&s, e);
   show(s);

   Pop(&s, &e);
   Pop(&s, &e);
   e = 2856 + 5;
   Push(&s, e);
   show(s);

 
   return e;
}
