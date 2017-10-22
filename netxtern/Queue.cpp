
// Ryan: Please include the Honor Pledge and Digital Signature in every file.
// Fixed: << Added The Honor Pledge >>
//
// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

// Ryan: You should use an initialization list here.
// Fixed: <<Change to a Initialization List >>
//
template <typename T>
Queue <T>::Queue (void) : queue_(new Array<T>()),beginning_of_queue_(0),end_of_queue_(0), size_(0)
{}

// Ryan: You should copy the contents of the queue_ from one Queue
// to another via an initialization list.
// Fixed: << Changed to a initialization list >>
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
 : queue_(queue.queue_), size_(queue.size_), beginning_of_queue_(queue.beginning_of_queue_), end_of_queue_(queue.end_of_queue_)
{}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    //delete queue_;
}

template <typename T>
void Queue<T>::enqueue(T element) {

// Ryan: The queue should not be full - it can be resized.
// Fixed: << the queue will not be full >>
       this->size_++;
       if(size_>= queue_->max_size()) // check the size of the queue and will resize
            queue_->resize((this->size_));

      queue_->set(end_of_queue_++,element); // will put an item at the end of the list
}


// Ryan: Why is this function not templated?
// Fixed: << Changed to a templated function >>
//
template <typename T>
T Queue<T>::dequeue(void){

  if(is_empty())
    throw Queue::empty_exception(); // throws an empty exception if the array is empty

    this->size_--;
    return this->queue_->get(beginning_of_queue_++); // else will grab an item at the beggining of the list
}
//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	// Ryan: What about queue_ here?
  // Fixed: << resized queue_ >> 
  queue_->resize(1);
  beginning_of_queue_ =end_of_queue_ = size_ = 0; // all data in queue will still exist but will be written over
}

template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
 if(this == &rhs)
  return *this;

  size_ = rhs.size();

  beginning_of_queue_ = rhs.beginning_of_queue_;
  end_of_queue_ = rhs.end_of_queue_;

  for (size_t i = rhs.size() ; i > 0; i--)
  {
    queue_[i] = rhs.queue_[i];
  }
}
