/*
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
using namespace std;


class Solution {
private:
    TreeNode* traversal_delete(TreeNode*, int);
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        auto res = traversal_delete(root,target);
        return res;
    }
};

TreeNode* Solution::traversal_delete(TreeNode* ptr, int target){
    if(ptr == nullptr){
        return nullptr;
    }
    else{
        ptr->left = traversal_delete(ptr->left, target);
        ptr->right = traversal_delete(ptr->right, target);
        if(ptr->val == target && ptr->left==nullptr && ptr->right==nullptr){
            //delete ptr;
            return nullptr;
        }
        else{
            return ptr;
        }
    }
}