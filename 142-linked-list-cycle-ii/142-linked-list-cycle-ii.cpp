/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            if(slow==NULL) return NULL;
            slow=slow->next;
            if(fast->next==NULL) return NULL;
            fast=fast->next->next;
        }while(slow!=NULL && fast!=NULL && slow!=fast);
        
        if(slow==NULL || fast==NULL) return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};