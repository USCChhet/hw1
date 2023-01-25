/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;
void doSplit(Node*& in, Node*& odds, Node*& evens)
{
  if(in == NULL)
  {
    return;
  }

  int value = in->value;

  //determine if odd or even
  if(value % 2 == 0)
  {
    //cout << "this is value: " << value << endl;
    //cout << "adding onto even: "<< value << endl; 
    //cout << endl;
    //recursive call
    evens = in;  
    doSplit(in->next, odds, evens->next); 
  }

  else if(value % 2 != 0)
  {
    //cout << "this is value: " << value << endl;
    //cout << "adding onto odd: " << value << endl;
    //cout << endl;
    //recursive call
    odds = in;
    doSplit(in->next, odds->next, evens);
  }

  //ensure that even node and odd node does not point to same thing
  if(odds == evens)
  {
    //cout << "found something" << endl;
    if(evens->value % 2 != 0)
    {
      evens = NULL;
    }

    else
    {
      odds = NULL;
    }
  }
}

void split(Node*& in, Node*& odds, Node*& evens)
{
  doSplit(in, odds, evens);
  in = NULL;
}