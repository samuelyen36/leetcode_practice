struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
203. Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = nullptr;
        ListNode *ptr = head;
        while(ptr != nullptr){
            if(ptr->val == val){        //delete this node
                if(prev == nullptr){    //first node meets the value to be deleted
                    head = ptr->next;
                    prev = nullptr;
                    ptr = ptr->next;
                }
                else if(prev!=nullptr){
                    prev->next = ptr->next;
                    ptr = ptr->next;
                }
                continue;
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};