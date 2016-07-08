#include <stddef.h>

#define START_CAPACITY 10

template <class T>
class max_heap{
private:
    T* h;
    unsigned int size;
    unsigned int capacity;
public:
    max_heap():h(new T[START_CAPACITY]),size(0),capacity(START_CAPACITY){};
    max_heap(unsigned int capacity):h(new T[capacity]),size(0),capacity(capacity){};
    ~max_heap(){ delete h;};
    void add(T element);
    void remove();
    T top() const {
        return h[0];
    };
    bool isEmpty(){
        return size == 0;
    };
protected:
    void resize();
};
template <class T>
void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
template <class T>
void max_heap<T>::add(T element) {
    int i = size++;
    h[i] = element;
    int p = (i - 1) / 2;
    while (p >= 0 && h[p] < h[i])
    {
        swap(h[i], h[p]);
        i = p;
        p = (i - 1) / 2;
    }
    if (size==capacity){
        resize();
    }
}

template <class T>
void max_heap<T>::remove() {
    T i = 0, sc = -1;
    swap(h[i], h[--size]);
    while (true)
    {
        T c1 = i * 2 + 1,
                c2 = i * 2 + 2;
        T sc = i;
        if (c1 < size && h[c1] > h[sc]) sc = c1;
        if (c2 < size && h[c2] > h[sc]) sc = c2;
        if (sc == i) break;
        swap(h[sc], h[i]);
        i = sc;
    }
}
template <class T>
void max_heap<T>::resize() {
    capacity *= 2;
    T * data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i]=h[i];
    }
    h = data;
    delete data;
}
