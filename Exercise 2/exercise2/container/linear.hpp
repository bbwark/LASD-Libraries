
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
    using Container::size;

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

    virtual void Traverse(TraverseFun traverseFun) const override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    virtual void PreOrderTraverse(TraverseFun traverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    virtual void PostOrderTraverse(TraverseFun traverseFun) const override; // Override PostOrderTraversableContainer member

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
  class SortableLinearContainer : virtual public LinearContainer<Data>
  {

  private:
  protected:
    using Container::size;

  public:
    // Destructor
    virtual ~SortableLinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    SortableLinearContainer &operator=(const SortableLinearContainer &) = delete;

    // Move assignment
    SortableLinearContainer &operator=(SortableLinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const SortableLinearContainer &) const noexcept;
    bool operator!=(const SortableLinearContainer &) const noexcept;

    /* ************************************************************************ */

    // Specific member function

    virtual void Sort();

  protected:
    void QuickSort(unsigned long start, unsigned long end);
    unsigned long Partition(unsigned long start, unsigned long end);
  };

  /* ************************************************************************** */

}

#include "linear.cpp"

#endif
