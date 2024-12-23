#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (-start + end)/2;
    while(start <= end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (-start + end)/2;
    }
    return -1;
}
int main(){
    int even[6] = {1, 4, 7, 23, 24, 39};
    int odd[5] = {-3, 0, 4, 6, 7};
    int index = binarySearch(odd, 5, -3);
    cout << "Index of -3 is " << index << endl;

}