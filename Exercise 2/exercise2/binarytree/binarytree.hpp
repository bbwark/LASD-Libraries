
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
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
    // Auxiliary functions, if necessary!
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
      MutableBinaryTree &operator=(MutableBinaryTree &&) noexcept = delete; // Move assignment of abstract types is not possible.

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
    MutableBinaryTree &operator=(MutableBinaryTree &&) noexcept = delete; // Move assignment of abstract types is not possible.

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
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {

  private:
  protected:
    using typename BinaryTree<Data>::Node;
    Node *node = nullptr;
    StackLst<Node *> stack;

  public:
    // Specific constructors
    BTPreOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderIterator(const BTPreOrderIterator<Data> &);

    // Move constructor
    BTPreOrderIterator(BTPreOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~BTPreOrderIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderIterator &operator=(const BTPreOrderIterator<Data> &);

    // Move assignment
    BTPreOrderIterator &operator=(BTPreOrderIterator<Data> &&) noexcept;

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

    void Reset() const noexcept; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data>
  {

  private:
  protected:
    using typename MutableBinaryTree<Data>::MutableNode;
    MutableNode *node = nullptr;
    StackLst<MutableNode *> stack;

  public:
    // Specific constructors
    BTPreOrderMutableIterator(MutableBinaryTree &&); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data> &);

    // Move constructor
    BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data> &&);

    /* ************************************************************************ */

    // Destructor
    ~BTPreOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator<Data>);

    // Move assignment
    BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator<Data> &&) noexcept;

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
    StackLst<Node *> stack;

  public:
    // Specific constructors
    BTPostOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderIterator(const BTPostOrderIterator<Data> &);

    // Move constructor
    BTPostOrderIterator(BTPostOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~BTPostOrderIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderIterator &operator=(const BTPostOrderIterator<Data> &);

    // Move assignment
    BTPostOrderIterator &operator=(BTPostOrderIterator<Data> &&) noexcept;

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

    void Reset() const noexcept; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>
  {

  private:
  protected:
    using typename MutableBinaryTree<Data>::MutableNode;
    MutableNode *node = nullptr;
    StackLst<MutableNode *> stack;

  public:
    // Specific constructors
    BTPostOrderMutableIterator(MutableBinaryTree &&); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> &);

    // Move constructor
    BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data> &&);

    /* ************************************************************************ */

    // Destructor
    ~BTPostOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator<Data>);

    // Move assignment
    BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator<Data> &&) noexcept;

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
    StackLst<Node *> stack;

  public:
    // Specific constructors
    BTInOrderIterator(const BinaryTree &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderIterator(const BTInOrderIterator<Data> &);

    // Move constructor
    BTInOrderIterator(BTInOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~BTInOrderIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderIterator &operator=(const BTInOrderIterator<Data> &);

    // Move assignment
    BTInOrderIterator &operator=(BTInOrderIterator<Data> &&) noexcept;

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

    void Reset() const noexcept; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>
  {

  private:
  protected:
    using typename MutableBinaryTree<Data>::MutableNode;
    MutableNode *node = nullptr;
    StackLst<MutableNode *> stack;

  public:
    // Specific constructors
    BTInOrderMutableIterator(MutableBinaryTree &&); // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> &);

    // Move constructor
    BTInOrderMutableIterator(BTInOrderMutableIterator<Data> &&);

    /* ************************************************************************ */

    // Destructor
    ~BTInOrderMutableIterator();

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator<Data>);

    // Move assignment
    BTInOrderMutableIterator &operator=(BTInOrderMutableIterator<Data> &&) noexcept;

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
  class BTBreadthIterator
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Specific constructors
    // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    // BTBreadthIterator(argument) specifiers;

    // Move constructor
    // BTBreadthIterator(argument) specifiers;

    /* ************************************************************************ */

    // Destructor
    // ~BTBreadthIterator() specifiers;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    // Move assignment
    // type operator=(argument) specifiers;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    // type Terminated() specifiers; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    // type operator++() specifiers; // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    // type Reset() const specifiers; // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthMutableIterator
  {
    // Must extend MutableIterator<Data>,
    //             BTBreadthIterator<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Specific constructors
    // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    // BTBreadthMutableIterator(argument) specifiers;

    // Move constructor
    // BTBreadthMutableIterator(argument) specifiers;

    /* ************************************************************************ */

    // Destructor
    // ~BTBreadthMutableIterator() specifiers;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    // Move assignment
    // type operator=(argument) specifiers;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
