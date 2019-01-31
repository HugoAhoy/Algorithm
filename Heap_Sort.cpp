#include"vector"
#include"algorithm"
using namespace std;

template<class T>
int Index_of_Max(int i, T arr[]) {
    int res_idx = i;
    if(arr[i] <arr[i*2]) {
        res_idx = i*2;
    }
    if(arr[res_idx] < arr[i*2+1]) {
        res_idx = i*2+1;
    }
    return res_idx;
}

template<class T>
void heapify(int i, T arr[], int size) {
    if(i*2 > size) {
        return;
    }
    else if(i*2 + 1 > size) {
        if(arr[i] < arr[i*2]) {
            swap(arr[i], arr[i*2]);
        }
        heapify(i*2, arr, size);
    }
    else {
        int idx = Index_of_Max(i, arr);
        if(idx == i) {
            return;
        }
        else {
            swap(arr[idx], arr[i]);
            heapify(idx, arr, size);
        }
    }
    return;
}

template<class T>
void HeapSort(T arr[], int size) {
    T *p = arr-1;
    for(int i = size/2; i > 0; i--) {
        heapify(i, p, size);
    }
    for(int i = size - 1; i >= 1; i--) {
        swap(p[1],p[i+1]);
        heapify(1, p, i);
    }
    return;
}
#include"iostream"
int main() {
    int a[] = {0,3,7,4,8,4,18,89};
    // vector<int> a = {0,3,7,4,8,4,18,89};
    // for(int i = (a.size()-1)/2; i > 0; i--) {
    //     heapify(i, a, a.size());
    // }
    // for(int i = a.size() - 2; i >= 1; i--) {
    //     swap(a[1],a[i+1]);
    //     heapify(1, a, i);
    // }
    HeapSort(a, 8);
    for(auto &x:a) {
        cout << x << endl;
    }
    return 0;
}