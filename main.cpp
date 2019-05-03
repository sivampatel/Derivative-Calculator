/*
 * Sivam Patel
 * SXP180045
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "linkedlist.h"

void ifIsX(int&, char *, Node *);
void ifTrig(int&, char *, Node *);

std::ostream & operator << (std::ostream &out, linkedlist);
std::ostream & operator << (std::ostream &out, Node *);
std::ofstream & operator << (std:: ofstream &os, Node * n);


int main()
{
   linkedlist list;

   std::ifstream file;
   char functions[] = "functions.txt";
   file.open(functions);

   if(!file.is_open())
      std::cout << "error" << std::endl;
   while(!file.eof()) {

      char *line = new char[100];
      file.getline(line, 100, '\n');
      std::cout << line << std::endl;

      int count = 0;
      Node *n = new Node();
      while (line[count] != '\0')
      {
         if (line[count] == '+' || line[count] == '-') {
            list.addNode(n);
            /*
            std::cout << "outer: " << n->getOuter() << "   inner: " << n->getInner() << "   exp: " << n->getExponent()
                      << std::endl;
                      */
            n = new Node();

            if (line[count] == '-')
               n->setOuter(-1);
            count++;
         }
         if (line[count] == ' ') {
            count++;
            continue;
         }
         if (line[count] == 'c') {
            // cos 4x
            std::cout << "cos" << std::endl;
            n->setTrig(2);
            count += 3;
            ifTrig(count, line, n);
            continue;
         } else if (line[count] == 's') {
            n->setTrig(1);
            count += 3;
            ifTrig(count, line, n);
            continue;
         } else if (line[count] == 't') {
            n->setTrig(3);
            count += 3;
            ifTrig(count, line, n);
            continue;
         }

         if (line[count] >= 48 && line[count] <= 57)
         {
            if (line[count] == '1' && line[count + 1] == '0') {
               n->setOuter(10);
               count += 2;
               continue;
            } else {
               n->setOuter(std::atoi(&line[count]));
               count++;
               continue;
            }
         }
         if (line[count == 'x']) {
            ifIsX(count, line, n);
            continue;
         }
         count++;
      }
      delete[] line;
      list.addNode(n);
      //std::cout << "outer: " << n->getOuter() << "   inner: " << n->getInner() << "   exp: " << n->getExponent()<< std::endl;
      /*
      Node * iter = list->getHead();
      std::cout << "loop print" << std::endl;
      while(iter != nullptr)
      {
         std::cout << iter << std::endl;
         iter = iter->getNext();
      }
       */
      std::cout << "loop print" << std::endl;
      list.sort();
      std::cout << list << std::endl;

      //list.~linkedlist();

   }


   list.sort();
   file.close();

   std::cout << " \n NEW PROBLEM, IF SORTING 1-COS 4X, IT PRINTS COS 4X + 1, need to find way to make - appear if first value"
                " \nadd read for trig if there is an exponent (trig w/ exponent) \n"
                "implement destructor to reset list \n \n Need to: \n overload [] \n overload << \n finish derive (do as char array)"
                "function \n make sure linkedlist destructor works \n add ++ operator\n overload constructors \n\n "
                "GOOD NEWS, THE DACIA SANDERO ... "
                "\n THE DESTRUCTOR IS WORKING. It works. " << std::endl;
   std::cout << "End OF PROGRAm" << std::endl;

   return 0;
}

void ifIsX(int &count, char * line, Node * n)
{

   if(line[count + 1] == '^')
   {
      count++;

      if(line[count + 1] == '-')
      {
         n->setExponent(-1);
         count++;
      }
      if(line[count + 1] == '1' && line[count + 2] == '0')
      {
         n->setExponent(10);
         count += 2;
      }
      else
      {
         n->setExponent(std::atoi(&line[count + 1]));
         count += 2;
      }
   }
   else
   {
      n->setExponent(1);
      count++;
   }
}

void ifTrig(int& count, char * line, Node * n)
{
   // tan -10x
   while(line[count] == ' ')
      count++;
   if(line[count] == '-')
   {
         n->setInner(-1);
         count++;
   }
   if(line[count] == '1' && line[count + 1] == '0')
   {
      n->setInner(10);
      count += 2;
   }
   else if(line[count] >= 48 && line[count] <= 57)
   {
      n->setInner(std::atoi(&line[count]));
      count++;
   }
   else
      n->setInner(1);

   if(line[count] == 'x')
   {
      return;
   }

}


