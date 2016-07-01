#pragma once
#include "vector.h"

const size_t N = 4;

//#define def template <class T> inline

template <class T>
class unordered_set {
private:
    vector<T> *hashmap;
    size_t backets_size;
    size_t elements_count;
public:
    unordered_set();
    ~unordered_set();
    void add(T value);
    void remove(T value);
    void clear();
    bool isEmpty() const;
    size_t getSize() const;
    bool contains(T value) const;
    size_t hash(T value) const;

    class Iterator;
    Iterator begin() { return Iterator(hashmap[0].begin(), hashmap, backets_size); };
    Iterator end() { return Iterator(hashmap[backets_size - 1].end(), hashmap, backets_size); };

    class ConstIterator;
    ConstIterator begin() const { return ConstIterator(hashmap[0].begin(), hashmap, backets_size); };
    ConstIterator end() const { return ConstIterator(hashmap[backets_size - 1].end(), hashmap, backets_size); };
protected:
    void resize();
    //T* toArray();
};

template<class T>
inline unordered_set<T>::unordered_set()
{
    backets_size = START_CAPACITY;
    hashmap = new vector<T>[backets_size];
}

template<class T>
inline unordered_set<T>::~unordered_set()
{
    delete[] hashmap;
}

template <class T> inline void unordered_set<T>::add(T value) {
    hashmap[hash(value)].add(value);
    if (elements_count > N*backets_size) {
        resize();
    }
    elements_count++;
}

template <class T> inline void unordered_set<T>::remove(T value) {
    hashmap[hash(value)].remove(value);
    elements_count--;
}

template <class T> inline void unordered_set<T>::clear() {
    delete[] hashmap;
    hashmap = new vector<T>[START_CAPACITY];
    elements_count = 0;
}

template <class T> inline bool unordered_set<T>::contains(T value) const {
    return hashmap[hash(value)].contains(value);
}

template <class T> inline size_t unordered_set<T>::hash(T value) const {
    int h = value * 31;
    int hash_mask = 0b10100000000000000001000101;
    return (h ^ (h << 15) ^ hash_mask) % backets_size;
}

template <class T> inline bool unordered_set<T>::isEmpty() const {
    return elements_count == 0;
}

template <class T> inline size_t unordered_set<T>::getSize() const {
    return elements_count;
}

//protected , non usefull fuction
#ifdef _DEBUG
template <class T> T * unordered_set<T>::toArray() {
size_t index = 0;
T* array = new T[elements_count];
for (size_t i = 0; i < backets_size; i++) {
if (!hashmap[i].isEmpty()) {
for (size_t j = 0; j < hashmap[i].getSize(); j++) {
array[index++] = hashmap[i].get(j);
}
}
}
return array;
}
#endif

template<class T> void unordered_set<T>::resize()
{
    size_t old_size = backets_size;
    backets_size *= N;
    vector<T> *newmap = new vector<T>[backets_size];
    for (size_t i = 0; i < old_size; i++) {
        if (!hashmap[i].isEmpty()) {
            for (size_t j = 0; j < hashmap[i].getSize(); j++) {
                T temp = hashmap[i].get(j);
                newmap[hash(temp)].add(temp);
            }
        }
    }
    delete[] hashmap;
    hashmap = newmap;
}
template <class T> class unordered_set<T>::Iterator {
private:
    T* ptr;
    size_t h_index;
    vector<T> *hs;
    size_t h_size;
public:
    Iterator(T* ptr, vector<T> *hs, size_t size) : ptr(ptr), hs(hs), h_index(0), h_size(size) {};
    T* operator++()
    {
        while (ptr != hs[h_size - 1].end() - 1) {
            if (ptr < hs[h_index].end() - 1) {
                return ++ptr;
            }
            h_index++;
            ptr = hs[h_index].begin();
            if (!hs[h_index].isEmpty())
                return ptr;
        }
        ptr = hs[h_size - 1].end();
        return ptr;

    }
    bool operator!=(const Iterator &rv) const
    {
        return ptr != rv.ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    operator T* () const
    {
        return ptr;
    }
};

template <class T> class unordered_set<T>::ConstIterator {
private:
    const T* ptr;
    size_t h_index;
    const vector<T> *hs;
    const size_t h_size;
public:
    ConstIterator(T* ptr, vector<T> *hs, size_t size) : ptr(ptr), hs(hs), h_index(0), h_size(size) {};
    const T* operator++()
    {
        while (ptr != hs[h_size - 1].end() - 1) {
            if (ptr < hs[h_index].end() - 1) {
                return ++ptr;
            }
            h_index++;
            ptr = hs[h_index].begin();
            if (!hs[h_index].isEmpty())
                return ptr;
        }
        ptr = hs[h_size - 1].end();
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