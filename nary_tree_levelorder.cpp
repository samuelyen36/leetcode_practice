#include <vector>
using namespace std;
/*
429. N-ary Tree Level Order Traversal
https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void traversal(Node*, vector<vector<int>>&,int );
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        traversal(root, res, 0);
        return res;
    }
};

void Solution::traversal(Node *ptr, vector<vector<int>>& res, int level){
    if(!ptr){
        return;
    }
    if(res.size() == level){    //haven't reach this level before
        vector<int> tmp;
        tmp.push_back(ptr->val);
        res.push_back(tmp);
    }
    else{
        res[level].push_back(ptr->val);
    }
    for(auto it: ptr->children){
        traversal(it, res, level+1);
    }
    return;
}