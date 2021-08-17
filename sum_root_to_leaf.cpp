/*
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
 #include <algorithm>
 using namespace std;
class Solution {
public:
    void traversal(TreeNode*, vector<int>&, int &);


    int sumNumbers(TreeNode* root) {
        vector<int> sum;
        int counting=0;
        traversal(root, sum, counting);
        int res=0;
        for(auto k: sum){
            res += k;
        }
        return res;
    }
};

void Solution::traversal(TreeNode *ptr,vector<int> &sum_vec, int &sum){
    if(!ptr){
        /*cout<<"push: "<<sum<<endl;
        sum_vec.push_back(sum);*/
    }
    else{
        sum*=10;
        sum += ptr->val;
        traversal(ptr->left, sum_vec, sum);
        traversal(ptr->right, sum_vec, sum);
        if(!ptr->left && !ptr->right){
            sum_vec.push_back(sum);
        }
        sum = sum/10;
    }
}


int main(){

}