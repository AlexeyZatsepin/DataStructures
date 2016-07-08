#include <stddef.h>

template <class T>
class queue{
private:
    T *q,*head,*tail;
public:
    queue(size_t capacity){
        q=new T[capacity];
        head=tail=q;
    }
    T front(){
        return *head;
    }
    void push(T value){
        *tail++ = value;
    }
    T pop(){
        return *head++;
    }
    bool empty() const{
        return head==tail;
    }
};