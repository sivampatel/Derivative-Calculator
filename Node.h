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

   Node();

   Node(int o, int i, int e, int t);

   int getOuter();

   int getInner();

   int getExponent();

   int getTrig();

   Node * getNext();

   void setNext(Node * n);

   void setOuter(int n);

   void setInner(int n);

   void setExponent(int n);

   void setTrig(int n);

   void swapNodes(int o, int i, int t, int e);

};


#endif //CS1337_PROJECT_NODE_H
