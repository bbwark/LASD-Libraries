
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
    Stack &operator=(const Stack<Data> &) = delete;

    // Move assignment
    Stack &operator=(Stack<Data> &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Stack<Data> &) const noexcept = delete;
    bool operator!=(const Stack<Data> &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions
    virtual const Data &Top() const = 0;
    virtual Data &Top() = 0;
    virtual void Pop() = 0;
    virtual Data TopNPop() = 0;
    virtual void Push(const Data &) = 0;
    virtual void Push(Data &&) noexcept = 0;
  };

  /* ************************************************************************** */

}

#endif