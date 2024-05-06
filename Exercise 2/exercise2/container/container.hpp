
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  class Container
  {

  private:
    // ...

  protected:
    unsigned long size = 0;

  public:
    // Destructor
    virtual ~Container() = default;

    /* ************************************************************************ */

    // Copy assignment
    Container &operator=(const Container &) = delete;

    // Move assignment
    Container &operator=(Container &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Container &) const noexcept = delete;
    bool operator!=(const Container &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual bool Empty() const noexcept
    {
      return size == 0;
    }

    virtual unsigned long Size() const noexcept
    {
      return size;
    }
  };

  /* ************************************************************************** */

  class ClearableContainer : virtual public Container
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~ClearableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    ClearableContainer &operator=(const ClearableContainer &) = delete;

    // Move assignment
    ClearableContainer &operator=(ClearableContainer &&) = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const ClearableContainer &) const noexcept = delete;
    bool operator!=(const ClearableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual void inline Clear() noexcept
    {
      size = 0;
    }
  };

  /* ************************************************************************** */

  class ResizableContainer : virtual public ClearableContainer
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~ResizableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    ResizableContainer &operator=(const ResizableContainer &);

    // Move assignment
    ResizableContainer &operator=(ResizableContainer &&);

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const ResizableContainer &) const noexcept = delete;
    bool operator!=(const ResizableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual void inline Resize(unsigned long n) noexcept
    {
      size = n;
    }

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    virtual void Clear() noexcept override
    {
      Resize(0);
    }
  };

  /* ************************************************************************** */

}

#endif
