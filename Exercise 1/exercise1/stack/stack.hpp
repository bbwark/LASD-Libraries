
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Stack : virtual public ClearableContainer
  {

  private:
  protected:
  public:
    // Destructor
    ~Stack() = default;

    /* ************************************************************************ */

    // Copy assignment
    Stack<Data> &operator=(const Stack<Data> &) = delete;

    // Move assignment
    Stack<Data> &operator=(Stack<Data> &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Stack<Data> &) const noexcept = delete;
    bool operator!=(const Stack<Data> &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &Top() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual Data &Top() = 0;             // (mutable version; concrete function must throw std::length_error when empty)
    virtual void Pop() = 0;              // (concrete function must throw std::length_error when empty)
    virtual Data TopNPop() = 0;          // (concrete function must throw std::length_error when empty)
    virtual Data Push(const Data &) = 0; // Copy of the value
    virtual Data Push(Data &&) = 0;     // Move of the value
  };

  /* ************************************************************************** */

}

#endif
