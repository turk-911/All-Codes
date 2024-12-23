#include<iostream>
using namespace std;
int firstOccurence(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    int ans=-1;
    while(s<=n){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOccurence(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    int ans=-1;
    while(s<=n){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){
    int arr[5]={1, 3, 5, 6, 6};
    cout << "The first occurence of 5 is at " << firstOccurence(arr, 5, 6) << endl;
    cout << "The last occurence of 5 is at index: " << lastOccurence(arr, 5, 6) <<endl;
    cout << "The total number of occurences are: " << (lastOccurence(arr, 5, 6) - firstOccurence(arr, 5, 6)  + 1) << endl;
}