//无头结点的单链表
//前向申明
template<typename T>
class SingleLinkList;
//结点类声明
template<typename T>
class Node
{
    friend class SingleLinkList<T>;
    public:
    Node(const T& _elem);
    Node();
    private:
    T elem;
    Node<T>* next;
};

//链表类声明
template<typename T>
class SingleLinkList
{
    private:
    Node<T> *head, *tail;
    int elemNum;

    public:
    SingleLinkList();
    virtual ~SingleLinkList();
    int Length();
    bool InsertAfter(int position, const T& elem);
    bool InsertAfter(int position, const Node<T>);
    bool Delete(int position, T& elem);
    bool Traverse(void (*func)(T& elem));
    void Clear();
    bool GetElem(int positon, T& elem) const;
    bool SetElem(int postion, const T& elem);
    int Prior(T &elem, T &elem_get);
    int Next(T &elem, T &elem_get);
    SingleLinkList(SingleLinkList<T>& obj);//拷贝构造

};

//函数实现
template<typename T>
Node<T>::Node(const T& _elem)
{
    this->elem = _elem;
    next = nullptr;
}

template<typename T>
Node<T>::Node()
{
    elem = T();
    next = nullptr;
}

template<typename T>
SingleLinkList<T>::SingleLinkList()
{
    head = tail = nullptr;
    elemNum = 0;
}

template<typename T>
int SingleLinkList<T>::Length()
{
    return elemNum;
}

template<typename T>
bool SingleLinkList<T>::InsertAfter(int position, const T& elem)
{
    if(position < 0 || position > elemNum)
    {
        return false;
    }
    else
    {
        Node<T>* p = new Node<T>(elem);
        Node<T>* temp;
        temp = head;
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        if(position == elemNum)
        {
            tail = p;
        }
        elemNum++;
        return true;
    }
}

template<typename T>
bool SingleLinkList<T>::InsertAfter(int position, const Node<T> elem)
{
    if(position < 0 || position > elemNum)
    {
        return false;
    }
    else
    {
        Node<T>* temp;
        temp = head;
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        elem.next = temp->next;
        temp->next = &elem;
        if(position == elemNum)
        {
            tail = &elem;
        }
        elemNum++;
        return true;
    }
}

template<typename T>
bool SingleLinkList<T>::Delete(int position, T& elem)
{
    if(position <= 0 || position > elemNum)
    {
        return false;
    }
    else
    {
        if(position == 1)
        {
            Node<T> *save = head->next;
            elem = head->elem;
            delete head;
            head = save;
        }
        else
        {
            Node<T> *save;
            Node<T> * temp = head;
            for(int i = 0; i < position - 2; i++)
            {
                temp = temp->next;
            }
            save = temp->next;
            elem = save->elem;
            temp->next = save->next;
            elemNum--;
            delete save;
        }
        return true;
    }
}

template<typename T>
bool SingleLinkList<T>::Traverse(void (*func)(T& elem))
{
    Node<T> * temp = head;
    for(int i = 0; i < elemNum; i++)
    {
        (*func)(temp->elem);
        temp = temp->next;
    }
    return true;
}

template<typename T>
void SingleLinkList<T>::Clear()
{
    while(elemNum != 0)
    {
        T temp_use;
        this->Delete(1, temp_use);
    }
    tail = nullptr;
    return;
}

template<typename T>
bool SingleLinkList<T>::GetElem(int position, T& elem) const
{
    if(position <= 0 || position > elemNum)
    {
        return false;
    }
    else
    {
        Node<T> * temp = head;
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        elem = temp->elem;
        return true;
    }
}

template<typename T>
bool SingleLinkList<T>::SetElem(int position, const T& elem)
{
    if(position <= 0 || position > elemNum)
    {
        return false;
    }
    else
    {
        Node<T> * temp = head;
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp->elem = elem;
        return true;
    }
}

template<typename T>
int SingleLinkList<T>::Prior(T &elem, T &elem_get)
{
    Node<T> *temp = head->next;
    T priorElem = head->elem;
    for(int i = 1; i < elemNum; i++)
    {
        if(temp->elem == elem)
        {
            elem_get = priorElem;
            return i;
        }
        else
        {
            priorElem = temp->elem;
            temp = temp->next;
        }
    }
    return -1;
}

template<typename T>
int SingleLinkList<T>::Next(T &elem, T &elem_get)
{
    Node<T> *temp = head;
    T nextElem = head->next->elem;
    for(int i = 1; i < elemNum; i++)
    {
        if(temp->elem == elem)
        {
            elem_get = nextElem;
            return i + 1;
        }
        else
        {
            temp = temp->next;
            nextElem = temp->next->elem;
        }
    }
    return -1;
}

template<typename T>
SingleLinkList<T>::~SingleLinkList()
{
    this->Clear();
}