#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root){
    int val;
    cout << "Enter the data: ";
    cin >> val;
    root = new node(val);
    if (val == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << val << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << val << endl;
    root->right = buildTree(root->right);

    return root;
}
node* lca(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == n1 || root -> data == n2){
        return root;
    }
    node* leftAns = lca(root -> left, n1, n2);
    node* rightAns = lca(root -> right, n1, n2);
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}
int main(){
    node* root = buildTree(root);
    node* ans = lca(root, 3, 4);
    cout << "The least common ancestor is: " << ans -> data << endl;
}