
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
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator accumulator)
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
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator)
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
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator)
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
    inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator)
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
    inline Accumulator lasd::BreadthTraversableContainer<Data>::BreadthOrderFold(FoldFun<Accumulator> foldFun, Accumulator accumulator)
    {
        BreadthOrderTraverse(
            [foldFun, &accumulator](const Data &data)
            {
                accumulator = foldFun(data, accumulator);
            });

        return accumulator;
    }

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun)
    {
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun)
    {
        PostOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun)
    {
        InOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun traverseFun)
    {
        BreadthOrderTraverse(traverseFun);
    }
}