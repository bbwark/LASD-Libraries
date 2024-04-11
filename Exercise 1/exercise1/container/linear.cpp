#include "linear.hpp"

namespace lasd
{
    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const
    {
        return (*this)[0];
    }

    template <typename Data>
    inline Data &LinearContainer<Data>::Front()
    {
        return (*this)[0];
    }

    template <typename Data>
    const Data &LinearContainer<Data>::Back() const
    {
        return (*this)[Size() - 1];
    }

    template <typename Data>
    Data &LinearContainer<Data>::Back()
    {
        return (*this)[Size() - 1];
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun traverseFun)
    {
        for (unsigned long i = 0; i < Size(); ++i)
        {
            traverseFun((*this)[i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun)
    {
        Traverse(traverseFun);
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun)
    {
        for (unsigned long i = Size() - 1; i >= 0; --i)
        {
            traverseFun((*this)[i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::Map(MapFun mapFun)
    {
        for (unsigned long i = 0; i < Size(); ++i)
        {
            (*this)[i] = mapFun((*this)[i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderMap(MapFun mapFun)
    {
        Map(mapFun);
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderMap(MapFun mapFun)
    {
        for (unsigned long i = Size() - 1; i >= 0; --i)
        {
            (*this)[i] = mapFun((*this)[i]);
        }
    }

    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer &con) const noexcept
    {
        if (Size() != con.Size())
            return false;

        bool same = true;
        unsigned long index = 0;
        con.Traverse([this, &same, &index](const Data &data)
                     {
            same = same && ((*this)[index] == data);
            index++; });

        return same;
    }

    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer &con) const noexcept
    {
        if (Size() != con.Size())
            return true;

        bool same = true;
        unsigned long index = 0;
        con.Traverse([this, &same, &index](const Data &data)
                     {
            same = same && ((*this)[index] == data);
            index++; });

        return !same;
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer &con) const noexcept
    {
        if (Size() != con.Size())
            return false;

        bool same = true;
        unsigned long index = 0;
        con.Traverse([this, &same, &index](const Data &data)
                     {
            same = same && ((*this)[index] == data);
            index++; });

        return same;
    }

    template <typename Data>
    bool lasd::SortableLinearContainer<Data>::operator!=(const SortableLinearContainer &con) const noexcept
    {
        if (Size() != con.Size())
            return true;

        bool same = true;
        unsigned long index = 0;
        con.Traverse([this, &same, &index](const Data &data)
                     {
            same = same && ((*this)[index] == data);
            index++; });

        return !same;
    }

    template <typename Data>
    unsigned long SortableLinearContainer<Data>::Partition(unsigned long start, unsigned long end)
    {
        Data pivotValue = (*this)[start];
        unsigned long pivotPosition = start;

        for (unsigned long pos = start + 1; pos <= end; pos++)
        {
            if ((*this)[pos] < pivotValue)
            {
                std::swap((*this)[pivotPosition + 1], (*this)[pos]);
                std::swap((*this)[pivotPosition], (*this)[pivotPosition + 1]);
                pivotPosition++;
            }
        }
        return pivotPosition;
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(unsigned long start, unsigned long end)
    {
        if (start < end)
        {
            unsigned long p = Partition(start, end);

            QuickSort(start, p - 1);
            QuickSort(p + 1, end);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort()
    {
        unsigned long start = 0;
        unsigned long end = Size() - 1;
        QuickSort(start, end);
    }
}
