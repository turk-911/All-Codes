#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};
TreeNode* insertToBST(TreeNode* root, int data){
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    }
    if(data > root -> val){
        root -> right = insertToBST(root -> right, data);
    }
    else{
        root -> left = insertToBST(root -> left, data);
    }
    return root;

}
void takeInput(TreeNode* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertToBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> val << " ";
            if (temp -> left){
                q.push(temp -> left);
            }
            if (temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
int main(){
    TreeNode* root = NULL;
    cout << "Enter data to insert in BST: " << endl;
    takeInput(root);
    return 0;
}