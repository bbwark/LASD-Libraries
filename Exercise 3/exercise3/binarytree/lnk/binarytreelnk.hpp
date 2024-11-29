
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTreeLnk : virtual public MutableBinaryTree<Data>
  {
    // Must extend MutableBinaryTree<Data>

  private:
    // ...

  protected:
    // using BinaryTree<Data>::???;
    using MutableBinaryTree<Data>::size;

  public:
    using typename BinaryTree<Data>::Node;
    using typename MutableBinaryTree<Data>::MutableNode;

  protected:
    struct NodeLnk : virtual MutableNode
    { // Must extend MutableNode

    private:
      // ...

    protected:
      // ...

    public:
      NodeLnk() = default;

      NodeLnk(const Data &);
      NodeLnk(Data &&) noexcept;

      NodeLnk(const NodeLnk &);
      NodeLnk(NodeLnk &&) noexcept;

      NodeLnk &operator=(const NodeLnk &);
      NodeLnk &operator=(NodeLnk &&) noexcept;

      ~NodeLnk();

      Data &Element() noexcept override;
      const Data &Element() const noexcept override;

      bool IsLeaf() const noexcept override;
      bool HasLeftChild() const noexcept override;
      bool HasRightChild() const noexcept override;

      virtual const Node &LeftChild() const override;
      virtual const Node &RightChild() const override;
      virtual MutableNode &LeftChild() override;
      virtual MutableNode &RightChild() override;

      Data element;
      NodeLnk *right = nullptr;
      NodeLnk *left = nullptr;
    };

    NodeLnk *root = nullptr;

  public:
    // Default constructor
    // BinaryTreeLnk() specifiers;

    BinaryTreeLnk() = default;

    /* ************************************************************************ */

    // Specific constructors
    // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
    // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer

    BinaryTreeLnk(const TraversableContainer<Data> &);
    BinaryTreeLnk(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    // BinaryTreeLnk(argument) specifiers;

    BinaryTreeLnk(const BinaryTreeLnk<Data> &);

    // Move constructor
    // BinaryTreeLnk(argument) specifiers;

    BinaryTreeLnk(BinaryTreeLnk<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~BinaryTreeLnk() specifiers;

    ~BinaryTreeLnk();

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    BinaryTreeLnk &operator=(const BinaryTreeLnk<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    BinaryTreeLnk &operator=(BinaryTreeLnk<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const BinaryTreeLnk<Data> &) const noexcept;
    bool operator!=(const BinaryTreeLnk<Data> &) const noexcept;

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

    NodeLnk *CreateTree(NodeLnk *);
  };

  /* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
