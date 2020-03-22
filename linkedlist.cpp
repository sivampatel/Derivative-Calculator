/*
 * Sivam Patel
 * SXP180045
 */

#include "linkedlist.h"

linkedlist::linkedlist()
{
   head = nullptr;
}

linkedlist::linkedlist(linkedlist &list)
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

linkedlist::~linkedlist() {

   deleteList();

}
void linkedlist::deleteList()
{
   Node * iter = head;
   while(iter != nullptr)
   {
      Node * placeholder = iter;
      iter = iter->getNext();
      delete placeholder;
   }
   head = nullptr;

}

void linkedlist::addNode(Node * n)
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

Node * linkedlist::getHead()
{
   return  head;
}

void linkedlist::sort()
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

int linkedlist::getSize()
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

void linkedlist::operator ++ ()
{
   Node * placeholder = head;
   Node * n = new Node();
   head = n;
   n->setNext(placeholder);
}

Node * linkedlist::operator [] (int i)
{
   Node * iter = head;
   while (iter != nullptr && i > 0) {
      iter = iter->getNext();
      i--;
   }
   return iter;
}