
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stackVec.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTree : virtual public PreOrderTraversableContainer<Data>, virtual public PostOrderTraversableContainer<Data>, virtual public InOrderTraversableContainer<Data>, virtual public BreadthTraversableContainer<Data>
  {

  private:
  protected:
    using Container::size;

  public:
    struct Node
    {

    protected:
      // Comparison operators
      bool operator==(const Node &) const noexcept; // Comparison of abstract types is possible, but is not visible.
      bool operator!=(const Node &) const noexcept; // Comparison of abstract types is possible, but is not visible.

    public:
      friend class BinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      virtual ~Node() = default;

      /* ********************************************************************** */

      // Copy assignment
      Node &operator=(const Node &) = delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      Node &operator=(Node &&) noexcept = delete; // Move assignment of abstract types is not possible.

      /* ********************************************************************** */

      // Specific member functions

      virtual const Data &Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

      virtual bool IsLeaf() const noexcept = 0;        // (concrete function should not throw exceptions)
      virtual bool HasLeftChild() const noexcept = 0;  // (concrete function should not throw exceptions)
      virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

      virtual const Node &LeftChild() const = 0;  // (concrete function must throw std::out_of_range when not existent)
      virtual const Node &RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    };

    /* ************************************************************************ */

    // Destructor
    virtual ~BinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    BinaryTree &operator=(const BinaryTree &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    BinaryTree &operator=(BinaryTree &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.
    bool operator!=(const BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.

    /* ************************************************************************ */

    // Specific member functions

    virtual const Node &Root() const = 0; // (concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    virtual void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    virtual void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderTraversableContainer)

    virtual void InOrderTraverse(TraverseFun) const override; // Override InOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthTraversableContainer)

    virtual void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

  protected:
    void Traverse(const Node &, const TraverseFun &) const;
    void PostOrderTraverse(const Node &, const TraverseFun &) const;
    void InOrderTraverse(const Node &, const TraverseFun &) const;
    // void BreadthTraverse(const Node &, const TraverseFun&) const;
    bool comparison(const Node &a, const Node &b) const noexcept;
  };

  /* ************************************************************************** */

  template <typename Data>
  class MutableBinaryTree : virtual public ClearableContainer, virtual public BinaryTree<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>, virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data>
  {
  private:
  protected:
    using Container::size;

    using typename BinaryTree<Data>::Node;

  public:
    struct MutableNode : Node
    {

      friend class MutableBinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      virtual ~MutableNode() = default;

      /* ********************************************************************** */

      // Copy assignment
      MutableBinaryTree &operator=(const MutableBinaryTree &) = delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      MutableBinaryTree &operator=(MutableBinaryTree<Data> &) noexcept = delete; // Move assignment of abstract types is not possible.

      /* ********************************************************************** */

      // Specific member functions

      virtual Data &Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

      virtual MutableNode &LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
      virtual MutableNode &LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    };

    /* ************************************************************************ */

    // Destructor
    virtual ~MutableBinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    MutableBinaryTree &operator=(const MutableBinaryTree &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    MutableBinaryTree &operator=(MutableBinaryTree<Data> &) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member functions

    virtual MutableNode &Root() = 0; // (concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    virtual void Map(MapFun) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    virtual void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    virtual void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderMappableContainer)

    virtual void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthMappableContainer)

    virtual void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

  protected:
    void Map(const Node &, const MapFun &);
    void PostOrderMap(const Node &, const MapFun &);
    void InOrderMap(const Node &, const MapFun &);
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {

  private:
  protected:
    using typename BinaryTree<Data>::Node;
    Node *node = nullptr;
    StackVec<const Node &> stack;

  public:
    // Specific constructors
    BTPreOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderIterator(const BTPreOrderIterator &);

    // Move constructor
    BTPreOrderIterator(BTPreOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPreOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderIterator &operator=(const BTPreOrderIterator &);

    // Move assignment
    BTPreOrderIterator &operator=(BTPreOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPreOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTPreOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override; // (throw std::out_of_range when terminated)

    bool Terminated() noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    BTPreOrderIterator &operator++() override; // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data>
  {

  private:
  protected:
    using BTPreOrderIterator<Data>::stack;

  public:
    // Specific constructors
    BTPreOrderMutableIterator(MutableBinaryTree<Data> &); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderMutableIterator(const BTPreOrderMutableIterator &);

    // Move constructor
    BTPreOrderMutableIterator(BTPreOrderMutableIterator &&);

    /* ************************************************************************ */

    // Destructor
    ~BTPreOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator &);

    // Move assignment
    BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPreOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTPreOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    Data &operator*() override; // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {

  private:
  protected:
    using typename BinaryTree<Data>::Node;
    Node *node = nullptr;
    StackVec<const Node &> stack;

  public:
    // Specific constructors
    BTPostOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderIterator(const BTPostOrderIterator &);

    // Move constructor
    BTPostOrderIterator(BTPostOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPostOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderIterator &operator=(const BTPostOrderIterator &);

    // Move assignment
    BTPostOrderIterator &operator=(BTPostOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPostOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTPostOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override; // (throw std::out_of_range when terminated)

    bool Terminated() noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    BTPostOrderIterator &operator++() override; // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>
  {

  private:
  protected:
    using BTPostOrderIterator<Data>::stack;

  public:
    // Specific constructors
    BTPostOrderMutableIterator(MutableBinaryTree<Data> &); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderMutableIterator(const BTPostOrderMutableIterator &);

    // Move constructor
    BTPostOrderMutableIterator(BTPostOrderMutableIterator &&);

    /* ************************************************************************ */

    // Destructor
    ~BTPostOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator &);

    // Move assignment
    BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPostOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTPostOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    Data &operator*() override; // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {

  private:
  protected:
    using typename BinaryTree<Data>::Node;
    Node *node = nullptr;
    StackVec<const Node &> stack;

  public:
    // Specific constructors
    BTInOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderIterator(const BTInOrderIterator &);

    // Move constructor
    BTInOrderIterator(BTInOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTInOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderIterator &operator=(const BTInOrderIterator &);

    // Move assignment
    BTInOrderIterator &operator=(BTInOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTInOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTInOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override; // (throw std::out_of_range when terminated)

    bool Terminated() noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    BTInOrderIterator &operator++() override; // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>
  {

  private:
  protected:
    using BTInOrderIterator<Data>::stack;

  public:
    // Specific constructors
    BTInOrderMutableIterator(MutableBinaryTree<Data> &); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderMutableIterator(const BTInOrderMutableIterator &);

    // Move constructor
    BTInOrderMutableIterator(BTInOrderMutableIterator &&);

    /* ************************************************************************ */

    // Destructor
    ~BTInOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator);

    // Move assignment
    BTInOrderMutableIterator &operator=(BTInOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTInOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTInOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    Data &operator*() override; // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {

  private:
  protected:
    using typename BinaryTree<Data>::Node;
    const Node &root = nullptr;
    QueueVec<Node *> que;

  public:
    // Specific constructors
    BTBreadthIterator(const BinaryTree<Data> &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTBreadthIterator(const BTBreadthIterator &);

    // Move constructor
    BTBreadthIterator(BTBreadthIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTBreadthIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTBreadthIterator &operator=(const BTBreadthIterator &);

    // Move assignment
    BTBreadthIterator &operator=(BTBreadthIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTBreadthIterator &) const noexcept;
    bool operator!=(const BTBreadthIterator &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override; // (throw std::out_of_range when terminated)

    bool Terminated() const noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    ForwardIterator<Data> &operator++() override; // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>
  {
  private:
  protected:
    using BTBreadthIterator<Data>::que;

  public:
    // Specific constructors
    BTBreadthMutableIterator(MutableBinaryTree<Data> &); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTBreadthMutableIterator(const BTBreadthMutableIterator &);

    // Move constructor
    BTBreadthMutableIterator(BTBreadthMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~BTBreadthMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTBreadthMutableIterator &operator=(const BTBreadthMutableIterator &);

    // Move assignment
    BTBreadthMutableIterator &operator=(BTBreadthMutableIterator &&);

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTBreadthMutableIterator &) const noexcept;
    bool operator!=(const BTBreadthMutableIterator &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    Data &operator*() override; // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
