  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void traversal_count(TreeNode*, int&, vector<int>&);

    int goodNodes(TreeNode* root) {
        vector<int> vec;
        int counter=0;
        traversal_count(root, counter, vec);
        return counter;
    }
};

void Solution::traversal_count(TreeNode *ptr, int &count, vector<int> &vec){
    if(!ptr){
        return;
    }
    else{
        int flg=0;
        for(auto i: vec){
            if(i>ptr->val){
                flg=1;
                break;
            }
        }
        count = flg?count:count+1;

        vec.push_back(ptr->val);
        traversal_count(ptr->left, count, vec);
        traversal_count(ptr->right, count, vec);
        vec.pop_back();
    }
}