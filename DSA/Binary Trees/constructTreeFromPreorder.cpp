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
    for(int i = 0; i < inorder.size(); i++){
        nodeToIndex[inorder[i]] = i;
    }
}
TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd, int n, map<int, int>& nodeToIndex){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }
    int element = preorder[index++];
    TreeNode* root = new TreeNode(element);
    int position = nodeToIndex[element];
    root -> left = solve(inorder, preorder, index, inorderStart, position - 1, n, nodeToIndex);
    root -> right = solve(inorder, preorder, index, position + 1, inorderEnd, n, nodeToIndex);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int n){
    int preorderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);
    TreeNode* ans = solve(inorder, preorder, preorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}
int main(){
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 5, 2};
    TreeNode* root = buildTree(inorder, preorder, 6);
    return 0;
}