#include "queuevec.hpp"

namespace lasd {

    template <typename Data>
    QueueVec<Data>::QueueVec(){
        size = 2;
        elements = new Data[size] {};
        head = 0;
        tail = 0;
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data> &container){
        size = (ulong)container.Size() * 1.5;
        if(size < 2){
            size = 2;
        }
        elements = new Data[size] {};
        ulong index = 0;
        container.Traverse(
            [this, &index](const Data &data){
                elements[index] = data;
                Enqueue(elements[index]);
                index++;
            }
        );
        head = 0;
        tail = container.Size();
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&container){
        size = (ulong)container.Size() * 1.5;
        if(size < 2){
            size = 2;
        }
        elements = new Data[size] {};
        ulong index = 0;
        container.Map(
            [this, &index](Data &data){
                elements[index] = std::move(data);
                Enqueue(elements[index]);
                index++;
            }
        );
        head = 0;
        tail = container.Size();
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(const QueueVec<Data> &queueVec){
        size = queueVec.size;
        head = queueVec.head;
        tail = queueVec.tail;
        elements = new Data[size];
        std::copy(queueVec.elements, queueVec.elements + queueVec.size, elements);
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec<Data> &&queueVec) noexcept{
        std::swap(size, queueVec.size);
        std::swap(elements, queueVec.elements);
        std::swap(head, queueVec.head);
        std::swap(tail, queueVec.tail);
    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &queueVec){
        QueueVec<Data> *tempQue = new QueueVec<Data>(queueVec);
        std::swap(*tempQue, *this);
        delete tempQue;
        return *this;
    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&queueVec) noexcept{
        std::swap(size, queueVec.size);
        std::swap(elements, queueVec.elements);
        std::swap(head, queueVec.head);
        std::swap(tail, queueVec.tail);
        return *this;
    }

    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data> &queueVec) const noexcept{
        if(Size() != queueVec.Size()){
            return false;
        } else{
            for(ulong i = 0; i < Size(); i++){
                if(elements[(i + head) % size] != queueVec.elements[(i + queueVec.head) % queueVec.size]){
                    return false;
                }
            }
            return true;
        }  
    }

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec<Data> &queueVec) const noexcept{
        return !(*this == queueVec);
    }

    template <typename Data>
    const Data &QueueVec<Data>::Head() const{
        if(!Empty()){
            return elements[head];
        } else{
            throw std::length_error("Invalid Access to An Empty Queue");
        }
    }

    template <typename Data>
    Data &QueueVec<Data>::Head(){
        if(!Empty()){
            return elements[head];
        } else{
            throw std::length_error("Invalid Access to An Empty Queue");
        }
    }

    template <typename Data>
    void QueueVec<Data>::Dequeue(){
        if(head == tail){
            throw std::length_error("Invalid Access to An Empty Queue");
        }
        head = (head + 1) % size;
        if(Size() <= size/4){
            Reduce();
        }
    }

    template <typename Data>
    Data QueueVec<Data>::HeadNDequeue(){
        Data dataRemoved = Head();
        Dequeue();
        return dataRemoved;
    }

    template <typename Data>
    void QueueVec<Data>::Enqueue(const Data &data){
        if(Size() == (size - 1)){
            Resize();
        }
        elements[tail] = data;
        tail = (tail + 1) % size;
    }

    template <typename Data>
    void QueueVec<Data>::Enqueue(Data &&data) noexcept{
        if(Size() == (size - 1)){
            Resize();
        }
        std::swap(elements[tail], data);
        tail = (tail + 1) % size;
    }

    template <typename Data>
    bool QueueVec<Data>::Empty() const noexcept{
        return (Size() == 0);
    }

    template <typename Data>
    ulong QueueVec<Data>::Size() const noexcept{
        if(head <= tail){
            return (tail - head);
        } else{
            return (size - head - tail);
        }
    }

    template <typename Data>
    void QueueVec<Data>::Clear(){
        size = 2;
        delete[] elements;
        elements = new Data[size];
        head = 0;
        tail = 0;
    }

    template <typename Data>
    void QueueVec<Data>::Resize(){
        if(head > tail){
            Data *vector = new Data[size] {};
            for(ulong i = 0; i < Size(); i++){
                vector[i] = elements[(i + head) % size];
            }
            delete[] elements;
            elements = vector;
            tail = Size();
            head = 0;
        }
        ulong newSize = size + (size / 2);
        Vector<Data>::Resize(newSize);
    }

    template <typename Data>
    void QueueVec<Data>::Reduce(){
        Data *vector = new Data[size] {};
        for(ulong i = 0; i < Size(); i++){
            vector[i] = elements[(i + head) % size];
        }
        delete[] elements;
        elements = vector;
        tail = Size();
        head = 0;
        ulong newSize = (size / 2);
        if(newSize < 2){
            newSize = 2;
        }
        Vector<Data>::Resize(newSize);
    }
}
