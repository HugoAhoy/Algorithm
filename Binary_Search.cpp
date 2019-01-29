//Binary_Search
template<class T>
int BinarySearch(T arr[], int size, T element) {
    int high = size - 1, low = 0, mid = (high + low)/2;
    while(high >= low) {
        if(arr[mid] == element) {
            return mid;
        }
        else {
            if(arr[mid] < element) {
                low = mid +1;
                mid = (high + low)/2;
            }
            else {
                high = mid -1;
                mid  = (high + low)/2;
            }
        }
    }
    return -1;
}