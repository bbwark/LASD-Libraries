#include "linear.hpp"
namespace lasd {

    template <typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer &container) const noexcept{
        if(size == container.size){
            bool isEqual = true;
            unsigned long index = 0;
            container.Traverse(
                [this, &isEqual, &index](const Data &data){
                    isEqual = isEqual && ((*this)[index] == data);
                    index++;
                }
            );
            return isEqual;
        } else{
            return false;
        }
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer &container) const noexcept{
        return !(*this == container);
    }

    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const{
        return operator[](0);
    }

    template <typename Data>
    inline Data &LinearContainer<Data>::Front(){
        return operator[](0);
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Back() const{
        return operator[](size-1);
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back(){
        return operator[](size-1);
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun) const{
        for(unsigned long index = 0; index < size; index++){
            traverseFun(operator[](index));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun) const{
        unsigned long index = size;
        while(index > 0){
            traverseFun(operator[](--index));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderMap(MapFun mapFun){
        for(unsigned long index = 0; index < size; index++){
            mapFun(operator[](index));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderMap(MapFun mapFun){
        unsigned long index = size;
        while(index > 0){
            mapFun(operator[](--index));
        }
    }

    template <typename Data>
    unsigned long SortableLinearContainer<Data>::Partition(unsigned long start, unsigned long end){
        Data pivotValue = (*this)[start];
        unsigned long pivotPosition = start;
        for(unsigned long position = start + 1; position <= end; position++){
            if((*this)[position] < pivotValue){
                pivotPosition++;
                std::swap((*this)[pivotPosition], (*this)[position]);
            }
        }
        std::swap((*this)[start], (*this)[pivotPosition]);
        return pivotPosition;
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(unsigned long start, unsigned long end){
        if(start < end){
            unsigned long partition = Partition(start, end);
            if(partition != 0){
                QuickSort(start, partition - 1);
                QuickSort(partition + 1, end);
            }
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort(){
        unsigned long start = 0;
        unsigned long end = size - 1; 
        QuickSort(start, end);
    }

    

}
