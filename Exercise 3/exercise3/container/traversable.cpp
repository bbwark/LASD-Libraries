namespace lasd
{

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data &val) const noexcept
    {
        bool exists = false;
        Traverse(
            [val, &exists](const Data &dat)
            {
                exists = exists || (dat == val);
            });
        return exists;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator acc) const
    {
        Traverse(
            [foldFun, &acc](const Data &dat)
            {
                acc = foldFun(dat, acc);
            });
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
    {
        PreOrderTraverse(
            [foldFun, &acc](const Data &dat)
            {
                acc = foldFun(dat, acc);
            });
        return acc;
    }

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
    {
        PostOrderTraverse(
            [foldFun, &acc](const Data &dat)
            {
                acc = foldFun(dat, acc);
            });
        return acc;
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        PostOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
    {
        InOrderTraverse(
            [foldFun, &acc](const Data &dat)
            {
                acc = foldFun(dat, acc);
            });
        return acc;
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        InOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
    {
        BreadthTraverse(
            [foldFun, &acc](const Data &dat)
            {
                acc = foldFun(dat, acc);
            });
        return acc;
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun traverseFun) const
    {
        BreadthTraverse(traverseFun);
    }

}