/*
 * Stack.h
 *
 *  Created on: Mar 9, 2018
 *      Author: steven
 */

#ifndef STACK_H_
#define STACK_H_

namespace std {

class SNode
{
   public:
   int Number;
   SNode *Next;
};

class Stack {
public:
      // constructor functions
      Stack();
      ~Stack();

      // general stack operations
      void Push(int Number);
      int Pop();
      int Top();
      bool IsFull();
      bool IsEmpty();
      void Print();
      int getLength();

   private:
      SNode *Head;
      int Length;
};

} /* namespace std */

#endif /* STACK_H_ */
