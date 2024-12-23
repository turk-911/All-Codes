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
node* buildTree(node* root){
    int val;
    cout << "Enter the data: ";
    cin >> val;
    root = new node(val);

    if(val == -1){
        return NULL;
    }

    cout << "Enter the value to insert in left of " << val << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the value to insert in right of " << val << endl;
    root -> right = buildTree(root -> right);

    return root;
}
pair<bool, int> isSumTreeFast(node* root){

    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root -> left == NULL && root -> right == NULL){
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root -> left);
    pair<bool, int> rightAns = isSumTreeFast(root -> right);

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condition = root -> data == leftSum + rightSum;

    bool left = leftAns.first;
    bool right = rightAns.first;

    pair<bool, int> ans;

    if(left && right && condition){
        ans.first = true;
        ans.second = (root -> data) + leftSum + rightSum;
    } 

    else{
        ans.first = false;
        ans.second = 0;
    }

    return ans;

}
bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}
int main(){
    return 0;
}