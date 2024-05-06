#include "queuelst.hpp"

namespace lasd
{

    template <typename Data>
    QueueLst<Data>::QueueLst(const QueueLst<Data> &queueLst) : List<Data>(queueLst) {}

    template <typename Data>
    QueueLst<Data>::QueueLst(QueueLst<Data> &&queueLst) noexcept : List<Data>(std::move(queueLst)) {}

    template <typename Data>
    QueueLst<Data> &QueueLst<Data>::operator=(const QueueLst<Data> &queueLst)
    {
        List<Data>::operator=(queueLst);
        return *this;
    }

    template <typename Data>
    QueueLst<Data> &QueueLst<Data>::operator=(QueueLst<Data> &&queueLst) noexcept
    {
        List<Data>::operator=(std::move(queueLst));
        return *this;
    }

    template <typename Data>
    bool QueueLst<Data>::operator==(const QueueLst<Data> &queueLst) const noexcept
    {
        return List<Data>::operator==(queueLst);
    }

    template <typename Data>
    bool QueueLst<Data>::operator!=(const QueueLst<Data> &queueLst) const noexcept
    {
        return !(*this == queueLst);
    }

    template <typename Data>
    inline const Data &QueueLst<Data>::Head() const
    {
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data &QueueLst<Data>::Head()
    {
        return List<Data>::Front();
    }

    template <typename Data>
    inline void QueueLst<Data>::Dequeue()
    {
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    inline Data QueueLst<Data>::HeadNDequeue()
    {
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(const Data &data)
    {
        return List<Data>::InsertAtBack(data);
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(Data &&data) noexcept
    {
        return List<Data>::InsertAtBack(std::move(data));
    }

}