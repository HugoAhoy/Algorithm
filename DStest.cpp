#include"iostream"
#include"sequencelist.cpp"
using namespace std;
void print(int &elem)
{
    cout << "Print: " << elem << endl;
    return;
}

int main()
{
    int rcv;
    SqList<int> list(0);
    cout << list.Length() << endl;
    cout << list.Insert(1,5) << endl;
    cout << list.Insert(2,6) << endl;
    cout << list.Length() << endl;
    list.Traverse(print);
    cout << endl;
    list.Insert(1,3);
    list.Insert(3,98);
    list.Traverse(print);
    cout << endl;
    list.Delete(2,rcv);
    list.Traverse(print);
    cout << endl;
    cout << "rcv:" << rcv << endl;
    cout << list.SetElem(2,7) << endl;
    cout << list.SetElem(8,9) << endl;
    cout << list.GetElem(3,rcv) << endl;
    list.Traverse(print);
    cout << endl;
    cout << "rcv:" << rcv << endl;
    cout << list.GetElem(8,rcv) << endl;
    list.Clear();
    cout << "traverse when it's cleared." << endl;
    list.Traverse(print);
    return 0;
}