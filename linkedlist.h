/*
 * Sivam Patel
 * SXP180045
 */

#ifndef CS1337_PROJECT_LINKEDLIST_H
#define CS1337_PROJECT_LINKEDLIST_H

#include "Node.h"

class linkedlist {
   Node * head;

public:
   friend std::ostream& operator << (std::ostream &os, linkedlist &list);

   linkedlist();

   linkedlist(linkedlist &list);

   ~linkedlist();

   void deleteList();

   void addNode(Node * n);

   Node * getHead();

   int getSize();

   void sort();

   void operator ++ ();

   Node * operator [] (int i);

};


#endif //CS1337_PROJECT_LINKEDLIST_H
