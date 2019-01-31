#include"algorithm"
#include"vector"
using namespace std;

template<class T>
class priority_queue {
    private:
    int size;
    vector<T> pq;
    void heapify(int i);
    int Index_of_Max(int i);

    public:
    priority_queue():size(0){pq.push_back(T());}
    void push(T &elem);
    T pop();
};

template<class T>
int priority_queue<T>::Index_of_Max(int i) {
    int res_idx = i;
    if(pq[i] <pq[i*2]) {
        res_idx = i*2;
    }
    if(pq[res_idx] < pq[i*2+1]) {
        res_idx = i*2+1;
    }
    return res_idx;
}

template<class T>
void priority_queue<T>::heapify(int i) {
    if(i*2 > size) {
        return;
    }
    else if(i*2 + 1 > size) {
        if(pq[i] < pq[i*2]) {
            swap(pq[i], pq[i*2]);
        }
        heapify(i*2);
    }
    else {
        int idx = Index_of_Max(i);
        if(idx == i) {
            return;
        }
        else {
            swap(pq[idx], pq[i]);
            heapify(idx);
        }
    }
    return;
}

template<class T>
void priority_queue<T>::push(T &elem) {
    pq.push_back(elem);
    size++;
    for(int i = size/2; i > 0; i--) {
        this->heapify(i);
    }
}

template<class T>
T priority_queue<T>::pop() {
    T res = pq.pop_back();
    swap(pq[1],pq[size]);
    size--;
    for(int i = this->size/2; i > 0; i--) {
        this->heapify(i);
    }

    return res;
}