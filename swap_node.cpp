  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

#include <iostream>
/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/
*/

class Solution {
public:
    void reverse(ListNode *head);           //reverse the linked list
    void traversal(ListNode *head);   //print the value of linked list
    ListNode* swapPairs(ListNode* head) {
        reverse(head);
        return head;
    }
};

void Solution::reverse(ListNode *head){
    auto ptr = head;
    ListNode *adj_next;
    while(ptr && ptr->next){      //stop when one of those is nullptr
        adj_next = ptr->next;
        auto tmp = ptr->val;
        ptr->val = adj_next->val;
        adj_next->val = tmp;
        ptr = adj_next->next;

        if(!ptr){
            break;
        }
    }
    return;
}

void Solution::traversal(ListNode *head){
    for(auto ptr = head; ptr!=nullptr; ptr = ptr->next){
        std::cout<<ptr->val<<" ";
    }
    std::cout<<std::endl;
}


int main(){

}