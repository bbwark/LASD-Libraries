
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

  private:
  protected:
    using Vector<Data>::size;
    using Vector<Data>::elements;
    unsigned long index = 0;

  public:
    // Default constructor
    StackVec() = default;

    /* ************************************************************************ */

    // Specific constructor
    StackVec(const TraversableContainer<Data> &container) : Vector<Data>(container){};
    StackVec(MappableContainer<Data> &&container) : Vector<Data>(std::move(container)){};

    /* ************************************************************************ */

    // Copy constructor
    StackVec(const StackVec<Data> &);

    // Move constructor
    StackVec(StackVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~StackVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    StackVec &operator=(const StackVec &);

    // Move assignment
    StackVec &operator=(StackVec &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const StackVec &) const noexcept;
    bool operator!=(const StackVec &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Stack)
    const Data &Top() const override;
    Data &Top() override;
    void Pop() override;
    Data TopNPop() override;
    void Push(const Data &) override;
    void Push(Data &&) noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from Container)
    bool Empty() const noexcept override;

    unsigned long Size() const noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)
    void Clear() noexcept override;

  protected:
    // Auxiliary functions, if necessary!
    void Resize();
    void Reduce();
  };

  /* ************************************************************************** */

}

#include "stackvec.cpp"

#endif