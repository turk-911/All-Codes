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
    node* root = new node(val);
    if(val == -1){
        return NULL;
    }
    cout << "Enter the data for inserting values in left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting values in right of " << val << endl;
    root -> right = buildTree(root -> right);
    return root;
}
node* solve(node* root, int &k, int val){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == val){
        return root;
    }
    node* leftAns = solve(root -> left, k, val);
    node* rightAns = solve(root -> right, k, val);
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(node* root, int k, int val){
    node* ans = solve(root, k, val);
    if(ans == NULL || ans -> data = val){
        return -1;
    }
    return ans -> data;
}
int main(){
    node* root = buildTree(root);
    int k;
    int val;
    cout << "Enter the value of node for which you find the kth ancestor: ";
    cin >> val;
    cout << "Enter the value of k: " ;
    cin >> k;
    int ans = kthAncestor(root, k, val);
    cout << "The kth ancestor of the node is: " << ans << endl;
    return 0;
}