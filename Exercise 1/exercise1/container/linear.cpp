
namespace lasd
{
    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const
    {
        return operator[](0);
    }

    template <typename Data>
    inline Data &LinearContainer<Data>::Front()
    {
        return operator[](0);
    }

    template <typename Data>
    const Data &LinearContainer<Data>::Back() const
    {
        return operator[](Size() - 1);
    }

    template <typename Data>
    Data &LinearContainer<Data>::Back()
    {
        return operator[](Size() - 1);
    }
}
