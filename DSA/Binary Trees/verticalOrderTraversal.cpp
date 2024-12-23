#include<iostream>
#include<vector>
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
    cout << "Enter the value to insert in left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the value to insert in right of " << val << endl;
    root -> right = buildTree(root -> right);
    return root;
}
vector<int> verticalOrderTraversal(node* root){
    map< int, map<int, vector<int> > > nodes;
    queue< pair<node*, pair<int, int> > > q;
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()){
        pair<node*, pair<int, int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontalDistance][level].push_back(frontNode -> data);

        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, make_pair(horizontalDistance - 1, level + 1)));
        }

        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main(){
    node* root;
    root = buildTree(root);
    vector<int> ans = verticalOrderTraversal(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}