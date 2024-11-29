
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTree : virtual public PreOrderTraversableContainer<Data>, virtual public PostOrderTraversableContainer<Data>, virtual public InOrderTraversableContainer<Data>, virtual public BreadthTraversableContainer<Data>
  {
    // Must extend PreOrderTraversableContainer<Data>,
    //             PostOrderTraversableContainer<Data>,
    //             InOrderTraversableContainer<Data>,
    //             BreadthTraversableContainer<Data>

  private:
    // ...

  protected:
    // ...
    using Container::size;

  public:
    struct Node
    {

    protected:
      // Comparison operators
      // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
      // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.

      bool operator==(const Node &) const noexcept;
      bool operator!=(const Node &) const noexcept;

    public:
      // friend class BinaryTree<Data>;

      friend class BinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      // ~Node() specifiers

      virtual ~Node() = default;

      /* ********************************************************************** */

      // Copy assignment
      // type operator=(argument); // Copy assignment of abstract types is not possible.

      Node &operator=(const Node &) = delete;

      // Move assignment
      // type operator=(argument); // Move assignment of abstract types is not possible.

      Node &operator=(Node &&) noexcept = delete;

      /* ********************************************************************** */

      // Specific member functions

      // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)

      virtual const Data &Element() const noexcept = 0;

      // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
      // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
      // type HasRightChild() specifiers; // (concrete function should not throw exceptions)

      virtual bool IsLeaf() const noexcept = 0;
      virtual bool HasLeftChild() const noexcept = 0;
      virtual bool HasRightChild() const noexcept = 0;

      // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
      // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

      virtual const Node &LeftChild() const = 0;
      virtual const Node &RightChild() const = 0;
    };

    /* ************************************************************************ */

    // Destructor
    // ~BinaryTree() specifiers

    virtual ~BinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    BinaryTree &operator=(const BinaryTree<Data> &) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    BinaryTree &operator=(BinaryTree<Data> &&) = delete;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
    // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.

    bool operator==(const BinaryTree<Data> &) const noexcept;
    bool operator!=(const BinaryTree<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    // type Root() specifiers; // (concrete function must throw std::length_error when empty)

    virtual const Node &Root() const = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    // using typename TraversableContainer<Data>::TraverseFun;
    // type Traverse(arguments) specifiers; // Override TraversableContainer member

    using typename TraversableContainer<Data>::TraverseFun;
    virtual void Traverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

    virtual void PreOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

    virtual void PostOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderTraversableContainer)

    // type InOrderTraverse(arguments) specifiers; // Override InOrderTraversableContainer member

    virtual void InOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthTraversableContainer)

    // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member

    virtual void BreadthTraverse(TraverseFun) const override;

  protected:
    // Auxiliary functions, if necessary!

    virtual void PreOrderTraverse(TraverseFun, const Node &) const;

    virtual void PostOrderTraverse(TraverseFun, const Node &) const;

    virtual void InOrderTraverse(TraverseFun, const Node &) const;

    virtual void BreadthTraverse(TraverseFun, const Node &) const;
  };

  /* ************************************************************************** */

  template <typename Data>
  class MutableBinaryTree : virtual public ClearableContainer, virtual public BinaryTree<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>, virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data>
  {
    // Must extend ClearableContainer,
    //             BinaryTree<Data>,
    //             PreOrderMappableContainer<Data>,
    //             PostOrderMappableContainer<Data>,
    //             InOrderMappableContainer<Data>,
    //             BreadthMappableContainer<Data>

  private:
    // ...

  protected:
    // ...
    using BinaryTree<Data>::size;
    using typename BinaryTree<Data>::Node;

  public:
    struct MutableNode : virtual Node
    {
      // Must extend Node

      // friend class MutableBinaryTree<Data>;

      friend class MutableBinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      // ~MutableNode() specifiers

      virtual ~MutableNode() = default;

      /* ********************************************************************** */

      // Copy assignment
      // type operator=(argument); // Copy assignment of abstract types is not possible.

      MutableNode &operator=(const MutableNode &) = delete;

      // Move assignment
      // type operator=(argument); // Move assignment of abstract types is not possible.

      MutableNode &operator=(MutableNode &&) noexcept = delete;

      /* ********************************************************************** */

      // Specific member functions

      // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)

      using Node::Element;
      virtual Data &Element() noexcept = 0;

      // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
      // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

      using Node::LeftChild;
      using Node::RightChild;
      virtual MutableNode &LeftChild() = 0;
      virtual MutableNode &RightChild() = 0;
    };

    /* ************************************************************************ */

    // Destructor
    // ~MutableBinaryTree() specifiers

    virtual ~MutableBinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    MutableBinaryTree &operator=(const MutableBinaryTree &) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    MutableBinaryTree &operator=(MutableBinaryTree &&) noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    // type Root() specifiers; // (concrete function must throw std::length_error when empty)

    using BinaryTree<Data>::Root;
    virtual MutableNode &Root() = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    // using typename MappableContainer<Data>::MapFun;
    // type Map(argument) specifiers; // Override MappableContainer member

    using typename MappableContainer<Data>::MapFun;
    virtual void Map(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

    virtual void PreOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

    virtual void PostOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderMappableContainer)

    // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member

    virtual void InOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthMappableContainer)

    // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

    virtual void BreadthMap(MapFun) override;

  protected:
    // Auxiliary functions, if necessary!

    virtual void PreOrderMap(MapFun, MutableNode &);

    virtual void PostOrderMap(MapFun, MutableNode &);

    virtual void InOrderMap(MapFun, MutableNode &);

    virtual void BreadthMap(MapFun, MutableNode &);
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    // ...
    const typename BinaryTree<Data>::Node *root = nullptr;
    StackLst<const typename BinaryTree<Data>::Node *> stk;
    const typename BinaryTree<Data>::Node *origin = nullptr;

  public:
    // Specific constructors
    // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree

    BTPreOrderIterator(const BinaryTree<Data> &);

    /* ************************************************************************ */

    // Copy constructor
    // BTPreOrderIterator(argument) specifiers;

    BTPreOrderIterator(const BTPreOrderIterator<Data> &);

    // Move constructor
    // BTPreOrderIterator(argument) specifiers;

    BTPreOrderIterator(BTPreOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~BTPreOrderIterator() specifiers;

    ~BTPreOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTPreOrderIterator &operator=(const BTPreOrderIterator<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    BTPreOrderIterator &operator=(BTPreOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTPreOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTPreOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    const Data &operator*() const override;

    // type Terminated() specifiers; // (should not throw exceptions)

    bool Terminated() const noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    // type operator++() specifiers; // (throw std::out_of_range when terminated)

    ForwardIterator<Data> &operator++() override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    // type Reset() specifiers; // (should not throw exceptions)

    void Reset() noexcept override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTPreOrderIterator<Data>

  private:
    // ...

  protected:
    // ...
    using BTPreOrderIterator<Data>::stk;
    using BTPreOrderIterator<Data>::root;
    using BTPreOrderIterator<Data>::origin;

  public:
    // Specific constructors
    // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

    BTPreOrderMutableIterator(MutableBinaryTree<Data> &mutBinaryTree) : BTPreOrderIterator<Data>(mutBinaryTree) {};

    /* ************************************************************************ */

    // Copy constructor
    // BTPreOrderMutableIterator(argument) specifiers;

    BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data> &preItr) : BTPreOrderIterator<Data>(preItr) {};

    // Move constructor
    // BTPreOrderMutableIterator(argument) specifiers;

    BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data> &&preItr) noexcept : BTPreOrderIterator<Data>(std::move(preItr)) {};

    /* ************************************************************************ */

    // Destructor
    // ~BTPreOrderMutableIterator() specifiers;

    ~BTPreOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator<Data> &preItr)
    {
      BTPreOrderIterator<Data>::operator=(preItr);
      return *this;
    }

    // Move assignment
    // type operator=(argument) specifiers;

    BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator<Data> &&preItr) noexcept
    {
      BTPreOrderIterator<Data>::operator=(std::move(preItr));
      return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTPreOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTPreOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    Data &operator*() override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    // ...
    const typename BinaryTree<Data>::Node *root = nullptr;
    StackLst<const typename BinaryTree<Data>::Node *> stk;
    const typename BinaryTree<Data>::Node *origin = nullptr;
    StackLst<const typename BinaryTree<Data>::Node *> stkOrigin;

  public:
    // Specific constructors
    // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

    BTPostOrderIterator(const BinaryTree<Data> &);

    /* ************************************************************************ */

    // Copy constructor
    // BTPostOrderIterator(argument) specifiers;

    BTPostOrderIterator(const BTPostOrderIterator<Data> &);

    // Move constructor
    // BTPostOrderIterator(argument) specifiers;

    BTPostOrderIterator(BTPostOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~BTPostOrderIterator() specifiers;

    ~BTPostOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTPostOrderIterator &operator=(const BTPostOrderIterator<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    BTPostOrderIterator &operator=(BTPostOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTPostOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTPostOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    const Data &operator*() const override;

    // type Terminated() specifiers; // (should not throw exceptions)

    bool Terminated() const noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    // type operator++() specifiers; // (throw std::out_of_range when terminated)

    ForwardIterator<Data> &operator++() override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    // type Reset() specifiers; // (should not throw exceptions)

    void Reset() noexcept override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTPostOrderIterator<Data>

  private:
    // ...

  protected:
    // ...
    using BTPostOrderIterator<Data>::root;
    using BTPostOrderIterator<Data>::stk;
    using BTPostOrderIterator<Data>::origin;
    using BTPostOrderIterator<Data>::stkOrigin;

  public:
    // Specific constructors
    // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

    BTPostOrderMutableIterator(MutableBinaryTree<Data> &mutBinaryTree) : BTPostOrderIterator<Data>(mutBinaryTree) {};

    /* ************************************************************************ */

    // Copy constructor
    // BTPostOrderMutableIterator(argument) specifiers;

    BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> &postItr) : BTPostOrderIterator<Data>(postItr) {};

    // Move constructor
    // BTPostOrderMutableIterator(argument) specifiers;

    BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data> &&postItr) noexcept : BTPostOrderIterator<Data>(std::move(postItr)) {};

    /* ************************************************************************ */

    // Destructor
    // ~BTPostOrderMutableIterator() specifiers;

    ~BTPostOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator<Data> &postIter)
    {
      BTPostOrderIterator<Data>::operator=(postIter);
      return *this;
    }

    // Move assignment
    // type operator=(argument) specifiers;

    BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator<Data> &&postIter) noexcept
    {
      BTPostOrderIterator<Data>::operator=(std::move(postIter));
      return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTPostOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTPostOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    Data &operator*() override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    // ...
    const typename BinaryTree<Data>::Node *root = nullptr;
    StackLst<const typename BinaryTree<Data>::Node *> stk;
    const typename BinaryTree<Data>::Node *origin = nullptr;
    StackLst<const typename BinaryTree<Data>::Node *> stkOrigin;

  public:
    // Specific constructors
    // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

    BTInOrderIterator(const BinaryTree<Data> &);

    /* ************************************************************************ */

    // Copy constructor
    // BTInOrderIterator(argument) specifiers;

    BTInOrderIterator(const BTInOrderIterator<Data> &);

    // Move constructor
    // BTInOrderIterator(argument) specifiers;

    BTInOrderIterator(BTInOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~BTInOrderIterator() specifiers;

    ~BTInOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTInOrderIterator &operator=(const BTInOrderIterator<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    BTInOrderIterator &operator=(BTInOrderIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTInOrderIterator<Data> &) const noexcept;
    bool operator!=(const BTInOrderIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    const Data &operator*() const override;

    // type Terminated() specifiers; // (should not throw exceptions)

    bool Terminated() const noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    // type operator++() specifiers; // (throw std::out_of_range when terminated)

    ForwardIterator<Data> &operator++() override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    // type Reset() specifiers; // (should not throw exceptions)

    void Reset() noexcept override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTInOrderIterator<Data>

  private:
    // ...

  protected:
    // ...
    using BTInOrderIterator<Data>::root;
    using BTInOrderIterator<Data>::stk;
    using BTInOrderIterator<Data>::origin;
    using BTInOrderIterator<Data>::stkOrigin;

  public:
    // Specific constructors
    // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

    BTInOrderMutableIterator(MutableBinaryTree<Data> &mutBinaryTree) : BTInOrderIterator<Data>(mutBinaryTree) {};

    /* ************************************************************************ */

    // Copy constructor
    // BTInOrderMutableIterator(argument) specifiers;

    BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> &inItr) : BTInOrderIterator<Data>(inItr) {};

    // Move constructor
    // BTInOrderMutableIterator(argument) specifiers;

    BTInOrderMutableIterator(BTInOrderMutableIterator<Data> &&inItr) noexcept : BTInOrderIterator<Data>(std::move(inItr)) {};

    /* ************************************************************************ */

    // Destructor
    // ~BTInOrderMutableIterator() specifiers;

    ~BTInOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator<Data> &inIter)
    {
      BTInOrderIterator<Data>::operator=(inIter);
      return *this;
    }

    // Move assignment
    // type operator=(argument) specifiers;

    BTInOrderMutableIterator &operator=(BTInOrderMutableIterator<Data> &&inIter) noexcept
    {
      BTInOrderIterator<Data>::operator=(std::move(inIter));
      return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTInOrderMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTInOrderMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    Data &operator*() override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    // ...
    const typename BinaryTree<Data>::Node *root = nullptr;
    QueueLst<const typename BinaryTree<Data>::Node *> que;
    const typename BinaryTree<Data>::Node *origin = nullptr;

  public:
    // Specific constructors
    // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

    BTBreadthIterator(const BinaryTree<Data> &);

    /* ************************************************************************ */

    // Copy constructor
    // BTBreadthIterator(argument) specifiers;

    BTBreadthIterator(const BTBreadthIterator<Data> &);

    // Move constructor
    // BTBreadthIterator(argument) specifiers;

    BTBreadthIterator(BTBreadthIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~BTBreadthIterator() specifiers;

    ~BTBreadthIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTBreadthIterator &operator=(const BTBreadthIterator<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    BTBreadthIterator &operator=(BTBreadthIterator<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTBreadthIterator<Data> &) const noexcept;
    bool operator!=(const BTBreadthIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)

    const Data &operator*() const override;

    // type Terminated() specifiers; // (should not throw exceptions)

    bool Terminated() const noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    // type operator++() specifiers; // (throw std::out_of_range when terminated)

    ForwardIterator<Data> &operator++() override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    // type Reset() specifiers; // (should not throw exceptions)

    void Reset() noexcept override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTBreadthIterator<Data>

  private:
    // ...

  protected:
    // ...
    using BTBreadthIterator<Data>::que;
    using BTBreadthIterator<Data>::root;
    using BTBreadthIterator<Data>::origin;

  public:
    // Specific constructors
    // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

    BTBreadthMutableIterator(MutableBinaryTree<Data> &mutBinaryTree) : BTBreadthIterator<Data>(mutBinaryTree) {};

    /* ************************************************************************ */

    // Copy constructor
    // BTBreadthMutableIterator(argument) specifiers;

    BTBreadthMutableIterator(const BTBreadthMutableIterator<Data> &breItr) : BTBreadthIterator<Data>(breItr) {};

    // Move constructor
    // BTBreadthMutableIterator(argument) specifiers;

    BTBreadthMutableIterator(BTBreadthMutableIterator<Data> &&breItr) noexcept : BTBreadthIterator<Data>(std::move(breItr)) {};

    /* ************************************************************************ */

    // Destructor
    // ~BTBreadthMutableIterator() specifiers;

    ~BTBreadthMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BTBreadthMutableIterator &operator=(const BTBreadthMutableIterator<Data> &breIter)
    {
      BTBreadthIterator<Data>::operator=(std::move(breIter));
      return *this;
    }

    // Move assignment
    // type operator=(argument) specifiers;

    BTBreadthMutableIterator &operator=(BTBreadthMutableIterator<Data> &&breIter) noexcept
    {
      BTBreadthIterator<Data>::operator=(std::move(breIter));
      return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BTBreadthMutableIterator<Data> &) const noexcept;
    bool operator!=(const BTBreadthMutableIterator<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    // type operator*() specifiers; // (throw std::out_of_range when terminated)
    Data &operator*() override;
  };

  /* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
