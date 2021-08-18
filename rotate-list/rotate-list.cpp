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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* last=temp;
        
        int len=0;
        while(temp!=NULL){
            len++;
            last=temp;
            temp=temp->next;
        }
        if(len==0){return head;}
        
        k=k%len;
        
        if(k==0){return head;}
        
        int n=len-k;
        temp=head;
        for(int i=2; i<=n; i++){
            temp=temp->next;
        }
        
        last->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};