// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//

#define MAXSIZE 100
template <typename T>
Array <T>::Array (void) : BaseArray <T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) : BaseArray <T>(length)
{
}
//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill) : BaseArray <T>(length,fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array) : BaseArray <T>(array)
{
}
//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
}
//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    // std::cout << "******** T __ T *********** ~///~ VIOLENTLY RESIZES ~///~ ******** T __ T ************\n";
    if (new_size >0){ // check if size is greater then 0
        if( new_size > this->max_size_)
        { // not allowing them to have an array bigger then max size
            T * temp = new T[new_size];
            for(size_t i =0; i < this->cur_size_; i++)
                temp[i]= this->data_[i]; // for resizing the array than store it into something

            delete[] this->data_; // delete old data
            this->data_ = temp;
            this->max_size_ = new_size ; // new maxsize
            this->cur_size_ = new_size; // new current size;
        }
        this->cur_size_ = new_size; // resizes the function if the new size < cur_size_ the data will still exist but just cannot be accessed
    }
    else {
        throw std::out_of_range("invalid new size"); //throws exception
    }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
  if (this == &rhs)
              return true;
          for(size_t i =0; i < this->cur_size_; i++)
          {
            // goes through the array and check to see if they are not equal
              if( *(this->data_ + i) != *(rhs.data_ + i))
                  return false;
          }
      return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
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
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
  if(this == &rhs)
  {
    return *this;
  }
  delete[] this->data_;

  this->max_size_ = rhs.max_size_; // sets the new max size
  this->cur_size_ = rhs.max_size_; // sets the new cur_size_

  this->data_ = new T[this->cur_size_];

  for (size_t i = 0; i < rhs.size(); i++){
    this->data_[i] = rhs.data_[i];
  }

    return *this;

}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
// returns data from a given index
    
    return this->data_[index]; // can I make this immutable by passing it to the const version
}

//
// operator []
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
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
T Array <T>::get (size_t index) const
{
  if (index > this->cur_size_)
         throw std::out_of_range("cant not do that with a GET call");

     return this->data_[index]; // returns a char at a given point
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
  if(this->cur_size_ > index){
       // checks to seee if it is in range before setting it
          this->data_[index]=value;
      }
     else{
       this->resize(index);
       this->data_[index] = value;
     }
}
