/*
    230. Kth Smallest Element in a BST
    https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
 /**/

 #include <vector>
class Solution {
public:
    void in_order_sort(TreeNode *ptr, std::vector<int> &sorted);
    void return_k(TreeNode *ptr, int k, int &counter, int &res);

    int kthSmallest(TreeNode* root, int k) {
        /*std::vector<int> res;
        in_order_sort(root, res);
        return res[k-1];*/

        int counter=0;
        int res=0;
        return_k(root, k, counter, res);


        return res;
    }
};

void Solution::in_order_sort(TreeNode *ptr, std::vector<int> &sorted){     //in order traversal
    while(1){
        if(!ptr){       //ptr is null
            return;
        }
        else{
            in_order_sort(ptr->left, sorted);
            sorted.push_back(ptr->val);
            in_order_sort(ptr->right, sorted);
            return;
        }
    }
}

void Solution::return_k(TreeNode *ptr, int k, int &counter, int &res){
    while(1){
        if(!ptr){       //ptr is null
            return;
        }
        else if(k == counter){
            return;
        }
        else{
            return_k(ptr->left, k, counter, res);

            if(++counter == k){
                res = ptr->val;
                return;
            }

            return_k(ptr->right, k, counter, res);
            return;
        }
    }

}