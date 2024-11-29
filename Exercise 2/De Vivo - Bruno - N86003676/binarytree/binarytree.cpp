
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    void BinaryTree<Data>::Traverse(TraverseFun fun) const
    {
        Traverse(&this->Root(), fun);
    }

    template <typename Data>
    void BinaryTree<Data>::Traverse(const Node *node, const TraverseFun &fun) const
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
        PostOrderTraverse(&this->Root(), fun);
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
        InOrderTraverse(&this->Root(), fun);
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
            const Node *nodeNode = queue.HeadNDequeue();
            fun(nodeNode->Element());
            if (nodeNode->HasLeftChild())
            {
                queue.Enqueue(&nodeNode->LeftChild());
            }
            if (nodeNode->HasRightChild())
            {
                queue.Enqueue(&nodeNode->RightChild());
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
            const Node *nodeNode = queue.HeadNDequeue();
            fun(nodeNode->Element());
            if (nodeNode->HasLeftChild())
            {
                queue.Enqueue(&nodeNode->LeftChild());
            }
            if (nodeNode->HasRightChild())
            {
                queue.Enqueue(&nodeNode->RightChild());
            }
        }
    }
    */

    template <typename Data>
    bool BinaryTree<Data>::operator==(const BinaryTree<Data> &bt) const noexcept
    {
        if (size != bt.size)
        {
            return false;
        }

        BTPreOrderIterator i(*this);
        BTPreOrderIterator j(bt);

        while (!(i.Terminated()))
        {
            if ((*i) != (*j))
            {
                return false;
            }

            ++i;
            ++j;
        }

        return true;
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree &bt) const noexcept
    {
        return !(*this == bt);
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MapFun fun)
    {
        Map(&this->Root(), fun);
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MutableNode *node, MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        fun(node->Element());

        if (node->HasLeftChild())
        {
            Map(&node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            Map(&node->RightChild(), fun);
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
        PostOrderMap(&this->Root(), fun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MutableNode *node, MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            PostOrderMap(&node->LeftChild(), fun);
        }

        if (node->HasRightChild())
        {
            PostOrderMap(&node->RightChild(), fun);
        }

        fun(node->Element());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun fun)
    {
        InOrderMap(&this->Root(), fun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MutableNode *node, MapFun &fun)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->HasLeftChild())
        {
            InOrderMap(&node->LeftChild(), fun);
        }

        fun(node->Element());

        if (node->HasRightChild())
        {
            InOrderMap(&node->RightChild(), fun);
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun fun)
    {
        if (!this->Empty())
        {
            BreadthMap(&this->Root(), fun);
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MutableNode *node, MapFun &fun)
    {
        lasd::QueueVec<MutableBinaryTree<Data>::MutableNode *> queue;
        if (node != nullptr)
        {
            queue.Enqueue(node);
        }

        while (!queue.Empty())
        {
            MutableBinaryTree<Data>::MutableNode *nodeNode = queue.HeadNDequeue();
            fun(nodeNode->Element());

            if (nodeNode->HasLeftChild())
            {
                queue.Enqueue(&nodeNode->LeftChild());
            }

            if (nodeNode->HasRightChild())
            {
                queue.Enqueue(&nodeNode->RightChild());
            }
        }
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &bt)
    {
        if (!bt.Empty())
        {
            root = &bt.Root();
            node = root;
        }
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &iterator) : stack(iterator.stack)
    {
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> &&iterator) noexcept : stack(std::move(iterator.stack))
    {
        std::swap(root, iterator.root);
        std::swap(node, iterator.node);
    }

    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &iterator)
    {
        root = iterator.root;
        stack = iterator.stack;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&iterator) noexcept
    {
        std::swap(root, iterator.root);
        std::swap(stack, iterator.stack);
        std::swap(node, iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator &iterator) const noexcept
    {
        return (node == iterator.node && stack == iterator.stack);
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> &iterator) const noexcept
    {
        return !(*this == iterator);
    }

    template <typename Data>
    const Data &BTPreOrderIterator<Data>::operator*() const
    {
        if (Terminated())
        {
            throw std::out_of_range("Iterator Terminated");
        }
        else
        {
            return node->Element();
        }
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::Terminated() const noexcept
    {
        return (node == nullptr);
    }

    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator++()
    {
        if (!Terminated())
        {
            if (node->HasLeftChild())
            {
                if (node->HasRightChild())
                {
                    stack.Push(&node->RightChild());
                }
                node = &(node->LeftChild());
            }
            else if (node->HasRightChild())
            {
                node = &(node->RightChild());
            }
            else if (!stack.Empty())
            {
                node = stack.TopNPop();
            }
            else
            {
                node = nullptr;
            }
        }
        else
        {
            throw std::out_of_range("Out of range iterator");
        }
        return *this;
    }

    template <typename Data>
    void BTPreOrderIterator<Data>::Reset() noexcept
    {
        stack.Clear();
        node = root;
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data> &bt)
    {
        if (!bt.Empty())
        {
            root = &bt.Root();
            node = root;
        }
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator &iterator)
    {
        stack = iterator.stack;
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator &&iterator) noexcept
    {
        std::swap(stack, iterator.stack);
        std::swap(root, iterator.root);
        std::swap(node, iterator.node);
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator &iterator)
    {
        this->root = iterator.root;
        this->stack = iterator.stack;
        this->node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator &&iterator) noexcept
    {
        this->root = std::move(iterator.root);
        this->stack = std::move(iterator.stack);
        this->node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator &iterator) const noexcept
    {
        return (node == iterator.node && stack == iterator.stack);
    }

    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data> &iterator) const noexcept
    {
        return !(*this == iterator);
    }

    template <typename Data>
    Data &BTPreOrderMutableIterator<Data>::operator*()
    {
        if (this->node != nullptr)
        {
            return const_cast<Data &>((this->node)->Element());
        }
        else
        {
            throw std::out_of_range("Iterator out of range");
        }
    }

    template <typename Data>
    inline BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &bt)
    {
        if (bt.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &bt.Root();
        }
        node = bottomLLeaf(root);
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator &iterator)
    {
        stack = iterator.stack;
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator &&iterator) noexcept : stack(std::move(iterator.stack))
    {
        root = std::move(iterator.root);
        node = std::move(iterator.node);
    }

    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator &iterator)
    {
        root = iterator.root;
        stack = iterator.stack;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(BTPostOrderIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        stack = std::move(iterator.stack);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator &iterator) const noexcept
    {
        return ((node == iterator.node) && (stack == iterator.stack));
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data> &iterator) const noexcept
    {
        return !(*this == iterator);
    }

    template <typename Data>
    const Data &BTPostOrderIterator<Data>::operator*() const
    {
        if (Terminated())
        {
            throw std::out_of_range("Iterator Terminated");
        }
        else
        {
            return node->Element();
        }
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::Terminated() const noexcept
    {
        return (node == nullptr);
    }

    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++()
    {
        if (!Terminated())
        {
            if (!(stack.Empty()))
            {
                if (stack.Top()->HasRightChild() && !(&(stack.Top()->RightChild()) == node))
                {
                    node = &(stack.Top()->RightChild());
                    node = bottomLLeaf(node);
                }
                else
                {
                    node = stack.TopNPop();
                }
            }
            else
            {
                node = nullptr;
            }
        }
        else
        {
            throw std::out_of_range("Iterator Terminated");
        }

        return *this;
    }

    template <typename Data>
    void BTPostOrderIterator<Data>::Reset() noexcept
    {
        stack.Clear();
        node = bottomLLeaf(root);
    }

    template <typename Data>
    const typename BinaryTree<Data>::Node *BTPostOrderIterator<Data>::bottomLLeaf(const typename BinaryTree<Data>::Node *node)
    {
        if (node != nullptr)
        {
            while (node->HasLeftChild())
            {
                stack.Push(node);
                node = &(node->LeftChild());
            }
            if (node->HasRightChild())
            {
                stack.Push(node);
                node = &(node->RightChild());
                node = bottomLLeaf(node);
            }
        }
        return node;
    }

    template <typename Data>
    inline BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data> &bt)
    {
        if (bt.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &bt.Root();
        }
        node = bottomLLeaf(root);
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator &iterator)
    {
        stack = iterator.stack;
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator &&iterator) noexcept
    {
        stack = std::move(iterator.stack);
        root = std::move(iterator.root);
        node = std::move(iterator.node);
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator &iterator)
    {
        root = iterator.root;
        stack = iterator.stack;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        stack = std::move(iterator.stack);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data> &iterator) const noexcept
    {
        return ((node == iterator.node) && (stack == iterator.stack));
    }

    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data> &iterator) const noexcept
    {
        return !(*this == iterator);
    }
    template <typename Data>
    Data &BTPostOrderMutableIterator<Data>::operator*()
    {
        if (this->node != nullptr)
        {
            return const_cast<Data &>((this->node)->Element());
        }
        else
        {
            throw std::out_of_range("Iterator out of range");
        }
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &iterator)
    {
        if (iterator.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &iterator.Root();
        }
        node = LeftLeaf(root);
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator &iterator)
    {
        stack = iterator.stack;
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator &&iterator) noexcept : stack(std::move(iterator.stack))
    {
        node = std::move(iterator.node);
        root = std::move(iterator.root);
    }

    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(const BTInOrderIterator &iterator)
    {
        root = iterator.root;
        stack = iterator.stack;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(BTInOrderIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        stack = std::move(iterator.stack);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator &iterator) const noexcept
    {
        return ((node == iterator.node) && (stack == iterator.stack));
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator &iterator) const noexcept
    {
        return (*this == iterator);
    }

    template <typename Data>
    const Data &BTInOrderIterator<Data>::operator*() const
    {
        if (Terminated())
        {
            throw std::out_of_range("Iterator Terminated");
        }
        else
        {
            return node->Element();
        }
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::Terminated() const noexcept
    {
        return (node == nullptr);
    }

    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator++()
    {
        if (!Terminated())
        {
            if ((stack.Empty()) && !(node->HasRightChild()))
            {
                node = nullptr;
            }
            else
            {
                if (node->HasRightChild())
                {
                    node = LeftLeaf(&node->RightChild());
                }
                else
                {
                    node = stack.TopNPop();
                }
            }
        }
        else
        {
            throw std::out_of_range("Iterator Terminated");
        }

        return *this;
    }

    template <typename Data>
    void BTInOrderIterator<Data>::Reset() noexcept
    {
        stack.Clear();
        node = LeftLeaf(root);
    }

    template <typename Data>
    const typename BinaryTree<Data>::Node *BTInOrderIterator<Data>::LeftLeaf(const typename BinaryTree<Data>::Node *node)
    {
        while (node != nullptr && (node->HasLeftChild()))
        {
            stack.Push(node);
            node = &node->LeftChild();
        }
        return node;
    }

    template <typename Data>
    inline BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data> &bt)
    {
        if (bt.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &bt.Root();
        }
        node = LeftLeaf(root);
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator &iterator)
    {
        stack = iterator.stack;
        root = iterator.root;
        node = iterator.node;
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator &&iterator) noexcept
    {
        stack = std::move(iterator.stack);
        root = std::move(iterator.root);
        node = std::move(iterator.node);
    }

    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator &iterator)
    {
        root = iterator.root;
        stack = iterator.stack;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        stack = std::move(iterator.stack);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data> &iterator) const noexcept
    {
        return ((node == iterator.node) && (stack == iterator.stack));
    }

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data> &iterator) const noexcept
    {
        return !(*this == iterator);
    }
    template <typename Data>
    Data &BTInOrderMutableIterator<Data>::operator*()
    {
        if (this->node != nullptr)
        {
            return const_cast<Data &>((this->node)->Element());
        }
        else
        {
            throw std::out_of_range("Iterator out of range");
        }
    }

    template <typename Data>
    inline BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &bt)
    {
        if (bt.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &bt.Root();
        }
        node = root;
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &iterator)
    {
        que = iterator.que;
        root = node = iterator.node;
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator &&iterator) noexcept : que(std::move(iterator.que))
    {
        root = std::move(iterator.root);
        node = std::move(iterator.node);
    }

    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(const BTBreadthIterator &iterator)
    {
        root = iterator.root;
        que = iterator.que;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(BTBreadthIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        que = std::move(iterator.que);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator &iterator) const noexcept
    {
        return (node == iterator.node && que == iterator.que);
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator &iterator) const noexcept
    {
        return (*this == iterator);
    }

    template <typename Data>
    const Data &BTBreadthIterator<Data>::operator*() const
    {
        if (Terminated())
        {
            throw std::out_of_range("Iterator Terminated");
        }
        else
        {
            return node->Element();
        }
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::Terminated() const noexcept
    {
        return (node == nullptr);
    }

    template <typename Data>
    ForwardIterator<Data> &BTBreadthIterator<Data>::operator++()
    {
        if (!Terminated())
        {
            if (node != nullptr)
            {
                if (node->HasLeftChild())
                    que.Enqueue(&(node->LeftChild()));
                if (node->HasRightChild())
                    que.Enqueue(&(node->RightChild()));

                if (!que.Empty())
                    node = que.HeadNDequeue();
                else
                    node = nullptr;
            }
        }
        else
        {
            throw std::out_of_range("Iterator Terminated");
        }

        return *this;
    }

    template <typename Data>
    void BTBreadthIterator<Data>::Reset() noexcept
    {
        que.Clear();
        node = root;
    }

    template <typename Data>
    inline BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data> &bt)
    {
        if (bt.Empty())
        {
            root = nullptr;
        }
        else
        {
            root = &bt.Root();
        }
        node = root;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator &iterator)
    {
        que = iterator.que;
        root = node = iterator.node;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator &&iterator) noexcept
    {
        que = std::move(iterator.que);
        root = std::move(iterator.root);
        node = std::move(iterator.node);
    }

    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator &iterator)
    {
        root = iterator.root;
        que = iterator.que;
        node = iterator.node;
        return *this;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator &&iterator) noexcept
    {
        root = std::move(iterator.root);
        que = std::move(iterator.que);
        node = std::move(iterator.node);
        return *this;
    }

    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator &iterator) const noexcept
    {
        return (node == iterator.node && que == iterator.que);
    }

    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator &iterator) const noexcept
    {
        return (*this == iterator);
    }

    template <typename Data>
    inline Data &BTBreadthMutableIterator<Data>::operator*()
    {

        if (this->node != nullptr)
        {
            return const_cast<Data &>((this->node)->Element());
        }
        else
        {
            throw std::out_of_range("Iterator Out of Range");
        }
    }

    /* ************************************************************************** */

}