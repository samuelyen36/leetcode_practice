#include <vector>
using namespace std;
/*
725. Split Linked List in Parts
https://leetcode.com/problems/split-linked-list-in-parts/
*/
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        vector<ListNode*> res;
        for(auto i=head; i!=nullptr; i=i->next){        //calculate the length of linked list
            len++;
        }

        if(len < k){        //have to fillin null
            for(auto i=head; i!=nullptr; ){
                auto prev = i;
                i = i->next;
                prev->next = nullptr;
                res.push_back(prev);
            }
            for(int i=0; i<k-len; i++){
                res.push_back(nullptr);
            }
        }
        else{
            int remain = len%k;     //see how many list should be size of one larger than others
            int each_size = len/k;  //size of each splited list
            auto root = head;

            while(root != nullptr){    
                if(remain >0){
                    remain--;
                    auto sp_root = root;    //root of this splited list
                    for(int i=0; i<=each_size; i++){
                        if(i==0){
                            res.push_back(sp_root);
                        }
                        if(i == each_size){
                            auto prev = root;
                            //root = nullptr?nullptr:root->next;
                            if(root!=nullptr)   root = root->next;
                            if(prev!=nullptr)   prev->next = nullptr;
                            continue;
                        }
                        root = nullptr?nullptr:root->next;
                        continue;
                    }
                }
                else{
                    auto sp_root = root;    //root of this splited list
                    for(int i=0; i<each_size; i++){
                        if(i==0){
                            res.push_back(sp_root);
                        }
                        if(i == each_size-1){
                            auto prev = root;
                            //root = nullptr?nullptr:root->next;
                            if(root!=nullptr)   root = root->next;
                            if(prev!=nullptr)   prev->next = nullptr;
                            continue;
                        }
                        //root = nullptr?nullptr:root->next;
                        if(root!=nullptr)   root = root->next;
                        continue;
                    }
                    remain--;
                }
            }

        }
        return res;
    }
};