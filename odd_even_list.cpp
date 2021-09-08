/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* oddhead = head;
        ListNode* evenhead = head->next;
        ListNode* evenptr = evenhead;

        while(evenptr && evenptr->next){
            oddhead->next = oddhead->next->next;
            evenptr->next = evenptr->next->next;
            oddhead = oddhead->next;
            evenptr = evenptr->next;    
        }
        oddhead = evenhead;
        return head;
    };
}