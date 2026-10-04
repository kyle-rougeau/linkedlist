#include "IntSLLNode.h"

using namespace std;

IntSLLNode::IntSLLNode()
{
}
IntSLLNode::IntSLLNode(int info, IntSLLNode* next)
{
   this->info = info;
   this->next = next;
}
IntSLLNode::~IntSLLNode()
{
}
