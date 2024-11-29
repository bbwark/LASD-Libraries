namespace lasd
{

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &container)
    {
        bool result = true;
        container.Traverse(
            [this, &result](const Data &dat)
            {
                result = result && Insert(dat);
            });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&container)
    {
        bool result = true;
        container.Map(
            [this, &result](Data &dat)
            {
                result = result && Insert(std::move(dat));
            });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> &container)
    {
        bool result = true;
        container.Traverse(
            [this, &result](const Data &dat)
            {
                result = result && Remove(dat);
            });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &container)
    {
        bool result = false;
        container.Traverse(
            [this, &result](const Data &dat)
            {
                result = result || Insert(dat);
            });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&container)
    {
        bool result = false;
        container.Map(
            [this, &result](Data &data)
            {
                result = result || Insert(std::move(data));
            });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> &container)
    {
        bool result = false;
        container.Traverse(
            [this, &result](const Data &dat)
            {
                bool removed = Remove(dat);
                result = result || removed;
            });
        return result;
    }

}
