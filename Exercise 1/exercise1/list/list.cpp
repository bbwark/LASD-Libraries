
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
    List &List<Data>::operator=(List &&) noexcept
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
    void List<Data>::Clear(){
        for(unsigned long index = 0; index < size; index++){
            RemoveFromFront();
        }
        size = 0;
    }
}