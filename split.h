#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }

  //my default
  Node()
  {
    value = 0;
    next = nullptr;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);
void doSplit(Node*& in, Node*& odds, Node*& evens);

#endif
