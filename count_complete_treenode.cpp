  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#include <math.h>
class Solution {
public:
    int countNodes(TreeNode* root) {
    int left_depth=0, right_depth=0;
    for(auto i=root; i!=nullptr; i=i->left){
        left_depth++;
    }        
    for(auto i=root; i!=nullptr; i=i->right){
        right_depth++;
    }        

    if(left_depth == right_depth){
        int sum=0;
        for(int i=0; i<left_depth; i++){
            sum += pow(2,i);
        }
        return sum;
    }
    else{
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    }
};

int main(){

}