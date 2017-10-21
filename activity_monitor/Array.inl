// Ryan: Please include the Honor Pledge and Digital Signature in every file.
// Fixed : << Added pledge >>
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
size_t Array <T>::size (void) const
{
  return this->cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array <T>::max_size (void) const
{
  return this->max_size_;
}
