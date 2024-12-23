#include<iostream>
#include<math.h>
using namespace std;
int max(int a, int b){

    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int n;
    int mx=-199999999;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        mx = max(mx, arr[i]);
        cout << max << " ";
    }
   

}