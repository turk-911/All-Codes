#include<iostream>
using namespace std;
int main(){
    int n=6;
    int arr[6]={4, 7, 11, 1, 2,3};
    int k=2;
    int s=0;
    int e=n-1;
    int mid=s+((e-s)/2);
    while(s<e){
        if(arr[mid]==k){
            cout << mid;
        }
        if(abs(arr[e]-k) < abs(arr[s]-k)){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+((e-s)/2);
    }
    
    
}