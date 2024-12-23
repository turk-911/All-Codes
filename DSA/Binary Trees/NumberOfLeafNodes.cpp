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
void inorderTraversal(node* &root, int &count){
    if(root == NULL){
        return;
    }
    inorderTraversal(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    inorderTraversal(root -> right, count);
}
int countLeafNodes(node* &root){
    int count = 0;
    inorderTraversal(root, count);
    return count;
}
void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node *temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelorderTraversal(node *&root){
    queue<node*> q;
    int val;
    cout << "Enter value for root: " << endl;
    cin >> val;
    root = new node(val);
    q.push(root);
    while (!q.empty()){
        node *temp = q.front();
        q.pop();
        cout << "Enter left data for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right data for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    cout << endl << "Tree has been created successfully !" << endl;
}
int main(){
    node* root = NULL;
    cout << "Building the tree: " << endl;
    buildFromLevelorderTraversal(root);
    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root);

    int count = countLeafNodes(root);
    cout << "Number of leaf nodes in the binary tree are: " << count << endl;
}