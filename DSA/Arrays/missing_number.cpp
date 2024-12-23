#include<iostream>
using namespace std;
int main(){
    int arr[8]={1, 2, 3, 4, 5, 6, 7, 9};
    int s=0;
    int n=8;
    int e=n-1;
    int mid=s+((e-s)/2);
    while(s<e){
        if(arr[e]-arr[mid]==e-mid){
            e=mid;
        }
        else{
            s=mid+1;
        }
        mid=s+((e-s)/2);
        if(arr[s+1]==arr[e]){
            cout << arr[s] + 1;
            break;
        }
    }
    
}