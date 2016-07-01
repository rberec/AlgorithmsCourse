#pragma once

#include <stdlib.h>
#include <stdexcept>

template<typename T>
class Stack {
  
  public:
    
    // Create empty stack
    Stack() {};
    
    ~Stack();
    
    // insert new item to stack
    void insert(const T& item);
    
    // remove and return most recently added item
    T pop();
    
    // check if stack is empty
    bool isEmpty() { return first_ == nullptr;};
    
  private:
    
    // internal data container
    struct Node {
      T item_;
      Node* next_;
      
      Node(const T& item, Node* next):
	item_(item),
	next_(next)
      {};
    };
    
    Node* first_ = nullptr;
    size_t size_ = 0;
    
    // Forbid copy and assignment
    Stack(const Stack&);
    Stack& operator=(const Stack&);
  
};

template<typename T>
void Stack<T>::insert(const T& item) {
  first_ = new Node(item, first_);
  ++size_;
}

template<typename T>
T Stack<T>::pop() {
  
  if(isEmpty()) throw std::runtime_error("Empty stack.");
  
  Node* tmpNode = first_;
  T tmpItem(tmpNode->item_);
  delete tmpNode;
  
  first_ = first_->next_;
  --size_;
  
  return tmpItem;
}

template<typename T>
Stack<T>::~Stack() {
  Node* nextNode;
  for (Node* tmpNode = first_; tmpNode != nullptr; tmpNode = nextNode) {
      nextNode = tmpNode->next_;
      delete tmpNode;
  }
}
