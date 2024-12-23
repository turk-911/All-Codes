#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root){
    int val;
    cout << "Enter the data: " << endl;
    cin >> val;
    if(val == -1){
        return NULL;
    }
    cout << "Enter the value for inserting in left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting in right of " << val << endl;
    root -> right = buildTree(root -> right);
    return root;
}
pair<int, int> solve(node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftAns = solve(root -> left);
    pair<int, int> rightAns = solve(root -> right);
    pair<int, int> result;
    result.first = root -> data + leftAns.second + rightAns.second;
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    return result;
}
int getMaxSum(node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main(){
    node* root = buildTree(root);
    int ans = getMaxSum(root);
    cout << "The maximum sum of non adjacent nodes in the binary tree is: " << ans << endl;
}