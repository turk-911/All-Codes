#include<iostream>
using namespace std;
// space complexity = O(1)
// time complexity = O(n2)
// selection sort is used when there are memeory constraints
int main(){
    int arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    int n = 9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            if(arr[j] >= arr[i]){
                int swap = arr[j];
                arr[j] = arr[i];
                arr[i] = swap;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}