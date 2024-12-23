#include<iostream>
#include<queue>
#include<map>
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
    cout << "Enter the value to be inserted in the left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the value to be inserted in right of " << val << endl;
    root -> right = buildTree(root -> right);
    return root;
}
vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> topNode;
    queue< pair<node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second;
        if(topNode.find(horizontalDistance) == topNode.end()){
            topNode[horizontalDistance] = frontNode -> data;
        }
        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, horizontalDistance - 1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, horizontalDistance + 1));
        }
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottomView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> topNode;
    queue< pair<node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second;
        topNode[horizontalDistance] = frontNode -> data;
        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, horizontalDistance - 1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, horizontalDistance + 1));
        }
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}
void solveForLeft(node* root, vector<int>& ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    solveForLeft(root -> left, ans, level + 1);
    solveForLeft(root -> right, ans, level + 1);
}
vector<int> leftView(node* root){
    vector<int> ans;
    int level = 0;
    solveForLeft(root, ans, level);
    return ans;
}
void solveForRight(node* root, vector<int>& ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    solveForRight(root -> right, ans, level + 1);
    solveForRight(root -> left, ans, level + 1);
}
vector<int> rightView(node* root){
    vector<int> ans;
    int level = 0;
    solveForRight(root, ans, level);
    return ans;
}
int main(){
    cout << "Constructing the tree: " << endl;
    node* root;
    root = buildTree(root);
    vector<int> top = topView(root);
    cout << "The top view of the tree is: " << endl;
    for(int i = 0; i < top.size(); i++){
        cout << top[i] << " ";
    }
    cout << endl;
    vector<int> bottom = bottomView(root);
    cout << "The bottom view of the tree is: " << endl;
    for(int i = 0; i < bottom.size(); i++){
        cout << bottom[i] << " ";
    }
    cout << endl;
    vector<int> left = leftView(root);
    cout << "Left view of the tree is: " << endl;
    for(int i = 0; i < left.size(); i++){
        cout << left[i] << " ";
    }
    cout << endl;
    vector<int> right = rightView(root);
    cout << "The right view of tree is: " << endl;
    for(int i = 0; i < right.size(); i++){
        cout << right[i] << " ";
    }
    cout << endl;
    return 0;
}