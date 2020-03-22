/*
 * Sivam Patel
 * SXP180045
 */

#include "Node.h"

Node::Node()
{
   outer = 1;
   inner = 0;
   exponent = 0;
   trig = NONE;
   next = nullptr;
}

Node::Node(int o, int i, int e, int t)
{
   outer = o;
   inner = i;
   exponent = e;
   trig = (TRIG)t;
   next = nullptr;
}

int Node::getOuter()
{
   return outer;
}
int Node::getInner()
{
   return inner;
}
int Node::getExponent()
{
   return exponent;
}
int Node::getTrig()
{
   return trig;
}
Node * Node::getNext()
{
   return next;
}
void Node::setNext(Node * n)
{
   next = n;
}
void Node::setOuter(int n)
{
   outer *= n;
}
void Node::setInner(int n)
{
   if(inner == 0)
      inner = n;
   else
      inner *= n;
}
void Node::setExponent(int n)
{
   if(exponent == 0)
      exponent = n;
   else
      exponent *= n;
}
void Node::setTrig(int n)
{
   trig = TRIG(n);
}

void Node::swapNodes(int o, int i, int t, int e)
{
   outer = o;
   inner = i;
   trig = TRIG(t);
   exponent = e;
}