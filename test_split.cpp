/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;

	if(!content.empty())
	{
		// create head
		head = new Node(content[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(content.cbegin());
		++nextValIter;

		for(; nextValIter != content.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}
	}

	return head;

}

void deleteList(Node *list)
{
	Node * currElement = list;

	while(currElement != NULL)
	{
		Node * nextElement = currElement->next;

		cout << "deleting: " << currElement->value << endl;

		delete currElement;

		currElement = nextElement;
	}
}

void print(Node* list)
{
  Node* temp = list;

  while(temp != NULL)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }

	cout << endl;
}

int main(int argc, char* argv[])
{
  //initliaze list
  Node* odds = NULL;
  Node* evens = NULL;
  Node* in = makeList({1, 2 , 3 , 4, 5, 6, 7});
	cout << "pre split list: " << endl;
  print(in);
	cout << endl;

  split(in, odds, evens);

	cout << endl;
	cout << "odd list: " << endl;
  print(odds);
	cout << "even list: " << endl;
  print(evens);
	cout << endl;

  cout << "odd list: " << endl;
  deleteList(odds);
	cout << "even list: " << endl;
  deleteList(evens);

  return 0;
}
