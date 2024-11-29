#include "vector.hpp"

namespace lasd
{

    // Specific Constructors.
    template <typename Data>
    Vector<Data>::Vector(const unsigned long newSize)
    {
        elements = new Data[newSize]{};
        size = newSize;
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> &container) : Vector(container.Size())
    {
        unsigned long index = 0;
        container.Traverse(
            [this, &index](const Data &data)
            {
                elements[index] = data;
                index++;
            });
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data> &&container) : Vector(container.Size())
    {
        unsigned long index = 0;
        container.Map(
            [this, &index](Data &data)
            {
                elements[index] = std::move(data);
                index++;
            });
    }

    // Copy Constructor
    template <typename Data>
    Vector<Data>::Vector(const Vector<Data> &vect)
    {
        elements = new Data[vect.size];
        std::copy(vect.elements, vect.elements + vect.size, elements);
        size = vect.size;
    }

    // Move Constructor
    template <typename Data>
    Vector<Data>::Vector(Vector<Data> &&vect) noexcept
    {
        std::swap(size, vect.size);
        std::swap(elements, vect.elements);
    }

    // Destructor
    template <typename Data>
    Vector<Data>::~Vector()
    {
        delete[] elements;
    }

    // Operator
    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vect)
    {
        Vector<Data> *tempVector = new Vector<Data>(vect);
        std::swap(*tempVector, *this);
        delete tempVector;
        return *this;
    }

    // Operator
    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vect) noexcept
    {
        std::swap(elements, vect.elements);
        std::swap(size, vect.size);
        return *this;
    }

    // Comparison Operator

    template <typename Data>
    bool Vector<Data>::operator==(const Vector &vect) const noexcept
    {
        if (size == vect.size)
        {
            for (unsigned long index = 0; index < size; ++index)
            {
                if (elements[index] != vect.elements[index])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    bool Vector<Data>::operator!=(const Vector &vect) const noexcept
    {
        return !(*this == vect);
    }

    template <typename Data>
    void Vector<Data>::Clear()
    {
        delete[] elements;
        elements = nullptr;
        size = 0;
    }

    template <typename Data>
    void Vector<Data>::Resize(const unsigned long newSize)
    {
        if (newSize == 0)
        {
            Clear();
        }
        else if (size != newSize)
        {
            Data *tempElement = new Data[newSize]{};
            unsigned long minimumSize;
            minimumSize = (size < newSize) ? size : newSize;
            for (unsigned long index = 0; index < minimumSize; index++)
            {
                std::swap(elements[index], tempElement[index]);
            }
            std::swap(elements, tempElement);
            size = newSize;
            delete[] tempElement;
        }
    }

    template <typename Data>
    const Data &Vector<Data>::operator[](const unsigned long index) const
    {
        if (index < size)
        {
            return elements[index];
        }
        else
        {
            throw std::out_of_range("Invalid Access to Index " + std::to_string(index));
        }
    }

    template <typename Data>
    Data &Vector<Data>::operator[](const unsigned long index)
    {
        if (index < size)
        {
            return elements[index];
        }
        else
        {
            throw std::out_of_range("Invalid Access to Index " + std::to_string(index));
        }
    }

    template <typename Data>
    const Data &Vector<Data>::Front() const
    {
        if (size != 0)
        {
            return elements[0];
        }
        else
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
    }

    template <typename Data>
    Data &Vector<Data>::Front()
    {
        if (size != 0)
        {
            return elements[0];
        }
        else
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
    }

    template <typename Data>
    const Data &Vector<Data>::Back() const
    {
        if (size != 0)
        {
            return elements[size - 1];
        }
        else
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
    }

    template <typename Data>
    Data &Vector<Data>::Back()
    {
        if (size != 0)
        {
            return elements[size - 1];
        }
        else
        {
            throw std::length_error("Invalid Access to empty Vector");
        }
    }

    // Specific Constructors
    template <typename Data>
    SortableVector<Data>::SortableVector(const unsigned long newSize)
    {
        elements = new Data[newSize]{};
        size = newSize;
    }

    template <typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data> &container) : SortableVector(container.Size())
    {
        unsigned long index = 0;
        container.Traverse(
            [this, &index](const Data &data)
            {
                elements[index] = data;
                index++;
            });
    }

    template <typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data> &&container) : SortableVector(container.Size())
    {
        unsigned long index = 0;
        container.Map(
            [this, &index](Data &data)
            {
                elements[index] = std::move(data);
                index++;
            });
    }

    // Copy Constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data> &vect)
    {
        size = vect.size;
        elements = new Data[size];
        std::copy(vect.elements, vect.elements + size, elements);
    }

    // Move Constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data> &&vect) noexcept
    {
        std::swap(size, vect.size);
        std::swap(elements, vect.elements);
    }

    // Destructor
    template <typename Data>
    SortableVector<Data>::~SortableVector()
    {
        Vector<Data>::Clear();
    }

    // Operator
    template <typename Data>
    SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector &vect)
    {
        Vector<Data>::operator=(vect);
        return *this;
    }

    // Operator
    template <typename Data>
    SortableVector<Data> &SortableVector<Data>::operator=(SortableVector &&vect) noexcept
    {
        Vector<Data>::operator=(std::move(vect));
        return *this;
    }

}
