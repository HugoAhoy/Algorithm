#include"vector"
#include"unordered_map"
#include"iostream"
#include"string"
#include"algorithm"
using namespace std;

//结点类声明及简单函数定义
template <class T>
class TreeNode {
    private:
    T element;
    int weight;
    string coding;
    TreeNode<T> *lchild;
    TreeNode<T> *rchild;
    public:
    TreeNode(T elem, int weight):element(elem),weight(weight),lchild(nullptr),rchild(nullptr),coding(""){}
    int getWeight() const {return weight;}
    bool addL(TreeNode<T> &elem);
    bool addR(TreeNode<T> &elem);
    bool isLeaf() {return (this->lchild == nullptr && this->rchild == nullptr);}
    void print() {cout << element << ':' << this->coding << endl;}
    friend TreeNode<char>* operator+(TreeNode<char> &_a,TreeNode<char> &_b);
    friend void Traverse(TreeNode<char> *root, unordered_map<char, string> &_toDic);
    friend void decode(string bin_code, TreeNode<char> *root);
};
//函数定义
TreeNode<char>* buildHuffman(vector<TreeNode<char>* > &pq);
void buildDic(string text, unordered_map<char, int> &dic);
//主函数
int main() {
    string text;
    vector<TreeNode<char>* > pq;
    TreeNode<char> *root;
    cin >> text;
    unordered_map<char, int> stat;
    unordered_map<char, string>toDic;
    buildDic(text, stat);
    for(auto &x:stat) {
        pq.push_back(new TreeNode<char>(x.first, x.second));
    }
    sort(pq.begin(), pq.end(), 
            [](const TreeNode<char> *_a,const TreeNode<char> *_b) {
                return _a->getWeight() > _b->getWeight();
                }
    );
    Traverse(buildHuffman(pq),toDic);
    return 0;   
}
//类函数及友元函数定义
TreeNode<char>* buildHuffman(vector<TreeNode<char>* > &pq) {
    TreeNode<char> *root, *right, *left;
    if(pq.empty()) {
        return nullptr;
    }
    while(pq.size() > 1) {
        right = pq.back();
        pq.pop_back();
        left = pq.back();
        pq.pop_back();
        root = *right + *left;
        root->addL(*left);
        root->addR(*right);
        pq.push_back(root);
        sort(pq.begin(), pq.end(), 
             [](const TreeNode<char> *_a,const TreeNode<char> *_b) {
                 return _a->getWeight() > _b->getWeight();
                 }
        );
    }
    root = pq.back();
    pq.pop_back();
    return root;
}

TreeNode<char>* operator+(TreeNode<char> &_a,TreeNode<char> &_b) {
    return new TreeNode<char>('\0',_a.weight + _b.weight);
}

template<class T>
bool TreeNode<T>::addL(TreeNode<T> &elem) {
    if(lchild == nullptr) {
        lchild = &elem;
        return true;
    }
    return false;
}

template<class T>
bool TreeNode<T>::addR(TreeNode<T> &elem) {
    if(rchild == nullptr) {
        rchild = &elem;
        return true;
    }
    return false;
}

void buildDic(string text, unordered_map<char, int> &dic) {
    int len = text.length();
    for(int i = 0; i < len; i++) {
        if(dic.find(text[i])==dic.end()) {
            dic[text[i]] = 1;
        }
        else {
            dic.at(text[i]) += 1;
        }
    }
}

void Traverse(TreeNode<char> *root, unordered_map<char, string> &_toDic) {
    if(root->isLeaf()) {
        root->print();
        return;
    }
    
    if (root->lchild != nullptr) {
        root->lchild->coding =  root->coding + '1';
        Traverse(root->lchild, _toDic);
    }
    if (root->rchild != nullptr) {
        root->rchild->coding =  root->coding + '0';
        Traverse(root->rchild, _toDic);
    }
    return;
}

void decode(string bin_code, TreeNode<char> *root) {
    string ans = "";
    TreeNode<char> *p = root;
    int len = bin_code.length();
    for(int i = 0 ;i < len; i++) {
        p = bin_code[i] == '1' ? p->lchild : p->rchild;
        if(p->isLeaf()) {
            ans = ans + p->element;
            p = root;
        }
    }
    cout << ans << endl;
}