std::ostream & operator << (std::ostream &os,  linkedlist list)
{
   int size = list.getSize();
   if(list[0] == nullptr)
      return os;

   for(int x = 0; x < size; x++)
   {
      if(x == 0 && list[0]->getOuter()  < 0)
      {
         os << "-";
      }
      else if(x > 0)
      {
         if(list[x]->getOuter() > 0)
            os << " + ";
         if(list[x]->getOuter() < 0)
            os << " - ";
      }
      os << list[x];
   }
   /*
   Node * iter = list.head;
   if(iter != nullptr)
   {
      os << iter;
   }
   else
   {
      return os;
   }
   if(iter->getNext() != nullptr)
      iter = iter->getNext();
   else
      return os;
   while(iter != nullptr)
   {
      if(iter->getOuter() > 0)
      {
         os << " + ";
      }
      else
      {
         os << " - ";
      }
      os << iter;
      iter = iter->getNext();
   }
    */

   return os;
}

std::ostream & operator << (std::ostream &os, Node * n)
{

   if(n == nullptr)
   {
      os << "0x0" << std::endl;
      return os;
   }
   if(n->trig)
   {
      //os << "trig" << std::endl;
      if(n->outer != 1 && n->outer != -1)
         os << n->outer;
      if(n->trig == 1)
         os << "sin ";
      if(n->trig == 2)
         os << "cos ";
      if(n->trig == 3)
         os << "tan ";

      if(n->inner == 1)
         os << "x";
      else if(n->inner == -1)
         os << "-x";
      else
         os << n->inner << "x";
   }
   else
   {
      // outer = 1;
      // exponent = 0;
      //
      if(n->outer != 1 && n->outer != -1)
         os << n->outer;

      if(n->exponent != 0)
      {
         if(n->exponent == 1)
         {
            os << "x";
         }
         else
         {
            os << "x^" << n->exponent;
         }
      }
      else
      {
         if(n->outer == 1)
            os << 1;
         else if(n->outer == -1)
            os << -1;
      }
   }
   return os;
}

std::ofstream & operator << (std::ofstream &os,  linkedlist list)
{
   int size = list.getSize();
   if(list[0] == nullptr)
      return os;

   for(int x = 0; x < size; x++)
   {
      if(x == 0 && list[0]->getOuter()  < 0)
      {
         os << "-";
      }
      else if(x > 0)
      {
         if(list[x]->getOuter() > 0)
            os << " + ";
         if(list[x]->getOuter() < 0)
            os << " - ";
      }
      os << list[x];
   }
   /*
   Node * iter = list.head;
   if(iter != nullptr)
   {
      os << iter;
   }
   else
   {
      return os;
   }
   if(iter->getNext() != nullptr)
      iter = iter->getNext();
   else
      return os;
   while(iter != nullptr)
   {
      if(iter->getOuter() > 0)
      {
         os << " + ";
      }
      else
      {
         os << " - ";
      }
      os << iter;
      iter = iter->getNext();
   }
    */

   return os;
}

std::ofstream & operator << (std:: ofstream &os, Node * n)
{
   if(n == nullptr)
   {
      os << "0x0" << std::endl;
      return os;
   }
   if(n->trig)
   {
      //os << "trig" << std::endl;
      if(n->outer != 1 && n->outer != -1)
         os << n->outer;
      if(n->trig == 1)
         os << "sin ";
      if(n->trig == 2)
         os << "cos ";
      if(n->trig == 3)
         os << "tan ";

      if(n->inner == 1)
         os << "x";
      else if(n->inner == -1)
         os << "-x";
      else
         os << n->inner << "x";
   }
   else
   {
      // outer = 1;
      // exponent = 0;
      //
      if(n->outer != 1 && n->outer != -1)
         os << n->outer;

      if(n->exponent != 0)
      {
         if(n->exponent == 1)
         {
            os << "x";
         }
         else
         {
            os << "x^" << n->exponent;
         }
      }
      else
      {
         if(n->outer == 1)
            os << 1;
         else if(n->outer == -1)
            os << -1;
      }
   }
   return os;
}

