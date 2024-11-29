#include "binarytreevec.hpp"

namespace lasd {

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &data){
        element = data;
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec::NodeVec(Data &&data) noexcept{
        std::swap(element, data);
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec &node){
        element = node.element;
        pvec = node.pvec;
        idxNode = node.idxNode;
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec &&node) noexcept{
        std::swap(element, node.element);
        std::swap(pvec, node.pvec);
        std::swap(idxNode, node.idxNode);
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec &node){
        element = node.element;
        pvec = node.pvec;
        idxNode = node.idxNode;
        return *this;
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::operator=(NodeVec &&node) noexcept{
        std::swap(element, node.element);
        std::swap(pvec, node.pvec);
        std::swap(idxNode, node.idxNode);
        return *this;
    }

    template <typename Data>
    Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept{
        return element;
    }

    template <typename Data>
    const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
        return element;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
        return (!HasLeftChild() && !HasRightChild());
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
        if((2 * (idxNode) + 1) < pvec -> Size()){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
        if((2 * (idxNode) + 2) < pvec -> Size()){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    const BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::NodeVec::LeftChild() const{
        if(HasLeftChild()){
            return *((*pvec)[2 * (idxNode) + 1]);
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::NodeVec::LeftChild(){
        if(HasLeftChild()){
            return *((*pvec)[2 * (idxNode) + 1]);
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    const BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::NodeVec::RightChild() const{
        if(HasRightChild()){
            return *((*pvec)[2 * (idxNode) + 2]);
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::NodeVec::RightChild(){
        if(HasRightChild()){
            return *((*pvec)[2 * (idxNode) + 2]);
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &container){
        Vector<Data> vector(container);
        vec.Resize(container.Size());
        for(ulong idx = 0; idx < container.Size(); idx++){
            vec[idx] = new NodeVec();
            vec[idx] -> element = vector[idx];
            vec[idx] -> idxNode = idx;
            vec[idx] -> pvec = &vec;
        }
        vector.Clear();
        size = container.Size();
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&container) noexcept{
        Vector<Data> vector(std::move(container));
        vec.Resize(container.Size());
        for(ulong idx = 0; idx < container.Size(); idx++){
            vec[idx] = new NodeVec();
            vec[idx] -> element = std::move(vector[idx]);
            vec[idx] -> idxNode = idx;
            vec[idx] -> pvec = &vec;
        }
        size = container.Size();
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &binaryTree){
        vec.Resize(binaryTree.size);
        for(ulong i = 0; i < binaryTree.size; i++){
            vec[i] = new NodeVec();
            vec[i] -> element = binaryTree.vec[i] -> element;
            vec[i] -> idxNode = binaryTree.vec[i] -> idxNode;
            vec[i] -> pvec = &vec;
        }
        size = binaryTree.size;
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&binaryTree) noexcept{
        std::swap(vec, binaryTree.vec);
        std::swap(size, binaryTree.size);
    }

    template <typename Data>
    BinaryTreeVec<Data>::~BinaryTreeVec(){
        Clear();
    }

    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &binaryTree){
        vec.Resize(binaryTree.size);
        for(ulong i = 0; i < binaryTree.size; i++){
            vec[i] = new NodeVec();
            vec[i] -> element = binaryTree.vec[i] -> element;
            vec[i] -> idxNode = i;
            vec[i] -> pvec = &vec;
        }
        size = binaryTree.size;
        return *this;
    }

    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&binaryTree) noexcept{
        std::swap(vec, binaryTree.vec);
        std::swap(size, binaryTree.size);
        return *this;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> &binaryTree) const noexcept{
        bool result = true;
        if(size != binaryTree.size){
            result = false;
        } else{
            ulong i = 0;
            while(result && i < size){
                if(binaryTree.vec[i] -> Element() != vec[i] -> Element()){
                    result = false;
                } else{
                    i++;
                }
            }
        }
        return result;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> &binaryTree) const noexcept{
        return !(*this == binaryTree);
    }

    template <typename Data>
    const BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::Root() const{
        if(size != 0){
            return *(vec[0]);
        } else{
            throw std::length_error("BinaryTreeVec is Empty");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::Root(){
        if(size != 0){
            return *(vec[0]);
        } else{
            throw std::length_error("BinaryTreeVec is Empty");
        }
    }

    template <typename Data>
    void BinaryTreeVec<Data>::Clear(){
        for(ulong i = 0; i < size; i++){
            delete vec[i];
        }
        vec.Clear();
        size = 0;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::Exists(const Data &data) const noexcept{
        if(size == 0){
            return false;
        } else{
            ulong i = 0;
            while(i < size){
                if(vec[i] -> Element() == data){
                    return true;
                } else{
                    i++;
                }
            }
            return false;
        }
    }

    template <typename Data>
    void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun traverseFun) const{
        for(ulong i = 0; i < size; i++){
            traverseFun(vec[i] -> element);
        }
    }

    template <typename Data>
    void BinaryTreeVec<Data>::BreadthMap(MapFun mapFun){
        for(ulong i = 0; i < size; i++){
            mapFun(vec[i] -> element);
        }
    }

}
