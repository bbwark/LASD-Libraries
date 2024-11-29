#include "queuevec.hpp"

namespace lasd {

    template <typename Data>
    QueueVec<Data>::QueueVec(){
        Vector<Data>::Resize(2);
        head = 0;
        tail = -1;
        effectiveSize = 0;
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(const QueueVec<Data> &queueVec) : Vector<Data>(queueVec){
        head = queueVec.head;
        tail = queueVec.tail;
        effectiveSize = queueVec.effectiveSize;
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec<Data> &&queueVec) noexcept{
        std::swap(elements, queueVec.elements);
        std::swap(head, queueVec.head);
        std::swap(tail, queueVec.tail);
        std::swap(effectiveSize, queueVec.effectiveSize);
    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &queueVec){
        Vector<Data>::operator=(queueVec);
        head = queueVec.head;
        tail = queueVec.tail;
        effectiveSize = queueVec.effectiveSize;
        return *this;
    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&queueVec) noexcept{
        Vector<Data>::operator=(std::move(queueVec));
        head = queueVec.head;
        tail = queueVec.tail;
        effectiveSize = queueVec.effectiveSize;
        return *this;
    }

    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data> &queueVec) const noexcept{
        if(size != queueVec.size){
            return false;
        } else{
            bool result = true;
            ulong idx = 0;
            while(result && idx < size){
                if(elements[idx] != queueVec.elements[idx]){
                    result = false;
                }
                idx++;
            }
            return result;
        }
    }

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec<Data> &queueVec) const noexcept{
        return !(*this == queueVec);
    }

    template <typename Data>
    inline const Data &QueueVec<Data>::Head() const{
        if(effectiveSize != 0){
            return elements[head];
        } else{
            throw std::length_error("Invalid Access to An Empty Queue");
        }
    }

    template <typename Data>
    inline Data &QueueVec<Data>::Head(){
        if(effectiveSize != 0){
            return elements[head];
        } else{
            throw std::length_error("Invalid Access to An Empty Queue");
        }
    }

    template <typename Data>
    inline void QueueVec<Data>::Dequeue(){
        if(effectiveSize <= size / 2){
            Reduce();
        }
        if(effectiveSize == 0){
            throw std::length_error("Invalid Access to An Empty Queue");
        } else{
            head++;
            head = head % Vector<Data>::Size();
            effectiveSize--;
        }
    }

    template <typename Data>
    inline Data QueueVec<Data>::HeadNDequeue(){
        Data dataRemoved = Head();
        Dequeue();
        return dataRemoved;
    }

    template <typename Data>
    inline void QueueVec<Data>::Enqueue(const Data &data){
        if(head == -1){
            head = 0;
        }
        if(effectiveSize == Vector<Data>::Size()){
            Resize();
        }
        tail++;
        tail = (tail % Vector<Data>::Size());
        elements[tail] = data;
        effectiveSize++;
    }

    template <typename Data>
    inline void QueueVec<Data>::Enqueue(Data &&data) noexcept{
        if(head == -1){
            head = 0;
        }
        if(effectiveSize == size){
            Resize();
        }
        tail++;
        tail = (tail % Vector<Data>::Size());
        elements[tail] = std::move(data);
        effectiveSize++;
    }

    template <typename Data>
    bool QueueVec<Data>::Empty() const noexcept{
        if(effectiveSize == 0){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    ulong QueueVec<Data>::Size() const noexcept{
        return effectiveSize;
    }

    template <typename Data>
    void QueueVec<Data>::Clear(){
        Vector<Data>::Clear();
        Vector<Data>::Resize(2);
        head = -1;
        tail = -1;
        effectiveSize = 0;
    }

    template <typename Data>
    void QueueVec<Data>::Resize(){
        Vector<Data> vector(size * 2);
        long j = 0;
        if(tail > head){
            for(long i = head; i <= tail; i++){
            vector[j] = elements[i];
            j++;
            }
        }
        if(tail < head){
            for(ulong i = head; i < Vector<Data>::Size(); i++){
            vector[j] = elements[i];
            j++;
            }
            for(long i = 0; i <= tail; i++){
            vector[j] = elements[i];
            j++;
            }
        }

        Vector<Data>::operator=(vector);
        head = 0;
        tail = effectiveSize - 1;
        size = vector.Size();
        vector.Clear();
    }

    template <typename Data>
    void QueueVec<Data>::Reduce(){
        Vector<Data> vector(size - (size / 4));
        long j = 0;
        if(tail > head){
            for(long i = head; i <= tail; i++){
            vector[j] = elements[i];
            j++;
            }
        }
        if(tail < head){
            for(ulong i = head; i < Vector<Data>::Size(); i++){
            vector[j] = elements[i];
            j++;
            }
            for(long i = 0; i <= tail; i++){
            vector[j] = elements[i];
            j++;
            }
        }

        Vector<Data>::operator=(vector);
        head = 0;
        tail = effectiveSize - 1;
        size = vector.Size();
        vector.Clear();
    }
}
