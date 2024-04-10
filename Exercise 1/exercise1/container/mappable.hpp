
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class MappableContainer : virtual public TraversableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~MappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MappableContainer &operator=(const MappableContainer &) = delete;

    // Move assignment
    MappableContainer &operator=(MappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const MappableContainer &) const noexcept = delete;
    bool operator!=(const MappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using MapFun = std::function<void(Data &)>;

    virtual void Map(MapFun mapFun) = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~PreOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

    // Move assignment
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PreOrderMap(MapFun mapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual void Map(MapFun mapFun) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~PostOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

    // Move assignment
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PostOrderMap(MapFun mapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual void Map(MapFun mapFun) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~InOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete;

    // Move assignment
    InOrderMappableContainer &operator=(InOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const InOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const InOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void InOrderMap(MapFun mapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual void Map(MapFun mapFun) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~BreadthMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    BreadthMappableContainer &operator=(const BreadthMappableContainer &) = delete;

    // Move assignment
    BreadthMappableContainer &operator=(BreadthMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BreadthMappableContainer &) const noexcept = delete;
    bool operator!=(const BreadthMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void BreadthMap(MapFun mapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual void Map(MapFun mapFun) override;
  };

  /* ************************************************************************** */

}

#include "mappable.cpp"

#endif
