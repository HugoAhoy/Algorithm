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
    // cout << "divide_index = " << (q-arr) << endl;
    return (q-arr);
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

#include"iostream"
using namespace std;

int main() {
    int b[] = {10,9,8,7,6,5,4,3,2,1};
    int a[] = {9,15,26,8,99,100,0,3};
    QuickSort(a,sizeof(a)/sizeof(int));
    // make_order(b,sizeof(b)/sizeof(int));
    // make_order(b,sizeof(b)/sizeof(int)-1);
    // make_order(b+1,sizeof(b)/sizeof(int)-2);    
    for(int i =0; i < sizeof(a)/sizeof(int);i++) {
        cout << a[i] << endl;
    }
    return 0;
}