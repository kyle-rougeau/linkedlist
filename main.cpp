#include <iostream>
#include "IntSLList.h"

using namespace std;

int main()
{

   IntSLL mySLList;
   
   mySLList.addToTail(10);
   mySLList.addToTail(20);
   mySLList.addToTail(30);
   mySLList.addToHead(40);
   
   mySLList.disp();
   
   cout << endl << "Deleting: " << mySLList.deleteFromHead() << " and " << mySLList.deleteFromTail() << endl;

   mySLList.disp();
   
   cout << endl << "Adding: 5 to head" << endl;
   mySLList.addToHead(5);
   
   mySLList.disp();
   
   cout << endl << "Deleting element at index 1 (10)" << endl;
   mySLList.deleteNode(1);
   
   mySLList.disp();
   
   cout << endl << "10 " << ((mySLList.isInList(10))? "is" : "is not") << " in the list" << endl;
   cout << endl << "20 " << ((mySLList.isInList(20))? "is" : "is not") << " in the list" << endl;
   
   cout << endl;
   
   mySLList.deleteNode(10);
   
   mySLList.deleteFromHead();
   mySLList.deleteFromTail();
   mySLList.deleteFromHead();
   mySLList.deleteFromTail();
   
   mySLList.disp();
   
   return 0;
}
