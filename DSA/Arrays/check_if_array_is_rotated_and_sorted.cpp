#include<iostream>
using namespace std;
int main(){
    int arr[5] = {3, 4, 5, 1, 2};
    int n = 5;
    int count = 0;
    cout << "The array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < n; i++){
        if(arr[i - 1] > arr[i]){
            count++;
        }
    }
    if(arr[n - 1] > arr[0]){
        count++;
    }
    if(count <= 1){
        cout << "The array is rotated and sorted. " << endl;
    }
    else{
        cout << "The array is not rotated and sorted. " << endl;
    }
}