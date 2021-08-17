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
public:
    void traversal(TreeNode*, vector<int>&, int);
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        traversal(root, res, 0);
        return res;
    }
};

void Solution::traversal(TreeNode* ptr, vector<int>& res, int depth){
    if(!ptr){
        return;
    }
    else{
        if(res.size() == depth ){
            res.push_back(ptr->val);
        }
            traversal(ptr->right, res, depth+1);
            traversal(ptr->left, res, depth+1);    
    }
    return;
}