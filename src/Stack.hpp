#pragma once

#include <stdlib.h>

template<typename T>
class Stack {
  
  public:
    
    // Create empty stack
    Stack() {};
    
    // insert new item to stack
    void insert(const T& item) {};
    
    // remove and return most recently added item
    T pop() {};
    
    // check if stack is empty
    bool isEmpty() {};
    
  
  // Forbid copy and assignment
  private:
    
    size_t size();
    
    Stack(const Stack&);
    Stack& operator=(const Stack&);
  
};