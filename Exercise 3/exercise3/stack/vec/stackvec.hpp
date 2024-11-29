
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class StackVec : virtual public Stack<Data>, virtual protected Vector<Data>
  {
    // Must extend Stack<Data>,
    //             Vector<Data>

  private:
    // ...

  protected:
    // using Vector<Data>::???;
    using Vector<Data>::size;
    using Vector<Data>::elements;
    unsigned long index = 0;
    // ...

  public:
    // Default constructor
    // StackVec() specifier;

    StackVec() = default;

    /* ************************************************************************ */

    // Specific constructor
    // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
    // StackVec(argument) specifiers; // A stack obtained from a MappableContainer

    StackVec(const TraversableContainer<Data> &container) : Vector<Data>(container) {};
    StackVec(MappableContainer<Data> &&container) : Vector<Data>(std::move(container)) {};

    /* ************************************************************************ */

    // Copy constructor
    // StackVec(argument);

    StackVec(const StackVec<Data> &);

    // Move constructor
    // StackVec(argument);

    StackVec(StackVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~StackVec() specifier;

    ~StackVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument);

    StackVec &operator=(const StackVec &);

    // Move assignment
    // type operator=(argument);

    StackVec &operator=(StackVec &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const StackVec &) const noexcept;
    bool operator!=(const StackVec &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Stack)

    // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
    // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
    // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
    // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
    // type Push(argument) specifiers; // Override Stack member (copy of the value)
    // type Push(argument) specifiers; // Override Stack member (move of the value)

    const Data &Top() const override;
    Data &Top() override;
    void Pop() override;
    Data TopNPop() override;
    void Push(const Data &) override;
    void Push(Data &&) noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from Container)

    // type Empty() specifiers; // Override Container member

    bool Empty() const noexcept override;

    // type Size() specifiers; // Override Container member

    unsigned long Size() const noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    // type Clear() specifiers; // Override ClearableContainer member

    void Clear() override;

  protected:
    // Auxiliary functions, if necessary!
    void Resize();
    void Reduce();
  };

  /* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
