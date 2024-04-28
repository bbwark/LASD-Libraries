
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data>
  {

  private:
  protected:
    using Vector<Data>::elements;
    using Vector<Data>::size;
    int head = 0;
    int tail = -1;
    unsigned long effectiveSize = 0;

  public:
    // Default constructor
    QueueVec();

    /* ************************************************************************ */

    // Specific constructor
    QueueVec(const TraversableContainer<Data> &container) : Vector<Data>(container){};
    QueueVec(MappableContainer<Data> &&container) : Vector<Data>(std::move(container)){};

    /* ************************************************************************ */

    // Copy constructor
    QueueVec(const QueueVec<Data> &);

    // Move constructor
    QueueVec(QueueVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~QueueVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    QueueVec &operator=(const QueueVec<Data> &);

    // Move assignment
    QueueVec &operator=(QueueVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const QueueVec<Data> &) const noexcept;
    bool operator!=(const QueueVec<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Queue)
    inline const Data &Head() const override;
    inline Data &Head() override;
    inline void Dequeue() override;
    inline Data HeadNDequeue() override;
    inline void Enqueue(const Data &) override;
    inline void Enqueue(Data &&) noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from Container)
    bool Empty() const noexcept override;

    unsigned long Size() const noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)
    void Clear() noexcept override;

  protected:
    void Resize();
    void Reduce();
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "queuevec.cpp"

#endif