#include<iostream>
using namespace std;
int solveRec(vector<int>& nums, int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        int ans = solveRec(nums, target - nums[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveDPmem(vector<int>& nums, int target, vector<int>& dp){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    if(dp[target] != -1){
        return dp[target];
    }
    int mini = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        int ans = solveDPmem(nums, target - nums[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveDPtab(vector<int>& nums, int target){
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < target; i++){
        for(int j = 0; j < nums.size(); j++){
            if(i - nums[j] >= 0 && dp[i - nums[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
            }
        }
    }
    if(dp[target] == INT_MAX){
        return -1;
    }
    return dp[target];
}
int minimumCoins(vector<int>& nums, int target){

    // Solving by Recursion -- TLE

    // int ans = solveRec(nums, target);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    // Solving by tabulation -- TLE

    // vector<int> dp(target + 1, -1);
    // int ans = solveDPmem(nums, target, dp);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    return solveDPtab(nums, target);
}