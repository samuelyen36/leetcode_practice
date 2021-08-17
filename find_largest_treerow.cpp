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
find largest value in each tree row
https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/
*/

#include <vector>
using namespace std;

class Solution {
public:
    void traverse_and_parse(TreeNode*, vector<int>&,int);

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        traverse_and_parse(root, res, 0);
        return res;
    }
};


void Solution::traverse_and_parse(TreeNode *ptr, vector<int>&vec,int depth){
    if(!ptr){
        return;
    }
    else{
        if(depth == vec.size()){
            vec.push_back(ptr->val);
        }
        else{
            auto tmp = vec[depth];
            if (ptr->val > tmp){
                vec[depth] = ptr->val;
            }
        }
        traverse_and_parse(ptr->left, vec, depth+1);
        traverse_and_parse(ptr->right, vec, depth+1);
    }
}