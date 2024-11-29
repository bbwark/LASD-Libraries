#include "stacklst.hpp"

namespace lasd {

    template <typename Data>
    inline StackLst<Data>::StackLst(const StackLst<Data> &stackLst) : List<Data>(stackLst) {}

    template <typename Data>
    inline StackLst<Data>::StackLst(StackLst<Data> &&stackLst) noexcept : List<Data>(std::move(stackLst)){}

    template <typename Data>
    inline StackLst<Data> &StackLst<Data>::operator=(const StackLst &stackLst){
        List<Data>::operator=(stackLst);
        return *this;
    }

    template <typename Data>
    inline StackLst<Data> &StackLst<Data>::operator=(StackLst &&stackLst) noexcept{
        List<Data>::operator=(stackLst);
        return *this;
    }

    template <typename Data>
    inline bool StackLst<Data>::operator==(const StackLst &stackLst) const noexcept{
        return List<Data>::operator==(stackLst);
    }

    template <typename Data>
    inline bool StackLst<Data>::operator!=(const StackLst &stackLst) const noexcept{
        return !(*this == stackLst);
    }

    template <typename Data>
    inline const Data &StackLst<Data>::Top() const
    {
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data &StackLst<Data>::Top(){
        return List<Data>::Front();
    }

    template <typename Data>
    inline void StackLst<Data>::Pop(){
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    inline Data StackLst<Data>::TopNPop(){
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    inline void StackLst<Data>::Push(const Data &data){
        return List<Data>::InsertAtFront(data);
    }

    template <typename Data>
    inline void StackLst<Data>::Push(Data &&data) noexcept{
        return List<Data>::InsertAtFront(std::move(data));
    }

    
}
