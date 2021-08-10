
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>

class Solution {
public:
    void swap(ListNode *&ptr1, ListNode *&ptr2){
        ListNode *tmp = ptr1;
        ptr1 = ptr2;
        ptr2 = tmp;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryin=0;
        ListNode *root = new ListNode();
        ListNode *ptr = root;
        ListNode *_it_l1 = l1;
        ListNode *_it_l2 = l2;
        for(; _it_l1!=nullptr && _it_l2!=nullptr; _it_l1 = _it_l1->next, _it_l2 = _it_l2->next){
            auto sum = _it_l1->val + _it_l2->val + carryin;
            carryin = sum/10;
            ptr->val = sum%10;
            ptr->next = new ListNode(0);
            ptr = ptr->next;
        }

        if(_it_l1==nullptr && _it_l2!=nullptr){ //swap the pointer of l1 and l2
            swap(_it_l1,_it_l2);
        }

        for(; _it_l1!=nullptr; _it_l1 = _it_l1->next){      //finish the rest of l1
            auto sum = _it_l1->val + carryin;
            carryin = sum/10;
            ptr->val = sum%10;
            ptr->next = new ListNode(0);
            ptr = ptr->next;
        }

        if(carryin){        //a remaining carryin
            ptr->val = 1;
        }

        if(ptr->val == 0){          //delete the last node if its value is zero.
            ListNode *tmp = root;
            for(; tmp != nullptr; tmp = tmp->next){        //search for REAL last node
                if(tmp->next == ptr){
                    break;
                }
            }
            delete ptr;
            tmp->next = nullptr;
        }
    return root;
    }
};


int main(void){

}