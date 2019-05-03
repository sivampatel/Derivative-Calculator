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
   friend std::ostream & operator << (std::ostream &os, linkedlist list);

   linkedlist()
   {
      head = nullptr;
   }

   linkedlist(linkedlist &list)
   {
      Node * iter = list.head;
      if(iter == nullptr)
      {
         head = nullptr;
         return;
      }
      head = iter;

      Node * current = head;

      while(iter != nullptr)
      {
         current->setNext(iter);
         iter = iter->getNext();
         current = current->getNext();
      }
   }

   ~linkedlist() {

      /*
       * // working linkedlist, worked when linkedlist was a pointer in main.
      Node* tempPtr = head;
      if(tempPtr == nullptr)
         return;

      //head = head->getNext();

      while (head != nullptr)
      {
         delete tempPtr;
         tempPtr = head;
         head = head->getNext();
      }
       */
      // doesnt work
      Node *iter = head;
      Node * reti;
      while(iter->getOuter() && iter != nullptr)
      {
         if(iter->getNext() == nullptr)
         {
            delete iter;
            return;
         }
         reti = iter;
         iter = iter->getNext();
         delete reti;
      }

   }
   void deleteList()
   {

   }

   void addNode(Node * n)
   {
      if(head == nullptr)
      {
         head = n;
         return;
      }
      Node * iter = head;
      while(iter->getNext() != nullptr)
      {
         iter = iter->getNext();
      }
      iter->setNext(n);
   }

   Node * getHead()
   {
      return  head;
   }

   void sort()
   {

      Node * iter = head;
      if(iter == nullptr)
         return;
      bool swap = false;
      do{
         swap = false;
         Node * reti = iter->getNext();
         while(reti != nullptr)
         {
            if(iter->getExponent() < reti->getExponent())
            {
               int outer1 = iter->getOuter();
               int inner1 = iter->getInner();
               int exponent1 = iter->getExponent();
               int t1 = iter->getTrig();

               iter->swapNodes(reti->getOuter(), reti->getInner(), reti->getTrig(), reti->getExponent());
               reti->swapNodes(outer1, inner1, t1, exponent1);

               swap = true;
            }
            iter = iter->getNext();
            reti = reti->getNext();
         }

      } while(swap);
   }

   int getSize()
   {
      Node * iter = head;
      int size = 0;
      while(iter != nullptr)
      {
         size ++;
         iter = iter->getNext();
      }
      return size;
   }



   void operator ++ ()
   {
      Node * placeholder = head;
      Node * n = new Node();
      head = n;
      n->setNext(placeholder);
   }

   Node * operator [] (int i)
   {
      Node * iter = head;
      while (iter != nullptr && i > 0) {
         iter = iter->getNext();
         i--;
      }
      return iter;
   }
};


#endif //CS1337_PROJECT_LINKEDLIST_H
