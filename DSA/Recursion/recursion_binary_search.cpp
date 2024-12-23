#include<iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int target){
    if(start > end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] > target){
        return binarySearch(arr, start, mid, target);
    }
    else{
        return binarySearch(arr, mid + 1, end, target);
    }
}
int main(){
    int arr[6] = {2, 4, 7, 8, 10, 12};
    int target;
    cout << "Enter the value you want to search: ";
    cin >> target;
    cout << endl << endl;
    cout << "The index of " << target << " is: " << binarySearch(arr, 0, 5, target) << endl;
}