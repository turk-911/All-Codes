#include<iostream>
using namespace std;
/*Question: Allocate the pages of book to m number of students such that the maximum number of 
pages alloted is minimum*/
bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum=0;
    for(int i=0; i<n; i++){
        if((pageSum+arr[i])<= mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum=arr[i];
        }
    } 
    return true;
}
int main(){
    int arr[4] = {10, 20, 30, 40};
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