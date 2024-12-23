#include<iostream>
using namespace std;
// int start = 0; means default value of start = 0
void print(int arr[], int n, int start = 0, int end = 0){
    for(int i = start; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[5] = {1, 3, 4, 2, 5};
    print(arr, 5, 1, 3);

    const int pi = 3.14;
    pi++; //invalid statement
}