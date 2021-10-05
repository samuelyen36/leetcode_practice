//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
 
class Solution {
private:
    TreeNode* recur_build(vector<int>& preorder, vector<int>& inorder, int& rootidx, int left, int right);
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootidx=0;
        return recur_build(preorder, inorder, rootidx, 0, preorder.size()-1);
    }
};

TreeNode* Solution::recur_build(vector<int>& preorder, vector<int>& inorder, int& rootidx, int left, int right){
    if(left > right){
        return nullptr;
    }
    int pivot_val = preorder[rootidx];
    int pivot_idx_in_inorder=left;
    while(inorder[pivot_idx_in_inorder] != pivot_val){
        pivot_idx_in_inorder++;
    }
    /*if(pivot_idx_in_inorder > right){
        cout<<"error when finding pivot\n";
    }*/
    TreeNode* ptr = new TreeNode(pivot_val,nullptr,nullptr);
    cout<<"build node with val: "<<pivot_val<<endl;
    rootidx++;
    ptr->left = recur_build(preorder, inorder, rootidx, left, pivot_idx_in_inorder-1);
    ptr->right = recur_build(preorder, inorder, rootidx, pivot_idx_in_inorder+1, right);
    //utilize the scheme of preorder traversal, build the node itself first, then build left and right child, while increasing rootidx
    /*printf("%d with ",ptr->val);
    if(ptr->left){
        printf("left: %d ",ptr->left->val);
    }
    else{
        printf("left: nullptr ");
    }
    if(ptr->right){
        printf("right: %d\n",ptr->right->val);
    }
    else{
        printf("right: nullptr\n");
    }*/


    return ptr;
}


int main(void){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    sol.buildTree(preorder, inorder);
}