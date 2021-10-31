#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        for(auto ptr = head; ptr; ptr=ptr->next){
            if(ptr->child){
                auto child_last = ptr->child;
                while(child_last->next != nullptr){     //get the last node of the child list
                    child_last = child_last->next;
                }
                auto ori_next = ptr->next;
                ptr->next = ptr->child;
                ptr->child = nullptr;
                ptr->next->prev = ptr;
                ori_next->prev = child_last;
                child_last->next = ori_next;
            }
        }
        return head;
    }
};