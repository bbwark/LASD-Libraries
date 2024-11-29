
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual protected List<Data>{
  // Must extend Queue<Data>,
  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;
  using List<Data>::tail;
  using List<Data>::head;
  // ...

public:

  // Default constructor
  // QueueLst() specifier;

  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A stack obtained from a TraversableContainer
  // QueueLst(argument) specifiers; // A stack obtained from a MappableContainer

  QueueLst(const TraversableContainer<Data> &container) : List<Data>(container){};
  QueueLst(MappableContainer<Data> &&container) : List<Data>(std::move(container)){};

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);

  QueueLst(const QueueLst<Data> &);

  // Move constructor
  // QueueLst(argument);

  QueueLst(QueueLst<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;

  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  QueueLst &operator=(const QueueLst<Data> &);

  // Move assignment
  // type operator=(argument);

  QueueLst &operator=(QueueLst<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const QueueLst<Data> &) const noexcept;
  bool operator!=(const QueueLst<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)

  inline const Data &Head() const override;
  inline Data &Head() override;
  inline void Dequeue() override;
  inline Data HeadNDequeue() override;
  inline void Enqueue(const Data &) override;
  inline void Enqueue(Data &&) noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
  // Forse void Clear() override?
  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
