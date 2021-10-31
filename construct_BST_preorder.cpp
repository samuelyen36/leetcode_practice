/**
  Definition for a binary tree node.
  */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include <vector>
#include <iostream>
using namespace std;


class Solution {
private:
    TreeNode* build_recursive(vector<int>& vec, int start, int end);
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int first_bigger_idx = preorder.size();
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i] > root->val){
                first_bigger_idx = i;
                break;
            }
        }
        
        root->left = build_recursive(preorder, 1, first_bigger_idx-1);
        root->right = build_recursive(preorder, first_bigger_idx, preorder.size()-1);

        return root;
    }
};

TreeNode* Solution::build_recursive(vector<int>& vec, int start, int end){
    cout<<"search: "<<start<<"\t"<<end<<endl;
    if(start > end){
        return nullptr;
    }
    else if(start == end){
        TreeNode* ptr = new TreeNode(vec[start]);
        ptr->left = ptr->right = nullptr;
        return ptr;
    }
    else{
        TreeNode* ptr = new TreeNode(vec[start]);
        int first_bigger_idx = end+1;
        for(int i=start+1; i<=end; i++){
            if(vec[i] > ptr->val){
                first_bigger_idx = i;
                break;
            }
        }
        ptr->left = build_recursive(vec, start+1, first_bigger_idx-1);
        ptr->right = build_recursive(vec, first_bigger_idx, end);
        return ptr;
    }
}