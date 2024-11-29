#include "bst.hpp"

namespace lasd {

    template <typename Data>
    BST<Data>::BST(const TraversableContainer<Data> &container){
        container.Traverse(
            [this](const Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    BST<Data>::BST(MappableContainer<Data> &&container){
        container.Map(
            [this](Data &data){
                Insert(std::move(data));
            }
        );
    }

    template <typename Data>
    BST<Data>::BST(const BST<Data> &bst){
        BTBreadthIterator<Data> itr(bst);
        while(!itr.Terminated()){
            Insert(*itr);
            ++itr;
        }
    }

    template <typename Data>
    BST<Data>::BST(BST<Data> &&bst) noexcept{
        std::swap(size, bst.size);
        std::swap(root, bst.root);
    }

    template <typename Data>
    BST<Data>::~BST(){
        Clear();
    }

    template <typename Data>
    BST<Data> &BST<Data>::operator=(const BST<Data> &bst){
        BinaryTreeLnk<Data>::operator=(bst);
        return *this;
    }

    template <typename Data>
    BST<Data> &BST<Data>::operator=(BST<Data> &&bst) noexcept{
        BinaryTreeLnk<Data>::operator=(std::move(bst));
        return *this;
    }

    template <typename Data>
    bool BST<Data>::operator==(const BST<Data> &bst) const noexcept{
        bool result = true;
        if(size != bst.size){
            result = false; 
        }else{
            BTInOrderIterator<Data> itr1(*this);
            BTInOrderIterator<Data> itr2(bst);
            while(result && !itr1.Terminated()){
                if(*itr1 != *itr2){
                    result = false;
                }
                ++itr1;
                ++itr2;
            }
        }
        return result;
    }

    template <typename Data>
    bool BST<Data>::operator!=(const BST<Data> &bst) const noexcept{
        return !(*this == bst);
    }

    template <typename Data>
    const Data &BST<Data>::Min() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return FindPointerToMin(root) -> element;
        }
    }

    template <typename Data>
    Data BST<Data>::MinNRemove(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return DataNDelete(DetachMin(root));
        }
    }

