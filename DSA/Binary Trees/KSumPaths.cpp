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
void solve(int k, node* root, int& count, vector<int>& paths){
    if(root == NULL){
        return;
    }
    paths.push_back(root -> data);
    solve(k, root -> left, count, paths);
    solve(k, root -> right, count, paths);
    int size = paths.size();
    int sum = 0;
    for(int i = size - 1; i >= 0; i--){
        sum += paths[i];
        if(sum == k){
            count++;
        }
    }
    paths.pop_back();
}
int sumKPaths(node* root, int k){
    vector<int> paths;
    int count = 0;
    solve(k, root, count, paths);
    return count;
}
int main(){
    node* root = buildTree(root);
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int paths = sumKPaths(root, k);
    cout << "The number of paths in the binary tree with sum  = " << k << " are: " << paths << endl;
    return 0;
}