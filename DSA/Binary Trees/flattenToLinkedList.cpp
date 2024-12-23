#include<iostream>
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
TreeNode* buildTree(TreeNode* root){
    int data;
    cout << "Enter the value: " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    cout << "Enter the value to be inserted in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the value to be inserted in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}
class Solution{
    public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root){
        if(root == NULL){
            return;
        }
        flatten(root -> left);
        flatten(root -> right);
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};