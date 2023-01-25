#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // g++ -g -Wall ulliststr.cpp test_ulliststr.cpp -o test_ulliststr
  ULListStr list;
	for(int count = 0; count < 4; ++count)
	{
		list.push_back("test");
    list.pop_back();
	}
  
  list.size();

  return 0;
}
