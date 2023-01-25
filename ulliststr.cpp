#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  //size_ = 0; original
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

//-------------------WRITE YOUR CODE HERE------------------//


void ULListStr::printAll() const
{
  Item* curr = head_;

  while(curr != NULL)
  {
    //logic for print each value
    for(size_t i = curr->first; i < curr->last; i++)
    {
      std::cout << curr->val[i];
    }

    //iterate through
    curr = curr->next;
  }
}

void ULListStr::push_back(const std::string& val)
{
  //increment size
  size_++;

  //first item is not initialized
  if(head_ == NULL)
  {
    //allocate new item
    Item* curr = new Item();

    //fill in val index
    curr->val[curr->first] = val;

    //update last
    curr->last++;

    //deal with pointers and initialize
    curr->prev = NULL;
    curr->next = NULL;
    head_ = curr;
    tail_ = curr;
  }

  else
  {
    //need new node
    if(tail_->last == ARRSIZE)
    {
      //allocate new neode
      Item* curr = new Item();
      curr->val[curr->first] = val;
      curr->last++;
      curr->prev = tail_;
      tail_->next = curr;
      tail_ = curr;
    }

    //regular case
    else
    {
      tail_->val[tail_->last] = val;
      //update last
      tail_->last++;
    }
    
  }
}

void ULListStr::push_front(const std::string& val)
{
  //increment size
  size_++;

  //first item is not initialized
  if(head_ == NULL)
  {
    //allocate new item
    Item* curr = new Item();

    //fill in val index
    curr->val[curr->first] = val;

    //update last
    curr->last++;

    //deal with pointers and initialize
    curr->prev = NULL;
    curr->next = NULL;
    head_ = curr;
    tail_ = curr;
  }

  else
  {
    //need new node
    if(head_->first == 0)
    {
      //allocate new node
      Item* curr = new Item();

      //fill in array
      curr->val[ARRSIZE - 1] = val;
      curr->last = ARRSIZE;
      curr->first = ARRSIZE - 1;
      curr->next = head_;
      head_->prev = curr;
      head_ = curr;
      
    }

    //regular case
    else
    {
      head_->val[head_->first - 1] = val;
      head_->first--;
    }
    
  }

}


void ULListStr::pop_back()
{
  //ensure there is something to pop
  if(tail_ == NULL)
  {
    return;
  }

  //store tail into temp
  Item* curr = tail_;
  size_--;

  //regular case
  curr->val[curr->last - 1] = "";
  curr->last--;

  //delete item case
  if(curr->first == curr->last)
  {
    if(tail_ == head_)
    {
      head_ = NULL;
      tail_ = NULL;
    }
    else
    {
      tail_ = tail_->prev;
      delete curr;
    }
  }
}

void ULListStr::pop_front()
{
  //ensure there is something to pop
  if(head_ == NULL)
  {
    return;
  }

  //store tail into temp
  Item* curr = head_;
  size_--;

  //regular case
  curr->val[curr->first] = "";
  curr->first++;

  //delete item case
  if(curr->first == curr->last)
  {
    if(tail_ == head_)
    {
      head_ = NULL;
      tail_ = NULL;
    }
    else
    {
      head_ = head_->next;
      delete curr;
    }
  }
}

//need to determine way to get all the content, not just one char
std::string const& ULListStr::front() const
{
  return head_->val[head_->first];
}

//need to determine way to get all the content, not just one char
std::string const& ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t index = 0;
  Item* curr = head_;

  while(curr != NULL)
  {
    //look through the entire array
    for(size_t i = curr->first; i < curr->last; i++)
    {
      //if location exists
      if(loc == index)
      {
        return &curr->val[i];
      }

      index++;
    }

    //did not find in the array traverse into next node
    curr = curr->next;
  }
  
  return NULL;
}

//--------------------------------------------------------//

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
