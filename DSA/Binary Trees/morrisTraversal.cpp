/*Using morris traversal, we can traverse a tree without using stack and recursion*/
#include<iostream>
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
void morrisTraversal(node* root){
    while(root != NULL){
        // if the left node child is null print the right child node data and move ahead
        if(root -> left == NULL){
            cout << root -> data << " ";
            root = root -> right;
        }
        else{
            node* current = root -> left;
            // find inorder predecessor
            while(current -> right && current -> right != NULL){
                current = current -> right;
            }
            // if the right child of the inorder predecessor already points to this node
            if(current -> right == root){
                current -> right = NULL;
                root = root -> right;
            }
            // if the right child doesn't point to this node, then print this node and make right child node to this node
            else{
                cout << root -> data << " ";
                current -> right = root;
                root = root -> left;
            }
        }
    }
}
void preorder(node* root){
    if(root != NULL){
        cout << root -> data;
        return;
    }
    preorder(root -> left);
    preorder(root -> right);
}
node* buildTree(node* root){
    int val;
    cout << "Enter the value: " << endl;
    cin >> val;
    root = new node(val);
    if(val == -1){
        return NULL;
    }
    cout << "Enter the value to be inserted in left of " << val << endl;
    buildTree(root -> left);
    cout << "Enter the value to be inserted in right of " << val << endl;
    buildTree(root -> right);

    return root;
}
int main(){
    node* root;
    root = buildTree(root);
    morrisTraversal(root);
    return 0;
}