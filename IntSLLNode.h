#ifndef INTSLLNODE_H
#define INTSLLNODE_H

using namespace std;

class IntSLLNode {
public:
   int info;
   IntSLLNode* next;
   IntSLLNode();
   IntSLLNode(int info, IntSLLNode* next);
   ~IntSLLNode();
};

#endif
