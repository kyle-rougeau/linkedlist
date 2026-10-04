#ifndef INTSLLNODE_H
#define INTSLLNODE_H

class IntSLLNode {
public:
   int info;
   IntSLLNode* next;
   IntSLLNode();
   IntSLLNode(int info, IntSLLNode* next);
   ~IntSLLNode();
};

#endif
