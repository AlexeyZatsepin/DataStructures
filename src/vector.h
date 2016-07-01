#pragma once
#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

const size_t START_CAPACITY = 16;
const size_t K = 2;

template <class T>
class vector {
private:
    T * array;
    size_t size;
    size_t capacity;
public:
    vector();
    vector(size_t capacity);
    vector(const vector<T>&);
    ~vector();
    void add(T value);//push_back
    T remove();
    void remove(size_t index);
    void insert(size_t index, T value);
    size_t getSize() const;
    bool clear();
    bool isEmpty() const;
    T& get(size_t index) const;
    bool contains(T value) const;
    size_t indexOf(T value) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    typedef T* Iterator;
    Iterator begin() { return array; };
    Iterator end() { return array + size ; };

    Iterator rbegin() { return array + size - 1; }
    Iterator rend() { return array - 1; }

    typedef const T* ConstIterator;
    ConstIterator begin() const { return array; };
    ConstIterator end() const { return array + size; };

protected:
    void trimToSize();
    void resize();
};

template <class T>
inline vector<T>::vector()
{
    capacity = START_CAPACITY;
    array = new T[capacity];
    size = 0;
}
template<class T>
inline vector<T>::vector(size_t capacity)
{
    this->capacity = capacity;
    array = new T[capacity];
    size = 0;
}
template<class T>
inline vector<T>::vector(const vector<T> & v)
{
    this->capacity = v.capacity;
    this->size = v.size;
    this->array = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        this->array[i] = v.array[i];
    }
}
template <class T>
inline vector<T>::~vector()
{
    delete[] array;
}

template <class T>
inline void vector<T>::add(T value)//push_back
{
    array[size++] = value;
    if (capacity == size) {
        resize();
    }
}

template<class T>
inline bool vector<T>::clear()
{
    delete[] array;
    array = new T[START_CAPACITY];
    size = 0;
    return true;
}

template <class T>
inline bool vector<T>::isEmpty() const {
    return size == 0;
}

template<class T>
inline T& vector<T>::get(size_t index) const{
#ifdef _DEBUG
    if (index > size) {
throw std::out_of_range("index out of bounds exeption");
}
#endif
    return array[index];
}

template<class T>
inline T vector<T>::remove()
{
    T temp = array[size - 1];
    if (size > 0) {
        size--;
    }
    trimToSize();
    return temp;
}

template<class T>
inline void vector<T>::insert(size_t index, T value) // insert after index
{
    #ifdef _DEBUG
    if (index > size) {
        throw std::out_of_range("index out of bounds exeption");
    }
    #endif
    for (size_t i = size; i > index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = value;
    size++;
    if (capacity == size) {
        resize();
    }
}
template<class T>
inline size_t vector<T>::getSize() const{
    return size;
}
template <class T>
inline void vector<T>::remove(size_t index) {
    #ifdef _DEBUG
    if (index > size)
        throw std::out_of_range("index out of bounds exeption");
    #endif
    for (size_t i = index; i < size; i++) {
        array[i] = array[i + 1];
    }
    size--;
    trimToSize();
}
template<class T>
inline void vector<T>::resize()
{
    capacity = capacity * K;
    T *newVector = new T[capacity];
    for (size_t i = 0; i < capacity / K; i++) {
        newVector[i] = array[i];
    }
    delete[] array;
    array = newVector;
}

template<class T>
inline T& vector<T>::operator[](size_t index)
{
    return array[index];
}

template<class T>
inline const T & vector<T>::operator[](size_t index) const{
    return array[index];
}

template<class T>
bool vector<T>::contains(T value) const{
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

template <class T>
size_t vector<T>::indexOf(T value) const{
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
#ifdef _DEBUG
    throw std::out_of_range("value doesn't exist");
#endif
}

template <class T>
void vector<T>::trimToSize() {
    if (capacity / (K*K) > size) {
        capacity = capacity / K;
        T *newVector = new T[capacity];
        for (size_t i = 0; i < capacity; i++) {
            newVector[i] = array[i];
        }
        delete[] array;
        array = newVector;
    }
}