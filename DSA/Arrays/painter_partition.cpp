#include<iostream>
using namespace std;
/*Question: Partition the number of boards in given number of painters such that the time taken
to paint those boards is minimum*/
// code runs successfully
bool isPossible(int arr[], int n, int m, int mid){
    int painterCount = 1;
    int boardCount=0;
    for(int i=0; i<n; i++){
        if((boardCount+arr[i])<= mid){
            boardCount+=arr[i];
        }
        else{
            painterCount++;
            if(painterCount > m || arr[i] > mid){
                return false;
            }
            boardCount=arr[i];
        }
    } 
    return true;
}
int main(){
    int arr[4] = {5, 5, 5, 5};
    int s=0;
    int sum=0;
    int n=4;
    for(int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if (isPossible(arr, 4, 2, mid)){
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid +1;
        }
        mid = s + (e-s)/2;
    }
    cout << ans << endl;
}