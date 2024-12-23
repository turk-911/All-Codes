#include<iostream>
using namespace std;
int main(){
    int arr[5] = {2, 4, 3, 8, 4};
    int n = 5;
    for(int i = 1; i <= n; i++){
        if(arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1]){
            cout << i << " " ;  
        }
    }
}