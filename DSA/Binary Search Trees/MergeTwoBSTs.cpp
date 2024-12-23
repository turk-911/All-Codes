#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this -> val = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void solve(TreeNode* root, vector<int>& inorder){
    if(root == NULL){
        return;
    }
    solve(root -> left, inorder);
    inorder.push_back(root -> val);
    solve(root -> right, inorder);
}
void mergeTwoSortedArrays(vector<int>& ans1, vector<int>& ans2, vector<int>& ans){
    int i = 0;
    int j = 0;
    while(i < ans1.size() && j < ans2.size()){
        if(ans1[i] < ans2[j]){
            ans.push_back(ans1[i]);
            i++;
        }
        else{
            ans.push_back(ans2[j]);
            j++;
        }
    }
    while(i < ans1.size()){
        ans.push_back(ans1[i]);
        i++;
    }
    while(j < ans2.size()){
        ans.push_back(ans2[j]);
        j++;
    }
}
TreeNode* inorderToBST(int start, int end, vector<int>& inorder){
    if(start > end){
        return NULL;
    }
    int mid = start + (end - start)/2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root -> left = inorderToBST(start, mid - 1, inorder);
    root -> right = inorderToBST(mid + 1, end, inorder);
    return root;
}
TreeNode* MergeBSTs(TreeNode* root1, TreeNode* root2){
    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans;
    solve(root1, ans1);
    solve(root2, ans2);
    mergeTwoSortedArrays(ans1, ans2, ans);
    return inorderToBST(0, ans.size() - 1, ans);
} 


/*the above solution has a time complexity of O(m + n) and a space complexity of O(m + n), but we want a solution with time complexity O(m + n) and space complexity of O(h1 + h2) where h1 and h2 are the heights of trees respectively.*/


void convertToSortedDLL(TreeNode* root, TreeNode*& head){
    if(root == NULL){
        return;
    }
    convertToSortedDLL(root -> right, head);
    root -> right = head;
    if(head != NULL){
        head -> left = root;
    }
    head = root;
    convertToSortedDLL(root -> left, head);
}
TreeNode* mergeTwoLLs(TreeNode* head1, TreeNode* head2){
    TreeNode* head = NULL;
    TreeNode* tail = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1 -> val < head2 -> val){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else{
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else{
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }
    while(head1 != NULL){
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    while(head2 != NULL){
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;
    }
    return head;
}
int countNodes(TreeNode* head){
    int count = 0;
    while(head){
        count++;
        head = head -> right;
    }
    return count;
}
TreeNode* sortedLLtoBST(TreeNode* head, int n){
    if(n <= 0 || root == NULL){
        return NULL;
    }
    TreeNode* left = sortedLLtoBST(head, n / 2);
    TreeNode* root = head;
    root -> left = left;    
    head = head -> right;
    TreeNode* right = sortedLLtoBST(head, n - n/2 - 1);
    root -> right = right;
    return root;
}
TreeNode* mergeBSTfast(TreeNode* root1, TreeNode* root2){
    TreeNode* head1 = NULL;
    convertToSortedDLL(root1, head1);
    head1 -> left = NULL;
    TreeNode* head2 = NULL;
    convertToSortedDLL(root2, head2);
    head2 -> left = NULL;

    TreeNode* head = mergeTwoLLs(head1, head2);
    return sortedLLtoBST(head, countNodes(head));
}