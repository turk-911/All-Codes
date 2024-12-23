#include<iostream>
#include<vector>
using namespace std;
int fibonacci(int n, vector<int>& dp){
    if(n == 0 || n == 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }   
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}
int main(){
    int n;
    cout << "Enter the number: " ;
    cin >> n;
    vector<int> dp(n + 1);
    for(int i = 0; i < n + 1; i++){
        dp[i] = -1;
    }
    cout << "Required ans is: " << fibonacci(n, dp) << endl;

    cout << "Space optimisation: " << endl;
    if(n == 0){
        cout << "Required ans is: " << "0" << endl;
        return 0;
    }
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;
    for(int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << "Required ans is: " << prev1 << endl;
    return 0;
}