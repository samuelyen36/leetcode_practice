  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*
https://leetcode.com/problems/binary-search-tree-iterator/
173. Binary Search Tree Iterator
*/

#include <queue>
using namespace std;


class BSTIterator {
private:
    void inorder_traversal(queue<int>& q, TreeNode* ptr, int& nodes);
    queue<int> q;
    int nodes;

public:
    BSTIterator(TreeNode* root) {
        nodes=0;
        this->inorder_traversal(q, root, nodes);
    }
    
    int next() {
        auto res = q.front();
        q.pop();
        return res;
    }
    
    bool hasNext() {
        if(q.empty()){
            return false;
        }
        else{
            return true;
        }
    }

};


void BSTIterator::inorder_traversal(queue<int>& q, TreeNode* ptr, int& nodes){
    if(!ptr){
        return;
    }
    else{
        this->inorder_traversal(q,ptr->left, nodes);
        q.push(ptr->val);
        nodes++;
        this->inorder_traversal(q,ptr->right, nodes);
        return;
    }
}
