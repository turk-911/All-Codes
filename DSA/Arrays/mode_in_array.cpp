#include<iostream>
using namespace std;
int main(){
    int arr[9]={3, 7, 3, 3, 5, 5, 5, 7, 7};
    int n=9;
    int max_count=0;
    int max_freq=0;
    for(int i=0; i<n; i++){
        int count=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count >= max_count){
            max_count = count;
            max_freq=arr[i];
        }
    }
    cout << "The number occuring maximum times is: " << max_freq << endl;
    cout << "The number occurs " << max_count << " times. " << endl;
}