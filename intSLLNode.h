#ifndef INTSLLNODE_H
#define INTSLLNODE_H

class intSLLNode {
public:
   int info;
   intSLLNode* next;
   intSLLNode();
   intSLLNode(int info, intSLLNode* next);
   ~intSLLNode();
};

#endif
