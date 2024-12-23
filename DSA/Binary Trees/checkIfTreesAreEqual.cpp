#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node *buildTree(node *root){
    int val;
    cout << "Enter the data: ";
    cin >> val;
    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << val << endl;
    root->left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << val << endl;
    root->right = buildTree(root -> right);

    return root;
}
bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if((root1 == NULL && root2) || (root1 && root2 == NULL)){
        return false;
    }
    bool leftVal = isIdentical(root1 -> left, root2 -> left);
    bool rightVal = isIdentical(root1 -> right, root2 -> right);
    bool curr = root1 -> data == root2 -> data;
    return (leftVal && rightVal && curr);
}
int main(){
    return 0;
}