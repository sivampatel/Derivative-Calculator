/*
 * Sivam Patel
 * SXP180045
 */

#ifndef CS1337_PROJECT_NODE_H
#define CS1337_PROJECT_NODE_H

#include <iostream>
enum TRIG {NONE = 0, SIN, COS, TAN};


class Node {
   int outer;
   int inner;
   int exponent;
   TRIG trig;
   Node * next;
public:
   friend std::ostream & operator << (std::ostream &os, Node * n);
   friend std::ofstream & operator << (std:: ofstream &os, Node * n);

   Node()
   {
      outer = 1;
      inner = 0;
      exponent = 0;
      trig = NONE;
      next = nullptr;
   }

   Node(int o, int i, int e, int t)
   {
      outer = o;
      inner = i;
      exponent = e;
      trig = (TRIG)t;
      next = nullptr;
   }

   /*
   ~Node()
   {
      if(next)
      delete next;
   }
    */


int getOuter()
{
   return outer;
}
int getInner()
{
   return inner;
}
int getExponent()
{
   return exponent;
}
int getTrig()
{
   return trig;
}
Node * getNext()
{
   return next;
}
void setNext(Node * n)
{
   next = n;
}
void setOuter(int n)
{
   outer *= n;
}
void setInner(int n)
{
   if(inner == 0)
      inner = n;
   else
      inner *= n;
}
void setExponent(int n)
{
   //std::cout << "setexp: "<< exponent << " " << n << std::endl;

   if(exponent == 0)
      exponent = n;
   else
      exponent *= n;
}
void setTrig(int n)
{
   trig = TRIG(n);
}
void derive()
{
   if(trig != 0)
   {

   }
   else if(exponent == 0)
      {
         return;
      }
      else if(exponent == 1)
      {
         std::cout << outer << " ";
      }
      else if(exponent > 1 || exponent < 0)
      {
         std::cout << outer * exponent << "x^" << exponent - 1 << " ";
      }
}
void swapNodes(int o, int i, int t, int e)
{
   outer = o;
   inner = i;
   trig = TRIG(t);
   exponent = e;
}

};


#endif //CS1337_PROJECT_NODE_H
