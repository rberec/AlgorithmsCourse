#pragma once

#include <stdlib.h>

template<typename T>
class Stack {
  
  public:
    
    // Create empty stack
    Stack();
    
    // insert new item to stack
    void insert(const T& item) {};
    
    // remove and return most recently added item
    T pop() {};
    
    // check if stack is empty
    bool isEmpty() {};
    
  private:
    
    struct Node {
      T item_;
      Node* next_;
      
      Node(const T& item, Node* next):
	item_(item),
	next_(next)
      {};
    };
    
    Node* first_ = nullptr;
    size_t size = 0;
    
    // Forbid copy and assignment
    Stack(const Stack&);
    Stack& operator=(const Stack&);
  
};

template<typename T>
Stack::Stack():
first_(nullptr)
{
  
}
