#include "IntSLLNode.h"

using namespace std;

class IntSLL {
private:
   IntSLLNode* head = NULL;
   IntSLLNode* tail = NULL;
public:
   IntSLLNode* getHead();
   
   IntSLLNode* getTail();
   
   void addToHead(int info);
   void addToTail(int info);
   
   int deleteFromHead();
   int deleteFromTail();
   
   int deleteNode(int index);
   
   bool isInList(int compare) const;
   
   void disp();
};
