#include<iostream>
using namespace std;
void solve(vector<int> nums, vector<vector<int>>& ans, int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j = 0; j < nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        // backtracking
        swap(nums[index], nums[j]);
    }
}
vector<string> permuatations(vector<int>& nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}
int main(){
    vector<int> nums;
    for(int i = 1; i <= 3; i++){
        nums.push_back(i);
    }
    vector<vector<int>> ans = permutations(nums);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}