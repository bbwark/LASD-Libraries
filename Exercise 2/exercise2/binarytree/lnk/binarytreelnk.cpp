#include "binarytreelnk.hpp"

namespace lasd {

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &data){
        element = data;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&data) noexcept{
        element = std::move(data);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &node){
        left = node.left;
        right = node.right;
        element = node.element;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&node) noexcept{
        std::swap(left, node.left);
        std::swap(right, node.right);
        std::swap(element, node.element);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &node){
        left = node.left;
        right = node.right;
        element = node.element;
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&node) noexcept{
        std::swap(left, node.left);
        std::swap(right, node.right);
        std::swap(element, node.element);
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
        if(left != nullptr){
            delete left;
        }
        if(right != nullptr){
            delete right;
        }
    }

    template <typename Data>
    inline Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
        return element;
    }

    template <typename Data>
    inline const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
        return element;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
        return (!HasLeftChild() && !HasRightChild());
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
        return (left != nullptr);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
        return (right != nullptr);
    }
    

    template <typename Data>
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::NodeLnk::RightChild(){
        if(HasRightChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
        if(HasRightChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &container){
        size = container.Size();
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        container.Traverse(
            [&que](const Data &data){
                NodeLnk *&curr = *que.HeadNDequeue();
                curr = new NodeLnk(data);
                que.Enqueue(&curr -> left);
                que.Enqueue(&curr -> right);
            }
        );
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&container){
        size = container.Size();
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        container.Map(
            [&que](const Data &data){
                NodeLnk *&curr = *que.HeadNDequeue();
                curr = new NodeLnk(std::move(data));
                que.Enqueue(&curr -> left);
                que.Enqueue(&curr -> right);
            }
        );
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &binaryTree){
        size = binaryTree.size;
        root = CreateTree(binaryTree.root);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&binaryTree) noexcept{
        std::swap(root, binaryTree.root);
        std::swap(size, binaryTree.size);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk(){
        Clear();
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &binaryTree){
        Clear();
        if(!binaryTree.Empty()){
            size = binaryTree.size;
            root = CreateTree(binaryTree.root);
        }
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&binaryTree) noexcept{
        std::swap(root, binaryTree.root);
        std::swap(size, binaryTree.size);
        return *this;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &binaryTree) const noexcept{
        return BinaryTree<Data>::operator==(binaryTree);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &binaryTree) const noexcept{
        return BinaryTree<Data>::operator!=(binaryTree);
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::Root() const{
        if(root != nullptr){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::Root(){
        if(root != nullptr){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty");
        }
    }

    template <typename Data>
    void BinaryTreeLnk<Data>::Clear(){
        if(root != nullptr){
            delete root;
            root = nullptr;
            size = 0;
        }
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::Exists(const Data &data) const noexcept{
        if(size == 0){
            return false;
        }else{
            BTInOrderIterator<Data> itr1(*this);
            while(!itr1.Terminated()){
                if(*itr1 == data){
                    return true;
                }
                ++itr1;
            }
            return false;
        }
    }

    template<typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CreateTree(NodeLnk *root){
        NodeLnk* tempNode = new NodeLnk();
        tempNode -> element = root -> Element();
        if(root -> HasLeftChild())
        tempNode -> left = CreateTree(root -> left);
        if(root -> HasRightChild())
        tempNode -> right = CreateTree(root -> right);
        return tempNode;
    }

}