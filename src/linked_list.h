template <typename T>
struct node{
    T data;
    node * next;
};

template <class T>
class linked_list{
private:
    node<T> * first;
public:
    linked_list():first(nullptr){};
    ~linked_list(){
        delete[] first;
    };
    void add(T value);
    bool contains(T value) const;
    void remove(T value);
    void clear();
    T& get(int index) const;
};


template <class T> inline
void linked_list<T>::add(T value) {
    node<T>* newlink = new node<T>;
    newlink->data = value;
    newlink->next = first;
    first = newlink;
}

template <class T>
bool linked_list<T>::contains(T value) const {
    node<T>* current = first;
    while( current != nullptr)
    {
        if (current->data== value) return true;
        current = current->next;
    }
    return false;
}

template <class T> inline
void linked_list<T>::remove(T value) {
    node<T>* current = first;
    while(current != nullptr)
    {
        if (current->next->data==value){
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

template <class T> inline
void linked_list<T>::clear() {
    first = nullptr;
}
template <class T> inline
T& linked_list<T>::get(int index) const{
    node<T>* current = first;
    while((current != nullptr )&&(0<index--))
    {
        current = current->next;
    }
    return current->data;
}
