#include <iostream>
#include "intSLLNode.h"

using namespace std;

class intSLL {
private:
   intSLLNode* head = NULL;
   intSLLNode* tail = NULL;
public:
   intSLLNode* getHead()
   {
      return head;
   }
   
   intSLLNode* getTail()
   {
      return tail;
   }
   
   void addToHead(int info)
   {
      head = new intSLLNode(info, head);
      if(head->next == NULL)
      {
         tail = head;
      }
   }
   void addToTail(int info)
   {
      intSLLNode* temp = new intSLLNode(info, NULL);
      if(head == NULL)
      {
         head = temp;
         tail = temp;
      }
      tail->next = temp;
      tail = temp;
   }
   
   int deleteFromHead()
   {
      intSLLNode* oldHead = head;
      int tempInfo = oldHead->info;
      
      if (head == tail)
      {
         head = NULL;
         tail = NULL;
      }
      else
      {
         head = oldHead->next;
         oldHead->~intSLLNode();
      }
      
      return tempInfo;
      
   }
   int deleteFromTail()
   {
      intSLLNode* beforeTail = head;
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
         tail->~intSLLNode();
         tail = beforeTail;
         tail->next = NULL;
      }
   
      return tempInfo;
   }
   
   void deleteNode(int index)
   {
      if (index = 0)
      {
         deleteFromHead();
      }
      else
      {
         intSLLNode* toPop = head;
         intSLLNode* beforeToPop = toPop;
         for(int i = 0; i < index; i++)
         {
            beforeToPop = toPop;
            toPop = head->next;
         }
         if (toPop = tail)
         {
            deleteFromTail();
         }
         else
         {
            beforeToPop->next = toPop->next;
            toPop->~intSLLNode();
         }
      }
   }
   
   bool isInList(int compare) const
   {
      intSLLNode* searchPoint = head;
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
};

int main()
{

   intSLL mySLList;
   
   mySLList.addToTail(10);
   mySLList.addToTail(20);
   mySLList.addToTail(30);
   mySLList.addToHead(40);
   
   intSLLNode* temp = mySLList.getHead();
   while(temp != NULL)
   {
      cout << temp->info << " ";
      temp = temp->next;
   }
   
   cout << endl << "Deleting: " << mySLList.deleteFromHead() << " and " << mySLList.deleteFromTail() << endl;

   temp = mySLList.getHead();
   while(temp != NULL)
   {
      cout << temp->info << " ";
      temp = temp->next;
   }
   
   cout << endl << "Adding: 5 to head" << endl;
   mySLList.addToHead(5);
   
   temp = mySLList.getHead();
   while(temp != NULL)
   {
      cout << temp->info << " ";
      temp = temp->next;
   }
   
   cout << endl << "Deleting element at index 1 (10)" << endl;
   mySLList.deleteNode(1);
   
   temp = mySLList.getHead();
   while(temp != NULL)
   {
      cout << temp->info << " ";
      temp = temp->next;
   }
   
   cout << endl << "10 " << ((mySLList.isInList(10))? "is" : "is not") << " in the list" << endl;
   cout << endl << "20 " << ((mySLList.isInList(20))? "is" : "is not") << " in the list" << endl;
   
   cout << endl;
   
   return 0;
}
