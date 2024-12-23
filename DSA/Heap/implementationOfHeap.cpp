#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteFromHeap(){
        if(size == 0){
            cout << "There is nothing to delete from the heap" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = (2 * i) + 1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;  
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};
void maxHeapify(int arr[], int n, int index){
    int i = index;
    int largest = index;
    int left = 2 * i;
    int right = 2*i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[index]);
        maxHeapify(arr, n, largest);
    }
}   
void minHeapify(int arr[], int n, int index){
    int smallest = index;
    int i = index;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest], arr[index]);
        minHeapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        maxHeapify(arr, size, 1);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(54);
    h.insert(55);
    h.insert(53);
    h.insert(59);
    h.insert(100);
    cout << "Before deleting: ";
    h.print();
    h.deleteFromHeap();
    cout << "After deleting: ";
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    cout << "Printing the original array: ";
    for(int i = 1; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = n / 2; i > 0; i--){
        maxHeapify(arr, n, i);
    }
    cout << "Printing the array after maxHeapify now: ";
    for(int i = 1; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Printing the array after minHeapify now: ";
    for(int i = n /2; i > 0; i--){
        minHeapify(arr, n, i);
    }
    for(int i = 1; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Printing the sorted array: ";
    heapSort(arr, 5);
    for(int i = 1; i > 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}