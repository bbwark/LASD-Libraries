
namespace lasd
{

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data &val) const noexcept
    {
        bool exists = false;
        Traverse([val, &exists](const Data &data)
                 { exists = exists || (data == val); });
        return exists;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator accumulator) const
    {
        Traverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator) const
    {
        PreOrderTraverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator) const
    {
        PostOrderTraverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator) const
    {
        InOrderTraverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator lasd::BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldFun, Accumulator accumulator) const
    {
        BreadthTraverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        PostOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        InOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        BreadthTraverse(traverseFun);
    }
}