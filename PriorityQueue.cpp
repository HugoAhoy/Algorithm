#include"algorithm"
#include"vector"
using namespace std;

template<class T>
class priority_queue {
    private:
    int size;
    vector<T> pq;
    void heapify(int i);
    int Index_of_Max(int i, vector<T> &heap);

    public:
    priority_queue():size(0){pq.push_back(T());}
    void push(T &elem);
    T pop();
};

template<class T>
int priority_queue<T>::Index_of_Max(int i, vector<T> &heap) {
    //TODO
    return i;
}

template<class T>
void priority_queue<T>::heapify(int i) {
    int size = heap.size();this->pq.size();
    if(i*2 > size) {
        return;
    }
    else if(i*2 + 1 > size) {
        if(heap[i] < heap[i*2]) {
            swap(heap[i], heap[i*2]);
        }
        heapify(i*2);
    }
    else {
        int idx = Index_of_Max(i);
        if(idx == i) {
            return;
        }
        else {
            swap(heap[idx], heap[i]);
            heapify(idx);
        }
    }
    return;
}

template<class T>
void priority_queue<T>::push(T &elem) {
    pq.push_back(elem);
    for(int i = this->size/2; i > 0; i--) {
        this->heapify(i);
    }
}