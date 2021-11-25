struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*
450. Delete Node in a BST
https://leetcode.com/problems/delete-node-in-a-bst/
*/ 
class Solution {
private:
    void delete_specific(TreeNode* ptr, TreeNode* root);
    int find_delete_sucessor(TreeNode* ptr);            //return the value of right sucessor of ptr, which is the leaf of right subtree
    TreeNode* prev;
    int left_right; //left=0, right=1
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* ptr = root;
        prev = nullptr;
        while(ptr){
            if(ptr->val == key){
                if(ptr==root){
                    if(root->left == nullptr && root->right == nullptr){
                        return nullptr;
                    }
                    else if(root->left == nullptr && root->right != nullptr){
                        root = root->right;
                        return root;
                    }
                    else if(root->left != nullptr && root->right == nullptr){
                        root = root->left;
                        return root;
                    }
                    else{
                        auto tmp = find_delete_sucessor(root);
                        root->val = tmp;
                        return root;
                    }
                }

                delete_specific(ptr, root);
                break;
            }
            else if(key > ptr->val){
                prev = ptr;
                left_right=1;
                ptr = ptr->right;
            }
            else{
                prev = ptr;
                left_right=0;
                ptr = ptr->left;
            }
        }
        return root;
    }
};

void Solution::delete_specific(TreeNode* ptr, TreeNode* root){
    if(ptr->left == nullptr && ptr->right == nullptr){
        if(left_right==1){
            delete prev->right;
            prev->right = nullptr;
        }
        else{
            delete prev->left;
            prev->left = nullptr;
        }
    }
    else if(ptr->left == nullptr && ptr->right != nullptr){
        if(left_right==1){
            prev->right = ptr->right;
        }
        else{
            prev->left = ptr->right;
        }
    }
    else if(ptr->left != nullptr && ptr->right == nullptr){
        if(left_right==1){
            prev->right = ptr->left;
        }
        else{
            prev->left = ptr->left;
        }
    }
    else{           //both nodes are not null
        int succ = find_delete_sucessor(ptr);
        ptr->val = succ;
    }
    return;
}

int Solution::find_delete_sucessor(TreeNode* ptr){
    int suc;
    TreeNode* previous=ptr;
    int leftright=1;
    ptr = ptr->right;
    while(ptr->left != nullptr){       //find the succssor node of ptr
        previous = ptr;
        leftright = 0;
        ptr = ptr->left;
    }
    suc = ptr->val;

    if(ptr->left!=nullptr && ptr->right==nullptr){
        if(leftright==0){
            previous->left = ptr->left;
        }
        if(leftright==1){
            previous->right = ptr->left;
        }

        //ptr = ptr->left;
    }

    else if(ptr->left==nullptr && ptr->right!=nullptr){
        if(leftright==0){
            previous->left = ptr->right;
        }
        if(leftright==1){
            previous->right = ptr->right;
        }    
    }

    else{               //leaf
        if(leftright==0){
            previous->left = nullptr;
        }
        if(leftright==1){
            previous->right = nullptr;
        }    
    }

    return suc;
}