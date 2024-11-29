
namespace lasd {

    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun);
    }

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun mapFun){
        PostOrderMap(mapFun);
    }

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun mapFun){
        InOrderMap(mapFun);
    }

    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun mapFun){
        BreadthMap(mapFun);
    }
}
