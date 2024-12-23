#include<iostream>
using namespace std;
int binarySearch(int n){
    int s=0;
    int e=n;
    int mid = s + (e-s)/2;
    int square=mid*mid;
    int ans;
    while(s<=e){
        if(square==n){
            return mid;
        }
        else if(square>n){
            e=mid-1;
            // cout << "_";
        }
        else{
            ans=mid;
            s=mid-1;
            // cout << "_";
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    cout << "The square root of the number is: " << binarySearch(n) << endl;
}