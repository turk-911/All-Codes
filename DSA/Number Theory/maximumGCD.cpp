#include<iostream>
using namespace std;
#define maxi 1e6
int gcd(int a, int b){
    if(b == 1 || a == 1){
        return 1;
    }
    if(a == b){
        return a;
    }
    while(a != b){
        if(a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}
int main(){
    // int n;
    // cin >> n;
    // int arr[n];
    // int hsh[1e6] = {0};
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    //     hsh[arr[i]]++;
    // }
    cout << (-8) % 7 << endl;
    
}