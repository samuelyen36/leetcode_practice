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
654. Maximum Binary Tree
https://leetcode.com/problems/maximum-binary-tree/
*/
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for(int i=0; i<nums.size(); i++){
            TreeNode *ptr = new TreeNode(nums[i]);
            while((!stk.empty()) && (stk.back()->val < nums[i])){
                ptr->left = stk.back();
                stk.pop_back();
            }

            if(!stk.empty()){       //something in stack is greater than current node.
                stk.back()->right = ptr;
            }

            stk.push_back(ptr);
        }
        //printf("%d\n",stk.size());
        return stk.front();
    }
};