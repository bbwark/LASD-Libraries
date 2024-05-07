
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    inline void BinaryTree<Data>::Traverse(TraverseFun fun) const
    {
        Traverse(Root(), fun);
    }

    template <typename Data>
    inline void BinaryTree<Data>::Traverse(const Node *node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        fun(node->Element());

        if (node->HasLeftChild())
        {
            Traverse(&node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            Traverse(&node->RightChild(), fun);
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
    void BinaryTree<Data>::PostOrderTraverse(const Node *node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            PostOrderTraverse(&node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            PostOrderTraverse(&node->RightChild(), fun);
        }

        fun(node->Element());
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const
    {
        InOrderTraverse(Root(), fun);
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(const Node *node, const TraverseFun &fun) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            InOrderTraverse(&node->LeftChild(), fun);
        }

        fun(node->Element());

        if (node->HasRightChild())
        {
            InOrderTraverse(&node->RightChild(), fun);
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
    void BinaryTree<Data>::BreadthTraverse(const Node *node, const TraverseFun& fun) const
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
        
    }

    /* ************************************************************************** */

}
