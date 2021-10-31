/**
 * Definition for a binary tree node.
 **/ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 /**/
#include <utility>
using namespace std;

class Solution {
private:
    pair<int, int> search(TreeNode* ptr, int x, int depth, int parent);     //return parent and depth of x
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto _x = search(root, x, 0, __INT_MAX__);
        auto _y = search(root, y, 0, __INT_MAX__);
        if(_x.first == _y.first){
            if(_x.second != _y.second){
                return true;
            }
            else{
                return false;
            }
        }
        return false;

    }
};

pair<int, int> Solution::search(TreeNode* ptr, int x,  int depth, int parent){
    if(!ptr){
        return make_pair(__INT_MAX__, __INT_MAX__);
    }
    else{
        if(ptr->val == x){
            return make_pair(depth, parent);
        }
        else{
            auto _left = search(ptr->left, x, depth+1, ptr->val);
            auto _right = search(ptr->right, x, depth+1, ptr->val);
            if(_left.first != __INT_MAX__ && _left.second != __INT_MAX__){
                return _left;
            }
            if(_right.first != __INT_MAX__ && _right.second != __INT_MAX__){
                return _right;
            }
            return _left;   //no search result
        }
    }
}