int const DEFAULT_SIZE = 10;

//顺序表声明
template<typename T>
class SqList
{
    private:
    int size;
    int MAXSIZE;
    T *data;
    bool Full() const;
    void init(int size);

    public:
    SqList(int n = DEFAULT_SIZE);//构造函数，初始化一个含有n个元素的空表
    virtual ~SqList();//虚析构函数
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void (*func)(T& elem));
    bool GetElem(int positon, T& elem) const;
    bool SetElem(int postion, const T& elem);
    bool Delete(int position, T& elem);
    bool Insert(int position, const T& elem);
    int Prior(T &elem, T &elem_get);
    int Next(T &elem, T &elem_get);
    SqList(SqList<T>& obj);//拷贝构造
    SqList<T>& operator = (const SqList<T>& obj);//复制运算符重载
};

//函数实现
template<typename T>
bool SqList<T>::Full() const
{
    return size == MAXSIZE;
}

template<typename T>
void SqList<T>::init(int size)
{
    this->data = new T[this->MAXSIZE];
    this->size = size;
    for(int i = 0; i < size; i++)
    {
        data[i] = T();
    }
    return;
}

template<typename T>
SqList<T>::SqList(int size)
{
    this->MAXSIZE = 50;
    init(size);
}

template<typename T>
SqList<T>::~SqList()
{
    delete []data;
}

template<typename T>
int SqList<T>::Length() const
{
    return size;
}

template<typename T>
bool SqList<T>::Empty() const
{
    return size == 0;
}

template<typename T>
void SqList<T> :: Clear()
{
    size = 0;
    return;
}

template<typename T>
void SqList<T>:: Traverse(void (*func)(T& elem))
{
    for(int i = 0; i < this->Length(); i++)
    {
        (*func)(this->data[i]);
    }
    return;
}

template<typename T>
bool SqList<T>::GetElem(int position, T& elem) const
{
    if(position < 1 || position > size)
    {
        return false;
    }
    else
    {
        elem = data[position - 1];
        return true;
    }
}

template<typename T>
bool SqList<T>::SetElem(int position, const T& elem)
{
    if(position < 1 || position > size)
    {
        return false;
    }
    else
    {
        data[position - 1] = elem;
        return true;
    }
}

template<typename T>
bool SqList<T>::Delete(int position, T& elem)
{
    if(position < 1 || position > size)
    {
        return false;
    }
    else
    {
        elem = data[position - 1];
        for(int i = position - 1; i < size - 1 ; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
}

template<typename T>
bool SqList<T>::Insert(int position, const T& elem)
{
    if(position < 0 || position > size + 1)
    {
        return false;
    }
    else
    {
        for(int i = size - 1; i >= position - 1; i--)
        {
            data[i + 1] = data[i];
        }
        data[position - 1] = elem;
        size++;
        return true;
    }
}

template<typename T>
SqList<T>::SqList(SqList<T>& obj)
{
    this->size = obj.size;
    this->MAXSIZE = obj.MAXSIZE;
    this->init();
    for(int i = 0; i < obj.size; i++)
    {
        this->data[i] = obj.data[i];
    }
}

template<typename T>
SqList<T>& SqList<T>::operator =(const SqList<T>& obj)
{
    this->size = obj.size;
    this->MAXSIZE = obj.MAXSIZE;
    this->init();
    for(int i = 0; i < obj.size; i++)
    {
        this->data[i] = obj.data[i];
    }
    return *this;
}