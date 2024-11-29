
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../bst/bst.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class HashTableClsAdr : virtual public HashTable<Data>
  {
    // Must extend HashTable<Data>

  private:
    // ...

  protected:
    static const ulong TABLESIZEMIN = 128;
    static const ulong TABLESIZEMAX = 65536;

    // using HashTable<Data>::???;
    using HashTable<Data>::HashKey;
    using HashTable<Data>::hash;
    using HashTable<Data>::tableSize;
    using HashTable<Data>::size;
    using HashTable<Data>::a;
    using HashTable<Data>::b;

    BST<Data> *table = nullptr;

  public:
    using DictionaryContainer<Data>::InsertAll;

    // Default constructor
    // HashTableClsAdr() specifiers;
    HashTableClsAdr();

    /* ************************************************************************ */

    // Specific constructors
    // HashTableClsAdr(argument) specifiers; // A hash table of a given size
    // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
    // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
    // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
    // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer

    HashTableClsAdr(const ulong);
    HashTableClsAdr(const TraversableContainer<Data> &);
    HashTableClsAdr(const ulong, const TraversableContainer<Data> &);
    HashTableClsAdr(MappableContainer<Data> &&);
    HashTableClsAdr(const ulong, MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    // HashTableClsAdr(argument) specifiers;

    HashTableClsAdr(const HashTableClsAdr<Data> &);

    // Move constructor
    // HashTableClsAdr(argument) specifiers;

    HashTableClsAdr(HashTableClsAdr<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~HashTableClsAdr() specifiers;

    ~HashTableClsAdr();

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    HashTableClsAdr &operator=(const HashTableClsAdr<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;

    HashTableClsAdr &operator=(HashTableClsAdr<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

    bool operator==(const HashTableClsAdr<Data> &) const noexcept;
    bool operator!=(const HashTableClsAdr<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
    // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
    // type Remove(argument) specifiers; // Override DictionaryContainer member

    bool Insert(const Data &) override;
    bool Insert(Data &&) noexcept override;
    bool Remove(const Data &) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    // type Exists(argument) specifiers; // Override TestableContainer member

    bool Exists(const Data &) const noexcept override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ResizableContainer)

    // type Resize(argument) specifiers; // Resize the hashtable to a given size

    void Resize(ulong) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from ClearableContainer)

    // type Clear() specifiers; // Override Container member

    void Clear() override;

  protected:
    ulong Pow2Next(const ulong) const noexcept;
  };

  /* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
