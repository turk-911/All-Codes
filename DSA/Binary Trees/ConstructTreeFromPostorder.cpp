#include<iostream>
#include<map>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this -> val = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n){
    for(int i = 0; i < n; i++){
        nodeToIndex[inorder[i]] = i;
    }
}
TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int& index, int n, int inorderStart, int inorderEnd, map<int, int>& nodeToIndex){
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    int element = postorder[index--];
    TreeNode* root = new TreeNode(element);
    int position = nodeToIndex[element];
    root -> right = solve(inorder, postorder, index, n, position + 1, inorderEnd, nodeToIndex);
    root -> left = solve(inorder, postorder, index, n, inorderStart, position - 1, nodeToIndex);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int n){
    int postorderIndex = n - 1;
    map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);
    TreeNode* ans = solve(inorder, postorder,postorderIndex, n, 0, n - 1, nodeToIndex);
    return ans;
}