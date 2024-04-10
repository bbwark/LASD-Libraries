
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class LinearContainer : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~LinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    LinearContainer &operator=(const LinearContainer &) = delete;

    // Move assignment
    LinearContainer &operator=(LinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const LinearContainer &) const noexcept;
    bool operator!=(const LinearContainer &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &operator[](ulong) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
    virtual Data &operator[](ulong) = 0;             // (mutable version; concrete function must throw std::out_of_range when out of range)

    virtual const Data &Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual Data &Front();             // (mutable version; concrete function must throw std::length_error when empty)

    virtual const Data &Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual Data &Back();             // (mutable version; concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    virtual void Traverse(TraverseFun traverseFun) override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    virtual void PreOrderTraverse(TraverseFun traverseFun) override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    virtual void PostOrderTraverse(TraverseFun traverseFun) override; // Override PostOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    virtual void Map(MapFun mapFun) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    virtual void PreOrderMap(MapFun mapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    virtual void PostOrderMap(MapFun mapFun) override; // Override PostOrderMappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class SortableLinearContainer
  {
    // Must extend LinearContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~SortableLinearContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not be possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

    /* ************************************************************************ */

    // Specific member function

    // type Sort() specifiers;

  protected:
    // Auxiliary member functions

    // ...
  };

  /* ************************************************************************** */

}

#include "linear.cpp"

#endif
