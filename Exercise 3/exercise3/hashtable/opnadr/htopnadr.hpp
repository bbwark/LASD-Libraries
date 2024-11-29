
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  enum State{
    EMPTY,
    FULL,
    REMOVED
  };

protected:

  static const ulong TABLESIZEMIN = 128;
  static const ulong TABLESIZEMAX = 65536;

  // using HashTable<Data>::???;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::hash;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::generatorA;
  using HashTable<Data>::generatorB;
  using HashTable<Data>::generator;
  using HashTable<Data>::size;

  Vector<Data> table;
  Vector<State> state;

  double capPercentage = 0.0;

public:

  using DictionaryContainer<Data>::InsertAll;

  // Default constructor
  // HashTableOpnAdr() specifiers;

  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer

  HashTableOpnAdr(const ulong);
  HashTableOpnAdr(const TraversableContainer<Data> &);
  HashTableOpnAdr(const ulong, const TraversableContainer<Data> &);
  HashTableOpnAdr(MappableContainer<Data> &&);
  HashTableOpnAdr(const ulong, MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;

  HashTableOpnAdr(const HashTableOpnAdr<Data> &);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;

  HashTableOpnAdr(HashTableOpnAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;

  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  HashTableOpnAdr &operator=(const HashTableOpnAdr<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  HashTableOpnAdr &operator=(HashTableOpnAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const HashTableOpnAdr<Data> &) const noexcept;
  bool operator!=(const HashTableOpnAdr<Data> &) const noexcept;

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

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

  ulong HashKey(ulong, const Data &) const noexcept;
  ulong Find(ulong, const Data &) const noexcept;
  ulong FindEmpty(ulong, const Data &) const noexcept;
  bool Remove(ulong, const Data &) noexcept;
  ulong Pow2Next(const ulong) const noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
