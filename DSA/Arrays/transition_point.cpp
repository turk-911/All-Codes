#include<iostream>
using namespace std;
int main(){
    int arr[5] = {0, 0, 0, 1, 1};
    int n = 5;
    cout << "The array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    cout << "The transition point in the above array is by 0  based indexing is: ";
    while(start <= end){
        if(arr[mid] ==  1 && (mid == 0 || arr[mid - 1] == 0)){
            cout << mid;
            break;
        }
        if(arr[mid] == 0){
            start = mid + 1;
        }
        if(arr[mid] == 1){
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
}