    template <typename Data>
    void BST<Data>::RemoveMin(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            delete DetachMin(root);
        }
    }

    template <typename Data>
    const Data &BST<Data>::Max() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return FindPointerToMax(root) -> element;
        }
    }

    template <typename Data>
    Data BST<Data>::MaxNRemove(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return DataNDelete(DetachMax(root));
        }
    }

    template <typename Data>
    void BST<Data>::RemoveMax(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            delete DetachMax(root);
        }
    }

    template <typename Data>
    const Data &BST<Data>::Predecessor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk * const *predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                return (*predecessor) -> element;
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk **predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                return DataNDelete(Detach(*predecessor));
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk **predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                delete Detach(*predecessor);
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    const Data &BST<Data>::Successor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk * const *successor = FindPointerToSuccessor(root, data);
            if(successor != nullptr){
                return (*successor) -> element;
            } else{
                throw std::length_error("Successor does NOT Exist");
            }
        }
    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk **successor = FindPointerToSuccessor(root, data);
            if(successor != nullptr){
                return DataNDelete(Detach(*successor));
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk **successor = FindPointerToSuccessor(root, data);
            if(successor != nullptr){
                delete Detach(*successor);
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(const Data &data){
        NodeLnk *&node = FindPointerTo(root, data);
        if(node == nullptr){
            node = new NodeLnk(data);
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(Data &&data) noexcept{
        NodeLnk *&node = FindPointerTo(root, data);
        if(node == nullptr){
            node = new NodeLnk(std::move(data));
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Remove(const Data &data){
        if(Exists(data)){
            delete Detach(FindPointerTo(root, data));
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Exists(const Data &data) const noexcept{
        return (FindPointerTo(root, data) != nullptr);
    }

    template <typename Data>
    void BST<Data>::Clear(){
        BinaryTreeLnk<Data>::Clear();
    }

    template <typename Data>
    Data BST<Data>::DataNDelete(NodeLnk *node){
        Data data;
        std::swap(data, node -> element);
        delete node;
        return data;
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Detach(NodeLnk *&node) noexcept{
        if(node != nullptr){
            if(node -> left == nullptr){
                return Skip2Right(node);
            }
            else if(node -> right == nullptr){
                return Skip2Left(node);
            } else{
                NodeLnk *detachMax = DetachMax(node -> left);
                std::swap(node -> element, detachMax -> element);
                return detachMax;
            }
        } else{
            return nullptr;
        }
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::DetachMin(NodeLnk *&node) noexcept{
        return Skip2Right(FindPointerToMin(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::DetachMax(NodeLnk *&node) noexcept{
        return Skip2Left(FindPointerToMax(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Skip2Left(NodeLnk *&node) noexcept{
        NodeLnk *ptrLeft = nullptr;
        if(node != nullptr){
            std::swap(ptrLeft, node -> left);
            std::swap(ptrLeft, node);
            --size;
        }
        return ptrLeft;
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Skip2Right(NodeLnk *&node) noexcept{
        NodeLnk *ptrRight = nullptr;
        if(node != nullptr){
            std::swap(ptrRight, node -> right);
            std::swap(ptrRight, node);
            --size;
        }
        return ptrRight;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(NodeLnk *&node) noexcept{
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *> (this) -> FindPointerToMin(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk * const &BST<Data>::FindPointerToMin(NodeLnk * const &node) const noexcept{
        NodeLnk * const *ptr = &node;
        NodeLnk *current = node;
        if(current != nullptr){
            while(current -> left != nullptr){
                ptr = &(current -> left);
                current = current -> left;
            }
        }
        return *ptr;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(NodeLnk *&node) noexcept{
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *> (this) -> FindPointerToMax(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk * const &BST<Data>::FindPointerToMax(NodeLnk * const &node) const noexcept{
        NodeLnk * const *ptr = &node;
        NodeLnk *current = node;
        if(current != nullptr){
            while(current -> right != nullptr){
                ptr = &(current -> right);
                current = current -> right;
            }
        }
        return *ptr;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *> (this) -> FindPointerTo(node, data));
    }

    template <typename Data>
    BST<Data>::NodeLnk * const &BST<Data>::FindPointerTo(NodeLnk * const &node, const Data &data) const noexcept{
        NodeLnk * const *ptr = &node;
        NodeLnk *current = node;
        if(current != nullptr){
            while(current != nullptr && current -> element != data){
                if(current -> element < data){
                    ptr = &(current -> right);
                    current = current -> right;
                } else{
                    ptr = &(current -> left);
                    current = current -> left;
                }
            }
        }
        return *ptr;
    }

    template <typename Data>
    BST<Data>::NodeLnk **BST<Data>::FindPointerToPredecessor(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk **>(static_cast<const BST<Data> *> (this) -> FindPointerToPredecessor(node, data));
    }

    template <typename Data>
    BST<Data>::NodeLnk * const *BST<Data>::FindPointerToPredecessor(NodeLnk * const &node, const Data &data) const noexcept{
        NodeLnk * const * ptr = &node;
        NodeLnk * const * predecessor = nullptr;
        NodeLnk *current = node;
        if(current != nullptr){
            while(current != nullptr && current -> element != data){
                if(current -> element < data){
                    predecessor = ptr;
                    ptr = &(current -> right);
                    current = current -> right;
                } else{
                    ptr = &(current -> left);
                    current = current -> left;
                }
            }
            if(current != nullptr && current -> left != nullptr){
                predecessor = &FindPointerToMax(current -> left);
            } 
        }
        return predecessor;
    }

    template <typename Data>
    BST<Data>::NodeLnk **BST<Data>::FindPointerToSuccessor(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk **>(static_cast<const BST<Data> *> (this) -> FindPointerToSuccessor(node, data));
    }

    template <typename Data>
    BST<Data>::NodeLnk * const *BST<Data>::FindPointerToSuccessor(NodeLnk * const &node, const Data &data) const noexcept{
        NodeLnk * const * ptr = &node;
        NodeLnk * const * successor = nullptr;
        NodeLnk *current = node;
        if(current != nullptr){
            while(current != nullptr && current -> element != data){
                if(current -> element > data){
                    successor = ptr;
                    ptr = &(current -> left);
                    current = current -> left;
                } else{
                    ptr = &(current -> right);
                    current = current -> right;
                }
            }
            if(current != nullptr && current -> right != nullptr){
                successor = &FindPointerToMin(current -> right);
            } 
        }
        return successor;
    }

}
