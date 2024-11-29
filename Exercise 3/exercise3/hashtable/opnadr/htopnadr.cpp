#include "htopnadr.hpp"

namespace lasd {

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(){
        tableSize = TABLESIZEMIN;
        a = 2*(generatorA(generator)) + 1;
        b = 2*(generatorB(generator));
        table.Resize(tableSize);
        state.Resize(tableSize); 
        for(ulong i = 0; i < tableSize; i++){
            state[i] = EMPTY;
        }
        capPercentage = (size / tableSize) * 100;
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize){
        tableSize = Pow2Next(newSize);
        a = 2*(generatorA(generator)) + 1;
        b = 2*(generatorB(generator));
        table.Resize(tableSize);
        state.Resize(tableSize);
        for(ulong i = 0; i < tableSize; i++){
            state[i] = EMPTY;
        }
        capPercentage = (size / tableSize) * 100;
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &container) : HashTableOpnAdr(container.Size()){
        InsertAll(container);
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, const TraversableContainer<Data> &container) : HashTableOpnAdr(newSize){
        InsertAll(container);
    }
    
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&container) : HashTableOpnAdr(container.Size()){
        InsertAll(std::move(container));
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, MappableContainer<Data> &&container) : HashTableOpnAdr(newSize){
        InsertAll(std::move(container));
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &hashTableOp){
        a = hashTableOp.a;
        b = hashTableOp.b;
        table = hashTableOp.table;
        state = hashTableOp.state;
        tableSize = hashTableOp.tableSize;
        capPercentage = hashTableOp.capPercentage;
        size = hashTableOp.size;
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&hashTableOp) noexcept{
        std::swap(a, hashTableOp.a);
        std::swap(b, hashTableOp.b);
        std::swap(table, hashTableOp.table);
        std::swap(state, hashTableOp.state);
        std::swap(tableSize, hashTableOp.tableSize);
        std::swap(capPercentage, hashTableOp.capPercentage);
        std::swap(size, hashTableOp.size);
    }

    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &hashTableOp){
        a = hashTableOp.a;
        b = hashTableOp.b;
        table = hashTableOp.table;
        state = hashTableOp.state;
        tableSize = hashTableOp.tableSize;
        capPercentage = hashTableOp.capPercentage;
        size = hashTableOp.size;
        return *this;
    }

    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&hashTableOp) noexcept{
        std::swap(a, hashTableOp.a);
        std::swap(b, hashTableOp.b);
        std::swap(table, hashTableOp.table);
        std::swap(state, hashTableOp.state);
        std::swap(tableSize, hashTableOp.tableSize);
        std::swap(capPercentage, hashTableOp.capPercentage);
        std::swap(size, hashTableOp.size);
        return *this;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data> &hashTableOp) const noexcept{
        if(size == hashTableOp.size){
            for(ulong i = 0; i < tableSize; i++){
                if(state[i] == FULL){
                    if(!(hashTableOp.Exists(table[i]))){
                        return false;
                    }
                }
            }
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data> &hashTableOp) const noexcept{
        return !(*this == hashTableOp);
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(const Data &data){
        capPercentage = (static_cast<double>(size) / static_cast<double>(tableSize)) * 100;
        if(capPercentage > 75){
            Resize(2 * tableSize + 1);
        }
        if(!Exists(data)){
            ulong idxEmpty = FindEmpty(0, data);
            if(idxEmpty < tableSize){
                ulong idx = HashKey(idxEmpty, data);
                if(state[idx] == EMPTY || state[idx] == REMOVED){
                    table[idx] = data;
                    state[idx] = FULL;
                    size++;
                    return true;
                }
            }
        }
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(Data &&data) noexcept{
        capPercentage = (static_cast<double>(size) / static_cast<double>(tableSize)) * 100;
        if(capPercentage > 75){
            Resize(2 * tableSize + 1);
        }
        if(!Exists(data)){
            ulong idxEmpty = FindEmpty(0, data);
            if(idxEmpty < tableSize){
                ulong idx = HashKey(idxEmpty, data);
                if(state[idx] == EMPTY || state[idx] == REMOVED){
                    table[idx] = std::move(data);
                    state[idx] = FULL;
                    size++;
                    return true;
                }
            }
        }
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(const Data &data){
        capPercentage = (static_cast<double>(size) / static_cast<double>(tableSize)) * 100;
        bool result = Remove(0, data);
        if(capPercentage < 10){
            Resize((tableSize / 2) - 1);
        }
        return result;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept{
        if(size != 0){
            ulong idxFound = Find(0, data);
            if(idxFound < tableSize){
                ulong idxHash = HashKey(idxFound, data);
                if(table[idxHash] == data && state[idxHash] == FULL){
                    return true;
                }
            }
        }
        return false;
    }

    template <typename Data>
    void HashTableOpnAdr<Data>::Resize(ulong newSize){
        ulong tempNewSize;
        tempNewSize = Pow2Next(newSize);
        HashTableOpnAdr<Data> *tempHashTable = new HashTableOpnAdr<Data>(tempNewSize);
        for(ulong i = 0; i < tableSize; i++){
            if(state[i] == FULL){
                tempHashTable -> Insert(table[i]);
            }
        }
        std::swap(*this, *tempHashTable);
        delete tempHashTable;
    }

    template<typename Data>
    void HashTableOpnAdr<Data>::Clear(){
        tableSize = TABLESIZEMIN;
        size = 0;
        table.Clear();
        table.Resize(tableSize);
        state.Resize(tableSize);
        for(ulong i = 0; i < tableSize; i++){
            state[i] = EMPTY;
        }
    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::HashKey(ulong idx, const Data &data) const noexcept{
        ulong idxHash = hash(data);
        return (HashKey(idxHash) + (((idx * idx) + idx) / 2)) % tableSize;
    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::Find(ulong idx, const Data &data) const noexcept{
        ulong idxToFind = HashKey(idx, data);
        while(idx < tableSize){
            if(table[idxToFind] == data){
                return idx;
            }
            if(state[idxToFind] == EMPTY){
                return tableSize;
            }
            idx++;
            idxToFind = HashKey(idx, data);
        }
        return idx;
    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::FindEmpty(ulong idx, const Data &data) const noexcept{
        ulong idxToFind = HashKey(idx, data);
        while(idx < tableSize){
            if(state[idxToFind] == EMPTY || state[idxToFind] == REMOVED){
                return idx;
            }
            idx++;
            idxToFind = HashKey(idx, data);
        }
        return idx;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(ulong idx, const Data &data) noexcept{
        if(size != 0){
            ulong idxToFind = Find(idx, data);
            if(idxToFind < tableSize){
                ulong idxHash = HashKey(idxToFind, data);
                if(state[idxHash] == FULL && table[idxHash] == data){
                    state[idxHash] = REMOVED;
                    size--;
                    return true;
                }
            }
        }
        return false;
    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::Pow2Next(const ulong next) const noexcept{
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