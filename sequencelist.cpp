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
    void Traverse();//参数不明白
    bool GetElem(int positon, T& elem) const;
    bool SetElem(int postion, const T& elem);
    bool Delete(int position, T& elem);
    bool Insert(int position, const T& elem);
    SqList(SqList<T>& obj);//拷贝构造
    SqList<T>& operator = (const SqList<T>& obj);//复制运算符重载
};

//函数实现
template<typename T>
bool SqList<T>::Full() const
{
    return size == maxsize;
}

template<typename T>
void SqList<T>::init(int size)
{
    this->data = new T[this->MAXSIZE];
    //如何初始化？
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
    delete data[];
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
void SqList<T>::Traverse()
{
    //待补充
    return;
}

template<typename T>
bool SqList<T>::GetElem(int position, T& elem) const
{
    if(postion < 1 || postion > size)
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
    if(postion < 1 || postion > size)
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
    if(postion < 1 || postion > size)
    {
        return false;
    }
    else
    {
        elem = data[position - 1];
        for(int i = position - 1; i < size - 2 ; i++)
        {
            data[i] = data[i + 1];
        }
        return true;
    }
}

template<typename T>
bool SqList<T>::Insert(int position, const T& elem)
{
    if(postion < 1 || postion > size)
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