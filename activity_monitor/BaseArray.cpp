// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

#include "BaseArray.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//

#define MAXSIZE 100
template <typename T>
BaseArray <T>::BaseArray (void) : data_( new T[MAXSIZE]), cur_size_(1), max_size_(MAXSIZE)
{

}

//
// BaseArray (size_t)
//
template <typename T>
BaseArray <T>::BaseArray (size_t length)
: max_size_(MAXSIZE), data_(new T[MAXSIZE])
{
       (length > 0) ? this->cur_size_ = length : throw std::out_of_range("Not allowed to use negitive numbers") ; // choose to let lenght be the current size
}

//
// BaseArray (size_t, char)
//
template <typename T>
BaseArray <T>::BaseArray (size_t length, T fill)
: max_size_(MAXSIZE), data_(new T[MAXSIZE])
{
       (length > 0) ? this->cur_size_ = length : throw std::out_of_range("Not allowed to use negitive numbers") ; // choose to let lenght be the current size
       this->fill(fill);
}

//
// BaseArray (const BaseArray &)
//
template <typename T>
BaseArray <T>::BaseArray (const BaseArray & array)
: max_size_(array.max_size_), cur_size_(array.cur_size_), data_(new T[MAXSIZE])
{
    for(size_t i =0; i< array.cur_size_; i++)
        this->data_[i]=array.data_[i];
}

//
// ~BaseArray
//
template <typename T>
BaseArray <T>::~BaseArray (void)
{
  delete[] data_;
}

//
// operator =
//
template <typename T>
const BaseArray <T> & BaseArray <T>::operator = (const BaseArray & rhs)
{
  if(this == &rhs)
  {
    return *this;
  }

  delete[] data_;

  this->max_size_ = rhs.max_size_; // sets the new max size
  this->cur_size_ = rhs.max_size_; // sets the new cur_size_

  data_ = new T[this->cur_size_];

  for (size_t i = 0; i < rhs.size(); i++)
    this->data_[i] = rhs.data_[i];

    return *this;

}

//
// operator []
//
template <typename T>
T & BaseArray <T>::operator [] (size_t index)
{
// returns data from a given index
    if(this->cur_size_ < index)
    {
        throw std::out_of_range("Out of range.");
    }
    return this->data_[index]; // can I make this immutable by passing it to the const version
}

//
// operator []
//
template <typename T>
const T & BaseArray <T>::operator [] (size_t index) const
{
 if(this->cur_size_ < index )
    {
        throw std::out_of_range("Out of range.");
    }
    return this->data_[index];
}

//
// get
//
template <typename T>
T BaseArray <T>::get (size_t index) const
{
  if (index > this->cur_size_)
         throw std::out_of_range("cant not do that with a GET call");

     return data_[index]; // returns a char at a given point
}

//
// set
//
template <typename T>
void BaseArray <T>::set (size_t index, T value)
{
  if(this->cur_size_ > index){
       // checks to seee if it is in range before setting it
          data_[index]=value;
      }
     else{
         throw std::out_of_range("index is out of range");
     }
}

//
// find (char)
//
template  <typename T>
int BaseArray <T>::find (T value) const
{
      return this->find(value, 0);
}

//
// find (char, size_t)
//
template <typename T>
int BaseArray <T>::find (T val, size_t start) const
{
    if(start > this->cur_size_)
        throw std::out_of_range("start is out of range");

    // starts searching at a given point if not found returns negitive 1
    for(int i = start; i< cur_size_; i++)
    {
        if (data_[i]==val)
            return i;

    }
        return -1;
}

//
// operator ==
//
template <typename T>
bool BaseArray <T>::operator == (const BaseArray & rhs) const
{
  if (this == &rhs)
              return true;
          for(size_t i =0; i < this->cur_size_; i++)
          {
            // goes through the BaseArray and check to see if they are not equal
              if( *(this->data_ + i) != *(rhs.data_ + i))
                  return false;
          }
      return true;
}

//
// operator !=
//
template <typename T>
bool BaseArray <T>::operator != (const BaseArray & rhs) const
{
	// Ryan: We could actually use the above function here - negated.
  // Josh: How? or Why?

if (this == &rhs) // check to see if they are already equal
            return true;

        for(size_t i =0; i < this->cur_size_; i++)
        {
            if( *(this->data_ + i) != *(rhs.data_ + i))
                return true;
        }
    return false;
}

//
// fill
//
template <typename T>
void BaseArray <T>::fill (T value)
{
  for (int i= 0; i< cur_size_; i++){
         data_[i] = value;
     }
}

template <typename T>
size_t BaseArray<T>::size(void) const
{
  return cur_size_;
}
template <typename T>
size_t BaseArray<T>::max_size(void) const
{
  return max_size_;
}
