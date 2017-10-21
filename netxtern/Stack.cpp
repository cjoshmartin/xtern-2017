#include <iostream>
// Stack
//
template <typename T>
Stack <T>::Stack (void)
{
 stack_ = new Array<T>(1);
 stack_pointer_=-1;
}

// Ryan: You should use an initialization list here and copy the stack.stack_
// from one Stack to the other.
//fixed : << I use just initialization list
//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: stack_(stack.stack_), stack_pointer_(stack.size())
{}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
   // delete[] stack_;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// Ryan: This will become unnecessary once the change to an Array is made.
    if( (this->size() ==  stack_pointer_))
      stack_->resize((this->size()+1)); // resized the array each time

	  // Ryan: You will need to resize though.
    // Fixed: << Resizes >>
  stack_->set(++stack_pointer_, element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{

  //if(this->is_empty()){
              //// Ryan: You should throw the empty exception here.
    //// Fixed: << I call the empty_exception constructor here >>
    //throw Stack::empty_exception();
    //stack_pointer_=-1;}
  //else
    --stack_pointer_;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
 if(this == &rhs)
  return *this;

	// Ryan: Here you should just assign the rhs.stack_ to the lhs.
  // Fixed: << I think I fixed it >>

  this-> stack_pointer_ = rhs.size();
  for (size_t i =stack_pointer_; i > 0; i--)
  {
    this->stack_[i] = rhs.stack_[i];
  }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{// set numbers of elemets to -1 because data in stack will now overwritten
	// Ryan: Here you should just resize the stack_ to 0.
  // fixed: << resized stack >>
  stack_->resize(1);
  this->stack_pointer_ = -1;
}
