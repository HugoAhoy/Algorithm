#include"iostream"
using namespace std;
//Quick_Sort
template<class T>
int make_order(T arr[], int size) {
    // if(size <= 1) {
    //     return 0;
    // }
    bool direction = true;
    T *p = arr, *q = arr+size-1, temp;
    while(p != q) {
        if(*p >*q) {    
            //exchage the two number
            temp = *p;
            *p = *q;
            *q = temp;
            direction = !direction;
        }
        //move the pointer
        if(direction) {
            q--;
        }
        else {
            p++;
        }
    }
    return (q-arr)/sizeof(T);
}

template<class T>
void QuickSort(T arr[], int size) {
    if(size <= 1) {
        return;
    }
    int divide = make_order(arr, size);
    // cout << divide << endl;
    QuickSort(arr, divide);
    QuickSort(arr+divide+1, size-divide-1);
}

int main() {
    int a[] = {9,15,26,8,99,100,0,3};
    QuickSort(a,sizeof(a)/sizeof(int));
    for(int i =0; i < sizeof(a)/sizeof(int);i++) {
        cout << a[i] << endl;
    }
    return 0;
}