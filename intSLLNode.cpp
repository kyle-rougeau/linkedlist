#include "intSLLNode.h"

using namespace std;

intSLLNode::intSLLNode()
{
}
intSLLNode::intSLLNode(int info, intSLLNode* next)
{
   this->info = info;
   this->next = next;
}
intSLLNode::~intSLLNode()
{
}
