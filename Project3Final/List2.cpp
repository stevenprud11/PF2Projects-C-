//----------------------------------------------
// Purpose: Implement simple List class.
// Author:  John Gauch
//----------------------------------------------

#include "List2.h"
#include <stdlib.h>

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List()
{
   Head = NULL;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List(const List & list)
{
   // Create first node
   LNode *copy = new LNode();
   Head = copy;

   // Walk list to copy nodes
   LNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->Next = new LNode();
      copy = copy->Next;
      copy->Value = ptr->Value;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
List::~List()
{
   // Walk list to delete nodes
   while (Head != NULL)
   {
      LNode *ptr = Head;
      Head = Head->Next;
      delete ptr;
   }
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertHead(float value)
{
   // Create new node
   LNode *ptr = new LNode();
   ptr->Value = value;
   ptr->Next = Head;

   // Insert new node
   Head = ptr;
   return true;
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertTail(float value)
{
   // Find tail node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Next != NULL))
      ptr = ptr->Next;

   // Create new node
   LNode *tmp = new LNode();
   tmp->Value = value;

   // Insert new node
   if (ptr != NULL)
   {
      tmp->Next = NULL;
      ptr->Next = tmp;
   }
   else
   {
      tmp->Next = Head;
      Head = tmp;
   }
   return true;
}

//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool List::Search(float value)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Value != value))
      ptr = ptr->Next;
   return (ptr != NULL);
}

//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool List::Delete(float value)
{
   // Walk list to deletion point
   LNode *curr = Head;
   LNode *prev = Head;
   while ((curr != NULL) && (curr->Value != value))
   {
      prev = curr;
      curr = curr->Next;
   }

   // Check if value was found
   if (curr == NULL)
      return false;

   // Delete node from list
   if (curr == Head)
      Head = curr->Next;
   else
      prev->Next = curr->Next;
   delete curr;
   return true;
}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void List::Print()
{
   LNode *ptr = Head;
   while (ptr != NULL)
   {
      cout << ptr->Value << endl;
      ptr = ptr->Next;
   }
}

//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool List::IsEmpty()
{
   return (Head == NULL);
}

