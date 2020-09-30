#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        //Finding the Middle element
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* Mid = slow;
        //Reversing the second list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* temp;
        
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;            
        }
        
//         Merging the Lists
        
        ListNode* first = head;
            ListNode* second = prev;
        
        while(second->next!=NULL){
            temp = first->next;
            first->next = second;
            first = temp;
            
            temp = second->next;
            second->next = first;
            second = temp;
        }

    }
};