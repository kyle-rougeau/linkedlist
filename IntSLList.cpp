#include <iostream>
#include "IntSLList.h"

using namespace std;

IntSLLNode* IntSLList::getHead()
{
   return head;
}

IntSLLNode* IntSLList::getTail()
{
   return tail;
}

void IntSLList::addToHead(int info)
{
   head = new IntSLLNode(info, head);
   if(head->next == NULL)
   {
      tail = head;
   }
}
void IntSLList::addToTail(int info)
{
   IntSLLNode* temp = new IntSLLNode(info, NULL);
   if(head == NULL)
   {
      head = temp;
      tail = temp;
   }
   tail->next = temp;
   tail = temp;
}

int IntSLList::deleteFromHead()
{
   if (head == NULL)
   {
      cout << "\n\nFailed to delete from head: no elements in list\n\n";
      return -1;
   }
   IntSLLNode* oldHead = head;
   int tempInfo = oldHead->info;
   
   if (head == tail)
   {
      head = NULL;
      tail = NULL;
   }
   else
   {
      head = oldHead->next;
      oldHead->~IntSLLNode();
   }
   
   return tempInfo;
   
}
int IntSLList::deleteFromTail()
{
   if (head == NULL)
   {
      cout << "\n\nFailed to delete from tail: no elements in list\n\n";
      return -1;
   }
   
   IntSLLNode* beforeTail = head;
   int tempInfo = tail->info;
   if (head == tail)
   {
      head = NULL;
      tail = NULL;
   }
   else
   {
      //find node just before tail
      while(beforeTail->next != tail)
      {
         beforeTail = beforeTail->next;
      }
      tail->~IntSLLNode();
      tail = beforeTail;
      tail->next = NULL;
   }

   return tempInfo;
}

int IntSLList::deleteNode(int index)
{
   if (index == 0)
   {
      deleteFromHead();
   }
   else
   {
      IntSLLNode* toPop = head;
      IntSLLNode* beforeToPop = toPop;
      for(int i = 0; i < index; i++)
      {
         if(toPop == tail)
         {
            cout << "\n\nFailed to delete node at " << index << ": index out of bounds\n\n";
            return -1;
         }
         else
         {
            beforeToPop = toPop;
            toPop = head->next;
         }
      }
      if (toPop == tail)
      {
         deleteFromTail();
      }
      else
      {
         beforeToPop->next = toPop->next;
         toPop->~IntSLLNode();
      }
   }
   return 0;
}

bool IntSLList::isInList(int compare) const
{
   IntSLLNode* searchPoint = head;
   while(searchPoint != NULL)
   {
      if(searchPoint->info == compare)
      {
         return true;
      }
      searchPoint = searchPoint->next;
   }
   return false;
}

bool IntSLList::isEqualTo(IntSLList compareTo)
{
    IntSLLNode* tempCompare = head;
    IntSLLNode* tempCompareTo = compareTo.getHead();

    if(tempCompare->info != tempCompareTo->info)
    {
        return false;
    }
    while(tempCompare->next != NULL)
    {
        if(tempCompareTo->next == NULL)
        {
            return false;
        }

        tempCompare = tempCompare->next;
        tempCompareTo = tempCompareTo->next;

        if(tempCompare->info != tempCompareTo->info)
        {
            return false;
        }
    }
    
    if (tempCompareTo->next != NULL)
    {
        return false;
    }
    
    return true;
}

void IntSLList::disp()
{
   IntSLLNode* temp = head;
   while(temp != NULL)
   {
      cout << temp->info << " ";
      temp = temp->next;
   }
}
