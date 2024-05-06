
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class QueueLst : virtual public Queue<Data>, virtual protected List<Data>
  {

  private:
  protected:
    using List<Data>::size;
    using List<Data>::tail;
    using List<Data>::head;

  public:
    // Default constructor
    QueueLst() = default;

    /* ************************************************************************ */

    // Specific constructor
    QueueLst(const TraversableContainer<Data> &container) : List<Data>(container){};
    QueueLst(MappableContainer<Data> &&container) : List<Data>(std::move(container)){};

    /* ************************************************************************ */

    // Copy constructor
    QueueLst(const QueueLst<Data> &);

    // Move constructor
    QueueLst(QueueLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~QueueLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    QueueLst &operator=(const QueueLst<Data> &);

    // Move assignment
    QueueLst &operator=(QueueLst<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const QueueLst<Data> &) const noexcept;
    bool operator!=(const QueueLst<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Queue)
    inline const Data &Head() const override;
    inline Data &Head() override;
    inline void Dequeue() override;
    inline Data HeadNDequeue() override;
    inline void Enqueue(const Data &) override;
    inline void Enqueue(Data &&) noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    using List<Data>::Clear;

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "queuelst.cpp"

#endif