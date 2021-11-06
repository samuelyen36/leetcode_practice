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
#include <vector>
using namespace std;

class Solution {
private:
    int sum;
    void traversal(TreeNode* ptr, bool left);
public:
    Solution(){
        this->sum=0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root, false);
        return sum;
    }
};

void Solution::traversal(TreeNode* ptr, bool left){
    if(!ptr){
        return;
    }
    if(ptr->left==nullptr && ptr->right==nullptr && left){
        this->sum += ptr->val;
    }
    traversal(ptr->left, true);
    traversal(ptr->right, false);
}