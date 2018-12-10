//前向申明
template<class T>
class list;
template<class T>
class ListIter;
//结点类声明
template<class T>
class Node
{
    friend class list<T>;
    friend class ListIter<T>;
    public:
    Node(const T &_elem);
    Node();
    private:
    T elem;
    Node<T> *pre;
    Node<T> *next;
};
//双向链表类声明
template<class T>
class list
{
    friend class ListIter<T>;
    private:
    Node<T> *head, *tail;
    int elemNum;

    public:
    list();
    ~list();
    bool empty();
    void push_back(const T elem);
    bool insert(const ListIter<T> &it, const T &elem);
    ListIter<T> begin();
    ListIter<T> end();
    ListIter<T> erase(ListIter<T> &it);
    void clear();
    int size();
};
//迭代器友元函数声明
template<class T>
void advance(ListIter<T> &it, int num);
//迭代器类声明以及实现
template<class T>
class ListIter {
    friend class list<T>;
    private:
    Node<T> *element;
    public:
    ListIter(Node<T> *elem = nullptr):element(elem){}
    void operator++(int) {
        if(element->next != nullptr) {
            element = element->next;
        }
    }
    void operator++() {
        if(element->next != nullptr) {
            element = element->next;
        }
    }
    void operator--(int) {
        if(element->pre->pre == nullptr) {
            return;
        }
        element = element->pre;
    }
    void operator--() {
        if(element->pre->pre == nullptr) {
            return;
        }
        element = element->pre;
    }
    T &operator *() {
        return element->elem;
    }
    bool operator==(const ListIter<T> &obj) {
        return this->element == obj.element;
    }
    bool operator !=(const ListIter<T> &obj) {
        return this->element != obj.element;
    }
    T *operator->() {
        return &element->elem;
    }
    friend void advance<>(ListIter<T> &it, int num);
};
//函数实现
template<class T>
Node<T>::Node(const T& _elem)
{
    this->elem = _elem;
    pre = nullptr;
    next = nullptr;
}

template<class T>
Node<T>::Node()
{
    elem = T();
    pre = nullptr;
    next = nullptr;
}

template<class T>
list<T>::list()
{
    tail = head = new Node<T>();
    head-> pre= new Node<T>();
    head->pre ->next = head;
    elemNum = 0;
}

template<class T>
bool list<T>::empty() {
    return elemNum==0;
}

template<class T>
ListIter<T> list<T>::begin() {
    return ListIter<T>(head);
}

template<class T>
ListIter<T> list<T>::end() {
    return ListIter<T>(tail);
}

template<class T>
int list<T>::size() {
    return elemNum;
}

template<class T>
bool list<T>::insert(const ListIter<T> &it, const T &elem)
{
    Node<T> *p = new Node<T>(elem);
    p->pre = it.element->pre;
    p->next = it.element;
    p->pre->next = p;
    it.element->pre = p;
    if(it.element == head) {
        head = p;
    }
    elemNum++;
    return true;
}

template<class T>
void list<T>::push_back(const T elem) {
    insert(this->end(),elem);
}

template<class T>
ListIter<T> list<T>::erase(ListIter<T> &it)
{
    if(elemNum == 0) {
        return it;
    }
    Node<T> *p = it.element;
    if(p == tail) {
        return it;
    }
    p->pre->next = p->next;
    p->next->pre = p->pre;
    it.element = it.element->next;
    delete p;
    if(p == head) {
        head = it.element;
    }
    elemNum--;
    return it;
}

template<class T>
void list<T>::clear()
{
    ListIter<T> it = this->begin();
    while(it != this->end()) {
        it = this->erase(it);
    }
    return;
}

template<class T>
list<T>::~list()
{
    this->clear();
    delete head->pre;
    delete head;
}

template<class T>
void advance(ListIter<T> &it, int num) {
    if(num > 0) {
        while(num--) {
            it++;
        }
    }
    else {
        while(num++) {
            it--;
        }
    }
}

// int main() {
//     list<int> a;
//     ListIter<int> it = a.begin();
//     for(int i =  0; i < 10; i++) {
//         a.push_back(i);
//     }
//     it = a.begin();
//     it++;
//     it = a.erase(it);
//     for(it = a.begin(); it != a.end(); it++) {
//         cout << *it << endl;
//     }
//     a.clear();
//     cout << 'h' << endl;
//     for(it = a.begin(); it != a.end(); it++) {
//         cout << *it << endl;
//     }
//     return 0;
// }