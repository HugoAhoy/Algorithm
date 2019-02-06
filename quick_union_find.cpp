class UF {
    public:
    UF(int N) {
        _count = N;
        id = new int[N];
        for(int i = 0; i < N; i++) {
            id[i] = i;
        }
    }
    int count();
    void unite(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    private:
    int *id;
    int _count;
};

void UF::unite(int p, int q) {
    if(id[find(p)] != find(q)) {
        id[find(p)] = find(q);
        _count--;
    }
    return;
}

int UF::find(int p) {
    if(id[p] != p) {
        return id[p] = find(id[p]);
    }
}

int UF::count() {
    return _count;
}

int UF::connected(int p, int q) {
    return id[p] == id[q];
}