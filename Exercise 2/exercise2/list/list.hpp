
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

      // Data
      Data element;
      struct Node *next = nullptr;

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
    List() = default;

    /* ************************************************************************ */

    // Specific constructor
    List(const TraversableContainer<Data> &);
    List(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    List(const List<Data> &);

    // Move constructor
    List(List<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~List();

    /* ************************************************************************ */

    // Copy assignment
    List &operator=(const List<Data> &);

    // Move assignment
    List &operator=(List<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const List<Data> &) const noexcept;
    inline bool operator!=(const List<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions
    void InsertAtFront(const Data &);
    void InsertAtFront(Data &&);
    void RemoveFromFront();
    Data FrontNRemove();
    
    void InsertAtBack(const Data &);
    void InsertAtBack(Data &&);

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)
    void Clear() noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)
    bool Insert(const Data &) override;
    bool Insert(Data &&) noexcept override;
    bool Remove(const Data &) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)
    const Data &operator[](const ulong) const override;
    Data &operator[](const ulong) override;
    
    const Data &Front() const override;
    Data &Front() override;
    
    const Data &Back() const override;
    Data &Back() override;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)
    using typename TraversableContainer<Data>::TraverseFun;
    inline void Traverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    void PreOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    void PostOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)
    
    using typename MappableContainer<Data>::MapFun;
    inline void Map(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    void PreOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)
    
    void PostOrderMap(MapFun) override;

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "list.cpp"

#endif