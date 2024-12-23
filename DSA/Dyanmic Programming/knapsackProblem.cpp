// A thief is robbing a store and can carry a maximal weight of W into his knapsack.There are N items and the ith item weighs wi and is of value vi.Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

#include<iostream>
using namespace std;

int solve(vector<int>& weights, vector<int>& values, int index, int maxWeight){
    if(index == 0){
        if(weights[0] <= maxWeight){
            return values[0];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weights[index] <= maxWeight){
        include = values[index] + solve(weights, values, index - 1, maxWeight - weights[index]);
    }
    int exclude = 0 + solve(weights, values, index - 1, maxWeight);

    int ans = max(include, exclude);
}

int solveMem(vector<int>& weights, vector<int>& values, int maxWeight, int index, vector<vector<int>>& dp){
    if(index == 0){
        if(weights[0] <= maxWeight){
            return values[0];
        }
        else{
            return 0;
        }
    }
    if(dp[index][maxWeight] != -1){
        return dp[index][maxWeight];
    }
    int include = 0;
    if(weights[index] <= maxWeight){
        include = values[index] + solveMem(weights, values, index - 1, maxWeight - weights[index], dp);
    }
    int exclude = 0 + solveMem(weights, values, maxWeight, index - 1, dp);
    dp[index][maxWeight] = max(include, exclude);
    return dp[index][maxWeight];
}

int solveTabulation(vector<int>& weights, vector<int>& values, int maxWeight){
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    for(int w = weights[0]; w <= maxWeight; w++){
        if(weights[0] <= maxWeight){
            dp[0][w] = weights[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index = 1; index < n; index++){
        for(int w = 0; w <= maxWeight; w++){
            int include = 0;
            if(weights[index] <= w){
                include = values[index] + dp[index - 1][w - weights[index]];
            }
            int exclude = 0 + dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][maxWeight];
}
int solveSpaceOptimisation(vector<int>& weights, vector<int>& values, int maxWeight){
    int n = weights.size();
    vector<int> prev(maxWeight + 1, -1);
    vector<int> curr(maxWeight + 1, -1);
    for(int w = weights[0]; w <= maxWeight; w++){
        if(weights[0] <= maxWeight){
            prev[w] = values[0];
        }
        else{
            prev[w] = 0;
        }
    }
    for(int index = 1; index < n; index++){
        for(int w = 0; w <= maxWeight; w++){
            int include = 0;
            if(weights[index] <= w){
                include = values[index] + prev[w - weights[index]];
            }
            int exclude = 0 + prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
int knapsack(vector<int>& weights, vector<int>& values, int maxWeight){
    int n = weights.size();
    // return solve(weights, values, n - 1, maxWeight);
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMem(weights, values, maxWeight, n - 1, dp);

    return solveTabulation(weights, values, maxWeight);
}