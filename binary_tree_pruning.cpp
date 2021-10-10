  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

using namespace std;
/*
814. Binary Tree Pruning
https://leetcode.com/problems/binary-tree-pruning/
*/
class Solution {
private:
    bool recurisive_purning(TreeNode*); // return true if it need to be purned
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool res = recurisive_purning(root);
        if(res){
            return nullptr;
        }
        return root;
    }
};

bool Solution::recurisive_purning(TreeNode* ptr){
    if(!ptr){
        return true;
    }
    
    bool _left(false),_right(false);
    _left = recurisive_purning(ptr->left);
    _right = recurisive_purning(ptr->right);
    if(_left && ptr->left!=nullptr){
        ptr->left = nullptr;
    }
    if(_right && ptr->right!=nullptr){
        ptr->right = nullptr;
    }

    if(_left && _right && ptr->val == 0){
        return true;
    }
    return false;
}