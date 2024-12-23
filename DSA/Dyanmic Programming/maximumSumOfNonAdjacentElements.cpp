#include<iostream>
#include<vector>
using namespace std;

// recursive solution -- gives TLE
int solve(vector<int>& nums, int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1) + 0;
    int ans = max(include, exclude);
    return ans;
}

// solve by memoization -- gives TLE
int solveByMemoization(vector<int>&nums, int n, vector<int>& dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int include = solveByMemoization(nums, n - 2, dp) + nums[n];
    int exclude = solveByMemoization(nums, n - 1, dp) + 0;
    dp[n] = max(include, exclude);
    return dp[n];
}

// solved by tabulation -- accepted
int solveByTabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0]; // base case
    for (int i = 1; i < n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    // return dp[n - 1];

    // space optimisation
    int prev2 = 0;
    int prev1 = nums[0];
    int ans;
    for(int i = 1; i < n; i++){
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int>& nums){
    // int n = nums.size();
    // int ans = solve(nums, n - 1);

    // int n = nums.size();
    // vector<int> dp(n, -1);
    // int ans = solveByMemoization(nums, n - 1, dp);

    int ans = solveByTabulation(nums);
    return ans;
}