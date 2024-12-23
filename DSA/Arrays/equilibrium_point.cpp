#include<iostream>
using namespace std;
int find(int arr[], int n){
    int mid = n/2;
    int left_sum = 0;
    int right_sum = 0;
    for(int i = 0; i < mid; i++){
        left_sum += arr[i];
    }
    for(int i = mid + 1; i < n; i++){
        right_sum += arr[i];
    }
    if(right_sum > left_sum){
        while(right_sum > left_sum && mid < n - 1) {
            right_sum -= arr[mid + 1];
            left_sum += arr[mid];
            mid++;
        }
    }
    else{
        while(left_sum > right_sum && mid > 0){
            left_sum -= arr[mid - 1];
            right_sum += arr[mid];
            mid--;
        }
    }
    if(right_sum == left_sum){
        cout << "Point of equilibrium is at index " << mid << endl;
    }
    else{
        cout << "Point of equilibrium does not exist" << endl;
    }


}
int main(){
    int arr[5] = {1, 3, 5s, 2, 2}; 
    int n = 5;
    cout << find(arr , n) << endl;
}