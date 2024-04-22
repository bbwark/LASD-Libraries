
namespace lasd
{
    template <typename Data>
    inline bool List<Data>::Node::operator==(const Node &node) const noexcept
    {
        return (element == node->element);
    }

    template <typename Data>
    bool lasd::List<Data>::Node::operator!=(const Node &node) const noexcept
    {
        return !(*this == node);
    }

    template <typename Data>
    List<Data>::Node *List<Data>::Node::Clone(Node *node)
    {
        if (next == nullptr)
        {
            return node;
        }
        else
        {
            Node *newNode = new Node(element);
            newNode->next = next->Clone(node);
            return newNode;
        }
    }

    template <typename Data>
    inline List<Data>::List(const TraversableContainer<Data> &con)
    {
        con.Traverse(
            [this](const Data &data)
            {
                InsertAtBack(data);
            });
    }

    template <typename Data>
    inline List<Data>::List(MappableContainer<Data> &&con)
    {
        con.Map(
            [this](const Data &data)
            {
                InsertAtBack(data);
            });
    }

    template <typename Data>
    List<Data>::List(const List<Data> &list)
    {
        if (list.tail != nullptr)
        {
            tail = new Node(*list.tail);
            head = list.head->Clone(tail);
            size = list.size;
        }
    }

    template <typename Data>
    List<Data>::List(List &&list) noexcept
    {
        std::swap(list.head, head);
        std::swap(list.tail, tail);
        std::swap(list.size, size);
    }

    template <typename Data>
    lasd::List<Data>::~List()
    {
        delete head;
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &list)
    {
        List<Data> *tempList = new List<Data>(list);
        std::swap(*tempList, *this);
        delete tempList;
        return *this;
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(List &&list) noexcept
    {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
        return *this;
    }

    template <typename Data>
    inline bool List<Data>::operator==(const List &list) const noexcept
    {
        if (size == list.size)
        {
            Node *first = head;
            Node *second = list.head;
            while (first != nullptr)
            {
                if (first->element != second->element)
                {
                    return false;
                }
                first = first->next;
                second = second->next;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    inline bool List<Data>::operator!=(const List &list) const noexcept
    {
        return !(*this == list);
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        if (tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&data)
    {
        Node *temp = new Node(std::move(data));
        temp->next = head;
        head = temp;
        if (tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront()
    {
        if (size > 0 || head != nullptr)
        {
            Node *temp = head;
            if (tail == head)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            size--;
            temp->next = nullptr;
            delete temp;
        }
        else
        {
            throw std::length_error("Trying to access an empty List");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove()
    {
        if (head != nullptr)
        {
            Data removedData = Front();
            RemoveFromFront();
            return removedData;
        }
        else
        {
            throw std::length_error("Trying to access an empty List");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &data)
    {
        Node *temp = new Node(data);
        if (tail == nullptr)
        {
            head = temp;
        }
        else
        {
            tail->next = temp;
        }
        tail = temp;
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data &&data)
    {
        Node *back = new Node(std::move(data));
        if (tail == nullptr)
        {
            head = back;
        }
        else
        {
            tail->next = back;
        }
        tail = back;
        size++;
    }

    template <typename Data>
    void List<Data>::Clear() noexcept
    {
        for (unsigned long index = 0; index < size; index++)
        {
            RemoveFromFront();
        }
        size = 0;
    }

    template <typename Data>
    bool List<Data>::Insert(const Data &data)
    {
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (current->element == data)
            {
                return false;
            }
        }
        InsertAtBack(data);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data &&data) noexcept
    {
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (current->element == data)
            {
                return false;
            }
        }
        InsertAtBack(std::move(data));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data &data)
    {
        Node *last = nullptr;
        for (Node **current = &head; *current != nullptr; last = *current, current = &((last->next)))
        {
            if ((*current)->element == data)
            {
                Node *node = *current;
                *current = node->next;
                node->next = nullptr;
                delete node;
                size--;
                if (tail == node)
                {
                    tail = last;
                }
                return true;
            }
        }
        return false;
    }

    template <typename Data>
    const Data &List<Data>::operator[](const unsigned long index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Access out of bounds [" + std::to_string(index) + "]");
        }
        else
        {
            Node *current = head;
            for (unsigned long i = 0; i < index; ++i, current = current->next)
            {
            }
            return current->element;
        }
    }

    template <typename Data>
    Data &List<Data>::operator[](const unsigned long index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Access out of bounds [" + std::to_string(index) + "]");
        }
        else
        {
            Node *current = head;
            for (unsigned long i = 0; i < index; ++i, current = current->next)
            {
            }
            return current->element;
        }
    }

    template <typename Data>
    const Data &List<Data>::Front() const
    {
        if (head == nullptr)
        {
            throw std::length_error("Head in List (" + std::to_string(*this) + ") is nullptr");
        }
        else
        {
            return head->element;
        }
    }

    template <typename Data>
    Data &List<Data>::Front()
    {
        if (head == nullptr)
        {
            throw std::length_error("Head in List (" + std::to_string(*this) + ") is nullptr");
        }
        else
        {
            return head->element;
        }
    }

    template <typename Data>
    const Data &List<Data>::Back() const
    {
        if (tail == nullptr)
        {
            throw std::length_error("Tail in List (" + std::to_string(*this) + ") is nullptr");
        }
        else
        {
            return tail->element;
        }
    }

    template <typename Data>
    Data &List<Data>::Back()
    {
        if (tail == nullptr)
        {
            throw std::length_error("Tail in List (" + std::to_string(*this) + ") is nullptr");
        }
        else
        {
            return tail->element;
        }
    }

    template <typename Data>
    void List<Data>::Traverse(TraverseFun traverseFun) const
    {
        for (unsigned long index = 0; index < size; ++index)
        {
            traverseFun((*this)[index]);
        }
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun traverseFun) const
    {
        Traverse(traverseFun);
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun traverseFun) const
    {
        ulong index = size;
        while (index > 0)
        {
            traverseFun((*this)[--index]);
        }
    }

    template <typename Data>
    void List<Data>::Map(MapFun mapFun)
    {
        for (unsigned long index = 0; index < size; ++index)
        {
            mapFun((*this)[index]);
        }
    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun mapFun)
    {
        Map(mapFun);
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun mapFun)
    {
        ulong index = size;
        while (index > 0)
        {
            mapFun((*this)[--index]);
        }
    }

}