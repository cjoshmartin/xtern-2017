
// Ryan: Please include the Honor Pledge and Digital Signature in every file.
// Fixed: << added Honor Pledge >>
// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
 return stack_pointer_+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
  return (*stack_)[stack_pointer_]; //
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
  return stack_pointer_ <= 0;
}

template <typename T>
inline
void Stack<T>::debug_stack(void) const
{
  std::cout << "[" ;
 for(size_t i = 0; i < stack_->size(); i++)
  (i < stack_->size() -1 ) ? std::cout << (*stack_)[i]<< ", " : std::cout << (*stack_)[i];
      std::cout<< "] " << std::endl;
}
