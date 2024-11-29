
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, virtual public LinearContainer<Data>, virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  struct Node{

    // Data
    Data element;
    struct Node* next = nullptr;

    // Default Constructor
    Node() = default;

    // Specific constructors
    Node(const Data &);
    Node(Data &&data) noexcept;

    // Copy constructor
    inline Node(const Node &node) : element(node.element){};

    // Move constructor
    inline Node(Node &&node) noexcept;

    // Destructor
    virtual ~Node();

    // Comparison operators
    bool operator==(const Node &) const noexcept;
    inline bool operator!=(const Node &) const noexcept;

    // Specific member functions
    virtual Node *Clone(Node *);

  };

  Node *head = nullptr;
  Node *tail = nullptr;
  
public:

  // Default constructor
  // List() specifiers;
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  // List(argument) specifiers; // A list obtained from a MappableContainer

  List(const TraversableContainer<Data> &);
  List(MappableContainer<Data> &&);


  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;

  List(const List<Data> &);

  // Move constructor
  // List(argument) specifiers;

  List(List<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;

  ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  List &operator=(const List<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  List &operator=(List<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  inline bool operator==(const List<Data> &) const noexcept;
  inline bool operator!=(const List<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  void InsertAtFront(const Data &);
  void InsertAtFront(Data &&);
  void RemoveFromFront();
  Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value

  void InsertAtBack(const Data &);
  void InsertAtBack(Data &&);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  // type Insert(argument) specifier; // Move of the value
  // type Remove(argument) specifier;

  bool Insert(const Data &) override;
  bool Insert(Data &&) noexcept override;
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  const Data &operator[](const ulong) const override;
  Data &operator[](const ulong) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data &Front() const override;
  Data &Front() override;

    // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data &Back() const override;
  Data &Back() override;

    /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  // type Traverse(arguments) specifiers; // Override TraversableContainer member

  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

  void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

  void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  // type Map(argument) specifiers; // Override MappableContainer member

  using typename MappableContainer<Data>::MapFun;
  inline void Map(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  void PostOrderMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
