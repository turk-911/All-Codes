/*Question statement: A square n x n matrix is is used to represent people at a party such that if an element of row i and column j is set to 1, it means that the ith person knows the jth person. Here M[i][i] will always be 0*/
/*Celebrity is a person who doesn't know anyone but everyone at the party know celebrity*/

#include<iostream>
#include<stack>
using namespace std;
// Function to check if a knows b or not
bool knows(int a, int b, vector<vector<int>>& M, int n){
    if(M[a][b] == 1){
        return true;
    }
    return false;
}
int celebrity(vector<vector<int>>& M, int n){
    stack<int> s;
    // Step 1: Push all elements in the stack
    for(int i = 0; i < n; i++){
        s.push(n);
    }

    // Step 2: Get 2 elements and compare them
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a, b, M, n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    // Step 3: Single element left in stack is potential celebrity so verify it
    int candidate = s.top();
    bool rowCheck = false;
    int zeroCount = 0;
    for(int i = 0; i < n; i++){
        if(M[candidate][i] == 0){
            zeroCount++;
        }
    }
    // Check if all of the row is zero: 
    if(zeroCount == n){
        rowCheck = true;
    }

    bool columnCheck = false;
    zeroCount = 0;
    for(int i = 0; i < n ; i++){
        if(M[i][candidate] == 0){
            zeroCount++;
        }
    }
    // Check if all of the column in zero
    if(zeroCount == n - 1){
        columnCheck = true;
    }

    // Return the ans
    if(rowCheck && columnCheck){
        return candidate;
    }
    return -1;
}