/*Question Statement: Find the maximum area of matrix occupied by 1s together in a binary matrix*/

#include<iostream>
#include<stack>
using namespace std;
vector<int> nextSmallerElement(vector<int>& arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int>& arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for(int i = 0; i < n; i++){
        int l = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}
int maxArea(vector<vector<int>>& M, int n, int m){
    // Compute area for first row
    int area = largestRectangleArea(M[0]);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            // Row updation: by adding previous row's values
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else{
                M[i][j] = 0;
            }
        }
        // All the rows have been updated
        area = max(area, largestRectangleArea(M[i]));
    }

    return area;

}
// Time complexity of the solution: O(n x m) : n is the number of rows and m is the number of columns
// Space complexity of the solution: O(m) : Stack has been used 
int main(){
    return 0;
}