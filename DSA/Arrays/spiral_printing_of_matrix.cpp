#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans;

    int row = matrix.size();
    int column = matrix[0].size();

    int count = 0;
    int total = row*column; // total number of elements

    int startingRow = 0;
    int endingRow = row - 1;
    int startingColumn = 0;
    int endingColumn = column - 1;
    while(count < total){
        for(int i = startingColumn; i < endingColumn; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        for(int i = startingRow; i < endingRow; i++){
            ans.push_back(matrix[i][endingColumn]);
            count++;
        }
        endingColumn--;
        for(int i = endingColumn; i >= startingColumn; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        for(int i = endingRow; i >= startingRow; i--){
            ans.push_back(matrix[i][startingColumn]);
            count++;
        }
        startingColumn++;
    }
    return ans;
}
int main(){
    vector<vector<int>>& matrix;
    matrix.push_back({1, 2, 3});
    matrix.push_back({4, 5, 6});
    matrix.push_back({7, 8, 9});

    spiralOrder(matrix);
}