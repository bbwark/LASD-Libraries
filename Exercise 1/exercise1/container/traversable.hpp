
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class TraversableContainer : virtual public TestableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~TraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    TraversableContainer &operator=(const TraversableContainer &) = delete;

    // Move assignment
    TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;
    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const TraversableContainer &) const noexcept = delete;
    bool operator!=(const TraversableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using TraverseFun = std::function<void(const Data &)>;

    virtual void Traverse(TraverseFun traverseFun) = 0;

    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

    template <typename Accumulator>
    virtual Accumulator Fold(FoldFun<Accumulator> foldFun, Accumulator accumulator) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from TestableContainer)

    // type Exists(argument) specifiers; // Override TestableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderTraversableContainer
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~PreOrderTraversableContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename TraversableContainer<Data>::TraverseFun;

    // type PreOrderTraverse(arguments) specifiers;

    // template <typename Accumulator>
    // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    // template <typename Accumulator>
    // type PreOrderFold(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    // type Traverse(arguments) specifiers; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderTraversableContainer
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~PostOrderTraversableContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename TraversableContainer<Data>::TraverseFun;

    // type PostOrderTraverse(arguments) specifiers;

    // template <typename Accumulator>
    // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    // template <typename Accumulator>
    // type PostOrderFold(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    // type Traverse(arguments) specifiers; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderTraversableContainer
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~InOrderTraversableContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename TraversableContainer<Data>::TraverseFun;

    // type InOrderTraverse(arguments) specifiers;

    // template <typename Accumulator>
    // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    // template <typename Accumulator>
    // type InOrderFold(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    // type Traverse(arguments) specifiers; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthTraversableContainer
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~BreadthTraversableContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename TraversableContainer<Data>::TraverseFun;

    // type BreadthTraverse(arguments) specifiers;

    // template <typename Accumulator>
    // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    // template <typename Accumulator>
    // type BreadthFold(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    // type Traverse(arguments) specifiers; // Override TraversableContainer member
  };

  /* ************************************************************************** */

}

#include "traversable.cpp"

#endif
