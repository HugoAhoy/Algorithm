//无头结点的单链表
//前向申明
template<typename T>
class SingLinkList;
//结点类声明
template<typename T>
class Node
{
    friend class SingLinkList<T>;
    private:
    T elem;
    Node<T>* next;
};

//链表类声明
template<typename T>
class SingLinkList
{
    private:
    Node<T> *head, *tail;

    public:
    SingLinkList();
    virtual ~SingLinkList();
    bool Insert(int position, const T& elem);
    bool Delete(int position, T& elem);
    bool Traverse();
    void Clear();
    bool GetElem(int positon, T& elem) const;
    bool SetElem(int postion, const T& elem);
    int Prior(T &elem, T &elem_get);
    int Next(T &elem, T &elem_get);
    SingLinkList(SingLinkList<T>& obj);//拷贝构造

};

//函数实现
template<typename T>
SingLinkList<T>::SingLinkList()
{
    head = tail = nullptr;
}