//2-way Merge Sort
template<class T>
void Merge(T a[],int low, int mid, int high, T assis[]) {
    int k = 0;
    int i = low, j= mid+1;
    for(; i <= mid &&j <= high;) {
        if(a[i] < a[j]) {
            assis[k++] = a[i++];
        }
        else {
            assis[k++] = a[j++];
        }
    }
    if(i > mid) {
        i = j;
    }
    while(k <= high) {
        assis[k++] = a[i++];
    }
    for(int i = 0; i < k; i++) {
        a[i] = assis[i];
    }
}

template<class T>
void Div_and_Merge(T a[], int size, T assis[]){
    if(size > 2) {
        Div_and_Merge(a, size/2, assis);
        Div_and_Merge(a+size/2, size-size/2, assis);
    }
    Merge(a, 0, size/2-1, size-1, assis);
}

template<class T>
void MergeSort(T a[], int size) {
    T *assis = new T[size];
    Div_and_Merge(a, size, assis);
    delete [] assis;
    assis = nullptr;
}

//function_test
#include"iostream"
using namespace std;

int main() {
    int a[] = {9,15,26,8,99,100,0,3};
    MergeSort(a,sizeof(a)/sizeof(int));
    for(int i =0; i < sizeof(a)/sizeof(int);i++) {
        cout << a[i] << endl;
    }
    return 0;
}