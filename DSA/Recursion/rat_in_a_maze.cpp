#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>>& m){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }
    else{
        return false;
    }  
}
void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
    if(x == n - 1 && y == n - 1){
        ans.push_back(path);
        return ;
    }
    visited[x][y] = 1;
    // for down
    int newX = x + 1;
    int newY = y;
    if(isSafe(newX, newY, n, visited, m)){
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // for left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, n, visited, m)){
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // for right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, n, visited, m)){
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // for Up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, m)){
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>>& m, int n){
    vector<string> ans;
    // if the rat cannot reach the starting index
    if(m[0][0] == 0){
        return {};
    }

    int src_x = 0; // starting coordinate for x
    int src_y = 0; // starting coordinate for y
    vector<vector<int>> visited; // to keep a track of visited boxes so that we don't go back into the maze

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(m, n, ans, src_x, src_y, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}