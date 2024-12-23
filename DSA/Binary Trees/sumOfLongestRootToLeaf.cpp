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
void solve(node* root, int len, int& maxLen, int sum, int& maxSum){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        if(len == maxLen){
            maxSum = max(maxSum, sum);
        }
        return;
    }
    sum = sum + root -> data;
    solve(root -> left, len + 1, maxLen, sum, maxSum);
    solve(root -> right, len + 1, maxLen, sum, maxSum);
}
int sumOfLongRootToLeaf(node* root){
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}
int main(){
    node* root = buildTree(root);
    int maxSum = sumOfLongRootToLeaf(root);
    cout << "The longest sum of path values in a binary tree is: " << maxSum << endl;
    return 0;
}