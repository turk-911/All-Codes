#include<iostream>
using namespace std;
int main(){
    int arr[10] = {-8, 0, 3, -6, -10, 7, 9, -11, 8, -2};
    int n = 10;
    cout << "Printing of 0 indicates that there is no negative number in two consecutive numbers. ";
    cout << endl;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] < 0 && arr[i + 1] < 0){
            cout << arr[i] << " ";
        }
        if(arr[i] >=0 && arr[i + 1] < 0){
            cout << arr[i + 1] << " ";
        }
        if(arr[i] < 0 && arr[i + 1] >= 0){
            cout << arr[i] << " ";
        }
        if(arr[i] >= 0 && arr[i + 1] >= 0){
            cout << "0 " ;
        }
    }
}