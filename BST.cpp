template<class K, class V>
class Node {
    private:
    Node *lchild;
    Node *rchild;
    K key;
    V value;
    public:
    Node(K Key, V Value);
    Node(const Node<K,V> &elem);
};

template<class K, class V>
class BST{
    friend class Node<K, V>;
    private:
    Node<K, V> *root;
    int _size;
    bool find(Node<K,V> *root, K Key);
    public:
    BST():root(nullptr){}
    void put(K Key, V value);
    void put(const Node<K, V> &elem);
    V get(K Key);
    void Delete(K Key);
    bool contains(K Keys);
    bool isEmpty();
    int size();
};

template<class K, class V>
Node<K, V>::Node(K Key, V Value) {
    key = Key;
    value = Value;
    lchild = rchild = nullptr;
}
template<class K, class V>
Node<K, V>::Node(const Node<K,V> &elem) {
    this->key = elem.key;
    this->value = elem.value;
    this->rchild = elem.rchild;
    this->lchild = elem.lchild;
}

template<class K, class V>
void put(K Key, V Value) {
    if(root == nullptr) {
        root = new Node<K, V>(Key, Value);
        return;
    }
    Node<K, V> *p = root;
    while(true) {
        if(Key > p->key) {
            if(p->rchild == nullptr) {
                p->lchild = new Node<K, V>(Key, Value);
                return;
            }
            else {
                p = p->lchild;
            }
        }
        else if(Key == p->key) {
            p->value = value;
            return;
        }
        else {
            if(p ->rchild == nullptr) {
                p->rchild = new Node<K, V>(Key, Value);
                return;
            }
            else {
                p = p->rchild;
            }
        }
    }
}

template<class K, class V>
void put(const Node<K,V> &elem) {
    if(root == nullptr) {
        root = new Node<K, V>(elem);
        return;
    }
    Node<K, V> *p = root;
    while(true) {
        if(Key > p->key) {
            if(p->rchild == nullptr) {
                p->lchild = new Node<K, V>(elem);
                return;
            }
            else {
                p = p->lchild;
            }
        }
        else if(Key == p->key) {
            p->value = value;
            return;
        }
        else {
            if(p ->rchild == nullptr) {
                p->rchild = new Node<K, V>(elem);
                return;
            }
            else {
                p = p->rchild;
            }
        }
    }
}

template<class K, class V>
bool BST<K,V>::find(Node<K,V> *root, K Key) {
    if(root == nullptr) {
        return false;
    }
    if(root->key == Key) {
        return true;
    }
    else if(root->key < Key) {
       return find(root->rchild, Key);
    }
    else {
        return find(root->lchild, Key);
    }
}

template<class K, class V>
bool BST<K,V>::contains(K Key) {
    return find(this->root, Key);
}

//TODO