#include<iostream>
#include<vector>
#include<queue>
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
    cout << "Enter the value: " << endl;
    cin >> val;
    root = new node(val);
    if(val == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << val << endl;
    root -> right = buildTree(root -> right);
    return root;
}
void traverseLeft(node* root, vector<int>& ans){
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
        return; 
    }
    ans.push_back(root -> data);
    if(root -> left){
        traverseLeft(root -> left, ans);
    }
    else{
        traverseLeft(root -> right, ans);
    }
}
void traverseLeaf(node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    }
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}
void traverseRight(node* root, vector<int>& ans){
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    if(root -> right){
        traverseRight(root -> right, ans);
    }
    else{
        traverseRight(root -> left, ans);
    }
    ans.push_back(root -> data);
}
vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root -> data);
    traverseLeft(root -> left, ans);
    traverseLeaf(root -> left, ans); // Leaf nodes in left subtree
    traverseLeaf(root -> right, ans); // Leaf nodes in right subtree
    traverseRight(root, ans);
    return ans;
}
int main(){
    node* root;
    cout << "Building the tree: " << endl;
    root = buildTree(root);
    vector<int> ans = boundaryTraversal(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}   