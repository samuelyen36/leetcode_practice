struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
102. Binary Tree Level Order Traversal
*/
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void traversal(TreeNode*, int);
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        this->traversal(root, 0);
        return this->res;
    }
};

void Solution::traversal(TreeNode* ptr, int depth){
    if(!ptr){
        return;
    }
    else{
        if(res.size() == depth){
            res.push_back(vector<int>());
        }
        this->res[depth].push_back(ptr->val);
        this->traversal(ptr->left, depth+1);
        this->traversal(ptr->right, depth+1);
        return;
    }
}