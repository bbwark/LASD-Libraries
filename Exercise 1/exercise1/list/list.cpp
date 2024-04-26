#include "list.hpp"

namespace lasd
{

    template <typename Data>
    inline List<Data>::List(const TraversableContainer<Data> &container)
    {
        container.Traverse(
            [this](const Data &data)
            {
                InsertAtBack(data);
            });
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data> &&container)
    {
        container.Map(
            [this](Data &data)
            {
                InsertAtBack(std::move(data));
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
    List<Data>::List(List<Data> &&list) noexcept
    {
        std::swap(list.head, head);
        std::swap(list.tail, tail);
        std::swap(list.size, size);
    }

    template <typename Data>
    List<Data>::~List()
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
    List<Data> &List<Data>::operator=(List<Data> &&list) noexcept
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
            Node *lista1 = head;
            Node *lista2 = list.head;
            while (lista1 != nullptr)
            {
                if (lista1->element != lista2->element)
                {
                    return false;
                }
                lista1 = lista1->next;
                lista2 = lista2->next;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    inline bool List<Data>::operator!=(const List &lista) const noexcept
    {
        return !(*this == lista);
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &data)
    {
        Node *front = new Node(data);
        front->next = head;
        head = front;
        if (tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&data)
    {
        Node *front = new Node(std::move(data));
        front->next = head;
        head = front;
        if (tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront()
    {
        if (head != nullptr)
        {
            Node *front = head;
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
            front->next = nullptr;
            delete front;
        }
        else
        {
            throw std::length_error("Access to Empty List");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove()
    {
        if (head != nullptr)
        {
            Data dataRemoved = Front();
            RemoveFromFront();
            return dataRemoved;
        }
        else
        {
            throw std::length_error("Access to Empty List");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &data)
    {
        Node *back = new Node(data);
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
        unsigned long cont = size;
        for (unsigned long index = 0; index < cont; index++)
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
            throw std::out_of_range("Invalid Access at Index " + std::to_string(index));
        }
        else
        {
            Node *current = head;
            for (unsigned long idx = 0; idx < index; ++idx, current = current->next)
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
            throw std::out_of_range("Invalid Access at Index " + std::to_string(index));
        }
        else
        {
            Node *current = head;
            for (unsigned long idx = 0; idx < index; ++idx, current = current->next)
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
            throw std::length_error("Invalid Access to empty Vector");
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
            throw std::length_error("Invalid Access to empty Vector");
        }
        else
        {
            return head->element;
        }
    }

    template <typename Data>
    const Data &List<Data>::Back() const
    {
        if (head == nullptr)
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
        else
        {
            return tail->element;
        }
    }

    template <typename Data>
    Data &List<Data>::Back()
    {
        if (head == nullptr)
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
        else
        {
            return tail->element;
        }
    }

    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun traverseFun) const
    {
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun traverseFun) const
    {
        for (unsigned long index = 0; index < size; index++)
        {
            traverseFun(operator[](index));
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun traverseFun) const
    {
        unsigned long index = size;
        while (index > 0)
        {
            traverseFun(operator[](--index));
        }
    }

    template <typename Data>
    inline void List<Data>::Map(MapFun mapFun)
    {
        PreOrderMap(mapFun);
    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun mapFun)
    {
        for (unsigned long index = 0; index < size; index++)
        {
            mapFun(operator[](index));
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun mapFun)
    {
        unsigned long index = size;
        while (index > 0)
        {
            mapFun(operator[](--index));
        }
    }

    template <typename Data>
    List<Data>::Node::Node(const Data &data)
    {
        element = data;
        next = nullptr;
    }

    template <typename Data>
    List<Data>::Node::Node(Data &&data) noexcept
    {
        std::swap(element, data);
    }

    template <typename Data>
    inline List<Data>::Node::Node(Node &&node) noexcept
    {
        std::swap(element, node.element);
        std::swap(next, node.next);
    }

    template <typename Data>
    List<Data>::Node::~Node()
    {
        delete next;
    }

    template <typename Data>
    bool List<Data>::Node::operator==(const Node &node) const noexcept
    {
        return (element == node->element);
    }

    template <typename Data>
    inline bool List<Data>::Node::operator!=(const Node &node) const noexcept
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

}