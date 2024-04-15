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
        return (*this)[size - 1];
    }

    template <typename Data>
    Data &LinearContainer<Data>::Back()
    {
        return (*this)[size - 1];
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        for (unsigned long i = 0; i < size; ++i)
        {
            traverseFun((*this)[i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun) const
    {
        Traverse(traverseFun);
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun) const
    {
        unsigned long i = size;
        while (i > 0)
        {
            traverseFun((*this)[--i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::Map(MapFun mapFun)
    {
        for (unsigned long i = 0; i < size; ++i)
        {
            mapFun((*this)[i]);
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
        unsigned long i = size;
        while (i > 0)
        {
            mapFun((*this)[--i]);
        }
    }

    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer &con) const noexcept
    {
        if (size != con.size)
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
        return !(*this == con);
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer &con) const noexcept
    {
        if (size != con.size)
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
    bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    unsigned long SortableLinearContainer<Data>::Partition(unsigned long start, unsigned long end)
    {
        Data pivotValue = (*this)[start];
        unsigned long pivotPosition = start;

        for (unsigned long pos = start + 1; pos < end; pos++)
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

            QuickSort(start, p);
            QuickSort(p + 1, end);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort()
    {
        unsigned long start = 0;
        unsigned long end = size - 1;
        QuickSort(start, end);
    }
}
