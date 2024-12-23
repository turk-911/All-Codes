#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = s + count; // place pivot at right position
    swap(arr[pivotIndex], arr[s]);
    int left = s;
    int right = e;
    while(left < pivotIndex && right > pivotIndex){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }
        if (left < pivotIndex && right > pivotIndex){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e){
    // base case
    if(s >= e){
        return ;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}
int main(){
    int arr[7] = {4, 3, 5, 1, 0, -9, 7};
    quickSort(arr, 0, 6 );
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}