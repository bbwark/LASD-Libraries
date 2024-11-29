#include "htclsadr.hpp"

namespace lasd {

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(){
        table = new BST<Data>[tableSize] {};
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize){
        if(newSize >= TABLESIZEMAX){
            tableSize = TABLESIZEMAX;
            table = new BST<Data>[tableSize] {};
        }
        else if(newSize <= TABLESIZEMIN){
            tableSize = TABLESIZEMIN;
            table = new BST<Data>[tableSize] {};
        } else{
            tableSize = Pow2Next(newSize);
            table = new BST<Data>[tableSize] {};
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &container) : HashTableClsAdr(container.Size()){
        InsertAll(container);
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, const TraversableContainer<Data> &container) : HashTableClsAdr(newSize){
        InsertAll(container);
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&container) : HashTableClsAdr(container.Size()){
        InsertAll(std::move(container));
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, MappableContainer<Data> &&container) : HashTableClsAdr(newSize){
        InsertAll(std::move(container));
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &hashTableCl){
        tableSize = hashTableCl.tableSize;
        size = hashTableCl.size;
        a = hashTableCl.a;
        b = hashTableCl.b;
        table = new BST<Data>[tableSize] {};
        std::copy(hashTableCl.table, hashTableCl.table + tableSize, table);
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&hashTableCl) noexcept{
        std::swap(tableSize, hashTableCl.tableSize);
        std::swap(size, hashTableCl.size);
        std::swap(a, hashTableCl.a);
        std::swap(b, hashTableCl.b);
        std::swap(table, hashTableCl.table);
    }

    template <typename Data>
    HashTableClsAdr<Data>::~HashTableClsAdr(){
        delete[] table;
    }

    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &hashTableCl){
        tableSize = hashTableCl.tableSize;
        size = hashTableCl.size;
        a = hashTableCl.a;
        b = hashTableCl.b;
        delete[] table;
        table = new BST<Data>[tableSize] {};
        for(ulong i = 0; i < tableSize; i++){
            table[i] = hashTableCl.table[i];
        }
        return *this;
    }

    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&hashTableCl) noexcept{
        std::swap(tableSize, hashTableCl.tableSize);
        std::swap(size, hashTableCl.size);
        std::swap(a, hashTableCl.a);
        std::swap(b, hashTableCl.b);
        std::swap(table, hashTableCl.table);
        return *this;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &hashTableCl) const noexcept{
        if(size == hashTableCl.size){
            for(ulong i = 0; i < tableSize; i++){
                if(!(table[i].Empty())){
                    BTInOrderIterator<Data> itr(table[i]);
                    while(!itr.Terminated()){
                        if(!(hashTableCl.Exists(*itr))){
                            return false;
                        } else{
                            ++itr;
                        }
                    }
                }
            }
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data> &hashTableCl) const noexcept{
        return !(*this == hashTableCl);
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(const Data &data){
        ulong idx = HashKey(hash(data));
        if(table[idx].Insert(data)){
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(Data &&data) noexcept{
        ulong idx = HashKey(hash(data));
        if(table[idx].Insert(std::move(data))){
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Remove(const Data &data){
        ulong idx = HashKey(hash(data));
        if(table[idx].Remove(data)){
            size--;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Exists(const Data &data) const noexcept{
        ulong idx = HashKey(hash(data));
        if(table[idx].Exists(data)){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    void HashTableClsAdr<Data>::Resize(ulong newSize){
        HashTableClsAdr<Data> *tempHashTable = new HashTableClsAdr<Data>(newSize);
        for(ulong i = 0; i < tableSize; i++){
            BTInOrderIterator<Data> itr(table[i]);
            while(!itr.Terminated()){
                tempHashTable -> Insert(*itr);
                ++itr;
            }
        }
        std::swap(*this, *tempHashTable);
        delete tempHashTable;
    }

    template <typename Data>
    void HashTableClsAdr<Data>::Clear(){
        delete[] table;
        table = new BST<Data>[tableSize] {};
        size = 0;
    }

    template <typename Data>
    ulong HashTableClsAdr<Data>::Pow2Next(const ulong next) const noexcept{
        ulong newSize = TABLESIZEMIN;
        while(newSize < next){
            if(newSize == TABLESIZEMAX){
                return newSize;
            }
            newSize = std::pow(newSize, 2);
        }
        return newSize;
    }
}