class UF {
    private:
    int *id;
    int _count;
    public:
    UF(int N) {
        id = new int[N];
        for(int i = 0; i < N; i++) {
            id[i] = i;
        }
        _count = N;
    }
    void unite(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    int count();
};

int UF::find(int p) {
    if(id[p] == p) {
        return p;
    }
    else {
        return find(id[p]);
    }
}

bool UF::connected(int p, int q) {
    return find(p) == find(q);
}

void UF::unite(int p, int q) {
    if(id[find(p)] != find(q)) {
        id[find(p)] = find(q);
        _count--;
    }
}

int UF::count() {
    return _count;
}

//union_find test
#include"iostream"
using namespace std;
int main() {
    char OP;
    int n, T, t;
    int p, q;
    cin >> n >> T >> t;
    UF a(n);
    for(int i = 0; i <= T; i++) {
        cin >> p >> q;
        a.unite(p, q);
    }
    cout << "Query Start" << endl;
    while(t--) {
        cin >> OP;
        if(OP == 'C') {
            cin >> p >> q;
            cout << a.connected(p, q) << endl;
        }
        else if(OP == 'F'){
            cin >> q;
            cout << a.find(q) << endl;
        }
        else {
            cout << a.count() << endl;
        }
    }
    return 0;
}