
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::elements;
  using Vector<Data>::size;
  ulong head = 0;
  ulong tail = 0;
  // ...

public:

  // Default constructor
  // QueueVec() specifier;

  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer

  QueueVec(const TraversableContainer<Data> &);
  QueueVec(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);

  QueueVec(const QueueVec<Data> &);

  // Move constructor
  // QueueVec(argument);

  QueueVec(QueueVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;

  ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  QueueVec &operator=(const QueueVec<Data> &);

  // Move assignment
  // type operator=(argument);

  QueueVec &operator=(QueueVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const QueueVec<Data> &) const noexcept;
  bool operator!=(const QueueVec<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)

  const Data &Head() const override;
  Data &Head() override;
  void Dequeue() override;
  Data HeadNDequeue() override;
  void Enqueue(const Data &) override;
  void Enqueue(Data &&) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member

  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member

  ulong Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

protected:

  void Resize();
  void Reduce();
  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
