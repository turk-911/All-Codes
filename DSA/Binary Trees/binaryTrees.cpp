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
node* buildTree(node* root){
    int val;
    cout << "Enter the data: " ;
    cin >> val;
    root = new node(val);
    if(val == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << val << endl;
    root -> right = buildTree(root -> right);

    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
void inorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}
void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}
void postorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}
void buildFromLevelorderTraversal(node* &root){
    queue<node*> q;
    int val;
    cout << "Enter value for root: " << endl;
    cin >> val;
    root = new node(val);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout << "Enter left data for " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }
        cout << "Enter right data for " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
    cout << endl << "Tree has been created successfully !" << endl;
}
void newLine(){
    cout << endl;
}
int main(){
    node* root = NULL;
    buildFromLevelorderTraversal(root);
    root = buildTree(root);
    // 1 3 5 -1 -1 6 -1 -1 4 9 -1 -1 -1
    cout << endl << endl << "Printing the level order traversal: " << endl;
    levelOrderTraversal(root);
    newLine();
    cout << "Inorder traversal of the binary tree is: " ;
    inorderTraversal(root);
    newLine();
    cout << "Preorder traversal of the binary tree is: ";
    preorderTraversal(root);
    newLine();
    cout << "Postorder traversal of the binary tree is: ";
    postorderTraversal(root);
    newLine();
    return 0;
}