
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Queue : virtual public ClearableContainer
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~Queue() = 0;

    /* ************************************************************************ */

    // Copy assignment
    Queue<Data> &operator=(const Queue<Data> &) = delete;

    // Move assignment
    Queue<Data> &operator=(Queue<Data> &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Data &) const noexcept = delete;
    bool operator!=(const Data &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &Head() const = 0;   // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual Data &Head() = 0;               // (mutable version; concrete function must throw std::length_error when empty)
    virtual void Dequeue() = 0;             // (concrete function must throw std::length_error when empty)
    virtual Data HeadNDequeue() = 0;        // (concrete function must throw std::length_error when empty)
    virtual void Enqueue(const Data &) = 0; // Copy of the value
    virtual void Enqueue(Data &&) = 0;      // Move of the value
  };

  /* ************************************************************************** */

}

#endif
