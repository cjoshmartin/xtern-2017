
// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart


template <typename T>
inline
size_t Queue<T>::size(void) const
{
  return size_;
}


template <typename T>
inline
bool Queue<T>::is_empty(void) const
{
  return this->size() == 0;
}


template <typename T>
inline
T Queue<T>::beginning(void) const
{
  return queue_->get(beginning_of_queue_);
}


template <typename T>
inline
T Queue<T>::end(void) const
{
  return queue_->get(end_of_queue_-1);
}
template <typename T>
inline
void Queue<T>::debug_queue(void) const
{
  std::cout << "[" ;
 for(size_t i = 0; i < queue_->size(); i++)
  (i < queue_->size() -1 ) ? std::cout << (*queue_)[i]<< ", " : std::cout << (*queue_)[i];
      std::cout<< "]\n " << std::endl;
}
