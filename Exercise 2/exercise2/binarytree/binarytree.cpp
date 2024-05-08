
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    void BinaryTree<Data>::Traverse(TraverseFun fun) const
    {
        Traverse(Root(), fun);
    }

    template <typename Data>
    void BinaryTree<Data>::Traverse(const Node &node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        fun(node->Element());

        if (node->HasLeftChild())
        {
            Traverse(node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            Traverse(node->RightChild(), fun);
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        Traverse(fun);
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        PostOrderTraverse(Root(), fun);
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(const Node &node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            PostOrderTraverse(node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            PostOrderTraverse(node->RightChild(), fun);
        }

        fun(node->Element());
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const
    {
        InOrderTraverse(Root(), fun);
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(const Node &node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            InOrderTraverse(node->LeftChild(), fun);
        }

        fun(node->Element());

        if (node->HasRightChild())
        {
            InOrderTraverse(node->RightChild(), fun);
        }
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const
    {
        if (&Root() == nullptr)
        {
            return;
        }

        QueueVec<const Node *> queue;
        queue.Enqueue(&Root());

        while (!queue.Empty())
        {
            const Node *currentNode = queue.HeadNDequeue();
            fun(currentNode->Element());
            if (currentNode->HasLeftChild())
            {
                queue.Enqueue(&currentNode->LeftChild());
            }
            if (currentNode->HasRightChild())
            {
                queue.Enqueue(&currentNode->RightChild());
            }
        }
    }

    /*
    //WITH AUXILIARY FUNCTION IMPLEMENTATION
    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(const Node &node, const TraverseFun& fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        QueueVec<const Node *> queue;
        queue.Enqueue(node);

        while (!queue.Empty())
        {
            const Node *currentNode = queue.HeadNDequeue();
            fun(currentNode->Element());
            if (currentNode->HasLeftChild())
            {
                queue.Enqueue(&currentNode->LeftChild());
            }
            if (currentNode->HasRightChild())
            {
                queue.Enqueue(&currentNode->RightChild());
            }
        }
    }
    */

    template <typename Data>
    bool BinaryTree<Data>::operator==(const BinaryTree &bt) const noexcept
    {
        if (size != bt.size)
            return false;
        return comparison(Root(), bt.Root());
    }

    template <typename Data>
    bool BinaryTree<Data>::comparison(const Node &a, const Node &b) const noexcept
    {
        if (a.IsLeaf() && b.IsLeaf())
            return true;

        if (!a.IsLeaf() && !b.IsLeaf())
        {
            return (a.Element() == b.Element() && identicalTrees(a.LeftChild(), b.LeftChild()) && identicalTrees(a.RightChild(), b.RightChild()));
        }

        return false;
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree &bt) const noexcept
    {
        return !(*this == bt)
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MapFun fun)
    {
        Map(Root(), fun);
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(const Node &node, const MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        fun(node->Element());

        if (node->HasLeftChild())
        {
            Map(node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            Map(node->RightChild(), fun);
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun fun)
    {
        Map(fun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun fun)
    {
        PostOrderMap(Root(), fun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(const Node &node, const MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            PostOrderMap(node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            PostOrderMap(node->RightChild(), fun);
        }

        fun(node->Element());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun fun)
    {
        InOrderMap(Root(), fun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(const Node &node, const MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            InOrderMap(node->LeftChild(), fun);
        }

        fun(node->Element());

        if (node->HasRightChild())
        {
            InOrderMap(node->RightChild(), fun);
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun fun)
    {
        if (&Root() == nullptr)
        {
            return;
        }

        QueueVec<const Node *> queue;
        queue.Enqueue(&Root());

        while (!queue.Empty())
        {
            const Node *currentNode = queue.HeadNDequeue();
            fun(currentNode->Element());
            if (currentNode->HasLeftChild())
            {
                queue.Enqueue(&currentNode->LeftChild());
            }
            if (currentNode->HasRightChild())
            {
                queue.Enqueue(&currentNode->RightChild());
            }
        }
    }
    
    /* ************************************************************************** */

}
