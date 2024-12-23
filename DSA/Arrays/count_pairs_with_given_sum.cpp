#include<iostream>
using namespace std;
int main(){
    int arr[4] = {1, 1, 1, 1};
    int count = 0;
    int sum = 2;
    int n = 4;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == sum){
                count++;
            }
        }
    }
    cout << "The number of pairs are: " << count << endl;
}