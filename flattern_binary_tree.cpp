  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*
114. Flatten Binary Tree to Linked List
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
    TreeNode *prev;
    void postorder(TreeNode* tree_ptr);
    public:
        Solution(){
            prev = nullptr;
        }
        void flatten(TreeNode* root) {
            postorder(root);
        }
};

void Solution::postorder(TreeNode* tree_ptr){
    if(!tree_ptr){
        return;
    }
    postorder(tree_ptr->right);
    postorder(tree_ptr->left);
    tree_ptr->right = prev;
    tree_ptr->left = nullptr;
    this->prev = tree_ptr;
    return;
}

