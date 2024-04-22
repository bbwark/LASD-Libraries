
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class List : virtual public ClearableContainer, virtual public LinearContainer<Data>, virtual public DictionaryContainer<Data>
  {

  private:
  protected:
    using Container::size;

    struct Node
    {

      Data element;
      Node *next = nullptr;

      /* ********************************************************************** */

      // Default constructors
      Node() = default;

      // Specific constructors
      Node(const Data &value)
      {
        element = value;
        next = nullptr;
      }

      /* ********************************************************************** */

      // Copy constructor
      Node(const Node &node)
      {
        element = node.element;
        next = node.next;
      }

      // Move constructor
      Node(Node &&node) noexcept
      {
        std::swap(element, node.element);
        std::swap(next, node.next);
      }

      /* ********************************************************************** */

      // Destructor
      ~Node() = default;

      /* ********************************************************************** */

      // Comparison operators
      bool operator==(const Node &) const noexcept;
      bool operator!=(const Node &) const noexcept;

      /* ********************************************************************** */

      // Specific member functions

      Node *Clone(Node *);
    };

    Node *head = nullptr;
    Node *tail = nullptr;

  public:
    // Default constructor
    List() = default;

    /* ************************************************************************ */

    // Specific constructor
    List(const TraversableContainer<Data> &);
    List(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    List(const List &);

    // Move constructor
    List(List &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~List();

    /* ************************************************************************ */

    // Copy assignment
    List &operator=(const List &);

    // Move assignment
    List &operator=(List &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const List &) const noexcept;
    inline bool operator!=(const List &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    void InsertAtFront(const Data &); // Copy of the value
    void InsertAtFront(Data &&);      // Move of the value
    void RemoveFromFront();           // (must throw std::length_error when empty)
    Data FrontNRemove();              // (must throw std::length_error when empty)

    void InsertAtBack(const Data &); // Copy of the value
    void InsertAtBack(Data &&);      // Move of the value

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() noexcept override; // Override ClearableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &) override;     // Copy of the value
    bool Insert(Data &&) noexcept override; // Move of the value
    bool Remove(const Data &) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    const Data &operator[](const unsigned long) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
    Data &operator[](const unsigned long) override;             // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

    const Data &Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    Data &Front() override;             // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

    const Data &Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    Data &Back() override;             // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    void Traverse(TraverseFun) const override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    void Map(MapFun) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "list.cpp"

#endif
