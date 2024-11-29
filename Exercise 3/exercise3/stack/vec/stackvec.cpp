#include "stackvec.hpp"

namespace lasd
{

    template <typename Data>
    StackVec<Data>::StackVec(const StackVec<Data> &stackVec) : Vector<Data>(stackVec)
    {
        index = stackVec.index;
        size = stackVec.size;
    }

    template <typename Data>
    StackVec<Data>::StackVec(StackVec<Data> &&stackVec) noexcept
    {
        std::swap(elements, stackVec.elements);
        std::swap(index, stackVec.index);
        std::swap(size, stackVec.size);
    }

    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(const StackVec<Data> &stackVec)
    {
        Vector<Data>::operator=(stackVec);
        index = stackVec.index;
        return *this;
    }

    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(StackVec<Data> &&stackVec) noexcept
    {
        Vector<Data>::operator=(std::move(stackVec));
        std::swap(index, stackVec.index);
        return *this;
    }

    template <typename Data>
    bool StackVec<Data>::operator==(const StackVec<Data> &stackVec) const noexcept
    {
        if (size != stackVec.size)
        {
            return false;
        }
        else
        {
            bool result = true;
            ulong idx = 0;
            while (result && idx < size)
            {
                if (elements[idx] != stackVec.elements[idx])
                {
                    result = false;
                }
                idx++;
            }
            return result;
        }
    }

    template <typename Data>
    bool StackVec<Data>::operator!=(const StackVec<Data> &stackVec) const noexcept
    {
        return !(*this == stackVec);
    }

    template <typename Data>
    const Data &StackVec<Data>::Top() const
    {
        if (index != 0)
        {
            return elements[index - 1];
        }
        else
        {
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    template <typename Data>
    Data &StackVec<Data>::Top()
    {
        if (index != 0)
        {
            return elements[index - 1];
        }
        else
        {
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    // To Modify for correct testing
    template <typename Data>
    void StackVec<Data>::Pop()
    {
        if (index == (size / 2))
        {
            Reduce();
        }
        if (index != 0)
        {
            index--;
        }
        else
        {
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop()
    {
        Data dataRemoved = Top();
        Pop();
        return dataRemoved;
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data &data)
    {
        if (index == (size))
        {
            Resize();
        }
        elements[index] = data;
        index++;
    }

    template <typename Data>
    void StackVec<Data>::Push(Data &&data) noexcept
    {
        if (index == (size))
        {
            Resize();
        }
        elements[index] = std::move(data);
        index++;
    }

    template <typename Data>
    bool StackVec<Data>::Empty() const noexcept
    {
        if (index == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    ulong StackVec<Data>::Size() const noexcept
    {
        return index;
    }

    template <typename Data>
    void StackVec<Data>::Clear()
    {
        Vector<Data>::Clear();
        Vector<Data>::Resize(1);
        index = 0;
    }

    template <typename Data>
    void StackVec<Data>::Resize()
    {
        Vector<Data>::Resize(size * 2);
    }

    template <typename Data>
    void StackVec<Data>::Reduce()
    {
        Vector<Data>::Resize(size - (size / 4));
    }
}
