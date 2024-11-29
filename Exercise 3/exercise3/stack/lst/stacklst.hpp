
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class StackLst : virtual public Stack<Data>, virtual protected List<Data>
  {
    // Must extend Stack<Data>,
    //             List<Data>

  private:
    // ...

  protected:
    // using List<Data>::???;
    using List<Data>::size;
    using List<Data>::head;
    // ...

  public:
    // Default constructor
    // StackLst() specifier;

    StackLst() = default;

    /* ************************************************************************ */

    // Specific constructor
    // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
    // StackLst(argument) specifiers; // A stack obtained from a MappableContainer

    StackLst(const TraversableContainer<Data> &container) : List<Data>(container) {};
    StackLst(MappableContainer<Data> &&container) : List<Data>(std::move(container)) {};

    /* ************************************************************************ */

    // Copy constructor
    // StackLst(argument);

    StackLst(const StackLst<Data> &);

    // Move constructor
    // StackLst(argument);

    StackLst(StackLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~StackLst() specifier;

    ~StackLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument);

    StackLst &operator=(const StackLst<Data> &);

    // Move assignment
    // type operator=(argument);

    StackLst &operator=(StackLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const StackLst<Data> &) const noexcept;
    bool operator!=(const StackLst<Data> &) const noexcept;
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

    // Specific member function (inherited from ClearableContainer)

    // using List<Data>::Clear;
    // Forse void Clear() override?
    using List<Data>::Clear;

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
