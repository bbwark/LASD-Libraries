
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class DictionaryContainer : TestableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~DictionaryContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    DictionaryContainer &operator=(const DictionaryContainer &) = delete;

    // Move assignment
    DictionaryContainer &operator=(DictionaryContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const DictionaryContainer &) const noexcept = delete;
    bool operator!=(const DictionaryContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual bool Insert(const Data &) const; // Copy of the value
    virtual bool Insert(Data &&) const;      // Move of the value
    virtual bool Remove(Data &&) const;

    virtual bool InsertAll(const TraversableContainer<Data> &) const; // Copy of the value; From TraversableContainer; True if all are inserted
    virtual bool InsertAll(MappableContainer<Data> &&) const;         // Move of the value; From MappableContainer; True if all are inserted
    virtual bool RemoveAll(TraversableContainer<Data> &&) const;      // From TraversableContainer; True if all are removed

    virtual bool InsertSome(const TraversableContainer<Data> &) const; // Copy of the value; From TraversableContainer; True if some is inserted
    virtual bool InsertSome(MappableContainer<Data> &&) const;         // Move of the value; From MappableContainer; True if some is inserted
    virtual bool RemoveSome(TraversableContainer<Data> &&) const;      // From TraversableContainer; True if some is removed
  };

  /* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
