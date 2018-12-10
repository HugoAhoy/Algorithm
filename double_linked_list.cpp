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
    Node(const T& _elem);
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
    bool empty(){return elemNum==0;};
    void push_back(const T elem);
    bool insert(ListIter<T> it, const T elem);
    ListIter<T> begin() {return ListIter<T>(this->head);}
    ListIter<T> end() {return tail->next;}
    bool erase(ListIter<T> it, T& elem);
    void clear();
    //begin(),end() iterator, advance(),erase()
};

//迭代器类声明
template<class T>
class ListIter {
    friend class list<T>;
    private:
    Node<T> *element;
    public:
    ListIter(Node<T> *elem):element(elem){}
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
        if(element == head) {
            return;
        }
        element = element->pre;
    }
    void operator--() {
        if(element == head) {
            return;
        }
        element = element->pre;
    }
    T &operator *() {
        return &element->elem;
    }
    bool operator==(ListIter<T> &obj) {
        return this->element == obj.element;
    }
    friend void advance(ListIter<T> it, int num);
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
bool list<T>::insert(ListIter<T> it, const T elem)
{
    Node<T> *p = new Node<T>(elem);
    p->pre = it.element->pre;
    p->pre->next = p;
    it.element->pre = p;
    if(it == this->begin()) {
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
bool list<T>::erase(ListIter<T> it, T& elem)
{
    if(elemNum == 0) {
        return false;
    }
    Node<T> *p = it.element;
    it.element->pre->next = it.element->next;
    it.element->next->pre = it.element->pre;
    p = it.element;
    it.element = it.element->next;
    delete p;
    elemNum--;
    return true;
}

template<class T>
void list<T>::clear()
{
    ListIter<T> it = this->begin();
    while(!(it == this->end()) {
        this->erase(it);
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
void advance(ListIter<T> it, int num) {
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