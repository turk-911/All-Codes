#include<iostream>
#include<vector>
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
void solve(TreeNode* root, vector<int>& inorder){
    if(root == NULL){
        return;
    }
    solve(root -> left, inorder);
    inorder.push_back(root -> val);
    solve(root -> right, inorder);
}
TreeNode* flatten(TreeNode* root){
    vector<int> inorder;
    solve(root, inorder);
    TreeNode* head = new TreeNode(inorder[0]);
    TreeNode* dummy = head;
    for(int i = 1; i < inorder.size() - 1; i++){
        TreeNode* temp = new TreeNode(inorder[i]);
        dummy -> right = temp;
        dummy -> left = NULL;
        temp = dummy;
    }
    TreeNode* temp = new TreeNode(inorder[inorder.size() - 1]);
    dummy -> right = temp;
    dummy -> left = NULL;
    temp -> right = NULL;
    temp -> left = NULL;
    return head;
}
TreeNode* buildTree(TreeNode* root){
    int data;
    cout << "Enter data to be inserted: " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    cout << "Enter data to be inserted in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to be inserted in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}
int main(){
    TreeNode* root = buildTree(root);
    return 0;
}