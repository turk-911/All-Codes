#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextSmallerElement(int arr[], int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n, 0);
    for(int i = n - 1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    cout << "Result is: ";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[5] = {2, 1, 0, 1, 2};
    nextSmallerElement(arr, 5);
    return 0;
}