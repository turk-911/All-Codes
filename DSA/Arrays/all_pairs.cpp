#include<iostream>
using namespace std;
int main(){
    int arr1[5] = {1, 2, 4, 5, 7};
    int arr2[5] = {5, 6, 4, 3, 8};
    int sum = 9;
    int n = 5;
    cout << "The pairs are: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((arr1[i] + arr2[j]) == sum){
                cout << arr1[i] << " " << arr2[j] << endl;
            }
        }
    }
}