#include"sequencelist.cpp"
template<typename T>
class Stack:public SqList<T>
{
    public:
    Stack(int n = DEFAULT_SIZE, int max = DEFAULT_MAXSIZE):SqList<T>(n, max){}
    ~Stack();
    bool Push(T elem) const;
    bool Pop(T &elem);
    bool Top(T &elem) const;
};

template<typename T>
inline bool Stack<T>::Push(T elem) const
{
    return Insert(size + 1,elem);
}

template<typename T>
inline bool Stack<T>::Pop(T &elem)
{
    return Delete(size, elem);
}

template<typename T>
inline bool Stack<T>::Top(T &elem) const
{
    return GetElem(size, elem);
}