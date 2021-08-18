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
    void solution(ListNode* l1, ListNode* l2, ListNode* prev, int carry){
        if(l1==NULL && l2==NULL){
            if(carry==0){return;}
            else{
                ListNode* temp=NULL;
                temp=new ListNode(carry);
                prev->next=temp;
                return;
            }
        }
        
        if(l1==NULL){
            int sum=carry+l2->val;
            int rem=sum%10;
            carry=sum/10;
            ListNode* temp=NULL;
            temp = new ListNode(rem);
            prev->next=temp;
            solution(NULL, l2->next, temp, carry);
            return;
        }
        if(l2==NULL){
            int sum=carry+l1->val;
            int rem=sum%10;
            carry=sum/10;
            ListNode* temp=NULL;
            temp = new ListNode(rem);
            prev->next=temp;
            solution(l1->next, NULL, temp, carry);
            return;
        }
        
        int sum=carry+l1->val+l2->val;
        int rem=sum%10;
        carry=sum/10;
        ListNode* temp=NULL;
        temp=new ListNode(rem);
        prev->next=temp;
        solution(l1->next, l2->next, temp, carry);
        return;
        
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        head = new ListNode(-1);
        solution(l1, l2, head, 0);
        return head->next;
    }
};