#pragma once

#include <stddef.h>
#include <utility>
#include <memory>
#include "vector.h"

using std::pair;
#ifdef N
const size_t N = 4;
#endif
template <class K, class T> class unordered_map;
template <class K, class T> class unordered_map{
private:
    vector<vector<pair<K,T>>> hashmap;
    size_t backets_size;
    size_t elements_count;
public:
    unordered_map():backets_size(START_CAPACITY),hashmap(vector<vector<pair<T,K>>>(START_CAPACITY)){};
    ~unordered_map(){};
    void put(K key,T value);
    T get(K key);
    void remove(K key);
    void clear();
    bool isEmpty() const;
    size_t getSize() const;
    bool contains(T value) const;
    size_t hash(K key) const;

    class Iterator;
    Iterator begin() { return Iterator(hashmap[0].begin(), hashmap); };
    Iterator end() { return Iterator(hashmap[backets_size - 1].end(), hashmap); };

    class ConstIterator;
    ConstIterator begin() const { return ConstIterator(hashmap[0].begin(), hashmap); };
    ConstIterator end() const { return ConstIterator(hashmap[backets_size - 1].end(), hashmap); };
protected:
    void resize();
    K findKeyByValue(T value) const ;
    T findValueByKey(K key) const ;
    //T* toArray();
};

template<class K,class T> inline void unordered_map<K,T>::put(K key,T value) {
    hashmap[hash(key)].add(std::make_pair(key,value));
    if (elements_count > N*backets_size) {
        //resize();
    }
    elements_count++;
}
template<class K,class T> inline T unordered_map<K,T>::get(K key) {
    return hashmap[hash(key)].get(0).second;

}
template <class K,class T> void unordered_map<K,T>::remove(K key) {
    size_t index=0;
    for (pair<K,T> node : hashmap[hash(key)]){
        if (node.first == key){
            hashmap[hash(key)].remove(index);
        }
        index++;
    }
    elements_count--;
}

template <class K,class T> inline void unordered_map<K,T>::clear() {
    delete[] hashmap;
    hashmap = vector<vector<T>>(START_CAPACITY);
    elements_count = 0;
}

template <class K,class T> bool unordered_map<K,T>::contains(T value) const {
    return findKeyByValue(value)!=nullptr;
}

template <class K,class T> inline size_t unordered_map<K,T>::hash(K value) const {
//    try{
        int h = value * 31;
        int hash_mask = 0b10100000000000000001000101;
        return (h ^ (h << 15) ^ hash_mask) % backets_size;
//    }catch(...) {
//        return hash(std::stoi(value));
//    }

}

template <class K,class T> inline bool unordered_map<K,T>::isEmpty() const {
    return elements_count == 0;
}

template <class K,class T> inline size_t unordered_map<K,T>::getSize() const {
    return elements_count;
}

//template <class K,class T> void unordered_map<K,T>::resize()
//{
//    size_t old_size = backets_size;
//    backets_size *= N;
//    for (size_t i = 0; i < old_size; i++) {
//        if (!hashmap[i].isEmpty()) {
//            for (size_t j = 0; j < hashmap[i].getSize(); j++) {
//                T temp = hashmap[i].get(j);
//                newmap[hash(temp)].add(temp);
//            }
//        }
//    }
//    delete[] hashmap;
//    hashmap = newmap;
//}
template <class K,class T> K unordered_map<K,T>::findKeyByValue(T value) const {
    for (vector<pair<K,T>> backet:hashmap){
        for (pair<K,T> node:backet){
            if (node.second == value){
                return node.first;
            }
        }
    }
    return nullptr;
}
template <class K,class T> T unordered_map<K,T>::findValueByKey(K key) const {
    for (vector<pair<K,T>> backet:hashmap){
        for (pair<K,T> node:backet){
            if (node.first == key){
                return node.second;
            }
        }
    }
    return nullptr;
}
template <class K,class T> class unordered_map<K,T>::Iterator {
private:
    pair<K,T>* ptr;
    size_t h_index;
    vector<vector<pair<K,T>>> table;
public:
    Iterator(T* ptr, vector<vector<pair<K,T>>> hs) : ptr(ptr), table(hs){};
    T* operator++()
    {
        while (ptr != table[table.getSize() - 1].end() - 1) {
            if (ptr < table[h_index].end() - 1) {
                return ++ptr->second;
            }
            h_index++;
            ptr = table[h_index].begin();
            if (!table[h_index].isEmpty())
                return ptr->second;
        }
        ptr = table[table.getSize() - 1].end();
        return ptr->second;

    }
    bool operator!=(const Iterator &rv) const
    {
        return ptr != rv.ptr;
    }
    T& operator*()
    {
        return *ptr->second;
    }
    operator T* () const
    {
        return ptr->second;
    }
};

template <class K,class T> class unordered_map<K,T>::ConstIterator {
private:
    const pair<K,T>* ptr;
    size_t h_index;
    const vector<vector<pair<K,T>>> hs;
public:
    ConstIterator(T* ptr, vector<vector<pair<K,T>>> hs) : ptr(ptr), hs(hs), h_index(0){};
    const T* operator++()
    {
        while (ptr != hs[hs.getSize() - 1].end() - 1) {
            if (ptr < hs[h_index].end() - 1) {
                return ++ptr;
            }
            h_index++;
            ptr = hs[h_index].begin();
            if (!hs[h_index].isEmpty())
                return ptr;
        }
        ptr = hs[hs.getSize() - 1].end();
        return ptr;

    }
    bool operator!=(const ConstIterator &rv) const
    {
        return ptr != rv.ptr;
    }
    const T& operator*() const
    {
        return *ptr;
    }
    explicit operator T* () const
    {
        return (T *) ptr;
    }
};

