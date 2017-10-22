
// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//is_empty:  Test  if  the  queue  is  empty.  If  the  queue  is  empty,  then  this  method  returns  true.Otherwise, this method returns false.
//size: Returns the number of elements in the queue.
//
//
#ifndef QUEUE_H
#define QUEUE_H
// Ryan: We should allow our Queue to be dynamic not fixed.
// Fixed: << Queue now uses Array and not Fixed Array >>
//
#include "Array.h"
#include <exception>

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Queue is empty.
   */

  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void): std::exception () {}
  };
  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Push a new \a element onto the Queue. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
 /* enter new methods here */

 //enqueue: Adds the element to the end of the list.
  void enqueue(T element);

//dequeue: Removes the element at the front of the list. If there are not elements in the queue, this method throws empty_exception, similar to the stack.
  T dequeue(void);


  /**
   * Test if the Queue is empty
   *
   * @retval         true          The Queue is empty
   * @retval         false         The Queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Queue.
   *
   * @return         Size of the Queue.
   */
  size_t size (void) const;

  T end(void) const;

  T beginning(void) const;
  /// Remove all elements from the Queue.
  void clear (void);

void debug_queue(void) const;
private:
  // add member variable here
  Array<T> * queue_;
  size_t beginning_of_queue_, end_of_queue_;
  size_t size_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"
#endif
