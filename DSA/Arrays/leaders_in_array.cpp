#include<iostream>
using namespace std;
int main(){
    int arr[6] = {16, 17, 4, 5, 3, 2};
    int n = 6;
    cout << "The leaders in the array are: ";
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]){
            cout << arr[i] << " ";
        }
    }
    cout << arr[n - 1];
}