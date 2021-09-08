/**
 * Definition for a binary tree node.
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 /**/
/*
513. Find Bottom Left Tree Value
https://leetcode.com/problems/find-bottom-left-tree-value/
*/
#include <vector>
using namespace std;


class Solution {
public:
    void traversal(TreeNode*, vector<int>&, int);
    int findBottomLeftValue(TreeNode* root) {
        vector<int> vec;
        this->traversal(root, vec, 0);
        return vec[(vec.size()-1)];
    }
};

void Solution::traversal(TreeNode* ptr, vector<int>& vec, int depth){
    if(!ptr){
        return;
    }
    else{
        if(vec.size() == depth){    //we haven't reach this depth before
            vec.push_back(ptr->val);
        }
        this->traversal(ptr->left, vec, depth+1);
        this->traversal(ptr->right, vec, depth+1);
        return;
    }
}