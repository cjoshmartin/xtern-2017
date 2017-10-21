// Honor Pledge:
 //
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

#ifndef BASE_ARRAY_H_
#define BASE_ARRAY_H_

#include <cstring>          // for size_t definition
#include <iostream>

// Ryan: A better approach here would be to create a Base BaseArray class
// and inherit from it. This will eliminate the problem in which the
// Fixed: << Array can inherit the resize function of this class. >>

/**
 * @class BaseArray
 *
 * Basic implementation of a standard BaseArray class for chars.
 */
template <typename T>
class BaseArray
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  BaseArray (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  BaseArray (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  BaseArray (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source BaseArray.
   */
  BaseArray (const BaseArray & arr);

  /// Destructor.
  ~BaseArray (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const BaseArray & operator = (const BaseArray & rhs);

  /**
   * Retrieve the current size of the BaseArray.
   *
   * @return          The current size
   */
  size_t size (void) const;

  /**
   * Retrieve the maximum size of the BaseArray.
   *
   * @return          The maximum size
   */
  size_t max_size (void) const;

  /**
   * Get the character at the specified index. If the index is not
   * within the range of the BaseArray, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
  T & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const T & operator [] (size_t index) const;

  /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the BaseArray, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
   */
  T get (size_t index) const;

  /**
   * Set the character at the specified \a index. If the \a index is not
   * within range of the BaseArray, then std::out_of_range exception is
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
   */
  void set (size_t index, T value);

  /**
   * Locate the specified character in the BaseArray. The index of the first
   * occurrence of the character is returned. If the character is not
   * found in the BaseArray, then -1 is returned.
   *
   * @param[in]        ch        Character to search for
   * @return           Index value of the character
   * @retval           -1        Character not found
   */
  int find (T element) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the BaseArray, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       ch                   Character to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Character not found
   * @exception       std::out_of_range    Invalid index
   */
  int find (T element, size_t start) const;

  /**
   * Test the BaseArray for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const BaseArray & rhs) const;

  /**
   * Test the BaseArray for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const BaseArray & rhs) const;

  /**
   * Fill the contents of the BaseArray.
   *
   * @param[in]       ch                   Fill character
   */
  void fill (T element);

  std::string toString();

protected:
  /// Pointer to the actual data.
  T * data_;

  /// Current size of the BaseArray.
  size_t cur_size_;

  /// Maximum size of the BaseArray.
  size_t max_size_;
};

//#include "Array.inl"
#include "BaseArray.cpp"

#endif   // !defined BASE_ARRAY_H_
