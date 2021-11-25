#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private: 
    TreeNode* _construct(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int po_start, int po_end);
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return this->_construct(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};

TreeNode* Solution::_construct(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int po_start, int po_end){
    if(in_start>in_end || po_start>po_end){
        return nullptr;
    }
    int pivot = postorder[po_end];
    int left_count = 0;
    int pivot_idx=0;
    TreeNode* ptr = new TreeNode(pivot);        //construct the node with last element of post order traversal
    for(int i=in_start; i<=in_end; i++){
        if(inorder[i] == pivot){
            left_count = i-in_start;        //how many element belongs to left side of the pivot
            pivot_idx = i;
        }
    }
    ptr->left = _construct(inorder, in_start, pivot_idx-1, postorder, po_start, po_start+left_count-1);
    ptr->right = _construct(inorder,pivot_idx+1, in_end, postorder, po_start+left_count, po_end-1);
    return ptr;
}