
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...

  using MutableBinaryTree<Data>::size;

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeVec : virtual MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:


    NodeVec() = default;

    NodeVec(const Data &);
    NodeVec(Data &&) noexcept;

    NodeVec(const NodeVec &);
    NodeVec(NodeVec &&) noexcept;

    NodeVec &operator=(const NodeVec &);
    NodeVec &operator=(NodeVec &&) noexcept;

    ~NodeVec() = default;

    Data &Element() noexcept override;
    const Data &Element() const noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    const Node &LeftChild() const override;
    const Node &RightChild() const override;
    MutableNode &LeftChild() override;
    MutableNode &RightChild() override;

    Data element;
    Vector<NodeVec*> *pvec;
    ulong idxNode;

  };

  Vector<NodeVec *> vec;

public:


  // Default constructor
  // BinaryTreeVec() specifiers;

  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer

  BinaryTreeVec(const TraversableContainer<Data> &);
  BinaryTreeVec(MappableContainer<Data> &&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;

  BinaryTreeVec(const BinaryTreeVec<Data> &);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;

  BinaryTreeVec(BinaryTreeVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;

  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  BinaryTreeVec &operator=(const BinaryTreeVec<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  BinaryTreeVec &operator=(BinaryTreeVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const BinaryTreeVec<Data> &) const noexcept;
  bool operator!=(const BinaryTreeVec<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  const Node &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

  MutableNode &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

  bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

  using typename MappableContainer<Data>::MapFun;
  virtual void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
