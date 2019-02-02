#include"vector"
#include"unordered_map"
#include"iostream"
#include"string"
#include"algorithm"
#include"fstream"
using namespace std;
//类定义及简单函数实现
template<class T>
class TreeNode {
    private:
    T element;
    TreeNode<T> *lchild;
    TreeNode<T> *rchild;
    public:
    TreeNode(T elem):element(elem),lchild(nullptr),rchild(nullptr){}
    bool addL(TreeNode<T> *elem);
    bool addR(TreeNode<T> *elem);
    bool isLeaf() {return (this->lchild == nullptr && this->rchild == nullptr);}
    friend void decode(string bin_code, TreeNode<char> *root);
    friend TreeNode<char> *buildHuffman(unordered_map<char,string> &toDic);
};
void decode(string bin_code, TreeNode<char> *root);
TreeNode<char> *buildHuffman(unordered_map<char,string> &toDic);
bool readDic(unordered_map<char, string> &dic, string filename = ".\\huffmandic.csv");
//主函数
int main() {
    char ch;
    string code, bin_code;
    TreeNode<char> *root;
    unordered_map<char,string> toDic;
    readDic(toDic);
    // while(true) {
    //     cout << "请输入字符及其对应的编码" << endl;
    //     cin >> ch >> code;
    // }
    {
toDic['i']="1111";
toDic['s']="1110";
toDic['r']="1101";
toDic['G']="1100";
toDic['a']="10";
toDic['S']="0111";
toDic['h']="0110";
toDic['d']="010";
toDic['o']="00";
}
    cout << "字典内容:" << endl;
    for(auto &x:toDic) {
        cout << x.first << ":" << x.second << endl;
    }
    cout << "输入待译码的内容:" << endl;
    cin >> bin_code;
    root = buildHuffman(toDic);
    decode(bin_code, root);
}
//类函数实现
template<class T>
bool TreeNode<T>::addL(TreeNode<T> *elem) {
    if(lchild == nullptr) {
        lchild = elem;
        return true;
    }
    return false;
}

template<class T>
bool TreeNode<T>::addR(TreeNode<T> *elem) {
    if(rchild == nullptr) {
        rchild = elem;
        return true;
    }
    return false;
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

TreeNode<char> *buildHuffman(unordered_map<char,string> &toDic) {
    TreeNode<char> *p, *root;
    root = new TreeNode<char>('\0');
    for(auto &x:toDic) {
        p = root;
        int len = x.second.length();
        char ch = x.first;
        // cout << x.first << ':' <<x.second << endl;
        for(int i = 0 ; i < len; i++) {
            if(x.second[i] == '1') {
                if(p->lchild == nullptr) {
                    p->lchild = new TreeNode<char>(ch);
                }
                p = p->lchild;
            }
            else {
                if(p->rchild == nullptr) {
                    p->rchild = new TreeNode<char>(ch);
                }
                p = p->rchild;
            }
        }
    }
    return root;
}

bool readDic(unordered_map<char, string> &dic, string filename) {
    ifstream fin(filename, ios::in);
    char a;
    string code;
    if(!fin.good()) {
        fin.close();
        return false;
    }
    while(getline(fin,code)) {
        a = code[0];
        dic[a] = code.substr(2);
    }
    fin.close();
    return true;
}