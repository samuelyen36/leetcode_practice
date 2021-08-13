/*
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 /**/
#include <bits/stdc++.h> 
class Solution {
public:
    void invert(TreeNode *);
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

void Solution::invert(TreeNode *ptr){
    if(!ptr){       //ptr is null
        return;
    }
    else{
        invert(ptr->left);
        invert(ptr->right);
        std::swap(ptr->left, ptr->right);
    }
}