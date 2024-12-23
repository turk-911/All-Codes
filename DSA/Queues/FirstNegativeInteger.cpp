/*Question statement: Given an array A[] of size N, print first negative integer for each subarray of size K*/
#include<iostream>
#include<deque>
#include<queue>
#include<vector>
using namespace std;
vector<long long int> printFirstNgativeInteger(long long int A[], long long int N, long long int K){
    deque<long long int> dq;
    vector<long long int> ans;
    // process first window of K size
    for(int i = 0; i < K; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    // store answer of first K size window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    // process for remaining windows
    for(int i = K; i < N; i++){
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front();
        }
        if(A[i] < 0){
            dq.push_back(i);
        }
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
int main(){
    long long int arr[6] = {1, 9, -2, 3, -4, -10};
    vector<long long int> ans;
    cout << "The input array is: ";
    ans = printFirstNgativeInteger(arr, 6, 4);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The output is: ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}