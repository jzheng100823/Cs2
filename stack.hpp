#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>
#include <iostream>
////////////////////////////////////////////////////////////////////////////
//           


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//
template <typename T>
class Node{
public:
  T data;
  Node<T>*next;
  Node(): next(0){}
  Node(const T& n):data(n),next(0){};
};





    
template <typename T>
class stack {
public:
              stack     ();
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};

// default constructor
template <typename T>
stack<T>::stack(){
  tos=0;
}

//copy constructor
template <typename T>
stack<T>::stack(const stack<T>& stack2){
  Node<T> *temp=stack2.tos,*bottom=0;
  tos=0;
  while(temp!=0){
    if(tos==0){
      tos=new Node<T>(temp -> data);
      bottom=tos;
    }
    else{
      bottom->next=new Node<T>(temp->data);
      bottom=bottom->next;
    }
    temp=temp->next;
  }
}

// destructor
template <typename T>
stack<T>::~stack(){
  while(tos!=0){
   Node<T> *temp=tos;
   tos=tos -> next;
   delete temp;
  }
}
//swap function
template <typename T>
void stack<T>::swap(stack<T>& stack2){
  Node<T>* temp=tos;
  tos=stack2.tos;
  stack2.tos=temp;
}

//operator= overload 
template <typename T>
stack<T>& stack<T>::operator=(stack<T> stack2){
  swap(stack2);
  return *this;
}

//empty function
template <typename T>
bool stack<T>::empty()const {
  return tos==0;
}

//full function
template <typename T>
bool stack<T>::full()const {
  Node<T> *temp=new Node<T>();

  if(temp==0){
    return true;
  }
  delete temp;
  return false;
}


//top
template <typename T>
T stack<T>::top()const{
  return tos->data;
}
//pop function
template<typename T>
T stack<T>::pop(){
  Node<T>*temp=tos;
  T result=tos->data;
  tos=tos->next;
  delete temp;
  return result;
}
//push function
template <typename T>
void stack<T>::push(const T& elem){
  assert(!full());
  Node<T>*temp=new Node<T>(elem);
  temp->next=tos;
  tos=temp;
}
#endif
