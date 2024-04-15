
namespace lasd
{

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &con) const
    {
        bool result = true;
        con.Traverse(
            [this, &result](const Data &data)
            {
                result = result && Insert(data);
            });

        return result;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&con) const
    {
        bool result = true;
        con.Map(
            [this, &result](Data &data)
            {
                result = result && Insert(std::move(data));
            });
        return result;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveAll(TraversableContainer<Data> &&con) const
    {
        bool result = true;
        con.Traverse(
            [this, &result](const Data &data)
            {
                result = result && Remove(data);
            });

        return result;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &con) const
    {
        bool result = false;
        con.Traverse(
            [this, &result](const Data &data)
            {
                result = result || Insert(data);
            });

        return result;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&con) const
    {
        bool result = false;
        con.Map(
            [this, &result](Data &data)
            {
                result = result || Insert(std::move(data));
            });
        return result;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveSome(TraversableContainer<Data> && con) const
    {
        bool result = false;
        con.Traverse(
            [this, &result](const Data &data)
            {
                result = result || Remove(data);
            });

        return result;
    }
}