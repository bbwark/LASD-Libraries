
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

  private:
  protected:
    using List<Data>::size;
    using List<Data>::head;

  public:
    // Default constructor
    StackLst() = default;

    /* ************************************************************************ */

    // Specific constructor
    StackLst(const TraversableContainer<Data> &container) : List<Data>(container){};
    StackLst(MappableContainer<Data> &&container) : List<Data>(std::move(container)){};

    /* ************************************************************************ */

    // Copy constructor
    StackLst(const StackLst<Data> &);

    // Move constructor
    StackLst(StackLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~StackLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    StackLst &operator=(const StackLst<Data> &);

    // Move assignment
    StackLst &operator=(StackLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const StackLst<Data> &) const noexcept;
    bool operator!=(const StackLst<Data> &) const noexcept;
    /* ************************************************************************ */

    // Specific member functions (inherited from Stack)
    const Data &Top() const override;
    Data &Top() override;
    void Pop() override;
    Data TopNPop() override;
    void Push(const Data &) override;
    void Push(Data &&) noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)
    using List<Data>::Clear;

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "stacklst.cpp"

#endif